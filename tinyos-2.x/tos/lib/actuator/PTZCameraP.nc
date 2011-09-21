
#include "Camera.h"

module PTZCameraP {
    provides interface RawActControl<ptz_config_t> as PTZControl;
    provides interface PhysicalConfig<pose2d_t> as Config2d;
    provides interface Init;

    uses interface PhysicalConfig<pose2d_t> as BaseConfig2d;
    uses interface Zone;
    uses interface StdControl as NeighborDiscovery;
    uses interface Vector<pose2d_t> as Vector2d;
    uses interface Timer<TMilli> as DummyActTimer;
    uses interface Timer<TMilli> as DiscoveryTimer;
}

implementation {
    ptz_config_t ptz;
    ptz_config_t *ptz_saved;
    uint16_t pan_speed;
    pose2d_t relative_pose;
    pose2d_t global_pose;
    bool enabled, discovery_on;

    /************ Private functions *************/
    uint32_t getTimeToZoom(uint16_t target, uint16_t from) {
        uint32_t zoom_time = 0;
        return zoom_time;
    }

    uint32_t getTimeToActuate(ptz_config_t* target,
                              ptz_config_t* from) {
        // Maximum time in msec it will take to actuate from 
        // config 'from' to 'target'.
        return 0;
    }

    pose2d_t* get_global_pose() {
        pose2d_t *base_pose = call BaseConfig2d.getGlobalPose();
        call Vector2d.add(base_pose, &relative_pose, &global_pose);
        return &global_pose;
    }

    void recalculate_zone() {
        // Camera pose changed.
        pose2d_t *gpose = get_global_pose();
        zone_circle_t z;
        memcpy(&z.center, &gpose->loc, sizeof(pose2d_t));
        z.radius = RANGE_MAX;
        call Zone.set((uint8_t*)&z);
    }

    /******************* Tasks *****************/

    task void signal_setDone() {
        signal PTZControl.setDone(ptz_saved);
    }

    task void signal_enabled() {
        signal PTZControl.enabled();
    }

    /************ Public functions *************/

    command error_t Init.init() {
        // Default configuration:
        // PTZ Camera on a static base, front facing,
        // aligned with its central axis.
        ptz.pan = ptz.tilt = ptz.zoom = 0;
        relative_pose.loc.x = relative_pose.loc.y = 0;
        relative_pose.a = 0;
        pan_speed = ANGULAR_SPEED_PAN;
        enabled = FALSE;
        discovery_on = FALSE;
        return SUCCESS;
    }

    command pose2d_t* Config2d.getGlobalPose() {
        return get_global_pose();
    }

    command error_t Config2d.setRelativePose(pose2d_t *value) {
        relative_pose.loc.x = value->loc.x;
        relative_pose.loc.y = value->loc.y;
        relative_pose.a = value->a;
        recalculate_zone();
        return SUCCESS;
    }

    command error_t PTZControl.enable(void *config) {
        if ( !enabled ) {
            uint32_t disc_time = 0;
            if ( config != NULL ) {
                disc_time = *((uint32_t*)config);
            }
            enabled = TRUE;
            call NeighborDiscovery.start();
            discovery_on = TRUE;
            recalculate_zone();
            if ( disc_time > 0 ) {
                call DiscoveryTimer.startOneShot(disc_time);
            } else {
                post signal_enabled();
            }
        }
        return SUCCESS;
    }
    
    command error_t PTZControl.disable() {
        if ( enabled ) {
            enabled = FALSE;
            if ( discovery_on ) {
                call NeighborDiscovery.stop();
                discovery_on = FALSE;
            }
        }
        return SUCCESS;
    }
    
    command error_t PTZControl.set(ptz_config_t* params) {
        uint32_t act_time = getTimeToActuate(params, &ptz);
        ptz_saved = params;
        if (act_time > 0) {
            call DummyActTimer.startOneShot(act_time);
            return SUCCESS;
        }
        // Change PTZ immediately
        ptz.pan = params->pan;
        ptz.tilt = params->tilt;
        ptz.zoom = params->zoom;
        post signal_setDone();
        return SUCCESS;
    }

    command ptz_config_t* PTZControl.get() {
        return &ptz;
    }

    command uint32_t PTZControl.getDelay(ptz_config_t* target,
                                         ptz_config_t* from) {
        // Maximum time it will take to actuate from config 'from' to
        // 'target'.
        return getTimeToActuate(target, from);
    }

    event void BaseConfig2d.changed() {
        // Location/orientation of the camera base changed.
        recalculate_zone();
        // Signal change to higher layers.
        signal Config2d.changed();
    }

    event void DiscoveryTimer.fired() {
        if ( discovery_on ) {
            //call NeighborDiscovery.stop();
            //discovery_on = FALSE;
            signal PTZControl.enabled();
        }
    }

    event void DummyActTimer.fired() {
        ptz.pan = ptz_saved->pan;
        ptz.tilt = ptz_saved->tilt;
        ptz.zoom = ptz_saved->zoom;
        signal PTZControl.setDone(ptz_saved);
    }

    event bool Zone.changed(dip_key_t key) { return TRUE; }

}
