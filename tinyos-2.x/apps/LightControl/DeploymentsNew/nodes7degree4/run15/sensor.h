#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1216; break;
		case 1: res = 1541; break;
		case 2: res = 1551; break;
		case 3: res = 1627; break;
		case 4: res = 1678; break;
		case 5: res = 1429; break;
		case 6: res = 1046; break;
		case 7: res = 1543; break;
		case 8: res = 2085; break;
		case 9: res = 2167; break;
		case 10: res = 2045; break;
		case 11: res = 2102; break;
		case 12: res = 2050; break;
		case 13: res = 1480; break;
		case 14: res = 1692; break;
		case 15: res = 2173; break;
		case 16: res = 2290; break;
		case 17: res = 2370; break;
		case 18: res = 2455; break;
		case 19: res = 2167; break;
		case 20: res = 1624; break;
		case 21: res = 1769; break;
		case 22: res = 2203; break;
		case 23: res = 2454; break;
		case 24: res = 2405; break;
		case 25: res = 2511; break;
		case 26: res = 2236; break;
		case 27: res = 1708; break;
		case 28: res = 1565; break;
		case 29: res = 2304; break;
		case 30: res = 2449; break;
		case 31: res = 2390; break;
		case 32: res = 2486; break;
		case 33: res = 2283; break;
		case 34: res = 1660; break;
		case 35: res = 1439; break;
		case 36: res = 1974; break;
		case 37: res = 2264; break;
		case 38: res = 2250; break;
		case 39: res = 2252; break;
		case 40: res = 2113; break;
		case 41: res = 1499; break;
		case 42: res = 1148; break;
		case 43: res = 1483; break;
		case 44: res = 1656; break;
		case 45: res = 1716; break;
		case 46: res = 1658; break;
		case 47: res = 1470; break;
		case 48: res = 1168; break;
		default: break;
	}
	return res;
}

#endif
