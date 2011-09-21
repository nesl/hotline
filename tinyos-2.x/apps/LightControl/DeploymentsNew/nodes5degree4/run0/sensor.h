#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1169; break;
		case 1: res = 1613; break;
		case 2: res = 1713; break;
		case 3: res = 1497; break;
		case 4: res = 1282; break;
		case 5: res = 1637; break;
		case 6: res = 2149; break;
		case 7: res = 2269; break;
		case 8: res = 2158; break;
		case 9: res = 1624; break;
		case 10: res = 1788; break;
		case 11: res = 2186; break;
		case 12: res = 2337; break;
		case 13: res = 2318; break;
		case 14: res = 1788; break;
		case 15: res = 1505; break;
		case 16: res = 2027; break;
		case 17: res = 2178; break;
		case 18: res = 2071; break;
		case 19: res = 1582; break;
		case 20: res = 1172; break;
		case 21: res = 1602; break;
		case 22: res = 1655; break;
		case 23: res = 1581; break;
		case 24: res = 1316; break;
		default: break;
	}
	return res;
}

#endif
