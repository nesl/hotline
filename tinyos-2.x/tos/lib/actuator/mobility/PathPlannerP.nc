
/*
 * This is the Actuator Manager for controlling mobility of a simulated robot
 * in Stage.
 * It uses a path planner interface that is implemented in Stage.
 */

#include "PathPlanner.h"
#include <math.h>
#include <Timer.h>

module PathPlannerP {
    provides interface ActuatorControl;
    provides interface Init;

    uses interface Timer<TMilli> as LocalTimer;
    uses interface Pool<pos_intent_t> as IntentPool;
    uses interface Location2d;

    uses interface SortedQueue as CommitQueue;

    uses interface VelocityControl;
}

implementation {

    uint32_t timer_expire_at;

    // Time is in ms.
#define MIN_TIMER_PERIOD    10

    // Distance is in cm.
#define EUCLIDEAN_DIST(x1, y1, x2, y2)  \
    ((uint32_t)sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1))))

    // Speed is in cm/s.
#define SPEED   100

    void release_request(pos_intent_t *new_intent) {
        call CommitQueue.delete((intent_hdr_t*)new_intent);
        call IntentPool.put(new_intent);
    }

    uint8_t within_bounds(area_rectangle_t *range, int32_t curr_x, int32_t curr_y) {
        return !( (curr_x < range->x1) ||
                  (curr_x > range->x2) ||
                  (curr_y < range->y1) ||
                  (curr_y > range->y2) );
    }

    uint32_t get_time_from_current(int32_t curr_x, int32_t curr_y,
            area_rectangle_t *range) {
        int32_t d_x = (range->x1 + range->x2) / 2;
        int32_t d_y = (range->y1 + range->y2) / 2;
        uint32_t dist = EUCLIDEAN_DIST(curr_x, curr_y, d_x, d_y);
        return ((dist*1000)/SPEED); // time in ms
    }

    uint32_t get_time_from_model(area_rectangle_t *srange,
            area_rectangle_t *drange) {
        int32_t s_x = (srange->x1 + srange->x2) / 2;
        int32_t s_y = (srange->y1 + srange->y2) / 2;
        int32_t d_x = (drange->x1 + drange->x2) / 2;
        int32_t d_y = (drange->y1 + drange->y2) / 2;
        uint32_t dist = EUCLIDEAN_DIST(s_x, s_y, d_x, d_y);
        return ((dist*1000)/SPEED); // time in ms
    }

    uint8_t overlap_1d(int32_t a_x1, int32_t a_x2, int32_t b_x1, int32_t b_x2)
    {
        if ( (a_x2<=b_x1) || (b_x2<=a_x1) ) return 0;   // No overlap
        if ( (a_x1<=b_x1) && (a_x2>=b_x2) ) return 1;   // a contains b
        if ( (b_x1<=a_x1) && (b_x2>=a_x2) ) return 2;   // b contains a
        return 3;
    }

    uint8_t get_overlap_1d(int32_t *a_x1, int32_t *a_x2, 
                           int32_t *b_x1, int32_t *b_x2)
    {
        // At the end of this function, [a_x1, a_x2] will contain the
        // overlapping segment.
        uint8_t olap = overlap_1d(*a_x1, *a_x2, *b_x1, *b_x2);
        
        switch (olap) {
            case 1:
            {
                // a contains b
                *a_x1 = *b_x1;
                *a_x2 = *b_x2;
                break;
            }
            case 2:
            {
                // b contains a
                // Nothing to be done.
                break;
            }
            case 3:
            {
                // Partial overlap
                if ( *a_x1>*b_x1 ) {
                    *a_x2 = *b_x2;
                } else {
                    *a_x1 = *b_x1;
                }
                break;
            }
            default: break;
        }
        
        return olap;
    }

    uint8_t compatible_intents(pos_intent_t *intent1, pos_intent_t *intent2) {
        uint8_t x_overlap = get_overlap_1d((int32_t*)&intent1->range.x1,
                                           (int32_t*)&intent1->range.x2,
                                           (int32_t*)&intent2->range.x1,
                                           (int32_t*)&intent2->range.x2);
        uint8_t y_overlap = get_overlap_1d((int32_t*)&intent1->range.y1,
                                           (int32_t*)&intent1->range.y2,
                                           (int32_t*)&intent2->range.y1,
                                           (int32_t*)&intent2->range.y2);
        if ( (x_overlap==0) || (y_overlap==0) ) {
            // No overlap
            return 0;
        }
        if ( (x_overlap==1) && (y_overlap==1) ) {
            // Complete overlap
            // intent2: stricter
            return 1;
        }
        if ( (x_overlap==2) && (y_overlap==2) ) {
            // Complete overlap
            // intent1: stricter
            return 2;
        }
        // Partial overlap
        return 3;
    }

    uint8_t compatible_post_op(pos_intent_t *new_intent, uint32_t start_time, pos_intent_t *nqueue) 
    {
        pos_intent_t *iter;
        
        for ( iter=nqueue; iter!=NULL; 
                iter=(pos_intent_t*)call CommitQueue.getNext((intent_hdr_t*)iter) ) {
            if ( (start_time+new_intent->info.t_use) >
                    iter->info.t_deadline ) {
                // Overlapping actuator usage.
                // Check actuator usage types.
                if ( (new_intent->info.use_type==ACTUATOR_EXCLUSIVE) ||
                     (iter->info.use_type==ACTUATOR_EXCLUSIVE) ) {
                    // At least one request indicates that app does not want to share
                    // actuator during use_time. Conflict!
                    return 0;
                }
                // Both requests can share actuator. Check compatibility.
                // Modify new_intent with overlapping intent range if overlap
                // exists.
                if ( compatible_intents(new_intent, iter) == 0 ) {
                    return 0;
                } 
            } else {
                // Non-overlapping actuator usage.
                // Check temporal compatibility.
                uint32_t delta_t = get_time_from_model(&new_intent->range,
                                                       &iter->range);
                if ( (start_time+new_intent->info.t_use+delta_t) >
                        iter->info.t_deadline ) {
                    // Conflicting usage.
                    return 0;
                }
                // No need to check with any more requests. Break out of
                // this loop.
                break;
            }
        }
        
        // All checks were fine. New request can be accommodated.
        return 1;
    }

    uint8_t compatible_pre_op(pos_intent_t *new_intent, pos_intent_t *pqueue) 
    {
        // Check if there is an overlapping request with new_intent.
        pos_intent_t *iter = (pos_intent_t*)call CommitQueue.getHead();
        uint8_t complete = 0;
        for ( ; iter!=new_intent;
            iter=(pos_intent_t*)call CommitQueue.getNext((intent_hdr_t*)iter) ) {
            if ((iter->info.t_deadline+iter->info.t_use)>new_intent->info.t_deadline)
            {
                complete = 1;
                // Overlapping actuator usage.
                // Check actuator usage types.
                if ( (new_intent->info.use_type==ACTUATOR_EXCLUSIVE) ||
                     (iter->info.use_type==ACTUATOR_EXCLUSIVE) ) {
                    // At least one request indicates that app does not want to share
                    // actuator during use_time. Conflict!
                    return 0;
                }
                // Both requests can share actuator. Check compatibility.
                // Modify new_intent with overlapping intent range if overlap
                // exists.
                if ( compatible_intents(new_intent, iter) == 0 ) {
                    // Incompatible intents
                    return 0;
                } 
            }
        }
        if ( !complete ) {
            // There was no overlapping usage with new request.
            uint32_t delta_t = get_time_from_model(&pqueue->range,
                                                   &new_intent->range);
            if ( (pqueue->info.t_deadline+pqueue->info.t_use+delta_t) >
                    new_intent->info.t_deadline ) {
                // Conflicting usage.
                return 0;
            }
        }
        return 1;
    }

    uint8_t compatible_current_state(pos_intent_t *new_intent, 
                                     uint32_t local_time, uint32_t *delta_t1) {
        // Get current physical context.
        int32_t curr_x = call Location2d.getX();
        int32_t curr_y = call Location2d.getY();
        if ( within_bounds(&new_intent->range, curr_x, curr_y) ) {
            // Intent of master has been achieved. Request denied.
            release_request(new_intent);
            return 0;
        }
        // Check if new intent can be accomodated between current state
        // and master intent.
        *delta_t1 = get_time_from_current(curr_x, curr_y,
                &new_intent->range);
        if ( (local_time+*delta_t1)>new_intent->info.t_deadline ) {
            // Request can not be accommodated.
            release_request(new_intent);
            return 0;
        }
        return 1;
    }

    uint32_t get_new_expiry() {
        uint32_t timer_at = 0;
        pos_intent_t *iter = (pos_intent_t*)call CommitQueue.getHead();
        for ( ; iter!=NULL && iter->info.rq_status==ACTUATOR_CTRLLER;
            iter=(pos_intent_t*)call CommitQueue.getNext((intent_hdr_t*)iter) ) {
            uint32_t iter_timer_at = iter->info.t_deadline+iter->info.t_use;
            if ( iter_timer_at>timer_at) {
                timer_at = iter_timer_at;
            }
        }
        return timer_at;
    }

    void grant_control(pos_intent_t *start) {
        pos_intent_t *iter = start;
        // Signal control to app with intent as 'iter'
        signal ActuatorControl.controlGranted((intent_hdr_t*)iter);
        for (; iter!=NULL && iter->info.rq_status==ACTUATOR_CTRLLER;
            iter=(pos_intent_t*)call CommitQueue.getNext((intent_hdr_t*)iter)
            ) {
            pos_intent_t *iter2 = (pos_intent_t*)call
                CommitQueue.getNext((intent_hdr_t*)iter);
            for (; iter2!=NULL; iter2=(pos_intent_t*)call
                    CommitQueue.getNext((intent_hdr_t*)iter2) ) {
                if ( (iter->info.t_deadline+iter->info.t_use) > 
                        iter2->info.t_deadline ) {
                    // Overlapping actuator usage with 'iter2'
                    if ( iter2->info.rq_status != ACTUATOR_CTRLLER ) {
                        // iter2 was marked as CTRLLER in this iteration only.
                        // Signal control to app with intent as 'iter2'
                        iter2->info.rq_status = ACTUATOR_CTRLLER;
                        signal ActuatorControl.controlGranted((intent_hdr_t*)iter2);
                    }
                }
            }
        }
    }

    void do_timer_task() {
        uint32_t local_time;
        // Clear all CTRLLERs from commit queue.
        pos_intent_t *iter = (pos_intent_t*)call CommitQueue.getHead();
        while ( iter!=NULL && iter->info.rq_status==ACTUATOR_CTRLLER ) {
            pos_intent_t *del = iter;
            iter = (pos_intent_t*)call
                CommitQueue.getNext((intent_hdr_t*)iter);
            call CommitQueue.delete((intent_hdr_t*)del);
            call IntentPool.put(del);
        }
        // Signal next set of CTRLLERs.
        // Start with head of queue.
        iter = (pos_intent_t*)call CommitQueue.getHead();
        if ( iter==NULL ) {
            // No more requests in the queue.
            timer_expire_at = 0;
            return;
        }
        iter->info.rq_status = ACTUATOR_CTRLLER;
        // Grant control to other apps with overlapping actuator usage.
        grant_control(iter);
        
        timer_expire_at = get_new_expiry();
        local_time = call LocalTimer.getNow();
        call LocalTimer.startOneShot(timer_expire_at-local_time);
    }

    /********* Tasks **************/

    task void timer_task() {
        do_timer_task();
    }

    /****** Public Functions ******/

    command error_t Init.init() {
        timer_expire_at = 0;
        return SUCCESS;
    }

    command error_t ActuatorControl.setIntent(intent_hdr_t *req) {
        pos_intent_t *prev_head, *next_head;
        uint32_t local_time = call LocalTimer.getNow();

        // Allocate space to store the new intent.
        pos_intent_t *new_intent = call IntentPool.get();
        if ( new_intent==NULL ) return FAIL;
        
        // Setup the new intent
        memcpy(new_intent, req, sizeof(pos_intent_t));
        // Convert deadline into absolute local time
        new_intent->info.t_deadline += local_time;
        new_intent->info.rq_status = 0;
        new_intent->info.len = sizeof(intent_hdr_t);

        // Insert the new request into the commit queue
        if ( call CommitQueue.insert((intent_hdr_t*)new_intent) != SUCCESS) {
            // No space in commit queue
            call IntentPool.put(new_intent);
            return FAIL;
        }

        // Get the next and previous elements of the newly inserted element
        prev_head = (pos_intent_t*)call
                    CommitQueue.getPrevious((intent_hdr_t*)new_intent);
        next_head = (pos_intent_t*)call
                    CommitQueue.getNext((intent_hdr_t*)new_intent);

        // Check if the CommitQueue is empty
        if ( (next_head==NULL) && (prev_head==NULL) ) {
            goto signal_success;
        }

        // Check where was the new element inserted.
        if ( prev_head==NULL ) {
            // New element was inserted at head of queue.
            uint32_t delta_t1;
            // Check if it is compatible with current state,
            // and post-op with all queue elements.
            if ( !compatible_current_state(new_intent, local_time, &delta_t1) ||
                 !compatible_post_op(new_intent, local_time+delta_t1, next_head) ) {
                // Request can not be accommodated.
                release_request(new_intent);
                return FAIL;
            } 
        } else if ( next_head==NULL ) {
            // New element was inserted at tail of queue.
            // Check if it is compatible pre-op with all queue elements.
            if ( !compatible_pre_op(new_intent, prev_head) ) {
                // Request can not be accommodated.
                release_request(new_intent);
                return FAIL;
            }
        } else {
            // New element was inserted in the middle of queue.
            // Check if it is compatible pre-op with all queue elements whose
            // deadlines are before its deadline, and post-op with those whose
            // deadlines are after its deadline.
            if ( !compatible_pre_op(new_intent, prev_head) ||
                 !compatible_post_op(new_intent, new_intent->info.t_deadline, next_head) ) {
                // Request can not be accommodated.
                release_request(new_intent);
                return FAIL;
            }
        }

signal_success:
        // Post a task to signal setDone to the app.
        if ( (prev_head==NULL) ||
             (new_intent->info.t_deadline<timer_expire_at) ) {
            // App with new_intent gets control immediately.
            uint32_t timer_at;
            new_intent->info.rq_status = ACTUATOR_CTRLLER;
            // Grant control to the app
            grant_control(new_intent);
            // Get new time at which to transfer control to next set of
            // applications.
            timer_at = get_new_expiry();
            // Invariant: timer_at >= timer_expire_at
            if ( timer_at > timer_expire_at ) {
                // The previous expiry period has been modified
                if ( call LocalTimer.isRunning() ) {
                    // Stop the timer
                    call LocalTimer.stop();
                }
                // (Re)start the timer according to new period.
                local_time = call LocalTimer.getNow();
                call LocalTimer.startOneShot(timer_at-local_time);
                // (Re)set expiry time
                timer_expire_at = timer_at;
            }
        }
        return SUCCESS;
    }

    command void ActuatorControl.clearIntent(intent_hdr_t *req) {
        pos_intent_t *iter = (pos_intent_t*)call CommitQueue.getHead();
        for ( ; iter!=NULL;
            iter=(pos_intent_t*)call CommitQueue.getNext((intent_hdr_t*)iter) )
        {
            if ( req->app_id==iter->info.app_id &&
                    req->seq==iter->info.seq ) {
                // Found the request that needs to be deleted.
                uint8_t status = iter->info.rq_status;
                dbg("PathPlanner", "Found element to delete.\n");
                call CommitQueue.delete((intent_hdr_t*)iter);
                call IntentPool.put(iter);
                dbg("PathPlanner", "Deleted.\n");
                if ( status==ACTUATOR_CTRLLER ) {
                    // The request was in control.
                    // Get new timer expiry
                    uint32_t timer_at = get_new_expiry();
                    uint32_t local_time = call LocalTimer.getNow();
                    dbg("PathPlanner", "New expiry time is %u. Old was %u.\n",
                            timer_at, timer_expire_at);
                    if ( timer_at<=(local_time+MIN_TIMER_PERIOD) ) {
                        // Timer should expire now as its past the new
                        // expiry time.
                        // Force stop the timer.
                        if ( call LocalTimer.isRunning() ) {
                            call LocalTimer.stop();
                        }
                        // Execute timer expiry routine.
                        do_timer_task();
                    } else if ( timer_at<timer_expire_at ) {
                        // Timer should expire at an earlier time.
                        // Force stop the timer.
                        if ( call LocalTimer.isRunning() ) {
                            call LocalTimer.stop();
                        }
                        // Restart it.
                        call LocalTimer.startOneShot(timer_at-local_time);
                        timer_expire_at = timer_at;
                    }
                }
            }
        }
    }

    command uint8_t ActuatorControl.setControl(intent_hdr_t *req) {
        vel_control_t *vel_ctrl = (vel_control_t*)req;
        pos_intent_t *head = (pos_intent_t*)call CommitQueue.getHead();
        pos_intent_t *iter;
        // Find this actuator intent in the commit queue
        for ( iter=head; iter!=NULL;
            iter=(pos_intent_t*)call CommitQueue.getNext((intent_hdr_t*)iter) )
        {
            if ( req->app_id==iter->info.app_id &&
                    req->seq==iter->info.seq ) {
                break;
            }
        }
        if ( iter==NULL ) return CTRL_UNKNOWN;
        if ( iter->info.rq_status!=ACTUATOR_CTRLLER ) {
            // This intent is not yet in control.
            return CTRL_NOT_AUTH;
        }
        if ( iter==head ) {
            // This is the master controller.
            call VelocityControl.set(iter, vel_ctrl->v.linear, vel_ctrl->v.angular);
            return CTRL_OK;
        }
        // This intent will be satisfied before its deadline without further
        // application intervention. So, the app should wait.
        return CTRL_WAIT;
    }

    event void VelocityControl.setDone(pos_intent_t *req, uint8_t status) {
        signal ActuatorControl.setControlDone((intent_hdr_t*)req, status);
    }

    event void LocalTimer.fired() {
        post timer_task();
    }

}

