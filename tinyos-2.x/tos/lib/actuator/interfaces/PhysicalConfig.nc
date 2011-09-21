
interface PhysicalConfig<t> {
    command t* getGlobalPose();
    command error_t setRelativePose(t* value);
    event void changed();
}
