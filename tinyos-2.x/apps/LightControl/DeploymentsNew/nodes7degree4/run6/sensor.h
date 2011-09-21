#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 983; break;
		case 1: res = 1401; break;
		case 2: res = 1528; break;
		case 3: res = 1674; break;
		case 4: res = 1602; break;
		case 5: res = 1356; break;
		case 6: res = 1044; break;
		case 7: res = 1430; break;
		case 8: res = 1915; break;
		case 9: res = 2139; break;
		case 10: res = 2162; break;
		case 11: res = 2134; break;
		case 12: res = 1901; break;
		case 13: res = 1445; break;
		case 14: res = 1507; break;
		case 15: res = 2007; break;
		case 16: res = 2302; break;
		case 17: res = 2295; break;
		case 18: res = 2355; break;
		case 19: res = 2027; break;
		case 20: res = 1477; break;
		case 21: res = 1558; break;
		case 22: res = 2115; break;
		case 23: res = 2375; break;
		case 24: res = 2193; break;
		case 25: res = 2259; break;
		case 26: res = 2138; break;
		case 27: res = 1640; break;
		case 28: res = 1618; break;
		case 29: res = 2229; break;
		case 30: res = 2312; break;
		case 31: res = 2363; break;
		case 32: res = 2439; break;
		case 33: res = 2262; break;
		case 34: res = 1709; break;
		case 35: res = 1605; break;
		case 36: res = 2076; break;
		case 37: res = 2278; break;
		case 38: res = 2407; break;
		case 39: res = 2406; break;
		case 40: res = 2271; break;
		case 41: res = 1638; break;
		case 42: res = 1247; break;
		case 43: res = 1642; break;
		case 44: res = 1823; break;
		case 45: res = 1752; break;
		case 46: res = 1823; break;
		case 47: res = 1660; break;
		case 48: res = 1351; break;
		default: break;
	}
	return res;
}

#endif
