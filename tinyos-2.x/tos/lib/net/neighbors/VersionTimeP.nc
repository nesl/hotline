
module VersionTimeP {
    provides interface Version;
    uses interface Timer<TMilli>;
}
implementation {
    command uint32_t Version.getNew(uint32_t current) {
        uint32_t now = call Timer.getNow();
        if ( now <= current ) {
            now = current + 1;
        }
        return now;
    }

    command bool Version.changed(uint32_t current, uint32_t newv) {
        return (current < newv);
    }

    event void Timer.fired() {}
}

