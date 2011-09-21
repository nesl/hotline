#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1101; break;
		case 1: res = 1367; break;
		case 2: res = 1366; break;
		case 3: res = 1501; break;
		case 4: res = 1534; break;
		case 5: res = 1485; break;
		case 6: res = 1154; break;
		case 7: res = 1519; break;
		case 8: res = 1963; break;
		case 9: res = 2035; break;
		case 10: res = 2022; break;
		case 11: res = 2211; break;
		case 12: res = 2120; break;
		case 13: res = 1693; break;
		case 14: res = 1696; break;
		case 15: res = 2172; break;
		case 16: res = 2259; break;
		case 17: res = 2358; break;
		case 18: res = 2597; break;
		case 19: res = 2451; break;
		case 20: res = 1770; break;
		case 21: res = 1726; break;
		case 22: res = 2179; break;
		case 23: res = 2440; break;
		case 24: res = 2445; break;
		case 25: res = 2641; break;
		case 26: res = 2407; break;
		case 27: res = 1794; break;
		case 28: res = 1668; break;
		case 29: res = 2336; break;
		case 30: res = 2479; break;
		case 31: res = 2399; break;
		case 32: res = 2470; break;
		case 33: res = 2330; break;
		case 34: res = 1664; break;
		case 35: res = 1609; break;
		case 36: res = 2102; break;
		case 37: res = 2235; break;
		case 38: res = 2328; break;
		case 39: res = 2306; break;
		case 40: res = 2062; break;
		case 41: res = 1416; break;
		case 42: res = 1308; break;
		case 43: res = 1618; break;
		case 44: res = 1735; break;
		case 45: res = 1713; break;
		case 46: res = 1633; break;
		case 47: res = 1453; break;
		case 48: res = 1132; break;
		default: break;
	}
	return res;
}

#endif
