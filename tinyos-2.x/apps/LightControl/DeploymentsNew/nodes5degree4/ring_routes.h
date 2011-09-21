#ifndef _ROUTES_H_
#define _ROUTES_H_

int8_t fill_route0(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 16: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 16 ;
			hops[ 1 ] = 11 ;
			hops[ 2 ] = 10 ;
			hops[ 3 ] = 5 ;
			return 4 ;
		}
		case 20: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 20 ;
			hops[ 1 ] = 15 ;
			hops[ 2 ] = 10 ;
			hops[ 3 ] = 5 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route1(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 2: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 2 ;
			return 1 ;
		}
		case 5: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 5 ;
			hops[ 1 ] = 0 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route2(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 3: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 3 ;
			return 1 ;
		}
		case 1: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 1 ;
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
		case 4: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 4 ;
			return 1 ;
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

int8_t fill_route4(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 6: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 6 ;
			hops[ 1 ] = 1 ;
			hops[ 2 ] = 2 ;
			hops[ 3 ] = 3 ;
			return 4 ;
		}
		case 3: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 3 ;
			return 1 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route5(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 1: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 1 ;
			hops[ 1 ] = 0 ;
			return 2 ;
		}
		case 20: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 20 ;
			hops[ 1 ] = 15 ;
			hops[ 2 ] = 10 ;
			return 3 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route6(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 7: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 7 ;
			return 1 ;
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

int8_t fill_route7(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 9: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 9 ;
			hops[ 1 ] = 8 ;
			return 2 ;
		}
		case 6: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 6 ;
			return 1 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route8(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 10: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 10 ;
			hops[ 1 ] = 5 ;
			hops[ 2 ] = 6 ;
			hops[ 3 ] = 7 ;
			return 4 ;
		}
		case 9: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 9 ;
			return 1 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route9(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 8: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 8 ;
			return 1 ;
		}
		case 7: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 7 ;
			hops[ 1 ] = 8 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route10(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 11: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 11 ;
			return 1 ;
		}
		case 8: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 8 ;
			hops[ 1 ] = 7 ;
			hops[ 2 ] = 12 ;
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
		case 12: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 12 ;
			return 1 ;
		}
		case 10: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 10 ;
			return 1 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route12(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 14: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 14 ;
			hops[ 1 ] = 13 ;
			return 2 ;
		}
		case 11: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 11 ;
			return 1 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route13(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 15: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 15 ;
			hops[ 1 ] = 10 ;
			hops[ 2 ] = 11 ;
			hops[ 3 ] = 12 ;
			return 4 ;
		}
		case 14: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 14 ;
			return 1 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route14(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 13: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 13 ;
			return 1 ;
		}
		case 12: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 12 ;
			hops[ 1 ] = 13 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route15(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 17: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 17 ;
			hops[ 1 ] = 16 ;
			return 2 ;
		}
		case 13: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 13 ;
			hops[ 1 ] = 18 ;
			hops[ 2 ] = 17 ;
			hops[ 3 ] = 16 ;
			return 4 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route16(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 0: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 0 ;
			hops[ 1 ] = 1 ;
			hops[ 2 ] = 6 ;
			hops[ 3 ] = 11 ;
			return 4 ;
		}
		case 24: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 24 ;
			hops[ 1 ] = 19 ;
			hops[ 2 ] = 18 ;
			hops[ 3 ] = 17 ;
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
		case 18: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 18 ;
			return 1 ;
		}
		case 15: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 15 ;
			hops[ 1 ] = 16 ;
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
		case 19: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 19 ;
			return 1 ;
		}
		case 17: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 17 ;
			return 1 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route19(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 21: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 21 ;
			hops[ 1 ] = 16 ;
			hops[ 2 ] = 17 ;
			hops[ 3 ] = 18 ;
			return 4 ;
		}
		case 18: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 18 ;
			return 1 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route20(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 5: {
			if (max_len < 3 ) return -1;
			hops[ 0 ] = 5 ;
			hops[ 1 ] = 10 ;
			hops[ 2 ] = 15 ;
			return 3 ;
		}
		case 0: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 0 ;
			hops[ 1 ] = 5 ;
			hops[ 2 ] = 10 ;
			hops[ 3 ] = 15 ;
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
		case 22: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 22 ;
			return 1 ;
		}
		case 19: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 19 ;
			hops[ 1 ] = 24 ;
			hops[ 2 ] = 23 ;
			hops[ 3 ] = 22 ;
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
		case 23: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 23 ;
			return 1 ;
		}
		case 21: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 21 ;
			return 1 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route23(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 24: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 24 ;
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

int8_t fill_route24(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 16: {
			if (max_len < 4 ) return -1;
			hops[ 0 ] = 16 ;
			hops[ 1 ] = 17 ;
			hops[ 2 ] = 18 ;
			hops[ 3 ] = 19 ;
			return 4 ;
		}
		case 23: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 23 ;
			return 1 ;
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
		default: return -1;
	}
	return -1;
}

#endif
