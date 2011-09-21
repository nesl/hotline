
interface RawActControl<t> {
    command error_t enable(void *config);
    command error_t disable();
    command error_t set(t* params);
    command t* get();
    command uint32_t getDelay(t* target, t* from);
    event void setDone(t* params);
    event void enabled();
}
