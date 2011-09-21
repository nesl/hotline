#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 799; break;
		case 1: res = 1195; break;
		case 2: res = 1141; break;
		case 3: res = 1089; break;
		case 4: res = 681; break;
		case 5: res = 1220; break;
		case 6: res = 1608; break;
		case 7: res = 1506; break;
		case 8: res = 1489; break;
		case 9: res = 1118; break;
		case 10: res = 1179; break;
		case 11: res = 1563; break;
		case 12: res = 1500; break;
		case 13: res = 1518; break;
		case 14: res = 1092; break;
		case 15: res = 1132; break;
		case 16: res = 1529; break;
		case 17: res = 1568; break;
		case 18: res = 1678; break;
		case 19: res = 1248; break;
		case 20: res = 701; break;
		case 21: res = 1012; break;
		case 22: res = 1103; break;
		case 23: res = 1228; break;
		case 24: res = 822; break;
		default: break;
	}
	return res;
}

#endif
