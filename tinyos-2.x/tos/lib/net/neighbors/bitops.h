#ifndef _BIT_OPS_H_
#define _BIT_OPS_H_

//////////////////////////////////
// Operations to modify bit values
//////////////////////////////////

void set_bits(uint8_t num_lsb, uint8_t bmap[]) {
    // Set all 0 to num_lsb-1 bits
    uint8_t i = num_lsb / 8;
    uint8_t j = num_lsb % 8;
    uint8_t k;
    if ( i > sizeof(bmap) ) return;
    if ( i > 0 ) {
        memset(bmap, 0xFF, i);
    }
    if ( i == sizeof(bmap) ) return;
    for ( k=0; k<j; k++ ) {
        bmap[i] |= (uint8_t)(1<<k);
    }
}

void set_bit(uint8_t n, uint8_t bmap[]) {
    uint8_t i, j;
    if ( n >= sizeof(bmap)*8 ) return;
    i = n / 8;
    j = n % 8;
    bmap[i] |= (uint8_t)(1<<j);
}

void clear_bit(uint8_t n, uint8_t bmap[]) {
    uint8_t i, j;
    if ( n >= sizeof(bmap)*8 ) return;
    i = n / 8;
    j = n % 8;
    bmap[i] &= ~(1<<j);
}

void clear_all_bits(uint8_t bmap[]) {
    memset(bmap, 0, sizeof(bmap));
}

//////////////////////////////////
// Operations to check bit values
//////////////////////////////////

bool bit_set(uint8_t n, uint8_t bmap[]) {
    uint8_t i, j;
    if ( n >= sizeof(bmap)*8 ) return FALSE;
    i = n / 8;
    j = n % 8;
    return (bmap[i]&(uint8_t)(1<<j)) > 0;
}

bool bit_clear(uint8_t n, uint8_t bmap[]) {
    uint8_t i, j;
    if ( n >= sizeof(bmap)*8 ) return FALSE;
    i = n / 8;
    j = n % 8;
    return (bmap[i]&(uint8_t)(1<<j)) == 0;
}

bool bits_clear(uint8_t bmap[]) {
    uint8_t i;
    for ( i=0; i<sizeof(bmap); i++ ) {
        if ( bmap[i] > 0 ) return FALSE;
    }
    return TRUE;
}


#endif

