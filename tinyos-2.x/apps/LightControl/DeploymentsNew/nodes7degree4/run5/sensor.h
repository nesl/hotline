#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1289; break;
		case 1: res = 1602; break;
		case 2: res = 1565; break;
		case 3: res = 1549; break;
		case 4: res = 1581; break;
		case 5: res = 1466; break;
		case 6: res = 1099; break;
		case 7: res = 1774; break;
		case 8: res = 2218; break;
		case 9: res = 2155; break;
		case 10: res = 1952; break;
		case 11: res = 2037; break;
		case 12: res = 1964; break;
		case 13: res = 1483; break;
		case 14: res = 1991; break;
		case 15: res = 2399; break;
		case 16: res = 2320; break;
		case 17: res = 2223; break;
		case 18: res = 2211; break;
		case 19: res = 2060; break;
		case 20: res = 1554; break;
		case 21: res = 1977; break;
		case 22: res = 2416; break;
		case 23: res = 2438; break;
		case 24: res = 2287; break;
		case 25: res = 2310; break;
		case 26: res = 2064; break;
		case 27: res = 1528; break;
		case 28: res = 1733; break;
		case 29: res = 2437; break;
		case 30: res = 2578; break;
		case 31: res = 2303; break;
		case 32: res = 2326; break;
		case 33: res = 2180; break;
		case 34: res = 1579; break;
		case 35: res = 1632; break;
		case 36: res = 2136; break;
		case 37: res = 2332; break;
		case 38: res = 2345; break;
		case 39: res = 2284; break;
		case 40: res = 2168; break;
		case 41: res = 1499; break;
		case 42: res = 1209; break;
		case 43: res = 1596; break;
		case 44: res = 1755; break;
		case 45: res = 1798; break;
		case 46: res = 1800; break;
		case 47: res = 1535; break;
		case 48: res = 1218; break;
		default: break;
	}
	return res;
}

#endif
