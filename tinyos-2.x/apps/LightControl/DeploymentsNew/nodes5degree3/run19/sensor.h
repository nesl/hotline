#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 797; break;
		case 1: res = 1205; break;
		case 2: res = 1246; break;
		case 3: res = 1225; break;
		case 4: res = 792; break;
		case 5: res = 1115; break;
		case 6: res = 1526; break;
		case 7: res = 1533; break;
		case 8: res = 1585; break;
		case 9: res = 1189; break;
		case 10: res = 1049; break;
		case 11: res = 1475; break;
		case 12: res = 1480; break;
		case 13: res = 1618; break;
		case 14: res = 1188; break;
		case 15: res = 1077; break;
		case 16: res = 1512; break;
		case 17: res = 1481; break;
		case 18: res = 1539; break;
		case 19: res = 1108; break;
		case 20: res = 765; break;
		case 21: res = 1099; break;
		case 22: res = 1110; break;
		case 23: res = 1131; break;
		case 24: res = 718; break;
		default: break;
	}
	return res;
}

#endif
