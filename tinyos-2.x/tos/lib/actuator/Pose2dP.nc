
#include "coord2d.h"
#include "gen_pose.h"

module Pose2dP {
    provides interface PhysicalConfig<pose2d_t> as Pose2d;
    provides interface Init;
}

implementation {
    pose2d_t pose;

    command pose2d_t* Pose2d.getGlobalPose() {
        get_pose(TOS_NODE_ID, &pose);
        return &pose;
    }
    
    command error_t Pose2d.setRelativePose(pose2d_t* value) {
        return SUCCESS;
    }

    command error_t Init.init() {
        pose.loc.x = pose.loc.y = 0;
        pose.a = 0;
        return SUCCESS;
    }

}
