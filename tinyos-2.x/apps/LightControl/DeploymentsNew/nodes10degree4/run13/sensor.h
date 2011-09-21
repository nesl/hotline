#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1283; break;
		case 1: res = 1601; break;
		case 2: res = 1734; break;
		case 3: res = 1715; break;
		case 4: res = 1629; break;
		case 5: res = 1638; break;
		case 6: res = 1674; break;
		case 7: res = 1733; break;
		case 8: res = 1548; break;
		case 9: res = 1114; break;
		case 10: res = 1540; break;
		case 11: res = 2148; break;
		case 12: res = 2309; break;
		case 13: res = 2191; break;
		case 14: res = 2135; break;
		case 15: res = 2150; break;
		case 16: res = 2225; break;
		case 17: res = 2220; break;
		case 18: res = 2031; break;
		case 19: res = 1526; break;
		case 20: res = 1660; break;
		case 21: res = 2245; break;
		case 22: res = 2341; break;
		case 23: res = 2237; break;
		case 24: res = 2170; break;
		case 25: res = 2263; break;
		case 26: res = 2313; break;
		case 27: res = 2295; break;
		case 28: res = 2135; break;
		case 29: res = 1562; break;
		case 30: res = 1666; break;
		case 31: res = 2141; break;
		case 32: res = 2307; break;
		case 33: res = 2195; break;
		case 34: res = 2229; break;
		case 35: res = 2093; break;
		case 36: res = 2219; break;
		case 37: res = 2166; break;
		case 38: res = 2065; break;
		case 39: res = 1570; break;
		case 40: res = 1632; break;
		case 41: res = 2201; break;
		case 42: res = 2262; break;
		case 43: res = 2252; break;
		case 44: res = 2138; break;
		case 45: res = 2232; break;
		case 46: res = 2194; break;
		case 47: res = 2127; break;
		case 48: res = 1962; break;
		case 49: res = 1500; break;
		case 50: res = 1788; break;
		case 51: res = 2296; break;
		case 52: res = 2480; break;
		case 53: res = 2347; break;
		case 54: res = 2351; break;
		case 55: res = 2233; break;
		case 56: res = 2271; break;
		case 57: res = 2082; break;
		case 58: res = 1936; break;
		case 59: res = 1502; break;
		case 60: res = 1821; break;
		case 61: res = 2488; break;
		case 62: res = 2492; break;
		case 63: res = 2553; break;
		case 64: res = 2314; break;
		case 65: res = 2365; break;
		case 66: res = 2185; break;
		case 67: res = 2148; break;
		case 68: res = 2044; break;
		case 69: res = 1584; break;
		case 70: res = 1843; break;
		case 71: res = 2492; break;
		case 72: res = 2625; break;
		case 73: res = 2359; break;
		case 74: res = 2433; break;
		case 75: res = 2367; break;
		case 76: res = 2441; break;
		case 77: res = 2258; break;
		case 78: res = 2090; break;
		case 79: res = 1711; break;
		case 80: res = 1705; break;
		case 81: res = 2281; break;
		case 82: res = 2424; break;
		case 83: res = 2320; break;
		case 84: res = 2184; break;
		case 85: res = 2223; break;
		case 86: res = 2172; break;
		case 87: res = 2314; break;
		case 88: res = 2181; break;
		case 89: res = 1589; break;
		case 90: res = 1293; break;
		case 91: res = 1619; break;
		case 92: res = 1749; break;
		case 93: res = 1721; break;
		case 94: res = 1708; break;
		case 95: res = 1695; break;
		case 96: res = 1740; break;
		case 97: res = 1727; break;
		case 98: res = 1662; break;
		case 99: res = 1247; break;
		default: break;
	}
	return res;
}

#endif
