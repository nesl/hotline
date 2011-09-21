#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 859; break;
		case 1: res = 1245; break;
		case 2: res = 1230; break;
		case 3: res = 1286; break;
		case 4: res = 864; break;
		case 5: res = 1239; break;
		case 6: res = 1639; break;
		case 7: res = 1594; break;
		case 8: res = 1655; break;
		case 9: res = 1273; break;
		case 10: res = 1095; break;
		case 11: res = 1573; break;
		case 12: res = 1584; break;
		case 13: res = 1626; break;
		case 14: res = 1150; break;
		case 15: res = 1117; break;
		case 16: res = 1572; break;
		case 17: res = 1613; break;
		case 18: res = 1699; break;
		case 19: res = 1247; break;
		case 20: res = 746; break;
		case 21: res = 1076; break;
		case 22: res = 1127; break;
		case 23: res = 1224; break;
		case 24: res = 809; break;
		default: break;
	}
	return res;
}

#endif
