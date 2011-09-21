#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1176; break;
		case 1: res = 1571; break;
		case 2: res = 1726; break;
		case 3: res = 1634; break;
		case 4: res = 1569; break;
		case 5: res = 1443; break;
		case 6: res = 1110; break;
		case 7: res = 1560; break;
		case 8: res = 2123; break;
		case 9: res = 2246; break;
		case 10: res = 2207; break;
		case 11: res = 2221; break;
		case 12: res = 1966; break;
		case 13: res = 1579; break;
		case 14: res = 1683; break;
		case 15: res = 2106; break;
		case 16: res = 2370; break;
		case 17: res = 2482; break;
		case 18: res = 2426; break;
		case 19: res = 2249; break;
		case 20: res = 1669; break;
		case 21: res = 1561; break;
		case 22: res = 2055; break;
		case 23: res = 2420; break;
		case 24: res = 2448; break;
		case 25: res = 2526; break;
		case 26: res = 2262; break;
		case 27: res = 1823; break;
		case 28: res = 1487; break;
		case 29: res = 2107; break;
		case 30: res = 2472; break;
		case 31: res = 2488; break;
		case 32: res = 2511; break;
		case 33: res = 2379; break;
		case 34: res = 1707; break;
		case 35: res = 1501; break;
		case 36: res = 1996; break;
		case 37: res = 2270; break;
		case 38: res = 2464; break;
		case 39: res = 2496; break;
		case 40: res = 2182; break;
		case 41: res = 1568; break;
		case 42: res = 1257; break;
		case 43: res = 1556; break;
		case 44: res = 1770; break;
		case 45: res = 1847; break;
		case 46: res = 1751; break;
		case 47: res = 1536; break;
		case 48: res = 1175; break;
		default: break;
	}
	return res;
}

#endif
