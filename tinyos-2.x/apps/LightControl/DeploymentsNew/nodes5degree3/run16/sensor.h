#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 752; break;
		case 1: res = 1074; break;
		case 2: res = 1137; break;
		case 3: res = 1219; break;
		case 4: res = 866; break;
		case 5: res = 1100; break;
		case 6: res = 1506; break;
		case 7: res = 1547; break;
		case 8: res = 1572; break;
		case 9: res = 1178; break;
		case 10: res = 1101; break;
		case 11: res = 1659; break;
		case 12: res = 1745; break;
		case 13: res = 1696; break;
		case 14: res = 1130; break;
		case 15: res = 1190; break;
		case 16: res = 1696; break;
		case 17: res = 1771; break;
		case 18: res = 1690; break;
		case 19: res = 1192; break;
		case 20: res = 857; break;
		case 21: res = 1165; break;
		case 22: res = 1245; break;
		case 23: res = 1273; break;
		case 24: res = 888; break;
		default: break;
	}
	return res;
}

#endif
