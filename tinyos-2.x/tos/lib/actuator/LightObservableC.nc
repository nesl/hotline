// $Id: TrickleTimerMilliC.nc,v 1.4 2006/12/12 18:23:29 vlahan Exp $
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
 * Configuration that encapsulates the trickle timer implementation to
 * its needed services and initialization. For details on the working
 * of the parameters, please refer to Levis et al., "A Self-Regulating
 * Algorithm for Code Maintenance and Propagation in Wireless Sensor
 * Networks," NSDI 2004.
 *
 * @param l Lower bound of the time period in seconds.
 * @param h Upper bound of the time period in seconds.
 * @param k Redundancy constant.
 * @param count How many timers to provide.
 *
 * @author Philip Levis
 * @author Gilman Tolle
 * @date   Jan 7 2006
 */ 

#include "zone2d.h"

configuration LightObservableC {
    provides interface ObservableAccess<uint16_t> as Observable;
    provides interface LocalTransaction<zone2d_t> as Transaction;
    uses interface ActNeighbor;
    uses interface Zone<zone2d_t> as Zone2d;
}
implementation {
    components MainC, LightObservableP;
    components DimLightActuatorC as ActuatorC;
    components new HotlineC(zone2d_t);

    Observable = LightPbservableP;
    Transaction = HotlineC;
    ActNeighbor = LightObservableP;
    Zone2d = LightObservableP;

    HotlineC.ObservableRequest -> LightObservableP;
    LightObservableP.LightDimControl -> ActuatorC;
    LightObservableP.ActuatorConfig2d -> ActuatorC;

    MainC.SoftwareInit -> LightObservableP;
}

  
