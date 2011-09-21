#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1206; break;
		case 1: res = 1561; break;
		case 2: res = 1657; break;
		case 3: res = 1472; break;
		case 4: res = 1139; break;
		case 5: res = 1509; break;
		case 6: res = 2007; break;
		case 7: res = 2110; break;
		case 8: res = 1924; break;
		case 9: res = 1416; break;
		case 10: res = 1513; break;
		case 11: res = 1906; break;
		case 12: res = 2111; break;
		case 13: res = 2028; break;
		case 14: res = 1615; break;
		case 15: res = 1306; break;
		case 16: res = 1757; break;
		case 17: res = 1928; break;
		case 18: res = 1925; break;
		case 19: res = 1429; break;
		case 20: res = 1063; break;
		case 21: res = 1414; break;
		case 22: res = 1574; break;
		case 23: res = 1563; break;
		case 24: res = 1230; break;
		default: break;
	}
	return res;
}

#endif
