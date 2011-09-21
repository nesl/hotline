#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1217; break;
		case 1: res = 1611; break;
		case 2: res = 1712; break;
		case 3: res = 1742; break;
		case 4: res = 1815; break;
		case 5: res = 1559; break;
		case 6: res = 1187; break;
		case 7: res = 1599; break;
		case 8: res = 2158; break;
		case 9: res = 2227; break;
		case 10: res = 2220; break;
		case 11: res = 2301; break;
		case 12: res = 2168; break;
		case 13: res = 1585; break;
		case 14: res = 1703; break;
		case 15: res = 2074; break;
		case 16: res = 2361; break;
		case 17: res = 2383; break;
		case 18: res = 2440; break;
		case 19: res = 2289; break;
		case 20: res = 1688; break;
		case 21: res = 1620; break;
		case 22: res = 2131; break;
		case 23: res = 2306; break;
		case 24: res = 2347; break;
		case 25: res = 2405; break;
		case 26: res = 2271; break;
		case 27: res = 1704; break;
		case 28: res = 1532; break;
		case 29: res = 2192; break;
		case 30: res = 2274; break;
		case 31: res = 2139; break;
		case 32: res = 2327; break;
		case 33: res = 2163; break;
		case 34: res = 1613; break;
		case 35: res = 1465; break;
		case 36: res = 1928; break;
		case 37: res = 2049; break;
		case 38: res = 2040; break;
		case 39: res = 1955; break;
		case 40: res = 1877; break;
		case 41: res = 1389; break;
		case 42: res = 1212; break;
		case 43: res = 1456; break;
		case 44: res = 1598; break;
		case 45: res = 1480; break;
		case 46: res = 1393; break;
		case 47: res = 1281; break;
		case 48: res = 1031; break;
		default: break;
	}
	return res;
}

#endif
