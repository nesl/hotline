#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1163; break;
		case 1: res = 1495; break;
		case 2: res = 1658; break;
		case 3: res = 1654; break;
		case 4: res = 1731; break;
		case 5: res = 1510; break;
		case 6: res = 1171; break;
		case 7: res = 1596; break;
		case 8: res = 2151; break;
		case 9: res = 2167; break;
		case 10: res = 2204; break;
		case 11: res = 2211; break;
		case 12: res = 2054; break;
		case 13: res = 1491; break;
		case 14: res = 1783; break;
		case 15: res = 2209; break;
		case 16: res = 2360; break;
		case 17: res = 2206; break;
		case 18: res = 2364; break;
		case 19: res = 2062; break;
		case 20: res = 1536; break;
		case 21: res = 1697; break;
		case 22: res = 2251; break;
		case 23: res = 2256; break;
		case 24: res = 2213; break;
		case 25: res = 2107; break;
		case 26: res = 2022; break;
		case 27: res = 1549; break;
		case 28: res = 1652; break;
		case 29: res = 2137; break;
		case 30: res = 2221; break;
		case 31: res = 2072; break;
		case 32: res = 2185; break;
		case 33: res = 2060; break;
		case 34: res = 1568; break;
		case 35: res = 1536; break;
		case 36: res = 1960; break;
		case 37: res = 2005; break;
		case 38: res = 2030; break;
		case 39: res = 2080; break;
		case 40: res = 2056; break;
		case 41: res = 1486; break;
		case 42: res = 1214; break;
		case 43: res = 1501; break;
		case 44: res = 1623; break;
		case 45: res = 1563; break;
		case 46: res = 1583; break;
		case 47: res = 1441; break;
		case 48: res = 1219; break;
		default: break;
	}
	return res;
}

#endif
