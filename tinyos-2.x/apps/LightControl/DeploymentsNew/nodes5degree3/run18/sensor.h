#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 779; break;
		case 1: res = 1098; break;
		case 2: res = 1166; break;
		case 3: res = 1220; break;
		case 4: res = 868; break;
		case 5: res = 1136; break;
		case 6: res = 1454; break;
		case 7: res = 1487; break;
		case 8: res = 1587; break;
		case 9: res = 1270; break;
		case 10: res = 1080; break;
		case 11: res = 1497; break;
		case 12: res = 1551; break;
		case 13: res = 1585; break;
		case 14: res = 1139; break;
		case 15: res = 1163; break;
		case 16: res = 1509; break;
		case 17: res = 1557; break;
		case 18: res = 1633; break;
		case 19: res = 1261; break;
		case 20: res = 804; break;
		case 21: res = 1048; break;
		case 22: res = 1128; break;
		case 23: res = 1189; break;
		case 24: res = 852; break;
		default: break;
	}
	return res;
}

#endif
