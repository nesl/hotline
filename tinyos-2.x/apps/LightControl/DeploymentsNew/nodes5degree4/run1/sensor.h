#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1213; break;
		case 1: res = 1587; break;
		case 2: res = 1668; break;
		case 3: res = 1407; break;
		case 4: res = 1148; break;
		case 5: res = 1562; break;
		case 6: res = 2089; break;
		case 7: res = 2151; break;
		case 8: res = 1916; break;
		case 9: res = 1467; break;
		case 10: res = 1662; break;
		case 11: res = 2092; break;
		case 12: res = 2260; break;
		case 13: res = 2169; break;
		case 14: res = 1585; break;
		case 15: res = 1407; break;
		case 16: res = 1889; break;
		case 17: res = 2129; break;
		case 18: res = 2143; break;
		case 19: res = 1551; break;
		case 20: res = 1070; break;
		case 21: res = 1551; break;
		case 22: res = 1698; break;
		case 23: res = 1641; break;
		case 24: res = 1322; break;
		default: break;
	}
	return res;
}

#endif
