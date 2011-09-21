#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1094; break;
		case 1: res = 1388; break;
		case 2: res = 1410; break;
		case 3: res = 1513; break;
		case 4: res = 1542; break;
		case 5: res = 1430; break;
		case 6: res = 1145; break;
		case 7: res = 1548; break;
		case 8: res = 1984; break;
		case 9: res = 2029; break;
		case 10: res = 1965; break;
		case 11: res = 2051; break;
		case 12: res = 2055; break;
		case 13: res = 1641; break;
		case 14: res = 1631; break;
		case 15: res = 2020; break;
		case 16: res = 2214; break;
		case 17: res = 2178; break;
		case 18: res = 2231; break;
		case 19: res = 2195; break;
		case 20: res = 1725; break;
		case 21: res = 1688; break;
		case 22: res = 2069; break;
		case 23: res = 2268; break;
		case 24: res = 2171; break;
		case 25: res = 2263; break;
		case 26: res = 2114; break;
		case 27: res = 1772; break;
		case 28: res = 1589; break;
		case 29: res = 2271; break;
		case 30: res = 2358; break;
		case 31: res = 2339; break;
		case 32: res = 2316; break;
		case 33: res = 2136; break;
		case 34: res = 1648; break;
		case 35: res = 1550; break;
		case 36: res = 2079; break;
		case 37: res = 2408; break;
		case 38: res = 2382; break;
		case 39: res = 2235; break;
		case 40: res = 2001; break;
		case 41: res = 1401; break;
		case 42: res = 1235; break;
		case 43: res = 1653; break;
		case 44: res = 1871; break;
		case 45: res = 1831; break;
		case 46: res = 1623; break;
		case 47: res = 1422; break;
		case 48: res = 1079; break;
		default: break;
	}
	return res;
}

#endif
