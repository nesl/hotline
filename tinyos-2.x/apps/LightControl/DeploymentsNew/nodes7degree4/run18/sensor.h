#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1081; break;
		case 1: res = 1411; break;
		case 2: res = 1555; break;
		case 3: res = 1685; break;
		case 4: res = 1723; break;
		case 5: res = 1551; break;
		case 6: res = 1153; break;
		case 7: res = 1499; break;
		case 8: res = 2035; break;
		case 9: res = 2218; break;
		case 10: res = 2172; break;
		case 11: res = 2222; break;
		case 12: res = 2097; break;
		case 13: res = 1565; break;
		case 14: res = 1701; break;
		case 15: res = 2263; break;
		case 16: res = 2427; break;
		case 17: res = 2422; break;
		case 18: res = 2345; break;
		case 19: res = 2108; break;
		case 20: res = 1520; break;
		case 21: res = 1868; break;
		case 22: res = 2408; break;
		case 23: res = 2566; break;
		case 24: res = 2378; break;
		case 25: res = 2300; break;
		case 26: res = 2058; break;
		case 27: res = 1533; break;
		case 28: res = 1803; break;
		case 29: res = 2539; break;
		case 30: res = 2546; break;
		case 31: res = 2321; break;
		case 32: res = 2314; break;
		case 33: res = 2093; break;
		case 34: res = 1544; break;
		case 35: res = 1731; break;
		case 36: res = 2163; break;
		case 37: res = 2361; break;
		case 38: res = 2277; break;
		case 39: res = 2217; break;
		case 40: res = 2041; break;
		case 41: res = 1456; break;
		case 42: res = 1281; break;
		case 43: res = 1666; break;
		case 44: res = 1764; break;
		case 45: res = 1701; break;
		case 46: res = 1646; break;
		case 47: res = 1517; break;
		case 48: res = 1209; break;
		default: break;
	}
	return res;
}

#endif
