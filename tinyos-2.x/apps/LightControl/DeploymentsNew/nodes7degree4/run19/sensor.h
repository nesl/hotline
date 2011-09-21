#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1073; break;
		case 1: res = 1417; break;
		case 2: res = 1561; break;
		case 3: res = 1679; break;
		case 4: res = 1762; break;
		case 5: res = 1522; break;
		case 6: res = 1150; break;
		case 7: res = 1527; break;
		case 8: res = 2009; break;
		case 9: res = 2151; break;
		case 10: res = 2302; break;
		case 11: res = 2358; break;
		case 12: res = 2031; break;
		case 13: res = 1555; break;
		case 14: res = 1725; break;
		case 15: res = 2206; break;
		case 16: res = 2529; break;
		case 17: res = 2534; break;
		case 18: res = 2477; break;
		case 19: res = 2263; break;
		case 20: res = 1616; break;
		case 21: res = 1701; break;
		case 22: res = 2255; break;
		case 23: res = 2596; break;
		case 24: res = 2530; break;
		case 25: res = 2495; break;
		case 26: res = 2270; break;
		case 27: res = 1645; break;
		case 28: res = 1578; break;
		case 29: res = 2296; break;
		case 30: res = 2452; break;
		case 31: res = 2431; break;
		case 32: res = 2396; break;
		case 33: res = 2192; break;
		case 34: res = 1667; break;
		case 35: res = 1470; break;
		case 36: res = 2003; break;
		case 37: res = 2141; break;
		case 38: res = 2148; break;
		case 39: res = 2187; break;
		case 40: res = 1982; break;
		case 41: res = 1530; break;
		case 42: res = 1178; break;
		case 43: res = 1469; break;
		case 44: res = 1630; break;
		case 45: res = 1538; break;
		case 46: res = 1483; break;
		case 47: res = 1407; break;
		case 48: res = 1175; break;
		default: break;
	}
	return res;
}

#endif
