#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 714; break;
		case 1: res = 1039; break;
		case 2: res = 1062; break;
		case 3: res = 1081; break;
		case 4: res = 729; break;
		case 5: res = 1095; break;
		case 6: res = 1456; break;
		case 7: res = 1512; break;
		case 8: res = 1452; break;
		case 9: res = 1100; break;
		case 10: res = 1002; break;
		case 11: res = 1441; break;
		case 12: res = 1603; break;
		case 13: res = 1556; break;
		case 14: res = 1091; break;
		case 15: res = 1112; break;
		case 16: res = 1580; break;
		case 17: res = 1728; break;
		case 18: res = 1695; break;
		case 19: res = 1198; break;
		case 20: res = 731; break;
		case 21: res = 1055; break;
		case 22: res = 1164; break;
		case 23: res = 1243; break;
		case 24: res = 815; break;
		default: break;
	}
	return res;
}

#endif
