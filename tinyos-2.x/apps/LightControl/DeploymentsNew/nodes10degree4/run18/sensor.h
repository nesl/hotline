#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1210; break;
		case 1: res = 1614; break;
		case 2: res = 1679; break;
		case 3: res = 1578; break;
		case 4: res = 1460; break;
		case 5: res = 1394; break;
		case 6: res = 1363; break;
		case 7: res = 1484; break;
		case 8: res = 1478; break;
		case 9: res = 1116; break;
		case 10: res = 1515; break;
		case 11: res = 2053; break;
		case 12: res = 2147; break;
		case 13: res = 1987; break;
		case 14: res = 1976; break;
		case 15: res = 1855; break;
		case 16: res = 1919; break;
		case 17: res = 1939; break;
		case 18: res = 1904; break;
		case 19: res = 1476; break;
		case 20: res = 1614; break;
		case 21: res = 2122; break;
		case 22: res = 2308; break;
		case 23: res = 2248; break;
		case 24: res = 2120; break;
		case 25: res = 2116; break;
		case 26: res = 2230; break;
		case 27: res = 2248; break;
		case 28: res = 2004; break;
		case 29: res = 1556; break;
		case 30: res = 1648; break;
		case 31: res = 2151; break;
		case 32: res = 2260; break;
		case 33: res = 2280; break;
		case 34: res = 2182; break;
		case 35: res = 2300; break;
		case 36: res = 2290; break;
		case 37: res = 2242; break;
		case 38: res = 2096; break;
		case 39: res = 1493; break;
		case 40: res = 1576; break;
		case 41: res = 2054; break;
		case 42: res = 2179; break;
		case 43: res = 2100; break;
		case 44: res = 2208; break;
		case 45: res = 2216; break;
		case 46: res = 2332; break;
		case 47: res = 2261; break;
		case 48: res = 2122; break;
		case 49: res = 1565; break;
		case 50: res = 1544; break;
		case 51: res = 2042; break;
		case 52: res = 2085; break;
		case 53: res = 2072; break;
		case 54: res = 1980; break;
		case 55: res = 2140; break;
		case 56: res = 2240; break;
		case 57: res = 2291; break;
		case 58: res = 2100; break;
		case 59: res = 1577; break;
		case 60: res = 1579; break;
		case 61: res = 1996; break;
		case 62: res = 2041; break;
		case 63: res = 1942; break;
		case 64: res = 2064; break;
		case 65: res = 2064; break;
		case 66: res = 2193; break;
		case 67: res = 2231; break;
		case 68: res = 2166; break;
		case 69: res = 1608; break;
		case 70: res = 1627; break;
		case 71: res = 2084; break;
		case 72: res = 2148; break;
		case 73: res = 2122; break;
		case 74: res = 2093; break;
		case 75: res = 2306; break;
		case 76: res = 2312; break;
		case 77: res = 2371; break;
		case 78: res = 2110; break;
		case 79: res = 1725; break;
		case 80: res = 1655; break;
		case 81: res = 2092; break;
		case 82: res = 2148; break;
		case 83: res = 2083; break;
		case 84: res = 2163; break;
		case 85: res = 2156; break;
		case 86: res = 2345; break;
		case 87: res = 2285; break;
		case 88: res = 2179; break;
		case 89: res = 1550; break;
		case 90: res = 1254; break;
		case 91: res = 1555; break;
		case 92: res = 1617; break;
		case 93: res = 1618; break;
		case 94: res = 1615; break;
		case 95: res = 1700; break;
		case 96: res = 1677; break;
		case 97: res = 1794; break;
		case 98: res = 1642; break;
		case 99: res = 1233; break;
		default: break;
	}
	return res;
}

#endif
