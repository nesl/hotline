#ifndef __OBSERVABLE_H__
#define __OBSERVABLE_H__

// Actuator IDs
enum {
    ACTUATOR_PATH_PLANNER   = 0,
    ACTUATOR_PAN_TILT       = 1,
};

// Actuator request status
enum {
    ACTUATOR_CTRLLER    = 1,
};

// Type of actuator usage requested
enum {
    ACTUATOR_SHARE      = 0,
    ACTUATOR_EXCLUSIVE  = 1,
};

// Return code for setControl request
enum {
    CTRL_OK         = 0,
    CTRL_WAIT       = 1,
    CTRL_NOT_AUTH   = 2,
    CTRL_UNKNOWN    = 3,
    CTRL_ERR        = 255,
};

typedef nx_struct intent_hdr_t {
    nx_uint8_t act_id;      // Actuator ID
    nx_uint8_t app_id;      // Application that wants to use the actuator
    nx_uint16_t seq;        // Application assigned sequence number
    nx_uint16_t node_id;    // Specific node which has the desired actuator
    nx_uint32_t t_deadline; // Deadline by which actuator goal should be achieved.
    nx_uint32_t t_use;      /* Time for which the app needs to use the
                             * actuator after goal is acheived.
                             */
    nx_uint8_t use_type;    // Actuator dependent or independent use
    nx_uint8_t rq_status;   // Current status of the request
    nx_uint16_t len;        /* Length of the complete intent packet including
                             * range of intent values that is specific to the
                             * actuator.
                             */
} intent_hdr_t;

enum {
    OK          = 0,
    SET_RANGE   = 1,
    CONFLICT    = 2,
};

enum {
    COMMIT  = 0,
    REVERT  = 1,
};


#endif

