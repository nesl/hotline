
generic configuration StatisticsC(float ALPHA, uint8_t WIN_SIZE) {
    provides interface Stats;
}
implementation {
    components new QueueC(uint16_t, WIN_SIZE) as WindowC;
    components new StatisticsP(ALPHA);

    Stats = StatisticsP;

    StatisticsP.Window -> WindowC;
}
