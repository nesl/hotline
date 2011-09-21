#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1016; break;
		case 1: res = 1371; break;
		case 2: res = 1498; break;
		case 3: res = 1391; break;
		case 4: res = 1148; break;
		case 5: res = 1418; break;
		case 6: res = 1934; break;
		case 7: res = 2111; break;
		case 8: res = 2021; break;
		case 9: res = 1529; break;
		case 10: res = 1565; break;
		case 11: res = 2178; break;
		case 12: res = 2373; break;
		case 13: res = 2234; break;
		case 14: res = 1712; break;
		case 15: res = 1458; break;
		case 16: res = 2000; break;
		case 17: res = 2211; break;
		case 18: res = 2116; break;
		case 19: res = 1583; break;
		case 20: res = 1136; break;
		case 21: res = 1567; break;
		case 22: res = 1746; break;
		case 23: res = 1646; break;
		case 24: res = 1247; break;
		default: break;
	}
	return res;
}

#endif
