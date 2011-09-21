#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1176; break;
		case 1: res = 1616; break;
		case 2: res = 1714; break;
		case 3: res = 1549; break;
		case 4: res = 1303; break;
		case 5: res = 1592; break;
		case 6: res = 2106; break;
		case 7: res = 2229; break;
		case 8: res = 2062; break;
		case 9: res = 1582; break;
		case 10: res = 1699; break;
		case 11: res = 2158; break;
		case 12: res = 2317; break;
		case 13: res = 2142; break;
		case 14: res = 1550; break;
		case 15: res = 1538; break;
		case 16: res = 1938; break;
		case 17: res = 2014; break;
		case 18: res = 1902; break;
		case 19: res = 1411; break;
		case 20: res = 1138; break;
		case 21: res = 1554; break;
		case 22: res = 1562; break;
		case 23: res = 1432; break;
		case 24: res = 1132; break;
		default: break;
	}
	return res;
}

#endif
