#ifndef _ROUTES_H_
#define _ROUTES_H_

int8_t fill_route0(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 1: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 1 ;
			return 1 ;
		}
		case 2: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 2 ;
			hops[ 1 ] = 1 ;
			return 2 ;
		}
		case 3: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 3 ;
			return 1 ;
		}
		case 4: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 4 ;
			hops[ 1 ] = 1 ;
			return 2 ;
		}
		case 6: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 6 ;
			hops[ 1 ] = 3 ;
			return 2 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route1(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 0: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 0 ;
			return 1 ;
		}
		case 2: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 2 ;
			return 1 ;
		}
		case 3: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 3 ;
			hops[ 1 ] = 0 ;
			return 2 ;
		}
		case 4: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 4 ;
			return 1 ;
		}
		case 5: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 5 ;
			hops[ 1 ] = 2 ;
			return 2 ;
		}
		case 7: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 7 ;
			hops[ 1 ] = 4 ;
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
		case 0: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 0 ;
			hops[ 1 ] = 1 ;
			return 2 ;
		}
		case 1: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 1 ;
			return 1 ;
		}
		case 4: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 4 ;
			hops[ 1 ] = 1 ;
			return 2 ;
		}
		case 5: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 5 ;
			return 1 ;
		}
		case 8: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 8 ;
			hops[ 1 ] = 5 ;
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
		case 0: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 0 ;
			return 1 ;
		}
		case 1: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 1 ;
			hops[ 1 ] = 0 ;
			return 2 ;
		}
		case 4: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 4 ;
			return 1 ;
		}
		case 5: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 5 ;
			hops[ 1 ] = 4 ;
			return 2 ;
		}
		case 6: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 6 ;
			return 1 ;
		}
		case 7: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 7 ;
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
		case 0: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 0 ;
			hops[ 1 ] = 1 ;
			return 2 ;
		}
		case 1: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 1 ;
			return 1 ;
		}
		case 2: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 2 ;
			hops[ 1 ] = 1 ;
			return 2 ;
		}
		case 3: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 3 ;
			return 1 ;
		}
		case 5: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 5 ;
			return 1 ;
		}
		case 6: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 6 ;
			hops[ 1 ] = 3 ;
			return 2 ;
		}
		case 7: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 7 ;
			return 1 ;
		}
		case 8: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 8 ;
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
		case 1: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 1 ;
			hops[ 1 ] = 2 ;
			return 2 ;
		}
		case 2: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 2 ;
			return 1 ;
		}
		case 3: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 3 ;
			hops[ 1 ] = 4 ;
			return 2 ;
		}
		case 4: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 4 ;
			return 1 ;
		}
		case 7: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 7 ;
			hops[ 1 ] = 8 ;
			return 2 ;
		}
		case 8: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 8 ;
			return 1 ;
		}
		default: {
			return -1;
		}
	}
	return -1;
}

int8_t fill_route6(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len){
	switch (dest) {
		case 0: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 0 ;
			hops[ 1 ] = 3 ;
			return 2 ;
		}
		case 3: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 3 ;
			return 1 ;
		}
		case 4: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 4 ;
			hops[ 1 ] = 3 ;
			return 2 ;
		}
		case 7: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 7 ;
			return 1 ;
		}
		case 8: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 8 ;
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
		case 1: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 1 ;
			hops[ 1 ] = 4 ;
			return 2 ;
		}
		case 3: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 3 ;
			hops[ 1 ] = 4 ;
			return 2 ;
		}
		case 4: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 4 ;
			return 1 ;
		}
		case 5: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 5 ;
			hops[ 1 ] = 8 ;
			return 2 ;
		}
		case 6: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 6 ;
			return 1 ;
		}
		case 8: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 8 ;
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
		case 2: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 2 ;
			hops[ 1 ] = 5 ;
			return 2 ;
		}
		case 4: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 4 ;
			hops[ 1 ] = 5 ;
			return 2 ;
		}
		case 5: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 5 ;
			return 1 ;
		}
		case 6: {
			if (max_len < 2 ) return -1;
			hops[ 0 ] = 6 ;
			hops[ 1 ] = 7 ;
			return 2 ;
		}
		case 7: {
			if (max_len < 1 ) return -1;
			hops[ 0 ] = 7 ;
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
		default: return -1;
	}
	return -1;
}

#endif
