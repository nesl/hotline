#include <Timer.h>
#include "LightSense.h"

module EstimatorP {
    uses interface Boot;
    uses interface SplitControl as RadioControl;
    uses interface StdControl as RoutingControl;
    uses interface Send;
    uses interface Timer<TMilli>;
    uses interface RootControl;
    uses interface Receive;
    uses interface Intercept;

    uses interface Read<uint16_t>;
    uses interface Random;
}
implementation {
    message_t packet;
    uint8_t done = 0;
    uint16_t seq = 0;
    bool sendBusy = FALSE;

    event void Boot.booted() {
        seq = 0;
        done = 0;
        sendBusy = FALSE;
        call RadioControl.start();
    }

    event void RadioControl.startDone(error_t err) {
        if (err != SUCCESS) {
            call RadioControl.start();
        } else {
            call RoutingControl.start();
            if (TOS_NODE_ID == 0) {
                done = 1;
                call RootControl.setRoot();
            } else {
                uint32_t r = call Random.rand32() % 1024;
                call Timer.startOneShot((60*1024L)+r);
            }
        }
    }

    event void RadioControl.stopDone(error_t err) {}

    event void Timer.fired() {
        call Read.read();
    }

    event void Read.readDone(error_t res, uint16_t val) {
        if ( !sendBusy ) {
            light_sense_msg_t* msg = (light_sense_msg_t*)
                call Send.getPayload(&packet,
                                     sizeof(light_sense_msg_t));
            msg->seq = seq;
            msg->value = val;
            msg->timestamp = call Timer.getNow();
            msg->src = TOS_NODE_ID;

            if (call Send.send(&packet, sizeof(light_sense_msg_t)) != SUCCESS) {
                call Timer.startOneShot(call Random.rand32() % 100);
            } else {
                sendBusy = TRUE;
                seq++;
                dbg("EstimatorPEval", "TX_%s_%u_%u\n",
                        sim_time_string(),
                        msg->timestamp,     // Tx timestamp
                        msg->seq );
            }
        }
    }

    event void Send.sendDone(message_t* m, error_t err) {
        if (err != SUCCESS) {
            seq--;
            call Timer.startOneShot(call Random.rand32() % 100);
        }
        sendBusy = FALSE;
    }

    event bool Intercept.forward(message_t* msg, void *payload, uint8_t len) {
        light_sense_msg_t* pkt = (light_sense_msg_t*)payload;
        dbg("EstimatorPEval", "FWD_%s_%u_%u_%u_%u\n",
                sim_time_string(),  // Rx timestamp
                pkt->timestamp,     // Tx timestamp
                pkt->seq,
                TOS_NODE_ID,        // Intercepting node
                pkt->src );
        return TRUE;
    }

    event message_t* Receive.receive(message_t* msg, void* payload, uint8_t len) {
        light_sense_msg_t* pkt = (light_sense_msg_t*)payload;
        dbg("EstimatorPEval", "RX_%s_%u_%u_%u_%u\n",
                sim_time_string(),  // Rx timestamp
                pkt->timestamp,     // Tx timestamp
                pkt->seq,
                pkt->value,
                pkt->src );
        done++;
        return msg;
    }
}

