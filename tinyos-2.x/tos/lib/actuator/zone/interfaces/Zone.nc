
interface Zone {
    command error_t enable();
    command error_t disable();
    command error_t set( uint8_t *newzone );
    command uint8_t* get( am_addr_t node_addr );
    command bool intersects( am_addr_t nbr );
    event bool changed( am_addr_t node );
}
