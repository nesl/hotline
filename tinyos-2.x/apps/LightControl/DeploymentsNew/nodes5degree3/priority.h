#ifndef _PRIORITY_H_
#define _PRIORITY_H_

uint32_t get_priority(am_addr_t nid) {
	switch (nid) {
		case 0 : return 0 ;
		case 11 : return 1 ;
		case 23 : return 2 ;
		case 24 : return 3 ;
		case 22 : return 4 ;
		case 21 : return 5 ;
		case 20 : return 6 ;
		case 17 : return 7 ;
		case 19 : return 8 ;
		case 18 : return 9 ;
		case 16 : return 10 ;
		case 15 : return 11 ;
		case 10 : return 12 ;
		case 7 : return 13 ;
		case 14 : return 14 ;
		case 13 : return 15 ;
		case 9 : return 16 ;
		case 8 : return 17 ;
		case 6 : return 18 ;
		case 5 : return 19 ;
		case 2 : return 20 ;
		case 4 : return 21 ;
		case 3 : return 22 ;
		case 1 : return 23 ;
		case 12 : return 24 ;
		default: return 0;
	}
	return 0;
}
#endif
