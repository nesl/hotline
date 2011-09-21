#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 902; break;
		case 1: res = 1292; break;
		case 2: res = 1283; break;
		case 3: res = 1302; break;
		case 4: res = 873; break;
		case 5: res = 1244; break;
		case 6: res = 1709; break;
		case 7: res = 1660; break;
		case 8: res = 1677; break;
		case 9: res = 1208; break;
		case 10: res = 1114; break;
		case 11: res = 1687; break;
		case 12: res = 1695; break;
		case 13: res = 1719; break;
		case 14: res = 1129; break;
		case 15: res = 1182; break;
		case 16: res = 1755; break;
		case 17: res = 1828; break;
		case 18: res = 1779; break;
		case 19: res = 1220; break;
		case 20: res = 831; break;
		case 21: res = 1217; break;
		case 22: res = 1330; break;
		case 23: res = 1333; break;
		case 24: res = 883; break;
		default: break;
	}
	return res;
}

#endif
