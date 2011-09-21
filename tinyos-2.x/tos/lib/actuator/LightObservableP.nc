
#include "Actuation.h"
#include "DimLight.h"
#include "zone2d.h"

module LightObservableP {
    provides interface ObservableAccess<uint16_t> as Observable;
    provides interface ObservableTransaction<zone2d_t> as Transaction;
    provides interface Init;

    uses interface RawActControl<dim_config_t> as LightDimControl;
    uses interface PhysicalConfig<pose2d_t> as ActuatorConfig2d;
    uses interface Zone<zone2d_t> as Zone2d;
    uses interface ActNeighbor;
}

implementation {
    uint16_t intensity, intensity_saved;
    uint16_t reqMin, reqMax;
    dim_config_t light_control;
    zone2d_t curr_range, zone;
    pose2d_t curr_pose;

    command error_t Init.init() {
        intensity = intensity_saved = 0;
        curr_pose.x = curr_pose.y = 0.0;
        curr_pose.a = 0;
        curr_range.x = curr_range.y = curr_range.radius = 0.0;
        zone.x = zone.y = zone.radius = 0.0;
        reqMin = reqMax = 0;
        return SUCCESS;
    }

    command error_t Observable.enable() {
        // get current pose of the actuator hardware
        curr_pose = call ActuatorConfig2d.getGlobalPose();
        // get raw actuator parameters
        light_control = call LightDimControl.getControlParams();
        
        // calculate current range radius from model
        // circular range is centred at location
        curr_range.x = curr_pose.x;
        curr_range.y = curr_pose.y;
        curr_range.radius = light_control.dimlevel/2;
        
        // calculate zone radius from model
        zone.x = curr_pose.x;
        zone.y = curr_pose.y;
        zone.radius = MAX_DIM_LEVEL/2.0;
        
        // calculate intensity from model
        intensity = light_control.dimlevel * LIGHT_CONSTANT;
        intensity_saved = intensity;

        // set the zone of this light
        call Zone2d.setZone(zone);
        // start discovering neighbors
        return call ActNeighbor.startDiscovery();
    }

    command uint16_t Observable.read() {
        return intensity;
    }

    command error_t Observable.write(uint16_t val) {
        intensity = val;
        return SUCCESS;
    }

    command uint32_t Observable.getTimeToActuate(uint16_t* target,
                                                 uint16_t* from) {
        dim_config_t dest, frm;
        dest.dimlevel = *target / LIGHT_CONSTANT;
        frm.dimlevel = *from / LIGHT_CONSTANT;
        return call LightDimControl.getTimeToActuate(&dest, &frm);
    }

    command error_t Observable.disable() {
        // stop discovering neighbors
        return call ActNeighbor.stopDiscovery();
    }

    task void doSignalActivate() {
        signal Transaction.activateDone(SET_RANGE, reqMin, reqMax);
    }

    command error_t Transaction.activate(zone2d_t area, 
                                         uint16_t min, 
                                         uint16_t max) {
        // Check if the area overlaps with the zone
        if (call Zone2d.intersects(area)) {
            // TODO: Check if the range is allowed by Cahoot
            reqMin = min;
            reqMax = max;
            post doSignalActivate();
            return SUCCESS;
        }
        return FAIL;
    }

    command error_t Transaction.beginTransaction() {
        // Save state of observable
        intensity_saved = intensity;
        return SUCCESS;
    }

    command error_t Transaction.endTransaction(int8_t cmd) {
        switch (cmd) {
            case COMMIT: {
                // Calculate the raw actuator parameters corresponding to new
                // intensity value.
                light_control.dimlevel = intensity / LIGHT_CONSTANT;
                return call LightDimControl.setControlParams(&light_control);
            }
            case REVERT: {
                intensity = intensity_saved;
                break;
            }
            default: break;
        }

        return SUCCESS;
    }

    event void LightDimControl.setControlDone(dim_config_t* values) {
        signal Transaction.transactionDone(SUCCESS);
    }

}

