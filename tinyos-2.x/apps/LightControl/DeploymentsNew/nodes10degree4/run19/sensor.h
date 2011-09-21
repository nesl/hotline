#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1182; break;
		case 1: res = 1571; break;
		case 2: res = 1636; break;
		case 3: res = 1581; break;
		case 4: res = 1539; break;
		case 5: res = 1569; break;
		case 6: res = 1541; break;
		case 7: res = 1595; break;
		case 8: res = 1426; break;
		case 9: res = 1141; break;
		case 10: res = 1594; break;
		case 11: res = 2080; break;
		case 12: res = 2158; break;
		case 13: res = 2110; break;
		case 14: res = 2039; break;
		case 15: res = 1949; break;
		case 16: res = 2032; break;
		case 17: res = 1989; break;
		case 18: res = 2005; break;
		case 19: res = 1489; break;
		case 20: res = 1676; break;
		case 21: res = 2299; break;
		case 22: res = 2402; break;
		case 23: res = 2234; break;
		case 24: res = 2107; break;
		case 25: res = 2129; break;
		case 26: res = 2242; break;
		case 27: res = 2316; break;
		case 28: res = 2167; break;
		case 29: res = 1699; break;
		case 30: res = 1666; break;
		case 31: res = 2296; break;
		case 32: res = 2503; break;
		case 33: res = 2315; break;
		case 34: res = 2290; break;
		case 35: res = 2210; break;
		case 36: res = 2315; break;
		case 37: res = 2413; break;
		case 38: res = 2329; break;
		case 39: res = 1699; break;
		case 40: res = 1527; break;
		case 41: res = 2231; break;
		case 42: res = 2493; break;
		case 43: res = 2448; break;
		case 44: res = 2360; break;
		case 45: res = 2285; break;
		case 46: res = 2419; break;
		case 47: res = 2569; break;
		case 48: res = 2273; break;
		case 49: res = 1709; break;
		case 50: res = 1581; break;
		case 51: res = 2178; break;
		case 52: res = 2418; break;
		case 53: res = 2472; break;
		case 54: res = 2326; break;
		case 55: res = 2283; break;
		case 56: res = 2414; break;
		case 57: res = 2308; break;
		case 58: res = 2302; break;
		case 59: res = 1679; break;
		case 60: res = 1473; break;
		case 61: res = 2147; break;
		case 62: res = 2354; break;
		case 63: res = 2411; break;
		case 64: res = 2256; break;
		case 65: res = 2281; break;
		case 66: res = 2284; break;
		case 67: res = 2359; break;
		case 68: res = 2152; break;
		case 69: res = 1618; break;
		case 70: res = 1500; break;
		case 71: res = 2169; break;
		case 72: res = 2398; break;
		case 73: res = 2297; break;
		case 74: res = 2399; break;
		case 75: res = 2283; break;
		case 76: res = 2405; break;
		case 77: res = 2275; break;
		case 78: res = 2121; break;
		case 79: res = 1594; break;
		case 80: res = 1535; break;
		case 81: res = 2106; break;
		case 82: res = 2241; break;
		case 83: res = 2236; break;
		case 84: res = 2257; break;
		case 85: res = 2272; break;
		case 86: res = 2103; break;
		case 87: res = 2235; break;
		case 88: res = 2018; break;
		case 89: res = 1565; break;
		case 90: res = 1165; break;
		case 91: res = 1537; break;
		case 92: res = 1706; break;
		case 93: res = 1693; break;
		case 94: res = 1694; break;
		case 95: res = 1638; break;
		case 96: res = 1728; break;
		case 97: res = 1606; break;
		case 98: res = 1590; break;
		case 99: res = 1163; break;
		default: break;
	}
	return res;
}

#endif
