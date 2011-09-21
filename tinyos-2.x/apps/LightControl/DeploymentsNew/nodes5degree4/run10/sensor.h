#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 982; break;
		case 1: res = 1352; break;
		case 2: res = 1503; break;
		case 3: res = 1447; break;
		case 4: res = 1156; break;
		case 5: res = 1383; break;
		case 6: res = 1794; break;
		case 7: res = 2057; break;
		case 8: res = 2011; break;
		case 9: res = 1528; break;
		case 10: res = 1489; break;
		case 11: res = 2053; break;
		case 12: res = 2285; break;
		case 13: res = 2133; break;
		case 14: res = 1590; break;
		case 15: res = 1499; break;
		case 16: res = 1959; break;
		case 17: res = 2125; break;
		case 18: res = 1994; break;
		case 19: res = 1484; break;
		case 20: res = 1282; break;
		case 21: res = 1686; break;
		case 22: res = 1696; break;
		case 23: res = 1610; break;
		case 24: res = 1178; break;
		default: break;
	}
	return res;
}

#endif
