
interface Sync {
    command void init();
    command void sync();
    command void cancel();
    event void synced();
}

