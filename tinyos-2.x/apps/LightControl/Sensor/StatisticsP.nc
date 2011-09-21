
generic module StatisticsP(float ALPHA) {
    provides interface Stats;

    uses interface Queue<uint16_t> as Window;
}
implementation {

    uint32_t win_sum;
    float old_ewma, new_ewma;

    void window_add(uint16_t n_elt) {
        if ( call Window.size() == call Window.maxSize() ) {
            // Window is full. Discard oldest estimate.
            uint16_t e = call Window.dequeue();
            win_sum -= e;
        }
        // Add the new estimate to the window after PSI consensus negotiations
        call Window.enqueue(n_elt);
        win_sum += n_elt;
        // Save current EWMA
        old_ewma = new_ewma;
        new_ewma = (1.0-ALPHA)*old_ewma + ALPHA*(float)n_elt;
    }

    command void Stats.init() {
        win_sum = 0;
        old_ewma = 0.0;
        new_ewma = 0.0;
    }

    command void Stats.add(uint16_t n_elt) {
        window_add(n_elt);
    }

    command uint16_t Stats.getMean() {
        if ( call Window.size() > 0 ) {
            uint32_t avg = win_sum / call Window.size();
            return (uint16_t)avg;
        }
        return 0;
    }

    command bool Stats.varianceHigh(uint32_t threshold) {
        int32_t avg = 0;
        uint32_t vsum = 0;
        uint8_t i;
        uint32_t var;
        if ( call Window.size() < call Window.maxSize() ) {
            // Wait for the window to get full.
            return TRUE;
        }
        avg = win_sum / call Window.size();
        for ( i=0; i<call Window.size(); i++ ) {
            int32_t x = (int32_t)call Window.element(i);
            vsum += ((x-avg)*(x-avg));
        }
        var = vsum / call Window.size();
        dbg("StatsPEval", "##_%s_sensor variance_%lu_%lu\n",
                sim_time_string(), var, threshold);
        if ( var >= threshold ) return TRUE;
        return FALSE;
    }

    command bool Stats.ewmaChanged(uint32_t threshold) {
        uint32_t diff = (uint32_t)fabs(old_ewma-new_ewma);
        if ( diff > threshold ) return TRUE;
        return FALSE;
    }

}

