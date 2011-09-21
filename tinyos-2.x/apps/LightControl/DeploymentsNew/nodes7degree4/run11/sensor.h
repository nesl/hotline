#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1048; break;
		case 1: res = 1425; break;
		case 2: res = 1539; break;
		case 3: res = 1660; break;
		case 4: res = 1706; break;
		case 5: res = 1532; break;
		case 6: res = 1188; break;
		case 7: res = 1455; break;
		case 8: res = 1864; break;
		case 9: res = 2109; break;
		case 10: res = 2174; break;
		case 11: res = 2214; break;
		case 12: res = 2102; break;
		case 13: res = 1585; break;
		case 14: res = 1540; break;
		case 15: res = 2060; break;
		case 16: res = 2262; break;
		case 17: res = 2363; break;
		case 18: res = 2400; break;
		case 19: res = 2303; break;
		case 20: res = 1705; break;
		case 21: res = 1585; break;
		case 22: res = 2136; break;
		case 23: res = 2360; break;
		case 24: res = 2321; break;
		case 25: res = 2508; break;
		case 26: res = 2290; break;
		case 27: res = 1833; break;
		case 28: res = 1602; break;
		case 29: res = 2220; break;
		case 30: res = 2286; break;
		case 31: res = 2304; break;
		case 32: res = 2429; break;
		case 33: res = 2316; break;
		case 34: res = 1856; break;
		case 35: res = 1628; break;
		case 36: res = 1995; break;
		case 37: res = 2159; break;
		case 38: res = 2157; break;
		case 39: res = 2210; break;
		case 40: res = 2186; break;
		case 41: res = 1664; break;
		case 42: res = 1242; break;
		case 43: res = 1605; break;
		case 44: res = 1696; break;
		case 45: res = 1537; break;
		case 46: res = 1547; break;
		case 47: res = 1571; break;
		case 48: res = 1289; break;
		default: break;
	}
	return res;
}

#endif
