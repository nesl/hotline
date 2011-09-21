#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1211; break;
		case 1: res = 1625; break;
		case 2: res = 1677; break;
		case 3: res = 1820; break;
		case 4: res = 1775; break;
		case 5: res = 1567; break;
		case 6: res = 1224; break;
		case 7: res = 1617; break;
		case 8: res = 2199; break;
		case 9: res = 2340; break;
		case 10: res = 2241; break;
		case 11: res = 2377; break;
		case 12: res = 2173; break;
		case 13: res = 1623; break;
		case 14: res = 1634; break;
		case 15: res = 2167; break;
		case 16: res = 2295; break;
		case 17: res = 2425; break;
		case 18: res = 2457; break;
		case 19: res = 2275; break;
		case 20: res = 1563; break;
		case 21: res = 1652; break;
		case 22: res = 1982; break;
		case 23: res = 2307; break;
		case 24: res = 2350; break;
		case 25: res = 2475; break;
		case 26: res = 2166; break;
		case 27: res = 1637; break;
		case 28: res = 1508; break;
		case 29: res = 2122; break;
		case 30: res = 2331; break;
		case 31: res = 2406; break;
		case 32: res = 2535; break;
		case 33: res = 2296; break;
		case 34: res = 1695; break;
		case 35: res = 1449; break;
		case 36: res = 1933; break;
		case 37: res = 2153; break;
		case 38: res = 2311; break;
		case 39: res = 2452; break;
		case 40: res = 2255; break;
		case 41: res = 1573; break;
		case 42: res = 1131; break;
		case 43: res = 1414; break;
		case 44: res = 1585; break;
		case 45: res = 1700; break;
		case 46: res = 1767; break;
		case 47: res = 1585; break;
		case 48: res = 1205; break;
		default: break;
	}
	return res;
}

#endif
