
#ifdef REAL_WORLD
#include <printf.h>
#endif

#include "SharedVar.h"

module UnreliableVarTransportP {
    provides interface VarTransport;
    provides interface Init;
    
    uses interface Send;
    uses interface Receive;
    uses interface DebugLog2;

    uses interface Random;
    uses interface Timer<TMilli> as RandomTimer;
}

implementation {

    typedef nx_struct {
        nx_am_addr_t src;
        nx_uint32_t seq;
        nx_uint16_t mmask;
        nx_uint16_t pmask;
        nx_uint8_t num_vars;
    } tr_hdr_t;

    bool busy = FALSE;
    uint32_t pktseq = 0;
    message_t pkt;

    shared_vars_t tx_vars;
    uint8_t tx_ptr, num_used, saved_tx_ptr;
    //var_t rx_vars[MAX_VARS_PER_PKT];

    /********** Private functions **********/
    
#ifdef REAL_WORLD
#else
#endif

    /************* Private functions *************/

    void reset_tx() {
        num_used = 0;
        tx_ptr = 0;
        saved_tx_ptr = 0;
    }

    void start_random_timer(uint32_t period) {
        uint32_t dtfire = 0; 
        if ( period == 0 ) {
            //period = 48;
            period = 64;
        }
        //dtfire = (call Random.rand32() % (period/2)) + (period)/2;
        dtfire = (call Random.rand32() % ((5*period)/8)) + ((3*period)/8);
        call RandomTimer.startOneShot(dtfire);
    }

    /**************** Tasks ******************/

    task void do_send() {
        tr_hdr_t *hdr;
        var_t *data;
        uint8_t total_len = sizeof(tr_hdr_t);
        uint8_t max_payload = call Send.maxPayloadLength();
        uint8_t max_vars_per_pkt = (max_payload-total_len)/sizeof(var_t);
        uint8_t frag_limit;
        // Total number of pkts that will be used to send this msg
        uint8_t num_pkts = (num_used + max_vars_per_pkt - 1) / max_vars_per_pkt;

        if ( max_payload < total_len ) return;  // Should NOT happen!!

        // Fill up the transport header information
        hdr = (tr_hdr_t*)(call Send.getPayload(&pkt, max_payload));
        hdr->src = TOS_NODE_ID;
        hdr->seq = pktseq;
        // Set num_pkts LSBs in mmask to 1
        hdr->mmask = 1;
        hdr->mmask <<= num_pkts;
        hdr->mmask -= 1;
        // Set the bit for current pkt that is going to be transmitted
        hdr->pmask = 1;
        hdr->pmask <<= (tx_ptr/max_vars_per_pkt);
        // Advance pointer to beginning of variable data in the pkt
        data = (var_t*)((uint8_t*)hdr+sizeof(tr_hdr_t));
        // Calculate number of variables that can be sent in this fragment
        frag_limit = (tx_ptr+max_vars_per_pkt)<num_used ? 
                        tx_ptr+max_vars_per_pkt : num_used;
        // Update total length of data
        hdr->num_vars = frag_limit-tx_ptr;
        total_len += ((hdr->num_vars) * sizeof(var_t));
        dbg("ShareDataP","Transport: Sending var indexes %u -- %u. Total length:%u\n",
                tx_ptr, frag_limit, total_len);
        // Save tx_ptr so that it can be restored if transmission fails
        // Set restore point
        saved_tx_ptr = tx_ptr;
        // Fill up the data
        for ( ; tx_ptr<frag_limit; tx_ptr++, data++ ) {
            memcpy(data, &tx_vars.v[tx_ptr], sizeof(var_t));
        }
        // Send the message
        if (call Send.send(&pkt,
                           total_len) == SUCCESS) {
            dbg("ShareDataP", "Transport: Success.\n");
        } else {
            dbg("ShareDataP", "Transport: Fail.\n");
            // Restore
            tx_ptr = saved_tx_ptr;
            //post do_send();
            start_random_timer(0);
        }
    }

    /***************** Commands ****************/

    command error_t Init.init() {
        busy = FALSE;
        pktseq = 0;
        reset_tx();
        return SUCCESS;
    }

    command am_addr_t VarTransport.address() {
        return TOS_NODE_ID;
    }

    command void VarTransport.clearAll() {}

    event void RandomTimer.fired() {
        post do_send();
    }

    command error_t VarTransport.send(shared_vars_t *data, 
            uint8_t *used, bool reTx) {
        uint8_t i = 0;
        if ( busy ) return EBUSY;
        // Copy over variables
        for ( ; i<MAX_SHARED_VAR; i++ ) {
            if ( used[i] == 0 ) continue;
            memcpy(&tx_vars.v[num_used], &data->v[i], sizeof(var_t));
            num_used++;
        }
        // Verify
        if ( num_used == 0 ) {
            return EINVAL;
        }
        if ( !reTx ) {
            // New update
            pktseq++;
        }
        // Start sending
        call DebugLog2.printLog(pktseq, num_used);
        //dbg("ShareDataPEval", "SVR_%s_TX_%u_%u\n",
        //        sim_time_string(), pktseq, num_used);
        dbg("ShareDataP", "Transport: Send %u variables.\n", num_used);
        busy = TRUE;
        //post do_send();
        start_random_timer(0);
        return SUCCESS;
    }

    /***************** Events ****************/


    event void Send.sendDone(message_t* msg, error_t err) {
        if (&pkt == msg) {
            dbg("ShareDataP", "Transport: Update send done - ");
            if ( err == SUCCESS ) {
                dbg_clear("ShareDataP", "SUCCESS. ");
                if ( tx_ptr < num_used ) {
                    // More fragments need to be sent
                    post do_send();
                    dbg_clear("ShareDataP", "More.\n");
                } else {
                    // Done sending all fragments
                    reset_tx();
                    busy = FALSE;
                    dbg_clear("ShareDataP", "Finished.\n");
                }
            } else {
                // Tx failed. Restore and send again.
                dbg_clear("ShareDataP", "FAIL.\n");
                tx_ptr = saved_tx_ptr;
                //post do_send();
                start_random_timer(0);
            }
        }
    }

    event message_t* Receive.receive(message_t* msg, void *payload, 
                                     uint8_t len) {
        tr_hdr_t *hdr = (tr_hdr_t *)payload;
        var_t *v = (var_t *)((uint8_t*)payload+sizeof(tr_hdr_t));
        
        // Signal receive to the app.
        dbg("ShareDataP", "Transport: Rcvd %u variables from node %u.\n",
                hdr->num_vars, hdr->src);
        signal VarTransport.receive(hdr->src, v, hdr->num_vars,
                hdr->seq, hdr->mmask, hdr->pmask);

        return msg;
    }
    
}

