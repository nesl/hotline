
#include "Actuation.h"
#include "DimLight.h"

module DimLightActuatorP {
    provides interface RawActControl<dim_config_t> as LightDimControl;
    provides interface PhysicalConfig<pose2d_t> as Config2d;
    provides interface Init;

    uses interface PhysicalConfig<pose2d_t> as BaseConfig2d;
    uses interface Vector<pose2d_t> as Vector2d;
    uses interface Timer<TMilli> as DummyActTimer;
}

implementation {
    dim_config_t light_control, *light_control_saved;
    pose2d_t relative_pose;

    /************ Private functions *************/
    uint32_t getTimeToActuate(dim_config_t* target,
                              dim_config_t* from) {
        // Maximum time in msec it will take to actuate from 
        // config 'from' to 'target'.
        if (target->dimlevel == from->dimlevel) return 0; 
        // Else, return a constant value
        return 512;
    }

    task void doSignalControlDone() {
        light_control.dimlevel = light_control_saved->dimlevel;
        signal RawActControl.setControlDone(light_control_saved);
    }

    /************ Public functions *************/

    command error_t Init.init() {
        // Default configuration:
        // Dimmable light on a static base, facing directly down,
        // aligned with its central axis.
        light_control.dimlevel = MIN_DIM_LEVEL;
        relative_pose.x = relative_pose.y = 0.0;
        relative_pose.a = 0;
    }

    command pose2d_t Config2d.getGlobalPose() {
        pose2d_t base_pose = BaseConfig2d.getGlobalPose();
        return call Vector2d.transform(base_pose, relative_pose);
    }

    command error_t Config2d.setRelativePose(pose2d_t value) {
        relative_pose.x = value.x;
        relative_pose.y = value.y;
        relative_pose.a = value.a;
        return SUCCESS;
    }

    command errot_t LightDimControl.setControlParams(dim_config_t* values) {
        uint32_t act_time = getTimeToActuate(values, &light_control);
        // Save the pointer to new values
        light_control_saved = values;
        if (act_time > 0) {
            // Emulate actuation as it will take some time to do so
            call DummyActTimer.startOneShot(act_time);
        } else {
            // It won't take time to actuate (maybe new values = old)
            post doSignalControlDone();
        }
        return SUCCESS;
    }

    command dim_config_t LightDimControl.getControlParams() {
        return light_control;
    }

    command_t uint32_t LightDimControl.getTimeToActuate(
                                            dim_config_t* target,
                                            dim_config_t* from) {
        // Maximum time it will take to actuate from config 'from' to
        // 'target'.
        return getTimeToActuate(target, from);
    }

    event void DummyActTimer.fired() {
        post doSignalControlDone();
    }

}
