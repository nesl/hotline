#ifndef _ROUTES_H_
#define _ROUTES_H_

int8_t fill_route0(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 46: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 46 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 18 ;
			hops[ 3 ] = 4 ;
			hops[ 4 ] = 2 ;
			return 5 ;
		}
		case 40: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 40 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 18 ;
			hops[ 3 ] = 4 ;
			hops[ 4 ] = 2 ;
			return 5 ;
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
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 6 ;
			hops[ 1 ] = 4 ;
			hops[ 2 ] = 2 ;
			return 3 ;
		}
		case 18: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 18 ;
			hops[ 1 ] = 4 ;
			hops[ 2 ] = 2 ;
			return 3 ;
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
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 43 ;
			hops[ 1 ] = 36 ;
			hops[ 2 ] = 22 ;
			hops[ 3 ] = 8 ;
			return 4 ;
		}
		case 17: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 17 ;
			hops[ 1 ] = 3 ;
			return 2 ;
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
			hops[ 1 ] = 8 ;
			hops[ 2 ] = 1 ;
			return 3 ;
		}
		case 32: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 32 ;
			hops[ 1 ] = 18 ;
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
		case 43: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 43 ;
			hops[ 1 ] = 36 ;
			hops[ 2 ] = 38 ;
			hops[ 3 ] = 32 ;
			hops[ 4 ] = 18 ;
			return 5 ;
		}
		case 8: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 8 ;
			hops[ 1 ] = 2 ;
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
		case 34: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 34 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 19 ;
			return 3 ;
		}
		case 21: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 21 ;
			hops[ 1 ] = 7 ;
			hops[ 2 ] = 1 ;
			hops[ 3 ] = 3 ;
			return 4 ;
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
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 16 ;
			hops[ 1 ] = 2 ;
			hops[ 2 ] = 4 ;
			return 3 ;
		}
		case 1: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 1 ;
			hops[ 1 ] = 2 ;
			hops[ 2 ] = 4 ;
			return 3 ;
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
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 38 ;
			hops[ 1 ] = 24 ;
			hops[ 2 ] = 10 ;
			hops[ 3 ] = 8 ;
			return 4 ;
		}
		case 34: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 34 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 18 ;
			hops[ 3 ] = 10 ;
			hops[ 4 ] = 8 ;
			return 5 ;
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
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 33 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 18 ;
			hops[ 3 ] = 10 ;
			return 4 ;
		}
		case 4: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 4 ;
			hops[ 1 ] = 2 ;
			return 2 ;
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
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 21 ;
			hops[ 1 ] = 7 ;
			return 2 ;
		}
		case 20: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 20 ;
			hops[ 1 ] = 12 ;
			hops[ 2 ] = 10 ;
			return 3 ;
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
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 48 ;
			hops[ 1 ] = 34 ;
			hops[ 2 ] = 32 ;
			hops[ 3 ] = 18 ;
			return 4 ;
		}
		case 29: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 29 ;
			hops[ 1 ] = 15 ;
			hops[ 2 ] = 8 ;
			return 3 ;
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
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 47 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 19 ;
			return 3 ;
		}
		case 38: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 38 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 18 ;
			return 3 ;
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
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 25 ;
			hops[ 1 ] = 11 ;
			return 2 ;
		}
		case 47: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 47 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 19 ;
			return 3 ;
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
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 40 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 19 ;
			return 3 ;
		}
		case 41: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 41 ;
			hops[ 1 ] = 27 ;
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
		case 42: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 42 ;
			hops[ 1 ] = 28 ;
			return 2 ;
		}
		case 37: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 37 ;
			hops[ 1 ] = 35 ;
			hops[ 2 ] = 21 ;
			return 3 ;
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
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 19 ;
			hops[ 1 ] = 17 ;
			return 2 ;
		}
		case 45: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 45 ;
			hops[ 1 ] = 37 ;
			hops[ 2 ] = 23 ;
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
		case 39: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 39 ;
			hops[ 1 ] = 37 ;
			hops[ 2 ] = 23 ;
			return 3 ;
		}
		case 6: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 6 ;
			hops[ 1 ] = 4 ;
			hops[ 2 ] = 2 ;
			return 3 ;
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
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 2 ;
			hops[ 1 ] = 3 ;
			return 2 ;
		}
		case 19: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 19 ;
			return 1 ;
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
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 1 ;
			hops[ 1 ] = 3 ;
			hops[ 2 ] = 4 ;
			return 3 ;
		}
		case 48: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 48 ;
			hops[ 1 ] = 34 ;
			hops[ 2 ] = 32 ;
			return 3 ;
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
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 17 ;
			return 1 ;
		}
		case 15: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 15 ;
			hops[ 1 ] = 17 ;
			return 2 ;
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
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 9 ;
			hops[ 1 ] = 16 ;
			hops[ 2 ] = 18 ;
			return 3 ;
		}
		case 35: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 35 ;
			hops[ 1 ] = 36 ;
			hops[ 2 ] = 38 ;
			hops[ 3 ] = 32 ;
			hops[ 4 ] = 34 ;
			return 5 ;
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
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 5 ;
			hops[ 1 ] = 3 ;
			hops[ 2 ] = 1 ;
			hops[ 3 ] = 7 ;
			return 4 ;
		}
		case 9: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 9 ;
			hops[ 1 ] = 7 ;
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
		case 30: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 30 ;
			return 1 ;
		}
		case 3: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 3 ;
			hops[ 1 ] = 1 ;
			hops[ 2 ] = 8 ;
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
		case 28: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 28 ;
			hops[ 1 ] = 21 ;
			return 2 ;
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
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 44 ;
			hops[ 1 ] = 38 ;
			return 2 ;
		}
		case 26: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 26 ;
			return 1 ;
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
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 45 ;
			hops[ 1 ] = 39 ;
			return 2 ;
		}
		case 12: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 12 ;
			hops[ 1 ] = 11 ;
			return 2 ;
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
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 24 ;
			return 1 ;
		}
		case 36: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 36 ;
			hops[ 1 ] = 38 ;
			hops[ 2 ] = 32 ;
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
		case 29: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 29 ;
			hops[ 1 ] = 23 ;
			hops[ 2 ] = 25 ;
			return 3 ;
		}
		case 42: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 42 ;
			hops[ 1 ] = 35 ;
			hops[ 2 ] = 37 ;
			hops[ 3 ] = 39 ;
			hops[ 4 ] = 33 ;
			return 5 ;
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
			hops[ 1 ] = 35 ;
			return 2 ;
		}
		case 23: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 23 ;
			hops[ 1 ] = 21 ;
			return 2 ;
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
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 10 ;
			hops[ 1 ] = 8 ;
			hops[ 2 ] = 15 ;
			return 3 ;
		}
		case 27: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 27 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 31 ;
			return 3 ;
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
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 22 ;
			return 1 ;
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
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 35 ;
			hops[ 1 ] = 37 ;
			return 2 ;
		}
		case 46: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 46 ;
			hops[ 1 ] = 32 ;
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
		case 3: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 3 ;
			hops[ 1 ] = 10 ;
			hops[ 2 ] = 18 ;
			return 3 ;
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
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 8 ;
			hops[ 1 ] = 9 ;
			hops[ 2 ] = 11 ;
			hops[ 3 ] = 19 ;
			return 4 ;
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
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 7 ;
			hops[ 1 ] = 8 ;
			hops[ 2 ] = 10 ;
			hops[ 3 ] = 12 ;
			hops[ 4 ] = 20 ;
			return 5 ;
		}
		case 5: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 5 ;
			hops[ 1 ] = 6 ;
			hops[ 2 ] = 20 ;
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
		case 20: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 20 ;
			hops[ 1 ] = 34 ;
			hops[ 2 ] = 32 ;
			hops[ 3 ] = 38 ;
			hops[ 4 ] = 36 ;
			return 5 ;
		}
		case 31: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 31 ;
			hops[ 1 ] = 37 ;
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
		case 26: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 26 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 38 ;
			return 3 ;
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

