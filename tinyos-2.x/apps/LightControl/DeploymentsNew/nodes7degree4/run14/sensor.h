#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1111; break;
		case 1: res = 1343; break;
		case 2: res = 1533; break;
		case 3: res = 1601; break;
		case 4: res = 1657; break;
		case 5: res = 1480; break;
		case 6: res = 1178; break;
		case 7: res = 1459; break;
		case 8: res = 1984; break;
		case 9: res = 2052; break;
		case 10: res = 2096; break;
		case 11: res = 2189; break;
		case 12: res = 2025; break;
		case 13: res = 1526; break;
		case 14: res = 1635; break;
		case 15: res = 2058; break;
		case 16: res = 2283; break;
		case 17: res = 2212; break;
		case 18: res = 2363; break;
		case 19: res = 2143; break;
		case 20: res = 1574; break;
		case 21: res = 1514; break;
		case 22: res = 2043; break;
		case 23: res = 2254; break;
		case 24: res = 2282; break;
		case 25: res = 2229; break;
		case 26: res = 2034; break;
		case 27: res = 1686; break;
		case 28: res = 1510; break;
		case 29: res = 2100; break;
		case 30: res = 2342; break;
		case 31: res = 2266; break;
		case 32: res = 2291; break;
		case 33: res = 2158; break;
		case 34: res = 1575; break;
		case 35: res = 1473; break;
		case 36: res = 2100; break;
		case 37: res = 2278; break;
		case 38: res = 2298; break;
		case 39: res = 2361; break;
		case 40: res = 2129; break;
		case 41: res = 1519; break;
		case 42: res = 1231; break;
		case 43: res = 1611; break;
		case 44: res = 1916; break;
		case 45: res = 1865; break;
		case 46: res = 1728; break;
		case 47: res = 1563; break;
		case 48: res = 1256; break;
		default: break;
	}
	return res;
}

#endif
