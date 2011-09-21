#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1211; break;
		case 1: res = 1609; break;
		case 2: res = 1644; break;
		case 3: res = 1696; break;
		case 4: res = 1685; break;
		case 5: res = 1438; break;
		case 6: res = 1125; break;
		case 7: res = 1798; break;
		case 8: res = 2254; break;
		case 9: res = 2317; break;
		case 10: res = 2150; break;
		case 11: res = 2214; break;
		case 12: res = 1990; break;
		case 13: res = 1514; break;
		case 14: res = 1983; break;
		case 15: res = 2415; break;
		case 16: res = 2533; break;
		case 17: res = 2424; break;
		case 18: res = 2217; break;
		case 19: res = 2124; break;
		case 20: res = 1614; break;
		case 21: res = 2001; break;
		case 22: res = 2362; break;
		case 23: res = 2488; break;
		case 24: res = 2307; break;
		case 25: res = 2323; break;
		case 26: res = 2114; break;
		case 27: res = 1706; break;
		case 28: res = 1808; break;
		case 29: res = 2543; break;
		case 30: res = 2473; break;
		case 31: res = 2334; break;
		case 32: res = 2268; break;
		case 33: res = 2170; break;
		case 34: res = 1697; break;
		case 35: res = 1746; break;
		case 36: res = 2224; break;
		case 37: res = 2425; break;
		case 38: res = 2338; break;
		case 39: res = 2272; break;
		case 40: res = 1984; break;
		case 41: res = 1501; break;
		case 42: res = 1399; break;
		case 43: res = 1723; break;
		case 44: res = 1909; break;
		case 45: res = 1816; break;
		case 46: res = 1604; break;
		case 47: res = 1428; break;
		case 48: res = 1142; break;
		default: break;
	}
	return res;
}

#endif
