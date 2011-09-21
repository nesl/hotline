
interface VirtualLock {
    command error_t acquireLock(uint32_t holdtime);
    command error_t releaseLock();
    command void enableRandomAccess();
    command void setPriority(uint32_t priority);
    command void setWaitPeriod(uint32_t period);
    command void setRequestPeriod(uint32_t period);
    event bool checkNbrMetric(uint32_t metric);
    event void lockGranted(int8_t err);
    event void lockRequest(uint32_t metric);
    event void lockViolation(uint32_t metric);
    event void lockConflict();
}
