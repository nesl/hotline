#include "Observable.h"

module HotlineP {
    provides interface ActuatorControl as Actuator[uint8_t app_id];

    uses interface ActuatorControl as VelocityController;
    //uses interface ActuatorManger[uint8_t act_id];
    // uses Routing Send and Receive interface to send actuator requests to the
    // Hotline components on other nodes.
}

implementation {

    /*******Public functions**********/

    command error_t Actuator.setIntent[uint8_t app_id](intent_hdr_t *req) {
        if (req == NULL) return FAIL;
        // Set the correct application id in the intent request.
        req->app_id = app_id;
        // Check if the request is for the actuator on this node.
        if (req->node_id == TOS_NODE_ID) {
            // Request is for a local actuator.
            switch (req->act_id) {
                case ACTUATOR_PATH_PLANNER:
                {
                    return call VelocityController.setIntent(req);
                }
                default: return FAIL;
            }
        } else {
            // Request is for a remote actuator.
            //return call RoutingSend.send(req->node_id, ... );
            return FAIL;
        }

        return SUCCESS;
    }

    command void Actuator.clearIntent[uint8_t app_id](intent_hdr_t *req) {
        if (req == NULL) return;
        // Set the correct application id in the intent request.
        req->app_id = app_id;
        // Check if the request is for the actuator on this node.
        if (req->node_id == TOS_NODE_ID) {
            // Request is for a local actuator.
            switch (req->act_id) {
                case ACTUATOR_PATH_PLANNER:
                {
                    call VelocityController.clearIntent(req);
                    break;
                }
                default: break;
            }
        } else {
            // Request is for a remote actuator.
            //return call RoutingSend.send(req->node_id, ... );
            return;
        }
    }

    event void VelocityController.controlGranted(intent_hdr_t *req) {
        signal Actuator.controlGranted[req->app_id](req);
    }

    command uint8_t Actuator.setControl[uint8_t app_id](
            intent_hdr_t *req) {
        if (req == NULL) return FAIL;
        // Set the correct application id in the intent request.
        req->app_id = app_id;
        // Check if the request is for the actuator on this node.
        if (req->node_id == TOS_NODE_ID) {
            // Request is for a local actuator.
            switch (req->act_id) {
                case ACTUATOR_PATH_PLANNER:
                {
                    return call VelocityController.setControl(req);
                }
                default: return FAIL;
            }
        } else {
            // Request is for a remote actuator.
            //return call RoutingSend.send(req->node_id, ... );
            return CTRL_ERR;
        }

        return CTRL_ERR;
    }

    event void VelocityController.setControlDone(
            intent_hdr_t *req, uint8_t status) {
        signal Actuator.setControlDone[req->app_id](req, status);
    }

    /******* default events ********/

    default event void Actuator.controlGranted[uint8_t app_id](intent_hdr_t *req) {
    }

    default event void Actuator.setControlDone[uint8_t app_id](
            intent_hdr_t *req, uint8_t status) {
    }

}

