#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1137; break;
		case 1: res = 1506; break;
		case 2: res = 1676; break;
		case 3: res = 1698; break;
		case 4: res = 1675; break;
		case 5: res = 1622; break;
		case 6: res = 1605; break;
		case 7: res = 1490; break;
		case 8: res = 1518; break;
		case 9: res = 1088; break;
		case 10: res = 1531; break;
		case 11: res = 2018; break;
		case 12: res = 2188; break;
		case 13: res = 2275; break;
		case 14: res = 2265; break;
		case 15: res = 2065; break;
		case 16: res = 1965; break;
		case 17: res = 2135; break;
		case 18: res = 1941; break;
		case 19: res = 1431; break;
		case 20: res = 1594; break;
		case 21: res = 2148; break;
		case 22: res = 2310; break;
		case 23: res = 2307; break;
		case 24: res = 2301; break;
		case 25: res = 2135; break;
		case 26: res = 2144; break;
		case 27: res = 2230; break;
		case 28: res = 2116; break;
		case 29: res = 1571; break;
		case 30: res = 1569; break;
		case 31: res = 2067; break;
		case 32: res = 2257; break;
		case 33: res = 2249; break;
		case 34: res = 2175; break;
		case 35: res = 2106; break;
		case 36: res = 2177; break;
		case 37: res = 2198; break;
		case 38: res = 2092; break;
		case 39: res = 1546; break;
		case 40: res = 1602; break;
		case 41: res = 2084; break;
		case 42: res = 2236; break;
		case 43: res = 2257; break;
		case 44: res = 2245; break;
		case 45: res = 2169; break;
		case 46: res = 2255; break;
		case 47: res = 2313; break;
		case 48: res = 2094; break;
		case 49: res = 1472; break;
		case 50: res = 1721; break;
		case 51: res = 2259; break;
		case 52: res = 2375; break;
		case 53: res = 2345; break;
		case 54: res = 2356; break;
		case 55: res = 2273; break;
		case 56: res = 2347; break;
		case 57: res = 2305; break;
		case 58: res = 2135; break;
		case 59: res = 1465; break;
		case 60: res = 1788; break;
		case 61: res = 2294; break;
		case 62: res = 2503; break;
		case 63: res = 2463; break;
		case 64: res = 2297; break;
		case 65: res = 2276; break;
		case 66: res = 2259; break;
		case 67: res = 2405; break;
		case 68: res = 2186; break;
		case 69: res = 1569; break;
		case 70: res = 1768; break;
		case 71: res = 2449; break;
		case 72: res = 2519; break;
		case 73: res = 2387; break;
		case 74: res = 2282; break;
		case 75: res = 2247; break;
		case 76: res = 2287; break;
		case 77: res = 2291; break;
		case 78: res = 2176; break;
		case 79: res = 1726; break;
		case 80: res = 1765; break;
		case 81: res = 2329; break;
		case 82: res = 2361; break;
		case 83: res = 2195; break;
		case 84: res = 2082; break;
		case 85: res = 1948; break;
		case 86: res = 1980; break;
		case 87: res = 2144; break;
		case 88: res = 2096; break;
		case 89: res = 1584; break;
		case 90: res = 1313; break;
		case 91: res = 1666; break;
		case 92: res = 1749; break;
		case 93: res = 1649; break;
		case 94: res = 1540; break;
		case 95: res = 1418; break;
		case 96: res = 1425; break;
		case 97: res = 1539; break;
		case 98: res = 1549; break;
		case 99: res = 1196; break;
		default: break;
	}
	return res;
}

#endif