int8_t fill_route37(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 14: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 14 ;
			hops[ 1 ] = 16 ;
			hops[ 2 ] = 23 ;
			return 3 ;
		}
		case 28: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 28 ;
			hops[ 1 ] = 35 ;
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
		case 11: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 11 ;
			hops[ 1 ] = 17 ;
			hops[ 2 ] = 24 ;
			return 3 ;
		}
		case 7: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 7 ;
			hops[ 1 ] = 8 ;
			hops[ 2 ] = 16 ;
			hops[ 3 ] = 24 ;
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
		case 36: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 36 ;
			hops[ 1 ] = 37 ;
			return 2 ;
		}
		case 16: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 16 ;
			hops[ 1 ] = 17 ;
			hops[ 2 ] = 25 ;
			return 3 ;
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
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 0 ;
			hops[ 1 ] = 2 ;
			hops[ 2 ] = 16 ;
			hops[ 3 ] = 18 ;
			hops[ 4 ] = 32 ;
			return 5 ;
		}
		case 13: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 13 ;
			hops[ 1 ] = 12 ;
			hops[ 2 ] = 26 ;
			return 3 ;
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
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 13 ;
			hops[ 1 ] = 27 ;
			return 2 ;
		}
		case 44: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 44 ;
			hops[ 1 ] = 37 ;
			hops[ 2 ] = 39 ;
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
		case 27: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 27 ;
			hops[ 1 ] = 33 ;
			hops[ 2 ] = 32 ;
			hops[ 3 ] = 38 ;
			hops[ 4 ] = 36 ;
			return 5 ;
		}
		case 14: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 14 ;
			hops[ 1 ] = 28 ;
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
		case 4: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 4 ;
			hops[ 1 ] = 3 ;
			hops[ 2 ] = 17 ;
			hops[ 3 ] = 23 ;
			hops[ 4 ] = 37 ;
			return 5 ;
		}
		case 2: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 2 ;
			hops[ 1 ] = 16 ;
			hops[ 2 ] = 22 ;
			hops[ 3 ] = 36 ;
			return 4 ;
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
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 41 ;
			hops[ 1 ] = 39 ;
			hops[ 2 ] = 37 ;
			return 3 ;
		}
		case 24: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 24 ;
			hops[ 1 ] = 38 ;
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
		case 15: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 15 ;
			hops[ 1 ] = 17 ;
			hops[ 2 ] = 31 ;
			return 3 ;
		}
		case 25: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 25 ;
			hops[ 1 ] = 39 ;
			return 2 ;
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
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 31 ;
			hops[ 1 ] = 32 ;
			return 2 ;
		}
		case 0: {
			if (max_len < 5 ) return -1;
			hops[ 0 ] = 0 ;
			hops[ 1 ] = 2 ;
			hops[ 2 ] = 4 ;
			hops[ 3 ] = 18 ;
			hops[ 4 ] = 32 ;
			return 5 ;
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
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 12 ;
			hops[ 1 ] = 19 ;
			hops[ 2 ] = 33 ;
			return 3 ;
		}
		case 11: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 11 ;
			hops[ 1 ] = 19 ;
			hops[ 2 ] = 33 ;
			return 3 ;
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
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 18 ;
			hops[ 1 ] = 32 ;
			hops[ 2 ] = 40 ;
			return 3 ;
		}
		case 10: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 10 ;
			hops[ 1 ] = 12 ;
			hops[ 2 ] = 20 ;
			hops[ 3 ] = 34 ;
			return 4 ;
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
