#ifndef _ROUTES_H_
#define _ROUTES_H_

int8_t fill_route0(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 3: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 3 ;
			hops[ 1 ] = 1 ;
			return 2 ;
		}
		case 2: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 2 ;
			return 1 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route1(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 93: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 93 ;
			hops[ 1 ] = 73 ;
			hops[ 2 ] = 71 ;
			hops[ 3 ] = 51 ;
			hops[ 4 ] = 41 ;
			hops[ 5 ] = 21 ;
			return 6 ;
		}
		case 9: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 9 ;
			hops[ 1 ] = 7 ;
			hops[ 2 ] = 5 ;
			hops[ 3 ] = 3 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route2(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 96: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 96 ;
			hops[ 1 ] = 76 ;
			hops[ 2 ] = 65 ;
			hops[ 3 ] = 64 ;
			hops[ 4 ] = 44 ;
			hops[ 5 ] = 33 ;
			hops[ 6 ] = 13 ;
			return 7 ;
		}
		case 0: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 0 ;
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
		case 0: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 0 ;
			hops[ 1 ] = 1 ;
			return 2 ;
		}
		case 6: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 6 ;
			hops[ 1 ] = 4 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route4(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 92: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 92 ;
			hops[ 1 ] = 72 ;
			hops[ 2 ] = 74 ;
			hops[ 3 ] = 64 ;
			hops[ 4 ] = 44 ;
			hops[ 5 ] = 24 ;
			return 6 ;
		}
		case 7: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 7 ;
			hops[ 1 ] = 5 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route5(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 95: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 95 ;
			hops[ 1 ] = 75 ;
			hops[ 2 ] = 65 ;
			hops[ 3 ] = 45 ;
			hops[ 4 ] = 25 ;
			return 5 ;
		}
		case 8: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 8 ;
			hops[ 1 ] = 6 ;
			return 2 ;
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
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 3 ;
			hops[ 1 ] = 4 ;
			return 2 ;
		}
		case 18: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 18 ;
			hops[ 1 ] = 7 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route7(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 4: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 4 ;
			hops[ 1 ] = 5 ;
			return 2 ;
		}
		case 11: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 11 ;
			hops[ 1 ] = 1 ;
			hops[ 2 ] = 3 ;
			hops[ 3 ] = 5 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route8(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 5: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 5 ;
			hops[ 1 ] = 6 ;
			return 2 ;
		}
		case 21: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 21 ;
			hops[ 1 ] = 1 ;
			hops[ 2 ] = 2 ;
			hops[ 3 ] = 4 ;
			hops[ 4 ] = 6 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route9(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 1: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 1 ;
			hops[ 1 ] = 3 ;
			hops[ 2 ] = 5 ;
			hops[ 3 ] = 7 ;
			return 4 ;
		}
		case 13: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 13 ;
			hops[ 1 ] = 14 ;
			hops[ 2 ] = 16 ;
			hops[ 3 ] = 18 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route10(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 97: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 97 ;
			hops[ 1 ] = 96 ;
			hops[ 2 ] = 76 ;
			hops[ 3 ] = 74 ;
			hops[ 4 ] = 72 ;
			hops[ 5 ] = 70 ;
			hops[ 6 ] = 50 ;
			hops[ 7 ] = 30 ;
			return 8 ;
		}
		case 17: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 17 ;
			hops[ 1 ] = 15 ;
			hops[ 2 ] = 13 ;
			hops[ 3 ] = 11 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route11(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 7: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 7 ;
			hops[ 1 ] = 5 ;
			hops[ 2 ] = 3 ;
			hops[ 3 ] = 1 ;
			return 4 ;
		}
		case 19: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 19 ;
			hops[ 1 ] = 17 ;
			hops[ 2 ] = 15 ;
			hops[ 3 ] = 13 ;
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
		case 98: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 98 ;
			hops[ 1 ] = 96 ;
			hops[ 2 ] = 76 ;
			hops[ 3 ] = 56 ;
			hops[ 4 ] = 36 ;
			hops[ 5 ] = 34 ;
			hops[ 6 ] = 32 ;
			return 7 ;
		}
		case 15: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 15 ;
			hops[ 1 ] = 13 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route13(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 9: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 9 ;
			hops[ 1 ] = 19 ;
			hops[ 2 ] = 17 ;
			hops[ 3 ] = 15 ;
			return 4 ;
		}
		case 16: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 16 ;
			hops[ 1 ] = 14 ;
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
		case 91: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 91 ;
			hops[ 1 ] = 71 ;
			hops[ 2 ] = 73 ;
			hops[ 3 ] = 53 ;
			hops[ 4 ] = 33 ;
			hops[ 5 ] = 34 ;
			return 6 ;
		}
		case 61: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 61 ;
			hops[ 1 ] = 41 ;
			hops[ 2 ] = 32 ;
			hops[ 3 ] = 34 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route15(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 12: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 12 ;
			hops[ 1 ] = 13 ;
			return 2 ;
		}
		case 29: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 29 ;
			hops[ 1 ] = 18 ;
			hops[ 2 ] = 16 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route16(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 13: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 13 ;
			hops[ 1 ] = 14 ;
			return 2 ;
		}
		case 20: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 20 ;
			hops[ 1 ] = 11 ;
			hops[ 2 ] = 12 ;
			hops[ 3 ] = 14 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route17(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 10: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 10 ;
			hops[ 1 ] = 12 ;
			hops[ 2 ] = 13 ;
			hops[ 3 ] = 15 ;
			return 4 ;
		}
		case 34: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 34 ;
			hops[ 1 ] = 35 ;
			hops[ 2 ] = 37 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route18(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 6: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 6 ;
			hops[ 1 ] = 7 ;
			return 2 ;
		}
		case 22: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 22 ;
			hops[ 1 ] = 12 ;
			hops[ 2 ] = 14 ;
			hops[ 3 ] = 16 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route19(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 11: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 11 ;
			hops[ 1 ] = 13 ;
			hops[ 2 ] = 15 ;
			hops[ 3 ] = 17 ;
			return 4 ;
		}
		case 23: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 23 ;
			hops[ 1 ] = 13 ;
			hops[ 2 ] = 15 ;
			hops[ 3 ] = 17 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route20(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 16: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 16 ;
			hops[ 1 ] = 14 ;
			hops[ 2 ] = 12 ;
			hops[ 3 ] = 10 ;
			return 4 ;
		}
		case 28: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 28 ;
			hops[ 1 ] = 26 ;
			hops[ 2 ] = 24 ;
			hops[ 3 ] = 22 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route21(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 8: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 8 ;
			hops[ 1 ] = 6 ;
			hops[ 2 ] = 5 ;
			hops[ 3 ] = 3 ;
			hops[ 4 ] = 1 ;
			return 5 ;
		}
		case 24: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 24 ;
			hops[ 1 ] = 22 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route22(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 18: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 18 ;
			hops[ 1 ] = 27 ;
			hops[ 2 ] = 25 ;
			hops[ 3 ] = 23 ;
			return 4 ;
		}
		case 25: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 25 ;
			hops[ 1 ] = 23 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route23(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 19: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 19 ;
			hops[ 1 ] = 17 ;
			hops[ 2 ] = 15 ;
			hops[ 3 ] = 13 ;
			return 4 ;
		}
		case 26: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 26 ;
			hops[ 1 ] = 24 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route24(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 21: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 21 ;
			hops[ 1 ] = 22 ;
			return 2 ;
		}
		case 27: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 27 ;
			hops[ 1 ] = 25 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route25(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 22: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 22 ;
			hops[ 1 ] = 23 ;
			return 2 ;
		}
		case 30: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 30 ;
			hops[ 1 ] = 21 ;
			hops[ 2 ] = 23 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route26(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 23: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 23 ;
			hops[ 1 ] = 24 ;
			return 2 ;
		}
		case 38: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 38 ;
			hops[ 1 ] = 36 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route27(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 24: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 24 ;
			hops[ 1 ] = 25 ;
			return 2 ;
		}
		case 39: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 39 ;
			hops[ 1 ] = 37 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route28(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 20: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 20 ;
			hops[ 1 ] = 22 ;
			hops[ 2 ] = 24 ;
			hops[ 3 ] = 26 ;
			return 4 ;
		}
		case 32: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 32 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 35 ;
			hops[ 3 ] = 37 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route29(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 15: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 15 ;
			hops[ 1 ] = 16 ;
			hops[ 2 ] = 18 ;
			return 3 ;
		}
		case 33: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 33 ;
			hops[ 1 ] = 34 ;
			hops[ 2 ] = 36 ;
			hops[ 3 ] = 38 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route30(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 25: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 25 ;
			hops[ 1 ] = 34 ;
			hops[ 2 ] = 32 ;
			return 3 ;
		}
		case 37: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 37 ;
			hops[ 1 ] = 35 ;
			hops[ 2 ] = 33 ;
			hops[ 3 ] = 32 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route31(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 99: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 99 ;
			hops[ 1 ] = 97 ;
			hops[ 2 ] = 77 ;
			hops[ 3 ] = 66 ;
			hops[ 4 ] = 64 ;
			hops[ 5 ] = 44 ;
			hops[ 6 ] = 33 ;
			return 7 ;
		}
		case 44: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 44 ;
			hops[ 1 ] = 33 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route32(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 28: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 28 ;
			hops[ 1 ] = 26 ;
			hops[ 2 ] = 24 ;
			hops[ 3 ] = 33 ;
			return 4 ;
		}
		case 35: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 35 ;
			hops[ 1 ] = 33 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route33(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 29: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 29 ;
			hops[ 1 ] = 27 ;
			hops[ 2 ] = 25 ;
			hops[ 3 ] = 34 ;
			return 4 ;
		}
		case 36: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 36 ;
			hops[ 1 ] = 34 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route34(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 17: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 17 ;
			hops[ 1 ] = 15 ;
			hops[ 2 ] = 35 ;
			return 3 ;
		}
		case 40: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 40 ;
			hops[ 1 ] = 30 ;
			hops[ 2 ] = 32 ;
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
		case 32: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 32 ;
			hops[ 1 ] = 33 ;
			return 2 ;
		}
		case 47: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 47 ;
			hops[ 1 ] = 36 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route36(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 33: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 33 ;
			hops[ 1 ] = 34 ;
			return 2 ;
		}
		case 41: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 41 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 34 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route37(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 30: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 30 ;
			hops[ 1 ] = 31 ;
			hops[ 2 ] = 33 ;
			hops[ 3 ] = 35 ;
			return 4 ;
		}
		case 43: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 43 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 35 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route38(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 26: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 26 ;
			hops[ 1 ] = 36 ;
			return 2 ;
		}
		case 42: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 42 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 34 ;
			hops[ 3 ] = 36 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route39(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 27: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 27 ;
			hops[ 1 ] = 37 ;
			return 2 ;
		}
		case 46: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 46 ;
			hops[ 1 ] = 37 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route40(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 34: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 34 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 41 ;
			return 3 ;
		}
		case 48: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 48 ;
			hops[ 1 ] = 46 ;
			hops[ 2 ] = 44 ;
			hops[ 3 ] = 42 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route41(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 36: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 36 ;
			hops[ 1 ] = 34 ;
			hops[ 2 ] = 32 ;
			return 3 ;
		}
		case 63: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 63 ;
			hops[ 1 ] = 43 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route42(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 38: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 38 ;
			hops[ 1 ] = 36 ;
			hops[ 2 ] = 34 ;
			hops[ 3 ] = 32 ;
			return 4 ;
		}
		case 45: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 45 ;
			hops[ 1 ] = 43 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route43(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 37: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 37 ;
			hops[ 1 ] = 35 ;
			hops[ 2 ] = 33 ;
			return 3 ;
		}
		case 49: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 49 ;
			hops[ 1 ] = 47 ;
			hops[ 2 ] = 45 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route44(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 31: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 31 ;
			hops[ 1 ] = 33 ;
			return 2 ;
		}
		case 56: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 56 ;
			hops[ 1 ] = 45 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route45(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 42: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 42 ;
			hops[ 1 ] = 43 ;
			return 2 ;
		}
		case 50: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 50 ;
			hops[ 1 ] = 41 ;
			hops[ 2 ] = 43 ;
			return 3 ;
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
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 39 ;
			hops[ 1 ] = 37 ;
			return 2 ;
		}
		case 52: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 52 ;
			hops[ 1 ] = 42 ;
			hops[ 2 ] = 44 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route47(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 35: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 35 ;
			hops[ 1 ] = 36 ;
			return 2 ;
		}
		case 51: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 51 ;
			hops[ 1 ] = 41 ;
			hops[ 2 ] = 43 ;
			hops[ 3 ] = 45 ;
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
		case 40: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 40 ;
			hops[ 1 ] = 42 ;
			hops[ 2 ] = 44 ;
			hops[ 3 ] = 46 ;
			return 4 ;
		}
		case 53: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 53 ;
			hops[ 1 ] = 44 ;
			hops[ 2 ] = 46 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route49(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 43: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 43 ;
			hops[ 1 ] = 45 ;
			hops[ 2 ] = 47 ;
			return 3 ;
		}
		case 55: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 55 ;
			hops[ 1 ] = 45 ;
			hops[ 2 ] = 47 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route50(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 45: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 45 ;
			hops[ 1 ] = 43 ;
			hops[ 2 ] = 41 ;
			return 3 ;
		}
		case 57: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 57 ;
			hops[ 1 ] = 56 ;
			hops[ 2 ] = 54 ;
			hops[ 3 ] = 52 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route51(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 47: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 47 ;
			hops[ 1 ] = 45 ;
			hops[ 2 ] = 54 ;
			hops[ 3 ] = 52 ;
			return 4 ;
		}
		case 54: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 54 ;
			hops[ 1 ] = 52 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route52(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 46: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 46 ;
			hops[ 1 ] = 44 ;
			hops[ 2 ] = 42 ;
			return 3 ;
		}
		case 58: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 58 ;
			hops[ 1 ] = 56 ;
			hops[ 2 ] = 54 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route53(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 48: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 48 ;
			hops[ 1 ] = 46 ;
			hops[ 2 ] = 44 ;
			return 3 ;
		}
		case 71: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 71 ;
			hops[ 1 ] = 73 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route54(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 51: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 51 ;
			hops[ 1 ] = 52 ;
			return 2 ;
		}
		case 59: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 59 ;
			hops[ 1 ] = 57 ;
			hops[ 2 ] = 55 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route55(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 49: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 49 ;
			hops[ 1 ] = 47 ;
			hops[ 2 ] = 45 ;
			return 3 ;
		}
		case 62: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 62 ;
			hops[ 1 ] = 64 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route56(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 44: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 44 ;
			hops[ 1 ] = 45 ;
			return 2 ;
		}
		case 79: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 79 ;
			hops[ 1 ] = 59 ;
			hops[ 2 ] = 57 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route57(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 50: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 50 ;
			hops[ 1 ] = 51 ;
			hops[ 2 ] = 53 ;
			hops[ 3 ] = 55 ;
			return 4 ;
		}
		case 64: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 64 ;
			hops[ 1 ] = 66 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route58(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 52: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 52 ;
			hops[ 1 ] = 54 ;
			hops[ 2 ] = 56 ;
			return 3 ;
		}
		case 60: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 60 ;
			hops[ 1 ] = 50 ;
			hops[ 2 ] = 52 ;
			hops[ 3 ] = 54 ;
			hops[ 4 ] = 56 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route59(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 54: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 54 ;
			hops[ 1 ] = 56 ;
			hops[ 2 ] = 57 ;
			return 3 ;
		}
		case 66: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 66 ;
			hops[ 1 ] = 68 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route60(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 58: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 58 ;
			hops[ 1 ] = 67 ;
			hops[ 2 ] = 65 ;
			hops[ 3 ] = 64 ;
			hops[ 4 ] = 62 ;
			return 5 ;
		}
		case 65: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 65 ;
			hops[ 1 ] = 64 ;
			hops[ 2 ] = 62 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route61(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 14: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 14 ;
			hops[ 1 ] = 34 ;
			hops[ 2 ] = 32 ;
			hops[ 3 ] = 41 ;
			return 4 ;
		}
		case 96: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 96 ;
			hops[ 1 ] = 76 ;
			hops[ 2 ] = 65 ;
			hops[ 3 ] = 63 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route62(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 55: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 55 ;
			hops[ 1 ] = 64 ;
			return 2 ;
		}
		case 67: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 67 ;
			hops[ 1 ] = 65 ;
			hops[ 2 ] = 64 ;
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
		case 41: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 41 ;
			hops[ 1 ] = 43 ;
			return 2 ;
		}
		case 68: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 68 ;
			hops[ 1 ] = 66 ;
			hops[ 2 ] = 64 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route64(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 57: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 57 ;
			hops[ 1 ] = 66 ;
			return 2 ;
		}
		case 69: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 69 ;
			hops[ 1 ] = 67 ;
			hops[ 2 ] = 65 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route65(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 60: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 60 ;
			hops[ 1 ] = 61 ;
			hops[ 2 ] = 63 ;
			return 3 ;
		}
		case 73: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 73 ;
			hops[ 1 ] = 64 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route66(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 59: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 59 ;
			hops[ 1 ] = 68 ;
			return 2 ;
		}
		case 78: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 78 ;
			hops[ 1 ] = 67 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route67(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 62: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 62 ;
			hops[ 1 ] = 63 ;
			hops[ 2 ] = 65 ;
			return 3 ;
		}
		case 70: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 70 ;
			hops[ 1 ] = 61 ;
			hops[ 2 ] = 63 ;
			hops[ 3 ] = 65 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route68(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 63: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 63 ;
			hops[ 1 ] = 64 ;
			hops[ 2 ] = 66 ;
			return 3 ;
		}
		case 82: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 82 ;
			hops[ 1 ] = 73 ;
			hops[ 2 ] = 64 ;
			hops[ 3 ] = 66 ;
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
		case 64: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 64 ;
			hops[ 1 ] = 65 ;
			hops[ 2 ] = 67 ;
			return 3 ;
		}
		case 72: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 72 ;
			hops[ 1 ] = 74 ;
			hops[ 2 ] = 65 ;
			hops[ 3 ] = 67 ;
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
		case 67: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 67 ;
			hops[ 1 ] = 65 ;
			hops[ 2 ] = 74 ;
			hops[ 3 ] = 72 ;
			return 4 ;
		}
		case 74: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 74 ;
			hops[ 1 ] = 72 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route71(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 53: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 53 ;
			hops[ 1 ] = 73 ;
			return 2 ;
		}
		case 75: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 75 ;
			hops[ 1 ] = 73 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route72(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 69: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 69 ;
			hops[ 1 ] = 67 ;
			hops[ 2 ] = 65 ;
			hops[ 3 ] = 74 ;
			return 4 ;
		}
		case 76: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 76 ;
			hops[ 1 ] = 74 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route73(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 65: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 65 ;
			hops[ 1 ] = 64 ;
			return 2 ;
		}
		case 77: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 77 ;
			hops[ 1 ] = 75 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route74(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 70: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 70 ;
			hops[ 1 ] = 72 ;
			return 2 ;
		}
		case 86: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 86 ;
			hops[ 1 ] = 75 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route75(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 71: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 71 ;
			hops[ 1 ] = 73 ;
			return 2 ;
		}
		case 87: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 87 ;
			hops[ 1 ] = 76 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route76(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 72: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 72 ;
			hops[ 1 ] = 74 ;
			return 2 ;
		}
		case 88: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 88 ;
			hops[ 1 ] = 77 ;
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
		case 73: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 73 ;
			hops[ 1 ] = 75 ;
			return 2 ;
		}
		case 81: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 81 ;
			hops[ 1 ] = 71 ;
			hops[ 2 ] = 73 ;
			hops[ 3 ] = 75 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route78(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 66: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 66 ;
			hops[ 1 ] = 67 ;
			return 2 ;
		}
		case 80: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 80 ;
			hops[ 1 ] = 70 ;
			hops[ 2 ] = 72 ;
			hops[ 3 ] = 74 ;
			hops[ 4 ] = 76 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route79(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 56: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 56 ;
			hops[ 1 ] = 67 ;
			hops[ 2 ] = 68 ;
			return 3 ;
		}
		case 84: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 84 ;
			hops[ 1 ] = 75 ;
			hops[ 2 ] = 77 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route80(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 78: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 78 ;
			hops[ 1 ] = 76 ;
			hops[ 2 ] = 74 ;
			hops[ 3 ] = 83 ;
			hops[ 4 ] = 81 ;
			return 5 ;
		}
		case 83: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 83 ;
			hops[ 1 ] = 81 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route81(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 77: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 77 ;
			hops[ 1 ] = 86 ;
			hops[ 2 ] = 85 ;
			hops[ 3 ] = 83 ;
			return 4 ;
		}
		case 94: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 94 ;
			hops[ 1 ] = 83 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route82(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 68: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 68 ;
			hops[ 1 ] = 66 ;
			hops[ 2 ] = 64 ;
			hops[ 3 ] = 73 ;
			return 4 ;
		}
		case 85: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 85 ;
			hops[ 1 ] = 83 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route83(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 80: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 80 ;
			hops[ 1 ] = 81 ;
			return 2 ;
		}
		case 95: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 95 ;
			hops[ 1 ] = 84 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route84(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 79: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 79 ;
			hops[ 1 ] = 77 ;
			hops[ 2 ] = 75 ;
			return 3 ;
		}
		case 91: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 91 ;
			hops[ 1 ] = 82 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route85(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 82: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 82 ;
			hops[ 1 ] = 83 ;
			return 2 ;
		}
		case 97: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 97 ;
			hops[ 1 ] = 96 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route86(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 74: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 74 ;
			hops[ 1 ] = 75 ;
			return 2 ;
		}
		case 89: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 89 ;
			hops[ 1 ] = 87 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route87(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 75: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 75 ;
			hops[ 1 ] = 76 ;
			return 2 ;
		}
		case 99: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 99 ;
			hops[ 1 ] = 97 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route88(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 76: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 76 ;
			hops[ 1 ] = 77 ;
			return 2 ;
		}
		case 90: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 90 ;
			hops[ 1 ] = 81 ;
			hops[ 2 ] = 82 ;
			hops[ 3 ] = 84 ;
			hops[ 4 ] = 86 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route89(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 86: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 86 ;
			hops[ 1 ] = 87 ;
			return 2 ;
		}
		case 92: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 92 ;
			hops[ 1 ] = 83 ;
			hops[ 2 ] = 85 ;
			hops[ 3 ] = 87 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route90(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 88: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 88 ;
			hops[ 1 ] = 97 ;
			hops[ 2 ] = 96 ;
			hops[ 3 ] = 94 ;
			hops[ 4 ] = 92 ;
			return 5 ;
		}
		case 93: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 93 ;
			hops[ 1 ] = 91 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route91(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 84: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 84 ;
			hops[ 1 ] = 82 ;
			return 2 ;
		}
		case 14: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 14 ;
			hops[ 1 ] = 34 ;
			hops[ 2 ] = 32 ;
			hops[ 3 ] = 41 ;
			hops[ 4 ] = 51 ;
			hops[ 5 ] = 71 ;
			return 6 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route92(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 89: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 89 ;
			hops[ 1 ] = 98 ;
			hops[ 2 ] = 96 ;
			hops[ 3 ] = 94 ;
			return 4 ;
		}
		case 4: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 4 ;
			hops[ 1 ] = 2 ;
			hops[ 2 ] = 12 ;
			hops[ 3 ] = 32 ;
			hops[ 4 ] = 52 ;
			hops[ 5 ] = 72 ;
			return 6 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route93(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 90: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 90 ;
			hops[ 1 ] = 91 ;
			return 2 ;
		}
		case 1: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 1 ;
			hops[ 1 ] = 2 ;
			hops[ 2 ] = 13 ;
			hops[ 3 ] = 33 ;
			hops[ 4 ] = 53 ;
			hops[ 5 ] = 73 ;
			return 6 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route94(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 81: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 81 ;
			hops[ 1 ] = 83 ;
			return 2 ;
		}
		case 98: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 98 ;
			hops[ 1 ] = 96 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route95(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 83: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 83 ;
			hops[ 1 ] = 84 ;
			return 2 ;
		}
		case 5: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 5 ;
			hops[ 1 ] = 15 ;
			hops[ 2 ] = 35 ;
			hops[ 3 ] = 55 ;
			hops[ 4 ] = 75 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route96(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 61: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 61 ;
			hops[ 1 ] = 72 ;
			hops[ 2 ] = 74 ;
			hops[ 3 ] = 76 ;
			return 4 ;
		}
		case 2: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 2 ;
			hops[ 1 ] = 3 ;
			hops[ 2 ] = 5 ;
			hops[ 3 ] = 25 ;
			hops[ 4 ] = 45 ;
			hops[ 5 ] = 65 ;
			hops[ 6 ] = 76 ;
			return 7 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route97(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 85: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 85 ;
			hops[ 1 ] = 96 ;
			return 2 ;
		}
		case 10: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 10 ;
			hops[ 1 ] = 11 ;
			hops[ 2 ] = 13 ;
			hops[ 3 ] = 33 ;
			hops[ 4 ] = 35 ;
			hops[ 5 ] = 46 ;
			hops[ 6 ] = 66 ;
			hops[ 7 ] = 77 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route98(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 94: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 94 ;
			hops[ 1 ] = 96 ;
			return 2 ;
		}
		case 12: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 12 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 34 ;
			hops[ 3 ] = 36 ;
			hops[ 4 ] = 38 ;
			hops[ 5 ] = 58 ;
			hops[ 6 ] = 78 ;
			return 7 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route99(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 87: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 87 ;
			hops[ 1 ] = 88 ;
			return 2 ;
		}
		case 31: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 31 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 35 ;
			hops[ 3 ] = 37 ;
			hops[ 4 ] = 39 ;
			hops[ 5 ] = 59 ;
			hops[ 6 ] = 79 ;
			return 7 ;
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
