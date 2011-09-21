#ifndef _SHARED_VAR_H_
#define _SHARED_VAR_H_

enum {
    AM_SHARED_VAR       = 12,
    MAX_SHARED_VAR      = 182,
};

#define SHARED_BMAP_SIZE   ((MAX_SHARED_VAR+7)/8)

typedef struct var_t {
    uint8_t key;
    float value;
    uint32_t version;
} var_t;

// Struct containing all variables shared by a node
typedef struct shared_vars_t {
    var_t v[MAX_SHARED_VAR];
} shared_vars_t;

#endif

