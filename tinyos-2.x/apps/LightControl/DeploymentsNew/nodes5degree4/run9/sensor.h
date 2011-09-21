#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1004; break;
		case 1: res = 1374; break;
		case 2: res = 1525; break;
		case 3: res = 1456; break;
		case 4: res = 1257; break;
		case 5: res = 1487; break;
		case 6: res = 1961; break;
		case 7: res = 2087; break;
		case 8: res = 2021; break;
		case 9: res = 1512; break;
		case 10: res = 1791; break;
		case 11: res = 2310; break;
		case 12: res = 2415; break;
		case 13: res = 2163; break;
		case 14: res = 1662; break;
		case 15: res = 1740; break;
		case 16: res = 2244; break;
		case 17: res = 2276; break;
		case 18: res = 2016; break;
		case 19: res = 1488; break;
		case 20: res = 1324; break;
		case 21: res = 1727; break;
		case 22: res = 1734; break;
		case 23: res = 1555; break;
		case 24: res = 1167; break;
		default: break;
	}
	return res;
}

#endif
