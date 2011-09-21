#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1031; break;
		case 1: res = 1472; break;
		case 2: res = 1734; break;
		case 3: res = 1708; break;
		case 4: res = 1339; break;
		case 5: res = 1426; break;
		case 6: res = 2100; break;
		case 7: res = 2425; break;
		case 8: res = 2268; break;
		case 9: res = 1707; break;
		case 10: res = 1641; break;
		case 11: res = 2257; break;
		case 12: res = 2543; break;
		case 13: res = 2460; break;
		case 14: res = 1787; break;
		case 15: res = 1532; break;
		case 16: res = 2089; break;
		case 17: res = 2296; break;
		case 18: res = 2107; break;
		case 19: res = 1514; break;
		case 20: res = 1180; break;
		case 21: res = 1607; break;
		case 22: res = 1686; break;
		case 23: res = 1580; break;
		case 24: res = 1118; break;
		default: break;
	}
	return res;
}

#endif
