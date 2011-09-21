#ifndef _PRIORITY_H_
#define _PRIORITY_H_

uint32_t get_priority(am_addr_t nid) {
	switch (nid) {
		case 6 : return 0 ;
		case 14 : return 1 ;
		case 17 : return 2 ;
		case 27 : return 3 ;
		case 35 : return 4 ;
		case 38 : return 5 ;
		case 48 : return 6 ;
		case 3 : return 7 ;
		case 7 : return 8 ;
		case 20 : return 9 ;
		case 24 : return 10 ;
		case 28 : return 11 ;
		case 41 : return 12 ;
		case 45 : return 13 ;
		case 2 : return 14 ;
		case 5 : return 15 ;
		case 23 : return 16 ;
		case 26 : return 17 ;
		case 44 : return 18 ;
		case 47 : return 19 ;
		case 4 : return 20 ;
		case 22 : return 21 ;
		case 25 : return 22 ;
		case 43 : return 23 ;
		case 46 : return 24 ;
		case 10 : return 25 ;
		case 13 : return 26 ;
		case 21 : return 27 ;
		case 31 : return 28 ;
		case 42 : return 29 ;
		case 16 : return 30 ;
		case 19 : return 31 ;
		case 37 : return 32 ;
		case 40 : return 33 ;
		case 15 : return 34 ;
		case 18 : return 35 ;
		case 36 : return 36 ;
		case 39 : return 37 ;
		case 9 : return 38 ;
		case 12 : return 39 ;
		case 30 : return 40 ;
		case 33 : return 41 ;
		case 8 : return 42 ;
		case 11 : return 43 ;
		case 32 : return 44 ;
		case 0 : return 45 ;
		case 29 : return 46 ;
		case 34 : return 47 ;
		case 1 : return 48 ;
		default: return 0;
	}
	return 0;
}
#endif
