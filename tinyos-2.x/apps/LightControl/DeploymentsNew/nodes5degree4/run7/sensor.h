#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1094; break;
		case 1: res = 1555; break;
		case 2: res = 1677; break;
		case 3: res = 1550; break;
		case 4: res = 1199; break;
		case 5: res = 1483; break;
		case 6: res = 2055; break;
		case 7: res = 2304; break;
		case 8: res = 2111; break;
		case 9: res = 1523; break;
		case 10: res = 1593; break;
		case 11: res = 2225; break;
		case 12: res = 2528; break;
		case 13: res = 2308; break;
		case 14: res = 1636; break;
		case 15: res = 1492; break;
		case 16: res = 2110; break;
		case 17: res = 2313; break;
		case 18: res = 2153; break;
		case 19: res = 1565; break;
		case 20: res = 1163; break;
		case 21: res = 1678; break;
		case 22: res = 1802; break;
		case 23: res = 1721; break;
		case 24: res = 1240; break;
		default: break;
	}
	return res;
}

#endif
