#ifndef _PRIORITY_H_
#define _PRIORITY_H_

uint32_t get_priority(am_addr_t nid) {
	switch (nid) {
		case 0 : return 0 ;
		case 10 : return 1 ;
		case 20 : return 2 ;
		case 30 : return 3 ;
		case 40 : return 4 ;
		case 50 : return 5 ;
		case 60 : return 6 ;
		case 70 : return 7 ;
		case 80 : return 8 ;
		case 90 : return 9 ;
		case 91 : return 10 ;
		case 92 : return 11 ;
		case 93 : return 12 ;
		case 94 : return 13 ;
		case 95 : return 14 ;
		case 96 : return 15 ;
		case 97 : return 16 ;
		case 98 : return 17 ;
		case 99 : return 18 ;
		case 89 : return 19 ;
		case 88 : return 20 ;
		case 87 : return 21 ;
		case 86 : return 22 ;
		case 85 : return 23 ;
		case 84 : return 24 ;
		case 83 : return 25 ;
		case 82 : return 26 ;
		case 81 : return 27 ;
		case 71 : return 28 ;
		case 72 : return 29 ;
		case 73 : return 30 ;
		case 74 : return 31 ;
		case 75 : return 32 ;
		case 76 : return 33 ;
		case 77 : return 34 ;
		case 78 : return 35 ;
		case 79 : return 36 ;
		case 69 : return 37 ;
		case 68 : return 38 ;
		case 67 : return 39 ;
		case 66 : return 40 ;
		case 65 : return 41 ;
		case 64 : return 42 ;
		case 63 : return 43 ;
		case 62 : return 44 ;
		case 61 : return 45 ;
		case 51 : return 46 ;
		case 52 : return 47 ;
		case 53 : return 48 ;
		case 54 : return 49 ;
		case 55 : return 50 ;
		case 56 : return 51 ;
		case 57 : return 52 ;
		case 58 : return 53 ;
		case 59 : return 54 ;
		case 49 : return 55 ;
		case 48 : return 56 ;
		case 47 : return 57 ;
		case 46 : return 58 ;
		case 45 : return 59 ;
		case 44 : return 60 ;
		case 43 : return 61 ;
		case 42 : return 62 ;
		case 41 : return 63 ;
		case 31 : return 64 ;
		case 32 : return 65 ;
		case 33 : return 66 ;
		case 34 : return 67 ;
		case 35 : return 68 ;
		case 36 : return 69 ;
		case 37 : return 70 ;
		case 38 : return 71 ;
		case 39 : return 72 ;
		case 29 : return 73 ;
		case 28 : return 74 ;
		case 27 : return 75 ;
		case 26 : return 76 ;
		case 25 : return 77 ;
		case 24 : return 78 ;
		case 23 : return 79 ;
		case 22 : return 80 ;
		case 21 : return 81 ;
		case 11 : return 82 ;
		case 12 : return 83 ;
		case 13 : return 84 ;
		case 14 : return 85 ;
		case 15 : return 86 ;
		case 16 : return 87 ;
		case 17 : return 88 ;
		case 18 : return 89 ;
		case 19 : return 90 ;
		case 9 : return 91 ;
		case 8 : return 92 ;
		case 7 : return 93 ;
		case 6 : return 94 ;
		case 5 : return 95 ;
		case 4 : return 96 ;
		case 3 : return 97 ;
		case 2 : return 98 ;
		case 1 : return 99 ;
		default: return 0;
	}
	return 0;
}
#endif
