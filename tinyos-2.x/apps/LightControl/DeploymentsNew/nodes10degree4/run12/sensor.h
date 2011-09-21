#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1241; break;
		case 1: res = 1548; break;
		case 2: res = 1676; break;
		case 3: res = 1775; break;
		case 4: res = 1635; break;
		case 5: res = 1668; break;
		case 6: res = 1620; break;
		case 7: res = 1655; break;
		case 8: res = 1547; break;
		case 9: res = 1233; break;
		case 10: res = 1561; break;
		case 11: res = 2051; break;
		case 12: res = 2160; break;
		case 13: res = 2141; break;
		case 14: res = 2289; break;
		case 15: res = 2064; break;
		case 16: res = 2103; break;
		case 17: res = 2194; break;
		case 18: res = 2168; break;
		case 19: res = 1605; break;
		case 20: res = 1554; break;
		case 21: res = 2170; break;
		case 22: res = 2285; break;
		case 23: res = 2317; break;
		case 24: res = 2287; break;
		case 25: res = 2264; break;
		case 26: res = 2182; break;
		case 27: res = 2404; break;
		case 28: res = 2377; break;
		case 29: res = 1806; break;
		case 30: res = 1574; break;
		case 31: res = 2091; break;
		case 32: res = 2284; break;
		case 33: res = 2328; break;
		case 34: res = 2249; break;
		case 35: res = 2277; break;
		case 36: res = 2320; break;
		case 37: res = 2284; break;
		case 38: res = 2346; break;
		case 39: res = 1772; break;
		case 40: res = 1519; break;
		case 41: res = 2003; break;
		case 42: res = 2319; break;
		case 43: res = 2269; break;
		case 44: res = 2364; break;
		case 45: res = 2274; break;
		case 46: res = 2403; break;
		case 47: res = 2415; break;
		case 48: res = 2230; break;
		case 49: res = 1712; break;
		case 50: res = 1543; break;
		case 51: res = 2055; break;
		case 52: res = 2209; break;
		case 53: res = 2355; break;
		case 54: res = 2334; break;
		case 55: res = 2429; break;
		case 56: res = 2436; break;
		case 57: res = 2390; break;
		case 58: res = 2260; break;
		case 59: res = 1621; break;
		case 60: res = 1512; break;
		case 61: res = 2083; break;
		case 62: res = 2282; break;
		case 63: res = 2325; break;
		case 64: res = 2440; break;
		case 65: res = 2490; break;
		case 66: res = 2430; break;
		case 67: res = 2369; break;
		case 68: res = 2192; break;
		case 69: res = 1597; break;
		case 70: res = 1575; break;
		case 71: res = 2280; break;
		case 72: res = 2333; break;
		case 73: res = 2397; break;
		case 74: res = 2488; break;
		case 75: res = 2540; break;
		case 76: res = 2449; break;
		case 77: res = 2287; break;
		case 78: res = 2020; break;
		case 79: res = 1512; break;
		case 80: res = 1611; break;
		case 81: res = 2125; break;
		case 82: res = 2296; break;
		case 83: res = 2272; break;
		case 84: res = 2286; break;
		case 85: res = 2197; break;
		case 86: res = 2166; break;
		case 87: res = 2139; break;
		case 88: res = 1842; break;
		case 89: res = 1312; break;
		case 90: res = 1279; break;
		case 91: res = 1499; break;
		case 92: res = 1688; break;
		case 93: res = 1669; break;
		case 94: res = 1649; break;
		case 95: res = 1654; break;
		case 96: res = 1609; break;
		case 97: res = 1502; break;
		case 98: res = 1449; break;
		case 99: res = 999; break;
		default: break;
	}
	return res;
}

#endif
