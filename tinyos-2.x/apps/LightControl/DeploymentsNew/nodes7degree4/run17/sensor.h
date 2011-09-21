#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1154; break;
		case 1: res = 1545; break;
		case 2: res = 1697; break;
		case 3: res = 1837; break;
		case 4: res = 1854; break;
		case 5: res = 1704; break;
		case 6: res = 1285; break;
		case 7: res = 1541; break;
		case 8: res = 2044; break;
		case 9: res = 2242; break;
		case 10: res = 2123; break;
		case 11: res = 2320; break;
		case 12: res = 2105; break;
		case 13: res = 1641; break;
		case 14: res = 1597; break;
		case 15: res = 2102; break;
		case 16: res = 2214; break;
		case 17: res = 2292; break;
		case 18: res = 2222; break;
		case 19: res = 2142; break;
		case 20: res = 1573; break;
		case 21: res = 1638; break;
		case 22: res = 2006; break;
		case 23: res = 2275; break;
		case 24: res = 2123; break;
		case 25: res = 2185; break;
		case 26: res = 2023; break;
		case 27: res = 1624; break;
		case 28: res = 1509; break;
		case 29: res = 2172; break;
		case 30: res = 2283; break;
		case 31: res = 2264; break;
		case 32: res = 2105; break;
		case 33: res = 2123; break;
		case 34: res = 1578; break;
		case 35: res = 1569; break;
		case 36: res = 2066; break;
		case 37: res = 2277; break;
		case 38: res = 2149; break;
		case 39: res = 2207; break;
		case 40: res = 1971; break;
		case 41: res = 1500; break;
		case 42: res = 1299; break;
		case 43: res = 1692; break;
		case 44: res = 1828; break;
		case 45: res = 1764; break;
		case 46: res = 1633; break;
		case 47: res = 1466; break;
		case 48: res = 1148; break;
		default: break;
	}
	return res;
}

#endif
