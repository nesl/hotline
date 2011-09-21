#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1178; break;
		case 1: res = 1546; break;
		case 2: res = 1633; break;
		case 3: res = 1704; break;
		case 4: res = 1597; break;
		case 5: res = 1369; break;
		case 6: res = 1036; break;
		case 7: res = 1677; break;
		case 8: res = 2241; break;
		case 9: res = 2321; break;
		case 10: res = 2252; break;
		case 11: res = 2218; break;
		case 12: res = 1963; break;
		case 13: res = 1457; break;
		case 14: res = 1837; break;
		case 15: res = 2348; break;
		case 16: res = 2444; break;
		case 17: res = 2408; break;
		case 18: res = 2408; break;
		case 19: res = 2176; break;
		case 20: res = 1542; break;
		case 21: res = 1790; break;
		case 22: res = 2223; break;
		case 23: res = 2537; break;
		case 24: res = 2304; break;
		case 25: res = 2301; break;
		case 26: res = 2097; break;
		case 27: res = 1651; break;
		case 28: res = 1617; break;
		case 29: res = 2289; break;
		case 30: res = 2319; break;
		case 31: res = 2339; break;
		case 32: res = 2327; break;
		case 33: res = 2235; break;
		case 34: res = 1650; break;
		case 35: res = 1532; break;
		case 36: res = 1984; break;
		case 37: res = 2235; break;
		case 38: res = 2217; break;
		case 39: res = 2333; break;
		case 40: res = 2200; break;
		case 41: res = 1599; break;
		case 42: res = 1088; break;
		case 43: res = 1524; break;
		case 44: res = 1690; break;
		case 45: res = 1779; break;
		case 46: res = 1720; break;
		case 47: res = 1616; break;
		case 48: res = 1270; break;
		default: break;
	}
	return res;
}

#endif
