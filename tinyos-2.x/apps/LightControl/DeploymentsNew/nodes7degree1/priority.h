#ifndef _PRIORITY_H_
#define _PRIORITY_H_

uint32_t get_priority(am_addr_t nid) {
	switch (nid) {
		case 0 : return 0 ;
		case 7 : return 1 ;
		case 14 : return 2 ;
		case 21 : return 3 ;
		case 28 : return 4 ;
		case 35 : return 5 ;
		case 42 : return 6 ;
		case 43 : return 7 ;
		case 44 : return 8 ;
		case 45 : return 9 ;
		case 46 : return 10 ;
		case 47 : return 11 ;
		case 48 : return 12 ;
		case 41 : return 13 ;
		case 40 : return 14 ;
		case 39 : return 15 ;
		case 38 : return 16 ;
		case 37 : return 17 ;
		case 36 : return 18 ;
		case 29 : return 19 ;
		case 30 : return 20 ;
		case 31 : return 21 ;
		case 32 : return 22 ;
		case 33 : return 23 ;
		case 34 : return 24 ;
		case 27 : return 25 ;
		case 26 : return 26 ;
		case 25 : return 27 ;
		case 24 : return 28 ;
		case 23 : return 29 ;
		case 22 : return 30 ;
		case 15 : return 31 ;
		case 16 : return 32 ;
		case 17 : return 33 ;
		case 18 : return 34 ;
		case 19 : return 35 ;
		case 20 : return 36 ;
		case 13 : return 37 ;
		case 6 : return 38 ;
		case 12 : return 39 ;
		case 5 : return 40 ;
		case 4 : return 41 ;
		case 11 : return 42 ;
		case 10 : return 43 ;
		case 3 : return 44 ;
		case 2 : return 45 ;
		case 9 : return 46 ;
		case 8 : return 47 ;
		case 1 : return 48 ;
		default: return 0;
	}
	return 0;
}
#endif
