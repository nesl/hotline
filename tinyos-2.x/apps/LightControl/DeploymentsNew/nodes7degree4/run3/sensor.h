#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1082; break;
		case 1: res = 1482; break;
		case 2: res = 1565; break;
		case 3: res = 1728; break;
		case 4: res = 1756; break;
		case 5: res = 1531; break;
		case 6: res = 1172; break;
		case 7: res = 1499; break;
		case 8: res = 1981; break;
		case 9: res = 2163; break;
		case 10: res = 2148; break;
		case 11: res = 2304; break;
		case 12: res = 2105; break;
		case 13: res = 1562; break;
		case 14: res = 1572; break;
		case 15: res = 2143; break;
		case 16: res = 2352; break;
		case 17: res = 2383; break;
		case 18: res = 2365; break;
		case 19: res = 2278; break;
		case 20: res = 1708; break;
		case 21: res = 1671; break;
		case 22: res = 2103; break;
		case 23: res = 2395; break;
		case 24: res = 2303; break;
		case 25: res = 2419; break;
		case 26: res = 2252; break;
		case 27: res = 1709; break;
		case 28: res = 1597; break;
		case 29: res = 2273; break;
		case 30: res = 2220; break;
		case 31: res = 2210; break;
		case 32: res = 2385; break;
		case 33: res = 2268; break;
		case 34: res = 1766; break;
		case 35: res = 1572; break;
		case 36: res = 1965; break;
		case 37: res = 2149; break;
		case 38: res = 2130; break;
		case 39: res = 2162; break;
		case 40: res = 2148; break;
		case 41: res = 1616; break;
		case 42: res = 1269; break;
		case 43: res = 1558; break;
		case 44: res = 1677; break;
		case 45: res = 1590; break;
		case 46: res = 1625; break;
		case 47: res = 1530; break;
		case 48: res = 1293; break;
		default: break;
	}
	return res;
}

#endif
