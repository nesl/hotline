
#include "coord2d.h"

configuration Pose2dC {
    provides interface PhysicalConfig<pose2d_t> as Pose2d;
}

implementation {
    components Pose2dP, MainC;

    Pose2d = Pose2dP;
    MainC.SoftwareInit -> Pose2dP;
}
