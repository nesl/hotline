#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1120; break;
		case 1: res = 1559; break;
		case 2: res = 1780; break;
		case 3: res = 1637; break;
		case 4: res = 1279; break;
		case 5: res = 1517; break;
		case 6: res = 2087; break;
		case 7: res = 2261; break;
		case 8: res = 2138; break;
		case 9: res = 1571; break;
		case 10: res = 1655; break;
		case 11: res = 2125; break;
		case 12: res = 2289; break;
		case 13: res = 2231; break;
		case 14: res = 1660; break;
		case 15: res = 1488; break;
		case 16: res = 2024; break;
		case 17: res = 2187; break;
		case 18: res = 2049; break;
		case 19: res = 1483; break;
		case 20: res = 1265; break;
		case 21: res = 1639; break;
		case 22: res = 1763; break;
		case 23: res = 1590; break;
		case 24: res = 1264; break;
		default: break;
	}
	return res;
}

#endif
