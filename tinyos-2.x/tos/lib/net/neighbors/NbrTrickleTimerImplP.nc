// $Id: NbrTrickleTimerImplP.nc,v 1.5 2007/07/30 00:42:00 scipio Exp $
/*
 * "Copyright (c) 2006 Stanford University. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software and
 * its documentation for any purpose, without fee, and without written
 * agreement is hereby granted, provided that the above copyright
 * notice, the following two paragraphs and the author appear in all
 * copies of this software.
 * 
 * IN NO EVENT SHALL STANFORD UNIVERSITY BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES
 * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN
 * IF STANFORD UNIVERSITY HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 * 
 * STANFORD UNIVERSITY SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE
 * PROVIDED HEREUNDER IS ON AN "AS IS" BASIS, AND STANFORD UNIVERSITY
 * HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, UPDATES,
 * ENHANCEMENTS, OR MODIFICATIONS."
 */

/*
 * Module that provides a service instance of trickle timers. For
 * details on the working of the parameters, please refer to Levis et
 * al., "A Self-Regulating Algorithm for Code Maintenance and
 * Propagation in Wireless Sensor Networks," NSDI 2004.
 *
 * @param l Lower bound of the time period in seconds.
 * @param h Upper bound of the time period in seconds.
 *
 * @author Philip Levis
 * @author Gilman Tolle
 * @date   Jan 7 2006
 */ 

#include <Timer.h>

generic module NbrTrickleTimerImplP(uint16_t low,
        uint16_t high,
        uint8_t scale) {
    provides {
        interface Init;
        interface NbrTrickleTimer;
    }
    uses {
        interface Timer<TMilli> as PeriodTimer;
        interface Random;
        interface Leds;
    }
}
implementation {

    uint32_t period;

    command error_t Init.init() {
        period = high;
        return SUCCESS;
    }

    /**
     * Start a trickle timer. Reset the counter to 0.
     */
    command error_t NbrTrickleTimer.start() {
        uint32_t dtfire = (call Random.rand32() % (period / 2)) + (period / 2);
        call PeriodTimer.startOneShot(dtfire);
        dbg("NbrTrickleImplP",
                "Starting trickle timer @ %s\n", sim_time_string());
        return SUCCESS;
    }

    /**
     * Stop the trickle timer. This call sets the timer period to H.
     */
    command void NbrTrickleTimer.stop() {
        call PeriodTimer.stop();
        dbg("NbrTrickleImplP",
                "Stopping trickle timer @ %s\n", sim_time_string());
    }

    /**
     * Reset the timer period to L. If called while the timer is running,
     * then a new interval (of length L) begins immediately.
     */
    command void NbrTrickleTimer.reset() {
        period = low;
        call PeriodTimer.stop();
        call PeriodTimer.startOneShot(period);
        dbg("NbrTrickleImplP",
                "Resetting trickle timer @ %s\n", sim_time_string());
    }

    /**
     * The trickle timer has fired.
     */
    event void PeriodTimer.fired() {
        uint32_t dtfire;
        if ( signal NbrTrickleTimer.fired() ) {
            period *= scale;
            if ( period > high ) period = high;
        }
        dtfire = (call Random.rand32() % (period / 2)) + (period / 2);
        dbg("NbrTrickleImplP",
            "Scheduling Trickle event with %u\n", period);
        call PeriodTimer.startOneShot(dtfire);
    }

}

