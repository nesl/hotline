#ifndef _ROUTES_H_
#define _ROUTES_H_

int8_t fill_route0(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 90: {
			if (max_len < 9 ) return -1;
			hops[ 0 ] = 90 ;
			hops[ 1 ] = 80 ;
			hops[ 2 ] = 70 ;
			hops[ 3 ] = 60 ;
			hops[ 4 ] = 50 ;
			hops[ 5 ] = 40 ;
			hops[ 6 ] = 30 ;
			hops[ 7 ] = 20 ;
			hops[ 8 ] = 10 ;
			return 9 ;
		}
		case 80: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 80 ;
			hops[ 1 ] = 70 ;
			hops[ 2 ] = 60 ;
			hops[ 3 ] = 50 ;
			hops[ 4 ] = 40 ;
			hops[ 5 ] = 30 ;
			hops[ 6 ] = 20 ;
			hops[ 7 ] = 10 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route1(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 18: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 18 ;
			hops[ 1 ] = 8 ;
			hops[ 2 ] = 7 ;
			hops[ 3 ] = 6 ;
			hops[ 4 ] = 5 ;
			hops[ 5 ] = 4 ;
			hops[ 6 ] = 3 ;
			hops[ 7 ] = 2 ;
			return 8 ;
		}
		case 15: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 15 ;
			hops[ 1 ] = 5 ;
			hops[ 2 ] = 4 ;
			hops[ 3 ] = 3 ;
			hops[ 4 ] = 2 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route2(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 87: {
			if (max_len < 13 ) return -1;
			hops[ 0 ] = 87 ;
			hops[ 1 ] = 77 ;
			hops[ 2 ] = 67 ;
			hops[ 3 ] = 66 ;
			hops[ 4 ] = 65 ;
			hops[ 5 ] = 64 ;
			hops[ 6 ] = 54 ;
			hops[ 7 ] = 44 ;
			hops[ 8 ] = 34 ;
			hops[ 9 ] = 33 ;
			hops[ 10 ] = 32 ;
			hops[ 11 ] = 22 ;
			hops[ 12 ] = 12 ;
			return 13 ;
		}
		case 12: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 12 ;
			return 1 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route3(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 22: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 22 ;
			hops[ 1 ] = 12 ;
			hops[ 2 ] = 2 ;
			return 3 ;
		}
		case 6: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 6 ;
			hops[ 1 ] = 5 ;
			hops[ 2 ] = 4 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route4(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 34: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 34 ;
			hops[ 1 ] = 24 ;
			hops[ 2 ] = 14 ;
			return 3 ;
		}
		case 84: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 84 ;
			hops[ 1 ] = 74 ;
			hops[ 2 ] = 64 ;
			hops[ 3 ] = 54 ;
			hops[ 4 ] = 44 ;
			hops[ 5 ] = 34 ;
			hops[ 6 ] = 24 ;
			hops[ 7 ] = 14 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route5(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 20: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 20 ;
			hops[ 1 ] = 10 ;
			hops[ 2 ] = 0 ;
			hops[ 3 ] = 1 ;
			hops[ 4 ] = 2 ;
			hops[ 5 ] = 3 ;
			hops[ 6 ] = 4 ;
			return 7 ;
		}
		case 48: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 48 ;
			hops[ 1 ] = 38 ;
			hops[ 2 ] = 37 ;
			hops[ 3 ] = 36 ;
			hops[ 4 ] = 35 ;
			hops[ 5 ] = 25 ;
			hops[ 6 ] = 15 ;
			return 7 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route6(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 3: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 3 ;
			hops[ 1 ] = 4 ;
			hops[ 2 ] = 5 ;
			return 3 ;
		}
		case 86: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 86 ;
			hops[ 1 ] = 76 ;
			hops[ 2 ] = 66 ;
			hops[ 3 ] = 56 ;
			hops[ 4 ] = 46 ;
			hops[ 5 ] = 36 ;
			hops[ 6 ] = 26 ;
			hops[ 7 ] = 16 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route7(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 16: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 16 ;
			hops[ 1 ] = 17 ;
			return 2 ;
		}
		case 44: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 44 ;
			hops[ 1 ] = 34 ;
			hops[ 2 ] = 35 ;
			hops[ 3 ] = 36 ;
			hops[ 4 ] = 37 ;
			hops[ 5 ] = 27 ;
			hops[ 6 ] = 17 ;
			return 7 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route8(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 71: {
			if (max_len < 14 ) return -1;
			hops[ 0 ] = 71 ;
			hops[ 1 ] = 72 ;
			hops[ 2 ] = 73 ;
			hops[ 3 ] = 74 ;
			hops[ 4 ] = 64 ;
			hops[ 5 ] = 65 ;
			hops[ 6 ] = 66 ;
			hops[ 7 ] = 67 ;
			hops[ 8 ] = 68 ;
			hops[ 9 ] = 58 ;
			hops[ 10 ] = 48 ;
			hops[ 11 ] = 38 ;
			hops[ 12 ] = 28 ;
			hops[ 13 ] = 18 ;
			return 14 ;
		}
		case 79: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 79 ;
			hops[ 1 ] = 69 ;
			hops[ 2 ] = 68 ;
			hops[ 3 ] = 58 ;
			hops[ 4 ] = 48 ;
			hops[ 5 ] = 38 ;
			hops[ 6 ] = 28 ;
			hops[ 7 ] = 18 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route9(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 97: {
			if (max_len < 11 ) return -1;
			hops[ 0 ] = 97 ;
			hops[ 1 ] = 98 ;
			hops[ 2 ] = 99 ;
			hops[ 3 ] = 89 ;
			hops[ 4 ] = 79 ;
			hops[ 5 ] = 69 ;
			hops[ 6 ] = 59 ;
			hops[ 7 ] = 49 ;
			hops[ 8 ] = 39 ;
			hops[ 9 ] = 29 ;
			hops[ 10 ] = 19 ;
			return 11 ;
		}
		case 42: {
			if (max_len < 11 ) return -1;
			hops[ 0 ] = 42 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 33 ;
			hops[ 3 ] = 34 ;
			hops[ 4 ] = 35 ;
			hops[ 5 ] = 36 ;
			hops[ 6 ] = 37 ;
			hops[ 7 ] = 27 ;
			hops[ 8 ] = 17 ;
			hops[ 9 ] = 18 ;
			hops[ 10 ] = 8 ;
			return 11 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route10(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 32: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 32 ;
			hops[ 1 ] = 22 ;
			hops[ 2 ] = 12 ;
			hops[ 3 ] = 11 ;
			return 4 ;
		}
		case 52: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 52 ;
			hops[ 1 ] = 42 ;
			hops[ 2 ] = 32 ;
			hops[ 3 ] = 22 ;
			hops[ 4 ] = 12 ;
			hops[ 5 ] = 11 ;
			return 6 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route11(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 30: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 30 ;
			hops[ 1 ] = 20 ;
			hops[ 2 ] = 10 ;
			return 3 ;
		}
		case 40: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 40 ;
			hops[ 1 ] = 41 ;
			hops[ 2 ] = 31 ;
			hops[ 3 ] = 21 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route12(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 2: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 2 ;
			return 1 ;
		}
		case 56: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 56 ;
			hops[ 1 ] = 46 ;
			hops[ 2 ] = 36 ;
			hops[ 3 ] = 35 ;
			hops[ 4 ] = 34 ;
			hops[ 5 ] = 33 ;
			hops[ 6 ] = 32 ;
			hops[ 7 ] = 22 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route13(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 21: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 21 ;
			hops[ 1 ] = 11 ;
			hops[ 2 ] = 12 ;
			return 3 ;
		}
		case 33: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 33 ;
			hops[ 1 ] = 23 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route14(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 26: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 26 ;
			hops[ 1 ] = 16 ;
			hops[ 2 ] = 15 ;
			return 3 ;
		}
		case 72: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 72 ;
			hops[ 1 ] = 73 ;
			hops[ 2 ] = 74 ;
			hops[ 3 ] = 64 ;
			hops[ 4 ] = 54 ;
			hops[ 5 ] = 44 ;
			hops[ 6 ] = 34 ;
			hops[ 7 ] = 24 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route15(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 1: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 1 ;
			hops[ 1 ] = 2 ;
			hops[ 2 ] = 3 ;
			hops[ 3 ] = 4 ;
			hops[ 4 ] = 5 ;
			return 5 ;
		}
		case 50: {
			if (max_len < 9 ) return -1;
			hops[ 0 ] = 50 ;
			hops[ 1 ] = 40 ;
			hops[ 2 ] = 41 ;
			hops[ 3 ] = 42 ;
			hops[ 4 ] = 32 ;
			hops[ 5 ] = 33 ;
			hops[ 6 ] = 34 ;
			hops[ 7 ] = 35 ;
			hops[ 8 ] = 25 ;
			return 9 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route16(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 70: {
			if (max_len < 12 ) return -1;
			hops[ 0 ] = 70 ;
			hops[ 1 ] = 60 ;
			hops[ 2 ] = 50 ;
			hops[ 3 ] = 40 ;
			hops[ 4 ] = 41 ;
			hops[ 5 ] = 42 ;
			hops[ 6 ] = 32 ;
			hops[ 7 ] = 33 ;
			hops[ 8 ] = 34 ;
			hops[ 9 ] = 35 ;
			hops[ 10 ] = 36 ;
			hops[ 11 ] = 26 ;
			return 12 ;
		}
		case 7: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 7 ;
			hops[ 1 ] = 17 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route17(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 64: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 64 ;
			hops[ 1 ] = 65 ;
			hops[ 2 ] = 66 ;
			hops[ 3 ] = 67 ;
			hops[ 4 ] = 57 ;
			hops[ 5 ] = 47 ;
			hops[ 6 ] = 37 ;
			hops[ 7 ] = 27 ;
			return 8 ;
		}
		case 82: {
			if (max_len < 12 ) return -1;
			hops[ 0 ] = 82 ;
			hops[ 1 ] = 72 ;
			hops[ 2 ] = 73 ;
			hops[ 3 ] = 74 ;
			hops[ 4 ] = 64 ;
			hops[ 5 ] = 65 ;
			hops[ 6 ] = 66 ;
			hops[ 7 ] = 67 ;
			hops[ 8 ] = 57 ;
			hops[ 9 ] = 47 ;
			hops[ 10 ] = 37 ;
			hops[ 11 ] = 27 ;
			return 12 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route18(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 92: {
			if (max_len < 14 ) return -1;
			hops[ 0 ] = 92 ;
			hops[ 1 ] = 82 ;
			hops[ 2 ] = 72 ;
			hops[ 3 ] = 73 ;
			hops[ 4 ] = 74 ;
			hops[ 5 ] = 64 ;
			hops[ 6 ] = 65 ;
			hops[ 7 ] = 66 ;
			hops[ 8 ] = 67 ;
			hops[ 9 ] = 68 ;
			hops[ 10 ] = 58 ;
			hops[ 11 ] = 48 ;
			hops[ 12 ] = 38 ;
			hops[ 13 ] = 28 ;
			return 14 ;
		}
		case 1: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 1 ;
			hops[ 1 ] = 2 ;
			hops[ 2 ] = 3 ;
			hops[ 3 ] = 4 ;
			hops[ 4 ] = 5 ;
			hops[ 5 ] = 6 ;
			hops[ 6 ] = 7 ;
			hops[ 7 ] = 8 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route19(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 79: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 79 ;
			hops[ 1 ] = 69 ;
			hops[ 2 ] = 59 ;
			hops[ 3 ] = 49 ;
			hops[ 4 ] = 39 ;
			hops[ 5 ] = 29 ;
			return 6 ;
		}
		case 57: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 57 ;
			hops[ 1 ] = 47 ;
			hops[ 2 ] = 37 ;
			hops[ 3 ] = 27 ;
			hops[ 4 ] = 17 ;
			hops[ 5 ] = 18 ;
			return 6 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route20(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 77: {
			if (max_len < 12 ) return -1;
			hops[ 0 ] = 77 ;
			hops[ 1 ] = 67 ;
			hops[ 2 ] = 66 ;
			hops[ 3 ] = 65 ;
			hops[ 4 ] = 64 ;
			hops[ 5 ] = 54 ;
			hops[ 6 ] = 44 ;
			hops[ 7 ] = 34 ;
			hops[ 8 ] = 33 ;
			hops[ 9 ] = 32 ;
			hops[ 10 ] = 22 ;
			hops[ 11 ] = 21 ;
			return 12 ;
		}
		case 5: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 5 ;
			hops[ 1 ] = 4 ;
			hops[ 2 ] = 3 ;
			hops[ 3 ] = 2 ;
			hops[ 4 ] = 1 ;
			hops[ 5 ] = 0 ;
			hops[ 6 ] = 10 ;
			return 7 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route21(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 58: {
			if (max_len < 10 ) return -1;
			hops[ 0 ] = 58 ;
			hops[ 1 ] = 48 ;
			hops[ 2 ] = 38 ;
			hops[ 3 ] = 37 ;
			hops[ 4 ] = 36 ;
			hops[ 5 ] = 35 ;
			hops[ 6 ] = 34 ;
			hops[ 7 ] = 33 ;
			hops[ 8 ] = 32 ;
			hops[ 9 ] = 22 ;
			return 10 ;
		}
		case 13: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 13 ;
			hops[ 1 ] = 12 ;
			hops[ 2 ] = 11 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route22(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 93: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 93 ;
			hops[ 1 ] = 83 ;
			hops[ 2 ] = 73 ;
			hops[ 3 ] = 72 ;
			hops[ 4 ] = 62 ;
			hops[ 5 ] = 52 ;
			hops[ 6 ] = 42 ;
			hops[ 7 ] = 32 ;
			return 8 ;
		}
		case 3: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 3 ;
			hops[ 1 ] = 2 ;
			hops[ 2 ] = 12 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route23(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 45: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 45 ;
			hops[ 1 ] = 35 ;
			hops[ 2 ] = 34 ;
			hops[ 3 ] = 24 ;
			return 4 ;
		}
		case 89: {
			if (max_len < 12 ) return -1;
			hops[ 0 ] = 89 ;
			hops[ 1 ] = 88 ;
			hops[ 2 ] = 78 ;
			hops[ 3 ] = 68 ;
			hops[ 4 ] = 67 ;
			hops[ 5 ] = 66 ;
			hops[ 6 ] = 65 ;
			hops[ 7 ] = 64 ;
			hops[ 8 ] = 54 ;
			hops[ 9 ] = 44 ;
			hops[ 10 ] = 34 ;
			hops[ 11 ] = 24 ;
			return 12 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route24(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 25: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 25 ;
			return 1 ;
		}
		case 83: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 83 ;
			hops[ 1 ] = 73 ;
			hops[ 2 ] = 74 ;
			hops[ 3 ] = 64 ;
			hops[ 4 ] = 54 ;
			hops[ 5 ] = 44 ;
			hops[ 6 ] = 34 ;
			return 7 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route25(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 85: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 85 ;
			hops[ 1 ] = 75 ;
			hops[ 2 ] = 65 ;
			hops[ 3 ] = 55 ;
			hops[ 4 ] = 45 ;
			hops[ 5 ] = 35 ;
			return 6 ;
		}
		case 24: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 24 ;
			return 1 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route26(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 43: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 43 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 34 ;
			hops[ 3 ] = 35 ;
			hops[ 4 ] = 25 ;
			return 5 ;
		}
		case 14: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 14 ;
			hops[ 1 ] = 15 ;
			hops[ 2 ] = 16 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route27(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 81: {
			if (max_len < 12 ) return -1;
			hops[ 0 ] = 81 ;
			hops[ 1 ] = 82 ;
			hops[ 2 ] = 72 ;
			hops[ 3 ] = 73 ;
			hops[ 4 ] = 74 ;
			hops[ 5 ] = 64 ;
			hops[ 6 ] = 65 ;
			hops[ 7 ] = 66 ;
			hops[ 8 ] = 67 ;
			hops[ 9 ] = 57 ;
			hops[ 10 ] = 47 ;
			hops[ 11 ] = 37 ;
			return 12 ;
		}
		case 41: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 41 ;
			hops[ 1 ] = 42 ;
			hops[ 2 ] = 32 ;
			hops[ 3 ] = 33 ;
			hops[ 4 ] = 34 ;
			hops[ 5 ] = 35 ;
			hops[ 6 ] = 36 ;
			hops[ 7 ] = 26 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route28(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 37: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 37 ;
			hops[ 1 ] = 27 ;
			return 2 ;
		}
		case 95: {
			if (max_len < 10 ) return -1;
			hops[ 0 ] = 95 ;
			hops[ 1 ] = 96 ;
			hops[ 2 ] = 97 ;
			hops[ 3 ] = 98 ;
			hops[ 4 ] = 88 ;
			hops[ 5 ] = 78 ;
			hops[ 6 ] = 68 ;
			hops[ 7 ] = 58 ;
			hops[ 8 ] = 48 ;
			hops[ 9 ] = 38 ;
			return 10 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route29(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 65: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 65 ;
			hops[ 1 ] = 66 ;
			hops[ 2 ] = 67 ;
			hops[ 3 ] = 68 ;
			hops[ 4 ] = 69 ;
			hops[ 5 ] = 59 ;
			hops[ 6 ] = 49 ;
			hops[ 7 ] = 39 ;
			return 8 ;
		}
		case 35: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 35 ;
			hops[ 1 ] = 36 ;
			hops[ 2 ] = 37 ;
			hops[ 3 ] = 27 ;
			hops[ 4 ] = 28 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route30(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 46: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 46 ;
			hops[ 1 ] = 36 ;
			hops[ 2 ] = 35 ;
			hops[ 3 ] = 34 ;
			hops[ 4 ] = 33 ;
			hops[ 5 ] = 32 ;
			hops[ 6 ] = 31 ;
			return 7 ;
		}
		case 11: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 11 ;
			hops[ 1 ] = 10 ;
			hops[ 2 ] = 20 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route31(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 59: {
			if (max_len < 10 ) return -1;
			hops[ 0 ] = 59 ;
			hops[ 1 ] = 49 ;
			hops[ 2 ] = 39 ;
			hops[ 3 ] = 38 ;
			hops[ 4 ] = 37 ;
			hops[ 5 ] = 36 ;
			hops[ 6 ] = 35 ;
			hops[ 7 ] = 34 ;
			hops[ 8 ] = 33 ;
			hops[ 9 ] = 32 ;
			return 10 ;
		}
		case 65: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 65 ;
			hops[ 1 ] = 64 ;
			hops[ 2 ] = 54 ;
			hops[ 3 ] = 44 ;
			hops[ 4 ] = 34 ;
			hops[ 5 ] = 33 ;
			hops[ 6 ] = 32 ;
			return 7 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route32(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 44: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 44 ;
			hops[ 1 ] = 34 ;
			hops[ 2 ] = 33 ;
			return 3 ;
		}
		case 10: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 10 ;
			hops[ 1 ] = 11 ;
			hops[ 2 ] = 12 ;
			hops[ 3 ] = 22 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route33(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 13: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 13 ;
			hops[ 1 ] = 23 ;
			return 2 ;
		}
		case 94: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 94 ;
			hops[ 1 ] = 84 ;
			hops[ 2 ] = 74 ;
			hops[ 3 ] = 64 ;
			hops[ 4 ] = 54 ;
			hops[ 5 ] = 44 ;
			hops[ 6 ] = 34 ;
			return 7 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route34(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 53: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 53 ;
			hops[ 1 ] = 43 ;
			hops[ 2 ] = 33 ;
			return 3 ;
		}
		case 4: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 4 ;
			hops[ 1 ] = 14 ;
			hops[ 2 ] = 24 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route35(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 29: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 29 ;
			hops[ 1 ] = 39 ;
			hops[ 2 ] = 38 ;
			hops[ 3 ] = 37 ;
			hops[ 4 ] = 36 ;
			return 5 ;
		}
		case 67: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 67 ;
			hops[ 1 ] = 66 ;
			hops[ 2 ] = 65 ;
			hops[ 3 ] = 55 ;
			hops[ 4 ] = 45 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route36(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 49: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 49 ;
			hops[ 1 ] = 39 ;
			hops[ 2 ] = 38 ;
			hops[ 3 ] = 37 ;
			return 4 ;
		}
		case 93: {
			if (max_len < 9 ) return -1;
			hops[ 0 ] = 93 ;
			hops[ 1 ] = 83 ;
			hops[ 2 ] = 73 ;
			hops[ 3 ] = 74 ;
			hops[ 4 ] = 64 ;
			hops[ 5 ] = 65 ;
			hops[ 6 ] = 66 ;
			hops[ 7 ] = 56 ;
			hops[ 8 ] = 46 ;
			return 9 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route37(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 55: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 55 ;
			hops[ 1 ] = 45 ;
			hops[ 2 ] = 35 ;
			hops[ 3 ] = 36 ;
			return 4 ;
		}
		case 28: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 28 ;
			hops[ 1 ] = 27 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route38(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 78: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 78 ;
			hops[ 1 ] = 68 ;
			hops[ 2 ] = 58 ;
			hops[ 3 ] = 48 ;
			return 4 ;
		}
		case 90: {
			if (max_len < 14 ) return -1;
			hops[ 0 ] = 90 ;
			hops[ 1 ] = 80 ;
			hops[ 2 ] = 81 ;
			hops[ 3 ] = 82 ;
			hops[ 4 ] = 72 ;
			hops[ 5 ] = 73 ;
			hops[ 6 ] = 74 ;
			hops[ 7 ] = 64 ;
			hops[ 8 ] = 65 ;
			hops[ 9 ] = 66 ;
			hops[ 10 ] = 67 ;
			hops[ 11 ] = 68 ;
			hops[ 12 ] = 58 ;
			hops[ 13 ] = 48 ;
			return 14 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route39(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 68: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 68 ;
			hops[ 1 ] = 69 ;
			hops[ 2 ] = 59 ;
			hops[ 3 ] = 49 ;
			return 4 ;
		}
		case 46: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 46 ;
			hops[ 1 ] = 36 ;
			hops[ 2 ] = 37 ;
			hops[ 3 ] = 38 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route40(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 11: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 11 ;
			hops[ 1 ] = 10 ;
			hops[ 2 ] = 20 ;
			hops[ 3 ] = 30 ;
			return 4 ;
		}
		case 60: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 60 ;
			hops[ 1 ] = 50 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route41(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 27: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 27 ;
			hops[ 1 ] = 37 ;
			hops[ 2 ] = 36 ;
			hops[ 3 ] = 35 ;
			hops[ 4 ] = 34 ;
			hops[ 5 ] = 33 ;
			hops[ 6 ] = 32 ;
			hops[ 7 ] = 42 ;
			return 8 ;
		}
		case 62: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 62 ;
			hops[ 1 ] = 52 ;
			hops[ 2 ] = 42 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route42(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 9: {
			if (max_len < 11 ) return -1;
			hops[ 0 ] = 9 ;
			hops[ 1 ] = 8 ;
			hops[ 2 ] = 7 ;
			hops[ 3 ] = 6 ;
			hops[ 4 ] = 5 ;
			hops[ 5 ] = 4 ;
			hops[ 6 ] = 3 ;
			hops[ 7 ] = 2 ;
			hops[ 8 ] = 12 ;
			hops[ 9 ] = 22 ;
			hops[ 10 ] = 32 ;
			return 11 ;
		}
		case 77: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 77 ;
			hops[ 1 ] = 67 ;
			hops[ 2 ] = 66 ;
			hops[ 3 ] = 65 ;
			hops[ 4 ] = 64 ;
			hops[ 5 ] = 54 ;
			hops[ 6 ] = 44 ;
			hops[ 7 ] = 43 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route43(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 74: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 74 ;
			hops[ 1 ] = 64 ;
			hops[ 2 ] = 54 ;
			hops[ 3 ] = 44 ;
			return 4 ;
		}
		case 26: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 26 ;
			hops[ 1 ] = 36 ;
			hops[ 2 ] = 35 ;
			hops[ 3 ] = 34 ;
			hops[ 4 ] = 33 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route44(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 7: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 7 ;
			hops[ 1 ] = 6 ;
			hops[ 2 ] = 5 ;
			hops[ 3 ] = 4 ;
			hops[ 4 ] = 14 ;
			hops[ 5 ] = 24 ;
			hops[ 6 ] = 34 ;
			return 7 ;
		}
		case 32: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 32 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 34 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route45(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 99: {
			if (max_len < 9 ) return -1;
			hops[ 0 ] = 99 ;
			hops[ 1 ] = 98 ;
			hops[ 2 ] = 97 ;
			hops[ 3 ] = 96 ;
			hops[ 4 ] = 86 ;
			hops[ 5 ] = 76 ;
			hops[ 6 ] = 66 ;
			hops[ 7 ] = 65 ;
			hops[ 8 ] = 55 ;
			return 9 ;
		}
		case 23: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 23 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 34 ;
			hops[ 3 ] = 35 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route46(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 39: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 39 ;
			hops[ 1 ] = 38 ;
			hops[ 2 ] = 37 ;
			hops[ 3 ] = 36 ;
			return 4 ;
		}
		case 30: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 30 ;
			hops[ 1 ] = 40 ;
			hops[ 2 ] = 41 ;
			hops[ 3 ] = 42 ;
			hops[ 4 ] = 43 ;
			hops[ 5 ] = 44 ;
			hops[ 6 ] = 45 ;
			return 7 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route47(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 75: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 75 ;
			hops[ 1 ] = 65 ;
			hops[ 2 ] = 66 ;
			hops[ 3 ] = 67 ;
			hops[ 4 ] = 57 ;
			return 5 ;
		}
		case 78: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 78 ;
			hops[ 1 ] = 68 ;
			hops[ 2 ] = 67 ;
			hops[ 3 ] = 57 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route48(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 5: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 5 ;
			hops[ 1 ] = 6 ;
			hops[ 2 ] = 7 ;
			hops[ 3 ] = 8 ;
			hops[ 4 ] = 18 ;
			hops[ 5 ] = 28 ;
			hops[ 6 ] = 38 ;
			return 7 ;
		}
		case 96: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 96 ;
			hops[ 1 ] = 97 ;
			hops[ 2 ] = 98 ;
			hops[ 3 ] = 88 ;
			hops[ 4 ] = 78 ;
			hops[ 5 ] = 68 ;
			hops[ 6 ] = 58 ;
			return 7 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route49(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 96: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 96 ;
			hops[ 1 ] = 97 ;
			hops[ 2 ] = 98 ;
			hops[ 3 ] = 99 ;
			hops[ 4 ] = 89 ;
			hops[ 5 ] = 79 ;
			hops[ 6 ] = 69 ;
			hops[ 7 ] = 59 ;
			return 8 ;
		}
		case 36: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 36 ;
			hops[ 1 ] = 37 ;
			hops[ 2 ] = 38 ;
			hops[ 3 ] = 48 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route50(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 15: {
			if (max_len < 9 ) return -1;
			hops[ 0 ] = 15 ;
			hops[ 1 ] = 14 ;
			hops[ 2 ] = 13 ;
			hops[ 3 ] = 12 ;
			hops[ 4 ] = 11 ;
			hops[ 5 ] = 10 ;
			hops[ 6 ] = 20 ;
			hops[ 7 ] = 30 ;
			hops[ 8 ] = 40 ;
			return 9 ;
		}
		case 99: {
			if (max_len < 13 ) return -1;
			hops[ 0 ] = 99 ;
			hops[ 1 ] = 89 ;
			hops[ 2 ] = 79 ;
			hops[ 3 ] = 78 ;
			hops[ 4 ] = 77 ;
			hops[ 5 ] = 67 ;
			hops[ 6 ] = 66 ;
			hops[ 7 ] = 65 ;
			hops[ 8 ] = 64 ;
			hops[ 9 ] = 54 ;
			hops[ 10 ] = 53 ;
			hops[ 11 ] = 52 ;
			hops[ 12 ] = 51 ;
			return 13 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route51(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 72: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 72 ;
			hops[ 1 ] = 71 ;
			hops[ 2 ] = 61 ;
			return 3 ;
		}
		case 64: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 64 ;
			hops[ 1 ] = 54 ;
			hops[ 2 ] = 53 ;
			hops[ 3 ] = 52 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route52(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 10: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 10 ;
			hops[ 1 ] = 11 ;
			hops[ 2 ] = 12 ;
			hops[ 3 ] = 22 ;
			hops[ 4 ] = 32 ;
			hops[ 5 ] = 42 ;
			return 6 ;
		}
		case 63: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 63 ;
			hops[ 1 ] = 53 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route53(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 63: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 63 ;
			return 1 ;
		}
		case 34: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 34 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 43 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route54(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 82: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 82 ;
			hops[ 1 ] = 72 ;
			hops[ 2 ] = 73 ;
			hops[ 3 ] = 74 ;
			hops[ 4 ] = 64 ;
			return 5 ;
		}
		case 88: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 88 ;
			hops[ 1 ] = 78 ;
			hops[ 2 ] = 68 ;
			hops[ 3 ] = 67 ;
			hops[ 4 ] = 66 ;
			hops[ 5 ] = 65 ;
			hops[ 6 ] = 64 ;
			return 7 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route55(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 91: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 91 ;
			hops[ 1 ] = 81 ;
			hops[ 2 ] = 71 ;
			hops[ 3 ] = 72 ;
			hops[ 4 ] = 73 ;
			hops[ 5 ] = 74 ;
			hops[ 6 ] = 64 ;
			hops[ 7 ] = 65 ;
			return 8 ;
		}
		case 37: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 37 ;
			hops[ 1 ] = 36 ;
			hops[ 2 ] = 35 ;
			hops[ 3 ] = 45 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route56(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 12: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 12 ;
			hops[ 1 ] = 13 ;
			hops[ 2 ] = 14 ;
			hops[ 3 ] = 24 ;
			hops[ 4 ] = 34 ;
			hops[ 5 ] = 35 ;
			hops[ 6 ] = 36 ;
			hops[ 7 ] = 46 ;
			return 8 ;
		}
		case 81: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 81 ;
			hops[ 1 ] = 71 ;
			hops[ 2 ] = 72 ;
			hops[ 3 ] = 73 ;
			hops[ 4 ] = 74 ;
			hops[ 5 ] = 64 ;
			hops[ 6 ] = 65 ;
			hops[ 7 ] = 66 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route57(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 19: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 19 ;
			hops[ 1 ] = 18 ;
			hops[ 2 ] = 17 ;
			hops[ 3 ] = 27 ;
			hops[ 4 ] = 37 ;
			hops[ 5 ] = 47 ;
			return 6 ;
		}
		case 87: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 87 ;
			hops[ 1 ] = 77 ;
			hops[ 2 ] = 67 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route58(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 95: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 95 ;
			hops[ 1 ] = 96 ;
			hops[ 2 ] = 97 ;
			hops[ 3 ] = 98 ;
			hops[ 4 ] = 88 ;
			hops[ 5 ] = 78 ;
			hops[ 6 ] = 68 ;
			return 7 ;
		}
		case 21: {
			if (max_len < 10 ) return -1;
			hops[ 0 ] = 21 ;
			hops[ 1 ] = 22 ;
			hops[ 2 ] = 32 ;
			hops[ 3 ] = 33 ;
			hops[ 4 ] = 34 ;
			hops[ 5 ] = 44 ;
			hops[ 6 ] = 45 ;
			hops[ 7 ] = 46 ;
			hops[ 8 ] = 47 ;
			hops[ 9 ] = 48 ;
			return 10 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route59(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 60: {
			if (max_len < 10 ) return -1;
			hops[ 0 ] = 60 ;
			hops[ 1 ] = 50 ;
			hops[ 2 ] = 51 ;
			hops[ 3 ] = 52 ;
			hops[ 4 ] = 53 ;
			hops[ 5 ] = 54 ;
			hops[ 6 ] = 55 ;
			hops[ 7 ] = 56 ;
			hops[ 8 ] = 57 ;
			hops[ 9 ] = 58 ;
			return 10 ;
		}
		case 31: {
			if (max_len < 10 ) return -1;
			hops[ 0 ] = 31 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 33 ;
			hops[ 3 ] = 34 ;
			hops[ 4 ] = 35 ;
			hops[ 5 ] = 36 ;
			hops[ 6 ] = 37 ;
			hops[ 7 ] = 38 ;
			hops[ 8 ] = 48 ;
			hops[ 9 ] = 49 ;
			return 10 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route60(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 40: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 40 ;
			hops[ 1 ] = 50 ;
			return 2 ;
		}
		case 59: {
			if (max_len < 10 ) return -1;
			hops[ 0 ] = 59 ;
			hops[ 1 ] = 69 ;
			hops[ 2 ] = 68 ;
			hops[ 3 ] = 67 ;
			hops[ 4 ] = 66 ;
			hops[ 5 ] = 65 ;
			hops[ 6 ] = 64 ;
			hops[ 7 ] = 63 ;
			hops[ 8 ] = 62 ;
			hops[ 9 ] = 61 ;
			return 10 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route61(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 67: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 67 ;
			hops[ 1 ] = 66 ;
			hops[ 2 ] = 65 ;
			hops[ 3 ] = 64 ;
			hops[ 4 ] = 63 ;
			hops[ 5 ] = 62 ;
			return 6 ;
		}
		case 98: {
			if (max_len < 10 ) return -1;
			hops[ 0 ] = 98 ;
			hops[ 1 ] = 97 ;
			hops[ 2 ] = 96 ;
			hops[ 3 ] = 86 ;
			hops[ 4 ] = 76 ;
			hops[ 5 ] = 66 ;
			hops[ 6 ] = 65 ;
			hops[ 7 ] = 64 ;
			hops[ 8 ] = 63 ;
			hops[ 9 ] = 62 ;
			return 10 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route62(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 73: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 73 ;
			hops[ 1 ] = 72 ;
			return 2 ;
		}
		case 41: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 41 ;
			hops[ 1 ] = 42 ;
			hops[ 2 ] = 52 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route63(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 52: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 52 ;
			hops[ 1 ] = 53 ;
			return 2 ;
		}
		case 53: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 53 ;
			return 1 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route64(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 51: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 51 ;
			hops[ 1 ] = 52 ;
			hops[ 2 ] = 53 ;
			hops[ 3 ] = 54 ;
			return 4 ;
		}
		case 17: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 17 ;
			hops[ 1 ] = 16 ;
			hops[ 2 ] = 15 ;
			hops[ 3 ] = 14 ;
			hops[ 4 ] = 24 ;
			hops[ 5 ] = 34 ;
			hops[ 6 ] = 44 ;
			hops[ 7 ] = 54 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route65(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 31: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 31 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 33 ;
			hops[ 3 ] = 34 ;
			hops[ 4 ] = 35 ;
			hops[ 5 ] = 45 ;
			hops[ 6 ] = 55 ;
			return 7 ;
		}
		case 29: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 29 ;
			hops[ 1 ] = 39 ;
			hops[ 2 ] = 38 ;
			hops[ 3 ] = 37 ;
			hops[ 4 ] = 36 ;
			hops[ 5 ] = 35 ;
			hops[ 6 ] = 45 ;
			hops[ 7 ] = 55 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route66(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 80: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 80 ;
			hops[ 1 ] = 70 ;
			hops[ 2 ] = 71 ;
			hops[ 3 ] = 72 ;
			hops[ 4 ] = 73 ;
			hops[ 5 ] = 74 ;
			hops[ 6 ] = 64 ;
			hops[ 7 ] = 65 ;
			return 8 ;
		}
		case 91: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 91 ;
			hops[ 1 ] = 81 ;
			hops[ 2 ] = 71 ;
			hops[ 3 ] = 72 ;
			hops[ 4 ] = 73 ;
			hops[ 5 ] = 74 ;
			hops[ 6 ] = 64 ;
			hops[ 7 ] = 65 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route67(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 35: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 35 ;
			hops[ 1 ] = 36 ;
			hops[ 2 ] = 37 ;
			hops[ 3 ] = 47 ;
			hops[ 4 ] = 57 ;
			return 5 ;
		}
		case 61: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 61 ;
			hops[ 1 ] = 62 ;
			hops[ 2 ] = 63 ;
			hops[ 3 ] = 64 ;
			hops[ 4 ] = 65 ;
			hops[ 5 ] = 66 ;
			return 6 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route68(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 94: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 94 ;
			hops[ 1 ] = 84 ;
			hops[ 2 ] = 74 ;
			hops[ 3 ] = 64 ;
			hops[ 4 ] = 65 ;
			hops[ 5 ] = 66 ;
			hops[ 6 ] = 67 ;
			return 7 ;
		}
		case 39: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 39 ;
			hops[ 1 ] = 38 ;
			hops[ 2 ] = 48 ;
			hops[ 3 ] = 58 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route69(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 73: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 73 ;
			hops[ 1 ] = 74 ;
			hops[ 2 ] = 64 ;
			hops[ 3 ] = 65 ;
			hops[ 4 ] = 66 ;
			hops[ 5 ] = 67 ;
			hops[ 6 ] = 68 ;
			return 7 ;
		}
		case 76: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 76 ;
			hops[ 1 ] = 66 ;
			hops[ 2 ] = 67 ;
			hops[ 3 ] = 68 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route70(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 83: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 83 ;
			hops[ 1 ] = 73 ;
			hops[ 2 ] = 72 ;
			hops[ 3 ] = 71 ;
			return 4 ;
		}
		case 16: {
			if (max_len < 12 ) return -1;
			hops[ 0 ] = 16 ;
			hops[ 1 ] = 15 ;
			hops[ 2 ] = 14 ;
			hops[ 3 ] = 13 ;
			hops[ 4 ] = 12 ;
			hops[ 5 ] = 11 ;
			hops[ 6 ] = 10 ;
			hops[ 7 ] = 20 ;
			hops[ 8 ] = 30 ;
			hops[ 9 ] = 40 ;
			hops[ 10 ] = 50 ;
			hops[ 11 ] = 60 ;
			return 12 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route71(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 84: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 84 ;
			hops[ 1 ] = 74 ;
			hops[ 2 ] = 73 ;
			hops[ 3 ] = 72 ;
			return 4 ;
		}
		case 8: {
			if (max_len < 14 ) return -1;
			hops[ 0 ] = 8 ;
			hops[ 1 ] = 18 ;
			hops[ 2 ] = 17 ;
			hops[ 3 ] = 16 ;
			hops[ 4 ] = 15 ;
			hops[ 5 ] = 14 ;
			hops[ 6 ] = 13 ;
			hops[ 7 ] = 23 ;
			hops[ 8 ] = 33 ;
			hops[ 9 ] = 32 ;
			hops[ 10 ] = 42 ;
			hops[ 11 ] = 41 ;
			hops[ 12 ] = 51 ;
			hops[ 13 ] = 61 ;
			return 14 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route72(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 14: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 14 ;
			hops[ 1 ] = 13 ;
			hops[ 2 ] = 23 ;
			hops[ 3 ] = 33 ;
			hops[ 4 ] = 32 ;
			hops[ 5 ] = 42 ;
			hops[ 6 ] = 52 ;
			hops[ 7 ] = 62 ;
			return 8 ;
		}
		case 51: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 51 ;
			hops[ 1 ] = 52 ;
			hops[ 2 ] = 62 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route73(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 62: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 62 ;
			hops[ 1 ] = 72 ;
			return 2 ;
		}
		case 69: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 69 ;
			hops[ 1 ] = 68 ;
			hops[ 2 ] = 67 ;
			hops[ 3 ] = 66 ;
			hops[ 4 ] = 65 ;
			hops[ 5 ] = 64 ;
			hops[ 6 ] = 74 ;
			return 7 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route74(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 76: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 76 ;
			hops[ 1 ] = 75 ;
			return 2 ;
		}
		case 43: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 43 ;
			hops[ 1 ] = 44 ;
			hops[ 2 ] = 54 ;
			hops[ 3 ] = 64 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route75(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 88: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 88 ;
			hops[ 1 ] = 78 ;
			hops[ 2 ] = 77 ;
			hops[ 3 ] = 76 ;
			return 4 ;
		}
		case 47: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 47 ;
			hops[ 1 ] = 46 ;
			hops[ 2 ] = 45 ;
			hops[ 3 ] = 55 ;
			hops[ 4 ] = 65 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route76(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 69: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 69 ;
			hops[ 1 ] = 68 ;
			hops[ 2 ] = 67 ;
			hops[ 3 ] = 66 ;
			return 4 ;
		}
		case 74: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 74 ;
			hops[ 1 ] = 75 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route77(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 42: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 42 ;
			hops[ 1 ] = 43 ;
			hops[ 2 ] = 44 ;
			hops[ 3 ] = 45 ;
			hops[ 4 ] = 46 ;
			hops[ 5 ] = 47 ;
			hops[ 6 ] = 57 ;
			hops[ 7 ] = 67 ;
			return 8 ;
		}
		case 20: {
			if (max_len < 12 ) return -1;
			hops[ 0 ] = 20 ;
			hops[ 1 ] = 21 ;
			hops[ 2 ] = 22 ;
			hops[ 3 ] = 32 ;
			hops[ 4 ] = 33 ;
			hops[ 5 ] = 34 ;
			hops[ 6 ] = 35 ;
			hops[ 7 ] = 36 ;
			hops[ 8 ] = 37 ;
			hops[ 9 ] = 47 ;
			hops[ 10 ] = 57 ;
			hops[ 11 ] = 67 ;
			return 12 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route78(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 47: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 47 ;
			hops[ 1 ] = 48 ;
			hops[ 2 ] = 58 ;
			hops[ 3 ] = 68 ;
			return 4 ;
		}
		case 38: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 38 ;
			hops[ 1 ] = 48 ;
			hops[ 2 ] = 58 ;
			hops[ 3 ] = 68 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route79(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 8: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 8 ;
			hops[ 1 ] = 9 ;
			hops[ 2 ] = 19 ;
			hops[ 3 ] = 29 ;
			hops[ 4 ] = 39 ;
			hops[ 5 ] = 49 ;
			hops[ 6 ] = 59 ;
			hops[ 7 ] = 69 ;
			return 8 ;
		}
		case 19: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 19 ;
			hops[ 1 ] = 29 ;
			hops[ 2 ] = 39 ;
			hops[ 3 ] = 49 ;
			hops[ 4 ] = 59 ;
			hops[ 5 ] = 69 ;
			return 6 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route80(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 0: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 0 ;
			hops[ 1 ] = 10 ;
			hops[ 2 ] = 20 ;
			hops[ 3 ] = 30 ;
			hops[ 4 ] = 40 ;
			hops[ 5 ] = 50 ;
			hops[ 6 ] = 60 ;
			hops[ 7 ] = 70 ;
			return 8 ;
		}
		case 66: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 66 ;
			hops[ 1 ] = 65 ;
			hops[ 2 ] = 64 ;
			hops[ 3 ] = 74 ;
			hops[ 4 ] = 73 ;
			hops[ 5 ] = 72 ;
			hops[ 6 ] = 82 ;
			hops[ 7 ] = 81 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route81(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 56: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 56 ;
			hops[ 1 ] = 66 ;
			hops[ 2 ] = 65 ;
			hops[ 3 ] = 64 ;
			hops[ 4 ] = 74 ;
			hops[ 5 ] = 73 ;
			hops[ 6 ] = 72 ;
			hops[ 7 ] = 82 ;
			return 8 ;
		}
		case 27: {
			if (max_len < 12 ) return -1;
			hops[ 0 ] = 27 ;
			hops[ 1 ] = 37 ;
			hops[ 2 ] = 36 ;
			hops[ 3 ] = 35 ;
			hops[ 4 ] = 34 ;
			hops[ 5 ] = 33 ;
			hops[ 6 ] = 32 ;
			hops[ 7 ] = 42 ;
			hops[ 8 ] = 41 ;
			hops[ 9 ] = 51 ;
			hops[ 10 ] = 61 ;
			hops[ 11 ] = 71 ;
			return 12 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route82(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 17: {
			if (max_len < 12 ) return -1;
			hops[ 0 ] = 17 ;
			hops[ 1 ] = 16 ;
			hops[ 2 ] = 15 ;
			hops[ 3 ] = 14 ;
			hops[ 4 ] = 13 ;
			hops[ 5 ] = 12 ;
			hops[ 6 ] = 22 ;
			hops[ 7 ] = 32 ;
			hops[ 8 ] = 42 ;
			hops[ 9 ] = 52 ;
			hops[ 10 ] = 62 ;
			hops[ 11 ] = 72 ;
			return 12 ;
		}
		case 54: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 54 ;
			hops[ 1 ] = 64 ;
			hops[ 2 ] = 74 ;
			hops[ 3 ] = 73 ;
			hops[ 4 ] = 72 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route83(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 24: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 24 ;
			hops[ 1 ] = 34 ;
			hops[ 2 ] = 33 ;
			hops[ 3 ] = 43 ;
			hops[ 4 ] = 53 ;
			hops[ 5 ] = 63 ;
			hops[ 6 ] = 73 ;
			return 7 ;
		}
		case 70: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 70 ;
			hops[ 1 ] = 71 ;
			hops[ 2 ] = 72 ;
			hops[ 3 ] = 73 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route84(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 4: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 4 ;
			hops[ 1 ] = 14 ;
			hops[ 2 ] = 24 ;
			hops[ 3 ] = 34 ;
			hops[ 4 ] = 44 ;
			hops[ 5 ] = 54 ;
			hops[ 6 ] = 64 ;
			hops[ 7 ] = 74 ;
			return 8 ;
		}
		case 71: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 71 ;
			hops[ 1 ] = 72 ;
			hops[ 2 ] = 73 ;
			hops[ 3 ] = 74 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route85(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 86: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 86 ;
			return 1 ;
		}
		case 25: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 25 ;
			hops[ 1 ] = 35 ;
			hops[ 2 ] = 45 ;
			hops[ 3 ] = 55 ;
			hops[ 4 ] = 65 ;
			hops[ 5 ] = 75 ;
			return 6 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route86(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 6: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 6 ;
			hops[ 1 ] = 16 ;
			hops[ 2 ] = 26 ;
			hops[ 3 ] = 36 ;
			hops[ 4 ] = 46 ;
			hops[ 5 ] = 56 ;
			hops[ 6 ] = 66 ;
			hops[ 7 ] = 76 ;
			return 8 ;
		}
		case 85: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 85 ;
			return 1 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route87(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 57: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 57 ;
			hops[ 1 ] = 67 ;
			hops[ 2 ] = 77 ;
			return 3 ;
		}
		case 2: {
			if (max_len < 13 ) return -1;
			hops[ 0 ] = 2 ;
			hops[ 1 ] = 3 ;
			hops[ 2 ] = 4 ;
			hops[ 3 ] = 5 ;
			hops[ 4 ] = 6 ;
			hops[ 5 ] = 7 ;
			hops[ 6 ] = 17 ;
			hops[ 7 ] = 27 ;
			hops[ 8 ] = 37 ;
			hops[ 9 ] = 47 ;
			hops[ 10 ] = 57 ;
			hops[ 11 ] = 67 ;
			hops[ 12 ] = 77 ;
			return 13 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route88(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 54: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 54 ;
			hops[ 1 ] = 64 ;
			hops[ 2 ] = 65 ;
			hops[ 3 ] = 66 ;
			hops[ 4 ] = 67 ;
			hops[ 5 ] = 68 ;
			hops[ 6 ] = 78 ;
			return 7 ;
		}
		case 75: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 75 ;
			hops[ 1 ] = 76 ;
			hops[ 2 ] = 77 ;
			hops[ 3 ] = 78 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route89(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 23: {
			if (max_len < 12 ) return -1;
			hops[ 0 ] = 23 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 34 ;
			hops[ 3 ] = 35 ;
			hops[ 4 ] = 36 ;
			hops[ 5 ] = 37 ;
			hops[ 6 ] = 38 ;
			hops[ 7 ] = 39 ;
			hops[ 8 ] = 49 ;
			hops[ 9 ] = 59 ;
			hops[ 10 ] = 69 ;
			hops[ 11 ] = 79 ;
			return 12 ;
		}
		case 97: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 97 ;
			hops[ 1 ] = 98 ;
			hops[ 2 ] = 88 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route90(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 38: {
			if (max_len < 14 ) return -1;
			hops[ 0 ] = 38 ;
			hops[ 1 ] = 37 ;
			hops[ 2 ] = 36 ;
			hops[ 3 ] = 35 ;
			hops[ 4 ] = 34 ;
			hops[ 5 ] = 33 ;
			hops[ 6 ] = 32 ;
			hops[ 7 ] = 42 ;
			hops[ 8 ] = 41 ;
			hops[ 9 ] = 40 ;
			hops[ 10 ] = 50 ;
			hops[ 11 ] = 60 ;
			hops[ 12 ] = 70 ;
			hops[ 13 ] = 80 ;
			return 14 ;
		}
		case 0: {
			if (max_len < 9 ) return -1;
			hops[ 0 ] = 0 ;
			hops[ 1 ] = 10 ;
			hops[ 2 ] = 20 ;
			hops[ 3 ] = 30 ;
			hops[ 4 ] = 40 ;
			hops[ 5 ] = 50 ;
			hops[ 6 ] = 60 ;
			hops[ 7 ] = 70 ;
			hops[ 8 ] = 80 ;
			return 9 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route91(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 66: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 66 ;
			hops[ 1 ] = 65 ;
			hops[ 2 ] = 64 ;
			hops[ 3 ] = 74 ;
			hops[ 4 ] = 73 ;
			hops[ 5 ] = 72 ;
			hops[ 6 ] = 82 ;
			hops[ 7 ] = 81 ;
			return 8 ;
		}
		case 55: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 55 ;
			hops[ 1 ] = 65 ;
			hops[ 2 ] = 64 ;
			hops[ 3 ] = 74 ;
			hops[ 4 ] = 73 ;
			hops[ 5 ] = 72 ;
			hops[ 6 ] = 82 ;
			hops[ 7 ] = 81 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route92(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 98: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 98 ;
			hops[ 1 ] = 97 ;
			hops[ 2 ] = 96 ;
			hops[ 3 ] = 95 ;
			hops[ 4 ] = 94 ;
			hops[ 5 ] = 93 ;
			return 6 ;
		}
		case 18: {
			if (max_len < 14 ) return -1;
			hops[ 0 ] = 18 ;
			hops[ 1 ] = 17 ;
			hops[ 2 ] = 16 ;
			hops[ 3 ] = 15 ;
			hops[ 4 ] = 14 ;
			hops[ 5 ] = 13 ;
			hops[ 6 ] = 12 ;
			hops[ 7 ] = 22 ;
			hops[ 8 ] = 32 ;
			hops[ 9 ] = 42 ;
			hops[ 10 ] = 52 ;
			hops[ 11 ] = 62 ;
			hops[ 12 ] = 72 ;
			hops[ 13 ] = 82 ;
			return 14 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route93(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 36: {
			if (max_len < 9 ) return -1;
			hops[ 0 ] = 36 ;
			hops[ 1 ] = 35 ;
			hops[ 2 ] = 34 ;
			hops[ 3 ] = 33 ;
			hops[ 4 ] = 43 ;
			hops[ 5 ] = 53 ;
			hops[ 6 ] = 63 ;
			hops[ 7 ] = 73 ;
			hops[ 8 ] = 83 ;
			return 9 ;
		}
		case 22: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 22 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 33 ;
			hops[ 3 ] = 43 ;
			hops[ 4 ] = 53 ;
			hops[ 5 ] = 63 ;
			hops[ 6 ] = 73 ;
			hops[ 7 ] = 83 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route94(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 33: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 33 ;
			hops[ 1 ] = 34 ;
			hops[ 2 ] = 44 ;
			hops[ 3 ] = 54 ;
			hops[ 4 ] = 64 ;
			hops[ 5 ] = 74 ;
			hops[ 6 ] = 84 ;
			return 7 ;
		}
		case 68: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 68 ;
			hops[ 1 ] = 67 ;
			hops[ 2 ] = 66 ;
			hops[ 3 ] = 65 ;
			hops[ 4 ] = 64 ;
			hops[ 5 ] = 74 ;
			hops[ 6 ] = 84 ;
			return 7 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route95(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 28: {
			if (max_len < 10 ) return -1;
			hops[ 0 ] = 28 ;
			hops[ 1 ] = 38 ;
			hops[ 2 ] = 37 ;
			hops[ 3 ] = 36 ;
			hops[ 4 ] = 35 ;
			hops[ 5 ] = 45 ;
			hops[ 6 ] = 55 ;
			hops[ 7 ] = 65 ;
			hops[ 8 ] = 75 ;
			hops[ 9 ] = 85 ;
			return 10 ;
		}
		case 58: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 58 ;
			hops[ 1 ] = 68 ;
			hops[ 2 ] = 67 ;
			hops[ 3 ] = 66 ;
			hops[ 4 ] = 65 ;
			hops[ 5 ] = 75 ;
			hops[ 6 ] = 85 ;
			return 7 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route96(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 48: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 48 ;
			hops[ 1 ] = 47 ;
			hops[ 2 ] = 46 ;
			hops[ 3 ] = 56 ;
			hops[ 4 ] = 66 ;
			hops[ 5 ] = 76 ;
			hops[ 6 ] = 86 ;
			return 7 ;
		}
		case 49: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 49 ;
			hops[ 1 ] = 48 ;
			hops[ 2 ] = 47 ;
			hops[ 3 ] = 46 ;
			hops[ 4 ] = 56 ;
			hops[ 5 ] = 66 ;
			hops[ 6 ] = 76 ;
			hops[ 7 ] = 86 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route97(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 89: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 89 ;
			hops[ 1 ] = 88 ;
			hops[ 2 ] = 98 ;
			return 3 ;
		}
		case 9: {
			if (max_len < 11 ) return -1;
			hops[ 0 ] = 9 ;
			hops[ 1 ] = 8 ;
			hops[ 2 ] = 7 ;
			hops[ 3 ] = 17 ;
			hops[ 4 ] = 27 ;
			hops[ 5 ] = 37 ;
			hops[ 6 ] = 47 ;
			hops[ 7 ] = 57 ;
			hops[ 8 ] = 67 ;
			hops[ 9 ] = 77 ;
			hops[ 10 ] = 87 ;
			return 11 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route98(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 61: {
			if (max_len < 10 ) return -1;
			hops[ 0 ] = 61 ;
			hops[ 1 ] = 71 ;
			hops[ 2 ] = 72 ;
			hops[ 3 ] = 73 ;
			hops[ 4 ] = 74 ;
			hops[ 5 ] = 75 ;
			hops[ 6 ] = 76 ;
			hops[ 7 ] = 77 ;
			hops[ 8 ] = 78 ;
			hops[ 9 ] = 88 ;
			return 10 ;
		}
		case 92: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 92 ;
			hops[ 1 ] = 93 ;
			hops[ 2 ] = 94 ;
			hops[ 3 ] = 95 ;
			hops[ 4 ] = 96 ;
			hops[ 5 ] = 97 ;
			return 6 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route99(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 50: {
			if (max_len < 13 ) return -1;
			hops[ 0 ] = 50 ;
			hops[ 1 ] = 51 ;
			hops[ 2 ] = 52 ;
			hops[ 3 ] = 53 ;
			hops[ 4 ] = 54 ;
			hops[ 5 ] = 64 ;
			hops[ 6 ] = 65 ;
			hops[ 7 ] = 66 ;
			hops[ 8 ] = 67 ;
			hops[ 9 ] = 68 ;
			hops[ 10 ] = 69 ;
			hops[ 11 ] = 79 ;
			hops[ 12 ] = 89 ;
			return 13 ;
		}
		case 45: {
			if (max_len < 9 ) return -1;
			hops[ 0 ] = 45 ;
			hops[ 1 ] = 46 ;
			hops[ 2 ] = 47 ;
			hops[ 3 ] = 48 ;
			hops[ 4 ] = 49 ;
			hops[ 5 ] = 59 ;
			hops[ 6 ] = 69 ;
			hops[ 7 ] = 79 ;
			hops[ 8 ] = 89 ;
			return 9 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len) {
	switch (TOS_NODE_ID) {
		case 0: return fill_route0(dest,hops,max_len);
		case 1: return fill_route1(dest,hops,max_len);
		case 2: return fill_route2(dest,hops,max_len);
		case 3: return fill_route3(dest,hops,max_len);
		case 4: return fill_route4(dest,hops,max_len);
		case 5: return fill_route5(dest,hops,max_len);
		case 6: return fill_route6(dest,hops,max_len);
		case 7: return fill_route7(dest,hops,max_len);
		case 8: return fill_route8(dest,hops,max_len);
		case 9: return fill_route9(dest,hops,max_len);
		case 10: return fill_route10(dest,hops,max_len);
		case 11: return fill_route11(dest,hops,max_len);
		case 12: return fill_route12(dest,hops,max_len);
		case 13: return fill_route13(dest,hops,max_len);
		case 14: return fill_route14(dest,hops,max_len);
		case 15: return fill_route15(dest,hops,max_len);
		case 16: return fill_route16(dest,hops,max_len);
		case 17: return fill_route17(dest,hops,max_len);
		case 18: return fill_route18(dest,hops,max_len);
		case 19: return fill_route19(dest,hops,max_len);
		case 20: return fill_route20(dest,hops,max_len);
		case 21: return fill_route21(dest,hops,max_len);
		case 22: return fill_route22(dest,hops,max_len);
		case 23: return fill_route23(dest,hops,max_len);
		case 24: return fill_route24(dest,hops,max_len);
		case 25: return fill_route25(dest,hops,max_len);
		case 26: return fill_route26(dest,hops,max_len);
		case 27: return fill_route27(dest,hops,max_len);
		case 28: return fill_route28(dest,hops,max_len);
		case 29: return fill_route29(dest,hops,max_len);
		case 30: return fill_route30(dest,hops,max_len);
		case 31: return fill_route31(dest,hops,max_len);
		case 32: return fill_route32(dest,hops,max_len);
		case 33: return fill_route33(dest,hops,max_len);
		case 34: return fill_route34(dest,hops,max_len);
		case 35: return fill_route35(dest,hops,max_len);
		case 36: return fill_route36(dest,hops,max_len);
		case 37: return fill_route37(dest,hops,max_len);
		case 38: return fill_route38(dest,hops,max_len);
		case 39: return fill_route39(dest,hops,max_len);
		case 40: return fill_route40(dest,hops,max_len);
		case 41: return fill_route41(dest,hops,max_len);
		case 42: return fill_route42(dest,hops,max_len);
		case 43: return fill_route43(dest,hops,max_len);
		case 44: return fill_route44(dest,hops,max_len);
		case 45: return fill_route45(dest,hops,max_len);
		case 46: return fill_route46(dest,hops,max_len);
		case 47: return fill_route47(dest,hops,max_len);
		case 48: return fill_route48(dest,hops,max_len);
		case 49: return fill_route49(dest,hops,max_len);
		case 50: return fill_route50(dest,hops,max_len);
		case 51: return fill_route51(dest,hops,max_len);
		case 52: return fill_route52(dest,hops,max_len);
		case 53: return fill_route53(dest,hops,max_len);
		case 54: return fill_route54(dest,hops,max_len);
		case 55: return fill_route55(dest,hops,max_len);
		case 56: return fill_route56(dest,hops,max_len);
		case 57: return fill_route57(dest,hops,max_len);
		case 58: return fill_route58(dest,hops,max_len);
		case 59: return fill_route59(dest,hops,max_len);
		case 60: return fill_route60(dest,hops,max_len);
		case 61: return fill_route61(dest,hops,max_len);
		case 62: return fill_route62(dest,hops,max_len);
		case 63: return fill_route63(dest,hops,max_len);
		case 64: return fill_route64(dest,hops,max_len);
		case 65: return fill_route65(dest,hops,max_len);
		case 66: return fill_route66(dest,hops,max_len);
		case 67: return fill_route67(dest,hops,max_len);
		case 68: return fill_route68(dest,hops,max_len);
		case 69: return fill_route69(dest,hops,max_len);
		case 70: return fill_route70(dest,hops,max_len);
		case 71: return fill_route71(dest,hops,max_len);
		case 72: return fill_route72(dest,hops,max_len);
		case 73: return fill_route73(dest,hops,max_len);
		case 74: return fill_route74(dest,hops,max_len);
		case 75: return fill_route75(dest,hops,max_len);
		case 76: return fill_route76(dest,hops,max_len);
		case 77: return fill_route77(dest,hops,max_len);
		case 78: return fill_route78(dest,hops,max_len);
		case 79: return fill_route79(dest,hops,max_len);
		case 80: return fill_route80(dest,hops,max_len);
		case 81: return fill_route81(dest,hops,max_len);
		case 82: return fill_route82(dest,hops,max_len);
		case 83: return fill_route83(dest,hops,max_len);
		case 84: return fill_route84(dest,hops,max_len);
		case 85: return fill_route85(dest,hops,max_len);
		case 86: return fill_route86(dest,hops,max_len);
		case 87: return fill_route87(dest,hops,max_len);
		case 88: return fill_route88(dest,hops,max_len);
		case 89: return fill_route89(dest,hops,max_len);
		case 90: return fill_route90(dest,hops,max_len);
		case 91: return fill_route91(dest,hops,max_len);
		case 92: return fill_route92(dest,hops,max_len);
		case 93: return fill_route93(dest,hops,max_len);
		case 94: return fill_route94(dest,hops,max_len);
		case 95: return fill_route95(dest,hops,max_len);
		case 96: return fill_route96(dest,hops,max_len);
		case 97: return fill_route97(dest,hops,max_len);
		case 98: return fill_route98(dest,hops,max_len);
		case 99: return fill_route99(dest,hops,max_len);
		default: return -1;
	}
	return -1;
}

#endif
