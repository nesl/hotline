#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1185; break;
		case 1: res = 1528; break;
		case 2: res = 1503; break;
		case 3: res = 1646; break;
		case 4: res = 1669; break;
		case 5: res = 1767; break;
		case 6: res = 1727; break;
		case 7: res = 1586; break;
		case 8: res = 1422; break;
		case 9: res = 971; break;
		case 10: res = 1562; break;
		case 11: res = 1939; break;
		case 12: res = 2057; break;
		case 13: res = 2011; break;
		case 14: res = 2229; break;
		case 15: res = 2280; break;
		case 16: res = 2171; break;
		case 17: res = 2109; break;
		case 18: res = 1889; break;
		case 19: res = 1371; break;
		case 20: res = 1535; break;
		case 21: res = 2170; break;
		case 22: res = 2184; break;
		case 23: res = 2210; break;
		case 24: res = 2303; break;
		case 25: res = 2404; break;
		case 26: res = 2316; break;
		case 27: res = 2228; break;
		case 28: res = 2131; break;
		case 29: res = 1562; break;
		case 30: res = 1613; break;
		case 31: res = 2125; break;
		case 32: res = 2242; break;
		case 33: res = 2203; break;
		case 34: res = 2218; break;
		case 35: res = 2162; break;
		case 36: res = 2215; break;
		case 37: res = 2300; break;
		case 38: res = 2125; break;
		case 39: res = 1586; break;
		case 40: res = 1592; break;
		case 41: res = 2032; break;
		case 42: res = 2166; break;
		case 43: res = 2149; break;
		case 44: res = 2193; break;
		case 45: res = 2006; break;
		case 46: res = 2144; break;
		case 47: res = 2224; break;
		case 48: res = 2151; break;
		case 49: res = 1578; break;
		case 50: res = 1566; break;
		case 51: res = 2135; break;
		case 52: res = 2160; break;
		case 53: res = 2141; break;
		case 54: res = 1981; break;
		case 55: res = 2042; break;
		case 56: res = 2173; break;
		case 57: res = 2222; break;
		case 58: res = 2107; break;
		case 59: res = 1490; break;
		case 60: res = 1583; break;
		case 61: res = 2110; break;
		case 62: res = 2210; break;
		case 63: res = 2062; break;
		case 64: res = 2079; break;
		case 65: res = 2088; break;
		case 66: res = 2142; break;
		case 67: res = 2265; break;
		case 68: res = 2090; break;
		case 69: res = 1513; break;
		case 70: res = 1573; break;
		case 71: res = 2190; break;
		case 72: res = 2318; break;
		case 73: res = 2226; break;
		case 74: res = 2065; break;
		case 75: res = 2158; break;
		case 76: res = 2350; break;
		case 77: res = 2366; break;
		case 78: res = 2097; break;
		case 79: res = 1597; break;
		case 80: res = 1569; break;
		case 81: res = 2024; break;
		case 82: res = 2144; break;
		case 83: res = 2071; break;
		case 84: res = 2019; break;
		case 85: res = 2041; break;
		case 86: res = 2161; break;
		case 87: res = 2308; break;
		case 88: res = 2106; break;
		case 89: res = 1527; break;
		case 90: res = 1078; break;
		case 91: res = 1465; break;
		case 92: res = 1570; break;
		case 93: res = 1536; break;
		case 94: res = 1534; break;
		case 95: res = 1527; break;
		case 96: res = 1644; break;
		case 97: res = 1750; break;
		case 98: res = 1714; break;
		case 99: res = 1240; break;
		default: break;
	}
	return res;
}

#endif
