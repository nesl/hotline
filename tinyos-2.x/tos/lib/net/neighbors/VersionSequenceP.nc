
module VersionSequenceP {
    provides interface Version;
}
implementation {
    command uint32_t Version.getNew(uint32_t current) {
        return current+1;
    }

    command bool Version.changed(uint32_t current, uint32_t newv) {
        return (current < newv);
    }

}

