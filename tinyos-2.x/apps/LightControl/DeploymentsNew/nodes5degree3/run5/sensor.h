#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 855; break;
		case 1: res = 1217; break;
		case 2: res = 1091; break;
		case 3: res = 1076; break;
		case 4: res = 693; break;
		case 5: res = 1182; break;
		case 6: res = 1607; break;
		case 7: res = 1469; break;
		case 8: res = 1415; break;
		case 9: res = 1011; break;
		case 10: res = 1130; break;
		case 11: res = 1647; break;
		case 12: res = 1627; break;
		case 13: res = 1545; break;
		case 14: res = 1014; break;
		case 15: res = 1141; break;
		case 16: res = 1690; break;
		case 17: res = 1763; break;
		case 18: res = 1749; break;
		case 19: res = 1181; break;
		case 20: res = 791; break;
		case 21: res = 1174; break;
		case 22: res = 1272; break;
		case 23: res = 1341; break;
		case 24: res = 866; break;
		default: break;
	}
	return res;
}

#endif
