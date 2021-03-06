#ifndef _ROUTES_H_
#define _ROUTES_H_

int8_t fill_route0(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 46: {
			if (max_len < 10 ) return -1;
			hops[ 0 ] = 46 ;
			hops[ 1 ] = 45 ;
			hops[ 2 ] = 44 ;
			hops[ 3 ] = 37 ;
			hops[ 4 ] = 36 ;
			hops[ 5 ] = 35 ;
			hops[ 6 ] = 28 ;
			hops[ 7 ] = 21 ;
			hops[ 8 ] = 14 ;
			hops[ 9 ] = 7 ;
			return 10 ;
		}
		case 40: {
			if (max_len < 10 ) return -1;
			hops[ 0 ] = 40 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 32 ;
			hops[ 3 ] = 25 ;
			hops[ 4 ] = 18 ;
			hops[ 5 ] = 11 ;
			hops[ 6 ] = 10 ;
			hops[ 7 ] = 9 ;
			hops[ 8 ] = 8 ;
			hops[ 9 ] = 1 ;
			return 10 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route1(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 6: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 6 ;
			hops[ 1 ] = 5 ;
			hops[ 2 ] = 4 ;
			hops[ 3 ] = 3 ;
			hops[ 4 ] = 2 ;
			return 5 ;
		}
		case 18: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 18 ;
			hops[ 1 ] = 11 ;
			hops[ 2 ] = 10 ;
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
		case 43: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 43 ;
			hops[ 1 ] = 36 ;
			hops[ 2 ] = 37 ;
			hops[ 3 ] = 30 ;
			hops[ 4 ] = 23 ;
			hops[ 5 ] = 16 ;
			hops[ 6 ] = 9 ;
			return 7 ;
		}
		case 17: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 17 ;
			hops[ 1 ] = 10 ;
			hops[ 2 ] = 3 ;
			return 3 ;
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
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 22 ;
			hops[ 1 ] = 15 ;
			hops[ 2 ] = 8 ;
			hops[ 3 ] = 1 ;
			hops[ 4 ] = 2 ;
			return 5 ;
		}
		case 32: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 32 ;
			hops[ 1 ] = 25 ;
			hops[ 2 ] = 18 ;
			hops[ 3 ] = 11 ;
			hops[ 4 ] = 4 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route4(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 43: {
			if (max_len < 9 ) return -1;
			hops[ 0 ] = 43 ;
			hops[ 1 ] = 36 ;
			hops[ 2 ] = 37 ;
			hops[ 3 ] = 38 ;
			hops[ 4 ] = 39 ;
			hops[ 5 ] = 32 ;
			hops[ 6 ] = 25 ;
			hops[ 7 ] = 18 ;
			hops[ 8 ] = 11 ;
			return 9 ;
		}
		case 8: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 8 ;
			hops[ 1 ] = 1 ;
			hops[ 2 ] = 2 ;
			hops[ 3 ] = 3 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route5(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 34: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 34 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 26 ;
			hops[ 3 ] = 19 ;
			hops[ 4 ] = 12 ;
			return 5 ;
		}
		case 21: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 21 ;
			hops[ 1 ] = 14 ;
			hops[ 2 ] = 7 ;
			hops[ 3 ] = 0 ;
			hops[ 4 ] = 1 ;
			hops[ 5 ] = 2 ;
			hops[ 6 ] = 3 ;
			hops[ 7 ] = 4 ;
			return 8 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route6(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 16: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 16 ;
			hops[ 1 ] = 9 ;
			hops[ 2 ] = 2 ;
			hops[ 3 ] = 3 ;
			hops[ 4 ] = 4 ;
			hops[ 5 ] = 5 ;
			return 6 ;
		}
		case 1: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 1 ;
			hops[ 1 ] = 2 ;
			hops[ 2 ] = 3 ;
			hops[ 3 ] = 4 ;
			hops[ 4 ] = 5 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route7(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 38: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 38 ;
			hops[ 1 ] = 37 ;
			hops[ 2 ] = 36 ;
			hops[ 3 ] = 35 ;
			hops[ 4 ] = 28 ;
			hops[ 5 ] = 21 ;
			hops[ 6 ] = 14 ;
			return 7 ;
		}
		case 34: {
			if (max_len < 9 ) return -1;
			hops[ 0 ] = 34 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 32 ;
			hops[ 3 ] = 25 ;
			hops[ 4 ] = 18 ;
			hops[ 5 ] = 11 ;
			hops[ 6 ] = 10 ;
			hops[ 7 ] = 9 ;
			hops[ 8 ] = 8 ;
			return 9 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route8(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 33: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 33 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 25 ;
			hops[ 3 ] = 18 ;
			hops[ 4 ] = 11 ;
			hops[ 5 ] = 10 ;
			hops[ 6 ] = 9 ;
			return 7 ;
		}
		case 4: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 4 ;
			hops[ 1 ] = 3 ;
			hops[ 2 ] = 2 ;
			hops[ 3 ] = 1 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route9(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 21: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 21 ;
			hops[ 1 ] = 14 ;
			hops[ 2 ] = 7 ;
			hops[ 3 ] = 8 ;
			return 4 ;
		}
		case 20: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 20 ;
			hops[ 1 ] = 13 ;
			hops[ 2 ] = 12 ;
			hops[ 3 ] = 11 ;
			hops[ 4 ] = 10 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route10(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 48: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 48 ;
			hops[ 1 ] = 41 ;
			hops[ 2 ] = 34 ;
			hops[ 3 ] = 33 ;
			hops[ 4 ] = 32 ;
			hops[ 5 ] = 25 ;
			hops[ 6 ] = 18 ;
			hops[ 7 ] = 11 ;
			return 8 ;
		}
		case 29: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 29 ;
			hops[ 1 ] = 22 ;
			hops[ 2 ] = 15 ;
			hops[ 3 ] = 8 ;
			hops[ 4 ] = 9 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route11(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 47: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 47 ;
			hops[ 1 ] = 40 ;
			hops[ 2 ] = 33 ;
			hops[ 3 ] = 32 ;
			hops[ 4 ] = 25 ;
			hops[ 5 ] = 18 ;
			return 6 ;
		}
		case 38: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 38 ;
			hops[ 1 ] = 39 ;
			hops[ 2 ] = 32 ;
			hops[ 3 ] = 25 ;
			hops[ 4 ] = 18 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route12(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 25: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 25 ;
			hops[ 1 ] = 18 ;
			hops[ 2 ] = 11 ;
			return 3 ;
		}
		case 47: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 47 ;
			hops[ 1 ] = 40 ;
			hops[ 2 ] = 33 ;
			hops[ 3 ] = 26 ;
			hops[ 4 ] = 19 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route13(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 40: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 40 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 34 ;
			hops[ 3 ] = 27 ;
			hops[ 4 ] = 20 ;
			return 5 ;
		}
		case 41: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 41 ;
			hops[ 1 ] = 34 ;
			hops[ 2 ] = 27 ;
			hops[ 3 ] = 20 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route14(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 42: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 42 ;
			hops[ 1 ] = 35 ;
			hops[ 2 ] = 28 ;
			hops[ 3 ] = 21 ;
			return 4 ;
		}
		case 37: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 37 ;
			hops[ 1 ] = 36 ;
			hops[ 2 ] = 35 ;
			hops[ 3 ] = 28 ;
			hops[ 4 ] = 21 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route15(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 19: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 19 ;
			hops[ 1 ] = 18 ;
			hops[ 2 ] = 17 ;
			hops[ 3 ] = 16 ;
			return 4 ;
		}
		case 45: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 45 ;
			hops[ 1 ] = 38 ;
			hops[ 2 ] = 37 ;
			hops[ 3 ] = 36 ;
			hops[ 4 ] = 29 ;
			hops[ 5 ] = 22 ;
			return 6 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route16(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 39: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 39 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 25 ;
			hops[ 3 ] = 18 ;
			hops[ 4 ] = 17 ;
			return 5 ;
		}
		case 6: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 6 ;
			hops[ 1 ] = 5 ;
			hops[ 2 ] = 4 ;
			hops[ 3 ] = 3 ;
			hops[ 4 ] = 2 ;
			hops[ 5 ] = 9 ;
			return 6 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route17(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 2: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 2 ;
			hops[ 1 ] = 3 ;
			hops[ 2 ] = 10 ;
			return 3 ;
		}
		case 19: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 19 ;
			hops[ 1 ] = 18 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route18(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 1: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 1 ;
			hops[ 1 ] = 2 ;
			hops[ 2 ] = 3 ;
			hops[ 3 ] = 4 ;
			hops[ 4 ] = 11 ;
			return 5 ;
		}
		case 48: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 48 ;
			hops[ 1 ] = 41 ;
			hops[ 2 ] = 34 ;
			hops[ 3 ] = 33 ;
			hops[ 4 ] = 32 ;
			hops[ 5 ] = 25 ;
			return 6 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route19(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 17: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 17 ;
			hops[ 1 ] = 18 ;
			return 2 ;
		}
		case 15: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 15 ;
			hops[ 1 ] = 16 ;
			hops[ 2 ] = 17 ;
			hops[ 3 ] = 18 ;
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
		case 9: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 9 ;
			hops[ 1 ] = 10 ;
			hops[ 2 ] = 11 ;
			hops[ 3 ] = 18 ;
			hops[ 4 ] = 19 ;
			return 5 ;
		}
		case 35: {
			if (max_len < 9 ) return -1;
			hops[ 0 ] = 35 ;
			hops[ 1 ] = 36 ;
			hops[ 2 ] = 37 ;
			hops[ 3 ] = 38 ;
			hops[ 4 ] = 39 ;
			hops[ 5 ] = 32 ;
			hops[ 6 ] = 33 ;
			hops[ 7 ] = 34 ;
			hops[ 8 ] = 27 ;
			return 9 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route21(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 5: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 5 ;
			hops[ 1 ] = 4 ;
			hops[ 2 ] = 3 ;
			hops[ 3 ] = 2 ;
			hops[ 4 ] = 1 ;
			hops[ 5 ] = 0 ;
			hops[ 6 ] = 7 ;
			hops[ 7 ] = 14 ;
			return 8 ;
		}
		case 9: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 9 ;
			hops[ 1 ] = 8 ;
			hops[ 2 ] = 7 ;
			hops[ 3 ] = 14 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route22(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 30: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 30 ;
			hops[ 1 ] = 29 ;
			return 2 ;
		}
		case 3: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 3 ;
			hops[ 1 ] = 2 ;
			hops[ 2 ] = 1 ;
			hops[ 3 ] = 8 ;
			hops[ 4 ] = 15 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route23(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 28: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 28 ;
			hops[ 1 ] = 21 ;
			hops[ 2 ] = 22 ;
			return 3 ;
		}
		case 30: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 30 ;
			return 1 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route24(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 44: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 44 ;
			hops[ 1 ] = 37 ;
			hops[ 2 ] = 38 ;
			hops[ 3 ] = 31 ;
			return 4 ;
		}
		case 26: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 26 ;
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
		case 45: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 45 ;
			hops[ 1 ] = 38 ;
			hops[ 2 ] = 39 ;
			hops[ 3 ] = 32 ;
			return 4 ;
		}
		case 12: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 12 ;
			hops[ 1 ] = 11 ;
			hops[ 2 ] = 18 ;
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
		case 24: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 24 ;
			hops[ 1 ] = 25 ;
			return 2 ;
		}
		case 36: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 36 ;
			hops[ 1 ] = 37 ;
			hops[ 2 ] = 38 ;
			hops[ 3 ] = 39 ;
			hops[ 4 ] = 32 ;
			hops[ 5 ] = 25 ;
			return 6 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route27(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 29: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 29 ;
			hops[ 1 ] = 22 ;
			hops[ 2 ] = 23 ;
			hops[ 3 ] = 24 ;
			hops[ 4 ] = 25 ;
			hops[ 5 ] = 26 ;
			return 6 ;
		}
		case 42: {
			if (max_len < 9 ) return -1;
			hops[ 0 ] = 42 ;
			hops[ 1 ] = 43 ;
			hops[ 2 ] = 36 ;
			hops[ 3 ] = 37 ;
			hops[ 4 ] = 38 ;
			hops[ 5 ] = 39 ;
			hops[ 6 ] = 32 ;
			hops[ 7 ] = 25 ;
			hops[ 8 ] = 26 ;
			return 9 ;
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
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 37 ;
			hops[ 1 ] = 30 ;
			hops[ 2 ] = 29 ;
			return 3 ;
		}
		case 23: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 23 ;
			hops[ 1 ] = 30 ;
			hops[ 2 ] = 29 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route29(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 10: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 10 ;
			hops[ 1 ] = 9 ;
			hops[ 2 ] = 8 ;
			hops[ 3 ] = 15 ;
			hops[ 4 ] = 22 ;
			return 5 ;
		}
		case 27: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 27 ;
			hops[ 1 ] = 34 ;
			hops[ 2 ] = 33 ;
			hops[ 3 ] = 32 ;
			hops[ 4 ] = 31 ;
			hops[ 5 ] = 30 ;
			return 6 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route30(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 23: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 23 ;
			return 1 ;
		}
		case 22: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 22 ;
			hops[ 1 ] = 23 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route31(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 35: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 35 ;
			hops[ 1 ] = 36 ;
			hops[ 2 ] = 37 ;
			hops[ 3 ] = 30 ;
			return 4 ;
		}
		case 46: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 46 ;
			hops[ 1 ] = 39 ;
			hops[ 2 ] = 32 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route32(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 3: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 3 ;
			hops[ 1 ] = 10 ;
			hops[ 2 ] = 11 ;
			hops[ 3 ] = 18 ;
			hops[ 4 ] = 25 ;
			return 5 ;
		}
		case 33: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 33 ;
			return 1 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route33(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 32: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 32 ;
			return 1 ;
		}
		case 8: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 8 ;
			hops[ 1 ] = 9 ;
			hops[ 2 ] = 10 ;
			hops[ 3 ] = 11 ;
			hops[ 4 ] = 12 ;
			hops[ 5 ] = 19 ;
			hops[ 6 ] = 26 ;
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
		case 7: {
			if (max_len < 9 ) return -1;
			hops[ 0 ] = 7 ;
			hops[ 1 ] = 8 ;
			hops[ 2 ] = 9 ;
			hops[ 3 ] = 10 ;
			hops[ 4 ] = 11 ;
			hops[ 5 ] = 12 ;
			hops[ 6 ] = 13 ;
			hops[ 7 ] = 20 ;
			hops[ 8 ] = 27 ;
			return 9 ;
		}
		case 5: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 5 ;
			hops[ 1 ] = 6 ;
			hops[ 2 ] = 13 ;
			hops[ 3 ] = 20 ;
			hops[ 4 ] = 27 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route35(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 20: {
			if (max_len < 9 ) return -1;
			hops[ 0 ] = 20 ;
			hops[ 1 ] = 27 ;
			hops[ 2 ] = 34 ;
			hops[ 3 ] = 33 ;
			hops[ 4 ] = 32 ;
			hops[ 5 ] = 39 ;
			hops[ 6 ] = 38 ;
			hops[ 7 ] = 37 ;
			hops[ 8 ] = 36 ;
			return 9 ;
		}
		case 31: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 31 ;
			hops[ 1 ] = 30 ;
			hops[ 2 ] = 37 ;
			hops[ 3 ] = 36 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route36(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 26: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 26 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 32 ;
			hops[ 3 ] = 39 ;
			hops[ 4 ] = 38 ;
			hops[ 5 ] = 37 ;
			return 6 ;
		}
		case 39: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 39 ;
			hops[ 1 ] = 38 ;
			hops[ 2 ] = 37 ;
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
		case 14: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 14 ;
			hops[ 1 ] = 21 ;
			hops[ 2 ] = 22 ;
			hops[ 3 ] = 23 ;
			hops[ 4 ] = 30 ;
			return 5 ;
		}
		case 28: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 28 ;
			hops[ 1 ] = 35 ;
			hops[ 2 ] = 36 ;
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
		case 11: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 11 ;
			hops[ 1 ] = 18 ;
			hops[ 2 ] = 17 ;
			hops[ 3 ] = 24 ;
			hops[ 4 ] = 31 ;
			return 5 ;
		}
		case 7: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 7 ;
			hops[ 1 ] = 8 ;
			hops[ 2 ] = 9 ;
			hops[ 3 ] = 16 ;
			hops[ 4 ] = 17 ;
			hops[ 5 ] = 24 ;
			hops[ 6 ] = 31 ;
			return 7 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route39(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 36: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 36 ;
			hops[ 1 ] = 37 ;
			hops[ 2 ] = 38 ;
			return 3 ;
		}
		case 16: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 16 ;
			hops[ 1 ] = 17 ;
			hops[ 2 ] = 18 ;
			hops[ 3 ] = 25 ;
			hops[ 4 ] = 32 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route40(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 0: {
			if (max_len < 10 ) return -1;
			hops[ 0 ] = 0 ;
			hops[ 1 ] = 1 ;
			hops[ 2 ] = 8 ;
			hops[ 3 ] = 9 ;
			hops[ 4 ] = 16 ;
			hops[ 5 ] = 17 ;
			hops[ 6 ] = 18 ;
			hops[ 7 ] = 19 ;
			hops[ 8 ] = 26 ;
			hops[ 9 ] = 33 ;
			return 10 ;
		}
		case 13: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 13 ;
			hops[ 1 ] = 12 ;
			hops[ 2 ] = 19 ;
			hops[ 3 ] = 26 ;
			hops[ 4 ] = 33 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route41(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 13: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 13 ;
			hops[ 1 ] = 20 ;
			hops[ 2 ] = 27 ;
			hops[ 3 ] = 34 ;
			return 4 ;
		}
		case 44: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 44 ;
			hops[ 1 ] = 37 ;
			hops[ 2 ] = 38 ;
			hops[ 3 ] = 39 ;
			hops[ 4 ] = 40 ;
			return 5 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route42(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 27: {
			if (max_len < 9 ) return -1;
			hops[ 0 ] = 27 ;
			hops[ 1 ] = 34 ;
			hops[ 2 ] = 33 ;
			hops[ 3 ] = 32 ;
			hops[ 4 ] = 39 ;
			hops[ 5 ] = 46 ;
			hops[ 6 ] = 45 ;
			hops[ 7 ] = 44 ;
			hops[ 8 ] = 43 ;
			return 9 ;
		}
		case 14: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 14 ;
			hops[ 1 ] = 21 ;
			hops[ 2 ] = 28 ;
			hops[ 3 ] = 35 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route43(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 4: {
			if (max_len < 9 ) return -1;
			hops[ 0 ] = 4 ;
			hops[ 1 ] = 11 ;
			hops[ 2 ] = 10 ;
			hops[ 3 ] = 9 ;
			hops[ 4 ] = 16 ;
			hops[ 5 ] = 15 ;
			hops[ 6 ] = 22 ;
			hops[ 7 ] = 29 ;
			hops[ 8 ] = 36 ;
			return 9 ;
		}
		case 2: {
			if (max_len < 7 ) return -1;
			hops[ 0 ] = 2 ;
			hops[ 1 ] = 1 ;
			hops[ 2 ] = 8 ;
			hops[ 3 ] = 15 ;
			hops[ 4 ] = 22 ;
			hops[ 5 ] = 29 ;
			hops[ 6 ] = 36 ;
			return 7 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route44(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 41: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 41 ;
			hops[ 1 ] = 48 ;
			hops[ 2 ] = 47 ;
			hops[ 3 ] = 46 ;
			hops[ 4 ] = 45 ;
			return 5 ;
		}
		case 24: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 24 ;
			hops[ 1 ] = 23 ;
			hops[ 2 ] = 30 ;
			hops[ 3 ] = 37 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route45(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 15: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 15 ;
			hops[ 1 ] = 16 ;
			hops[ 2 ] = 17 ;
			hops[ 3 ] = 24 ;
			hops[ 4 ] = 31 ;
			hops[ 5 ] = 38 ;
			return 6 ;
		}
		case 25: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 25 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 31 ;
			hops[ 3 ] = 38 ;
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
		case 31: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 31 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 39 ;
			return 3 ;
		}
		case 0: {
			if (max_len < 10 ) return -1;
			hops[ 0 ] = 0 ;
			hops[ 1 ] = 1 ;
			hops[ 2 ] = 8 ;
			hops[ 3 ] = 9 ;
			hops[ 4 ] = 10 ;
			hops[ 5 ] = 11 ;
			hops[ 6 ] = 18 ;
			hops[ 7 ] = 25 ;
			hops[ 8 ] = 32 ;
			hops[ 9 ] = 39 ;
			return 10 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route47(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 12: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 12 ;
			hops[ 1 ] = 19 ;
			hops[ 2 ] = 26 ;
			hops[ 3 ] = 33 ;
			hops[ 4 ] = 40 ;
			return 5 ;
		}
		case 11: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 11 ;
			hops[ 1 ] = 12 ;
			hops[ 2 ] = 19 ;
			hops[ 3 ] = 26 ;
			hops[ 4 ] = 33 ;
			hops[ 5 ] = 40 ;
			return 6 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route48(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 18: {
			if (max_len < 6 ) return -1;
			hops[ 0 ] = 18 ;
			hops[ 1 ] = 19 ;
			hops[ 2 ] = 26 ;
			hops[ 3 ] = 33 ;
			hops[ 4 ] = 40 ;
			hops[ 5 ] = 41 ;
			return 6 ;
		}
		case 10: {
			if (max_len < 8 ) return -1;
			hops[ 0 ] = 10 ;
			hops[ 1 ] = 11 ;
			hops[ 2 ] = 12 ;
			hops[ 3 ] = 13 ;
			hops[ 4 ] = 20 ;
			hops[ 5 ] = 27 ;
			hops[ 6 ] = 34 ;
			hops[ 7 ] = 41 ;
			return 8 ;
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
		default: return -1;
	}
	return -1;
}

#endif
