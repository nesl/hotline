#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1238; break;
		case 1: res = 1640; break;
		case 2: res = 1630; break;
		case 3: res = 1732; break;
		case 4: res = 1775; break;
		case 5: res = 1589; break;
		case 6: res = 1168; break;
		case 7: res = 1710; break;
		case 8: res = 2252; break;
		case 9: res = 2409; break;
		case 10: res = 2298; break;
		case 11: res = 2337; break;
		case 12: res = 2163; break;
		case 13: res = 1630; break;
		case 14: res = 1919; break;
		case 15: res = 2419; break;
		case 16: res = 2630; break;
		case 17: res = 2499; break;
		case 18: res = 2443; break;
		case 19: res = 2338; break;
		case 20: res = 1670; break;
		case 21: res = 1858; break;
		case 22: res = 2443; break;
		case 23: res = 2491; break;
		case 24: res = 2398; break;
		case 25: res = 2438; break;
		case 26: res = 2171; break;
		case 27: res = 1631; break;
		case 28: res = 1666; break;
		case 29: res = 2372; break;
		case 30: res = 2403; break;
		case 31: res = 2202; break;
		case 32: res = 2231; break;
		case 33: res = 2050; break;
		case 34: res = 1593; break;
		case 35: res = 1540; break;
		case 36: res = 2027; break;
		case 37: res = 2150; break;
		case 38: res = 2094; break;
		case 39: res = 1972; break;
		case 40: res = 1944; break;
		case 41: res = 1458; break;
		case 42: res = 1256; break;
		case 43: res = 1486; break;
		case 44: res = 1703; break;
		case 45: res = 1538; break;
		case 46: res = 1487; break;
		case 47: res = 1374; break;
		case 48: res = 1092; break;
		default: break;
	}
	return res;
}

#endif
