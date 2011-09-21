
#include "ValveControl.h"

module ValveControlP {
    provides interface RawActControl<valve_config_t> as ValveControl;
    provides interface PhysicalConfig<pose2d_t> as Config2d;
    provides interface Init;

    uses interface PhysicalConfig<pose2d_t> as BaseConfig2d;
    uses interface Zone;
    uses interface StdControl as NeighborDiscovery;
    uses interface Timer<TMilli> as DummyActTimer;
    uses interface Timer<TMilli> as DiscoveryTimer;
}

implementation {
    valve_config_t valve;
    valve_config_t *valve_saved;
    bool enabled, discovery_on;

    /************ Private functions *************/
    uint32_t getTimeToActuate(valve_config_t* target,
                              valve_config_t* from) {
        // Maximum time in msec it will take to actuate from 
        // config 'from' to 'target'.
        return 0;
    }

    pose2d_t* get_global_pose() {
        return call BaseConfig2d.getGlobalPose();
    }

    void recalculate_zone() {
        zone1d_t z;
        z.min = 0;
        z.max = 100;
        call Zone.set((uint8_t*)&z);
    }

    /******************* Tasks *****************/

    task void signal_setDone() {
        signal ValveControl.setDone(valve_saved);
    }

    task void signal_enabled() {
        signal ValveControl.enabled();
    }

    /************ Public functions *************/

    command error_t Init.init() {
        // Default configuration: Closed valve
        valve.openlevel = 0;
        enabled = FALSE;
        discovery_on = FALSE;
        return SUCCESS;
    }

    command pose2d_t* Config2d.getGlobalPose() {
        return get_global_pose();
    }

    command error_t Config2d.setRelativePose(pose2d_t *value) {
        return SUCCESS;
    }

    command error_t ValveControl.enable(void *config) {
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
    
    command error_t ValveControl.disable() {
        if ( enabled ) {
            enabled = FALSE;
            if ( discovery_on ) {
                call NeighborDiscovery.stop();
                discovery_on = FALSE;
            }
        }
        return SUCCESS;
    }
    
    command error_t ValveControl.set(valve_config_t* params) {
        uint32_t act_time = getTimeToActuate(params, &valve);
        valve_saved = params;
        if (act_time > 0) {
            call DummyActTimer.startOneShot(act_time);
            return SUCCESS;
        }
        // Change PTZ immediately
        valve.openlevel = params->openlevel;
        post signal_setDone();
        return SUCCESS;
    }

    command valve_config_t* ValveControl.get() {
        return &valve;
    }

    command uint32_t ValveControl.getDelay(valve_config_t* target,
                                           valve_config_t* from) {
        // Maximum time it will take to actuate from config 'from' to
        // 'target'.
        return getTimeToActuate(target, from);
    }

    event void BaseConfig2d.changed() {
        // Signal change to higher layers.
        signal Config2d.changed();
    }

    event void DiscoveryTimer.fired() {
        if ( discovery_on ) {
            signal ValveControl.enabled();
        }
    }

    event void DummyActTimer.fired() {
        valve.openlevel = valve_saved->openlevel;
        signal ValveControl.setDone(valve_saved);
    }

    event void Zone.changed( am_addr_t node ) { }

}
