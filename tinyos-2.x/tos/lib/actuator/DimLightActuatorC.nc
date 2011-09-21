
#include "Actuation.h"
#include "DimLight.h"

configuration DimLightActuatorC {
    provides interface RawActControl<dim_config_t> as LightControl;
    provides interface PhysicalConfig<pose2d_t> as Config2d;
}
implementation {
    components MainC, Location2dC, Vector2dC;
    components DimLightActuatorP as ActuatorP;
    components new TimerMilliC() as DummyTimerC;

    LightControl = ActuatorP.LightDimControl;
    Config2d = ActuatorP.Config2d;

    MainC.SoftwareInit -> ActuatorP;

    ActuatorP.BaseConfig2d -> Location2dC;
    ActuatorP.Vector2d -> Vector2dC;
    ActuatorP.DummyActTimer -> DummyTimerC;
}
