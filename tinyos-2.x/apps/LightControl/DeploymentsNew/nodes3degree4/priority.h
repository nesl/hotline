#ifndef _PRIORITY_H_
#define _PRIORITY_H_

uint32_t get_priority(am_addr_t nid) {
	switch (nid) {
		case 0 : return 0 ;
		case 7 : return 1 ;
		case 6 : return 2 ;
		case 5 : return 3 ;
		case 4 : return 4 ;
		case 3 : return 5 ;
		case 2 : return 6 ;
		case 1 : return 7 ;
		case 8 : return 8 ;
		default: return 0;
	}
	return 0;
}
#endif
