#ifndef _PRIORITY_H_
#define _PRIORITY_H_

uint32_t get_priority(am_addr_t nid) {
	switch (nid) {
		case 0 : return 0 ;
		case 40 : return 1 ;
		case 80 : return 2 ;
		case 93 : return 3 ;
		case 97 : return 4 ;
		case 99 : return 5 ;
		case 98 : return 6 ;
		case 96 : return 7 ;
		case 95 : return 8 ;
		case 94 : return 9 ;
		case 92 : return 10 ;
		case 91 : return 11 ;
		case 90 : return 12 ;
		case 83 : return 13 ;
		case 87 : return 14 ;
		case 89 : return 15 ;
		case 88 : return 16 ;
		case 86 : return 17 ;
		case 85 : return 18 ;
		case 84 : return 19 ;
		case 82 : return 20 ;
		case 81 : return 21 ;
		case 74 : return 22 ;
		case 78 : return 23 ;
		case 79 : return 24 ;
		case 77 : return 25 ;
		case 76 : return 26 ;
		case 75 : return 27 ;
		case 73 : return 28 ;
		case 72 : return 29 ;
		case 71 : return 30 ;
		case 70 : return 31 ;
		case 63 : return 32 ;
		case 67 : return 33 ;
		case 69 : return 34 ;
		case 68 : return 35 ;
		case 66 : return 36 ;
		case 65 : return 37 ;
		case 64 : return 38 ;
		case 62 : return 39 ;
		case 61 : return 40 ;
		case 60 : return 41 ;
		case 53 : return 42 ;
		case 57 : return 43 ;
		case 59 : return 44 ;
		case 58 : return 45 ;
		case 56 : return 46 ;
		case 55 : return 47 ;
		case 54 : return 48 ;
		case 52 : return 49 ;
		case 51 : return 50 ;
		case 50 : return 51 ;
		case 43 : return 52 ;
		case 47 : return 53 ;
		case 49 : return 54 ;
		case 48 : return 55 ;
		case 46 : return 56 ;
		case 45 : return 57 ;
		case 44 : return 58 ;
		case 42 : return 59 ;
		case 41 : return 60 ;
		case 34 : return 61 ;
		case 38 : return 62 ;
		case 39 : return 63 ;
		case 37 : return 64 ;
		case 36 : return 65 ;
		case 35 : return 66 ;
		case 33 : return 67 ;
		case 32 : return 68 ;
		case 30 : return 69 ;
		case 23 : return 70 ;
		case 27 : return 71 ;
		case 29 : return 72 ;
		case 28 : return 73 ;
		case 26 : return 74 ;
		case 25 : return 75 ;
		case 24 : return 76 ;
		case 22 : return 77 ;
		case 21 : return 78 ;
		case 20 : return 79 ;
		case 13 : return 80 ;
		case 17 : return 81 ;
		case 19 : return 82 ;
		case 18 : return 83 ;
		case 16 : return 84 ;
		case 15 : return 85 ;
		case 14 : return 86 ;
		case 12 : return 87 ;
		case 11 : return 88 ;
		case 10 : return 89 ;
		case 3 : return 90 ;
		case 7 : return 91 ;
		case 9 : return 92 ;
		case 8 : return 93 ;
		case 6 : return 94 ;
		case 5 : return 95 ;
		case 4 : return 96 ;
		case 2 : return 97 ;
		case 1 : return 98 ;
		case 31 : return 99 ;
		default: return 0;
	}
	return 0;
}
#endif
