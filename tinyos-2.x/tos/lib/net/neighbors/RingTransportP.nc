
#include "route_fragment.h"
#include <ring.h>

generic module RingTransportP(uint16_t MAX_LEN) {
    provides interface Ring;
    provides interface Init;
    
    uses interface Token;
}

implementation {

    bool tx_busy;
    uint16_t curr_token;
    uint8_t *snd;
    uint16_t tx_ptr, saved_tx_ptr;
    uint16_t total_len;
    uint8_t total_frags;
    uint8_t tx_seq;

    bool rx_busy;
    uint8_t rcv[MAX_LEN];
    uint8_t rcv_bmap[4];    // Supports 32 fragments
    uint16_t rcv_token;
    uint16_t rcv_len;

    /********** Private functions **********/
    
    void reset_tx() {
        tx_busy = FALSE;
        curr_token = 0;
        snd = NULL;
        tx_ptr = 0;
        saved_tx_ptr = 0;
        total_len = 0;
        total_frags = 0;
        tx_seq = 0;
    }

    void reset_rx() {
        rx_busy = FALSE;
        memset(rcv, 0, sizeof(rcv));
        memset(rcv_bmap, 0, sizeof(rcv_bmap));
        rcv_token = 0;
        rcv_len = 0;
    }

    void set_bits(uint8_t num_lsb) {
        // Set all 0 to num_lsb-1 bits
        uint8_t i = num_lsb / 8;
        uint8_t j = num_lsb % 8;
        uint8_t k;
        if ( i > sizeof(rcv_bmap) ) return;
        if ( i > 0 ) {
            memset(rcv_bmap, 0xFF, i);
        }
        if ( i == sizeof(rcv_bmap) ) return;
        for ( k=0; k<j; k++ ) {
            rcv_bmap[i] |= (uint8_t)(1<<k);
        }
    }

    void unset_bit(uint8_t n) {
        uint8_t i, j;
        if ( n >= sizeof(rcv_bmap)*8 ) return;
        i = n / 8;
        j = n % 8;
        rcv_bmap[i] &= ~(1<<j);
    }

    bool bit_set(uint8_t n) {
        uint8_t i, j;
        if ( n >= sizeof(rcv_bmap)*8 ) return FALSE;
        i = n / 8;
        j = n % 8;
        return (rcv_bmap[i]&(uint8_t)(1<<j)) > 0;
    }

    bool bits_clear() {
        uint8_t i;
        for ( i=0; i<sizeof(rcv_bmap); i++ ) {
            if ( rcv_bmap[i] > 0 ) return FALSE;
        }
        return TRUE;
    }

    /**************** Tasks ******************/

    task void tx_token() {
        error_t ret = SUCCESS;
        uint16_t full_pkt_end = tx_ptr + call Token.maxPayloadLength();
        uint16_t frag_limit = (full_pkt_end<total_len) ? 
                              full_pkt_end : total_len;
        am_addr_t dest = right_n[TOS_NODE_ID];

        if ( !tx_busy ) return;    // Tx state was reset

        // Tx next fragment
        ret = call Token.send(curr_token, total_frags, tx_seq, 
                              dest,
                              &snd[tx_ptr],
                              (uint8_t)(frag_limit-tx_ptr));
        if ( ret == SUCCESS ) {
            // Save restore state
            saved_tx_ptr = tx_ptr;
            tx_ptr = frag_limit;
            dbg("TransportPEval","TOKEN_%s_%u_TX_%u_%u_OF_%u\n",
                    sim_time_string(),
                    curr_token,
                    dest,
                    tx_seq,
                    total_frags);
        } else {
            post tx_token();
        }
    }

    task void signal_rx() {
        if ( !rx_busy ) return;
        signal Ring.receive(rcv_token, rcv, rcv_len);
        reset_rx();
    }

    /***************** Commands ****************/

    command error_t Init.init() {
        reset_rx();
        reset_tx();
        return SUCCESS;
    }

    command error_t Ring.sendToNext(uint16_t token, void *data, uint16_t len) {
        if ( len == 0 ) return EINVAL;
        if ( tx_busy ) {
            if ( token > curr_token ) {
                // Trying to send a new token. Discard old token.
                reset_tx();
            } else {
                return EBUSY;   // Busy sending a token
            }
        }
        // Record Tx parameters
        tx_busy = TRUE;
        tx_ptr = 0;
        total_len = len;
        snd = (uint8_t*)data;
        curr_token = token;
        total_frags = (total_len+call Token.maxPayloadLength()-1) / 
                       call Token.maxPayloadLength();
        tx_seq = 0;
        dbg("TransportP","##_%s_Send token %u with %u frags, %u len\n",
                sim_time_string(),
                curr_token,
                total_frags,
                total_len);
        // Start sending token fragments
        post tx_token();
        return SUCCESS;
    }

    /***************** Events ****************/

    event void Token.sendDone(uint16_t token, uint8_t seq, error_t err) {
        if ( (token==curr_token) &&
             (seq==tx_seq) ) {
            if ( err != SUCCESS ) {
                // Restore and retry
                tx_ptr = saved_tx_ptr;
                post tx_token();
            } 
        }
    }

    event void Token.acked(uint16_t token, uint8_t seq) {
        if ( (token==curr_token) &&
             (seq==tx_seq) ) {
            dbg("TransportP","##_%s_Acked token %u, %u of %u\n",
                    sim_time_string(),
                    curr_token,
                    tx_seq,
                    total_frags);
            // Advance sequence number
            tx_seq++;
            if ( tx_seq == total_frags ) {
                // Finished.
                dbg("TransportP","##_%s_Finished token %u\n",
                        sim_time_string(),
                        token);
                reset_tx();
                signal Ring.sendDone(token, SUCCESS);
            } else {
                // More.
                post tx_token();
            }
        }
    }

    event void Token.receive(uint16_t token, uint8_t frag, uint8_t seq, 
            void *payload, uint8_t len) {
        // If busy rx another token, drop this one.
        if ( rx_busy ) {
            if ( token > rcv_token ) {
                // Received new token. Discard old state.
                reset_rx();
            } else if ( token < rcv_token ) {
                // Received some old token. Drop it.
                return;
            }
        }
        if ( !rx_busy ) {
            // New token.
            rx_busy = TRUE;
            rcv_token = token;
            rcv_len = 0;
            set_bits(frag);
            dbg("TransportP","##_%s_Start rx token %u with %u frags\n",
                    sim_time_string(),
                    token,
                    frag);
        }
        dbg("TransportPEval","TOKEN_%s_%u_RX_%u_OF_%u\n",
                sim_time_string(),
                rcv_token,
                seq,
                frag);
        if ( bit_set(seq) ) {
            // New fragment
            uint16_t rx_ptr = (uint16_t)seq * (uint16_t)call Token.maxPayloadLength();
            unset_bit(seq);
            rcv_len += len;
            memcpy(&rcv[rx_ptr], payload, len);
            if ( bits_clear() ) {
                // Received all fragments.
                post signal_rx();
            }
        }
    }

}

