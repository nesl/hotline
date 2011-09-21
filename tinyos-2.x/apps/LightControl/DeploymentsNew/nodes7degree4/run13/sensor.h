#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1089; break;
		case 1: res = 1326; break;
		case 2: res = 1430; break;
		case 3: res = 1574; break;
		case 4: res = 1574; break;
		case 5: res = 1485; break;
		case 6: res = 1169; break;
		case 7: res = 1472; break;
		case 8: res = 1954; break;
		case 9: res = 2010; break;
		case 10: res = 1927; break;
		case 11: res = 2057; break;
		case 12: res = 2003; break;
		case 13: res = 1608; break;
		case 14: res = 1670; break;
		case 15: res = 2084; break;
		case 16: res = 2280; break;
		case 17: res = 2213; break;
		case 18: res = 2238; break;
		case 19: res = 2162; break;
		case 20: res = 1606; break;
		case 21: res = 1697; break;
		case 22: res = 2217; break;
		case 23: res = 2348; break;
		case 24: res = 2237; break;
		case 25: res = 2295; break;
		case 26: res = 2069; break;
		case 27: res = 1714; break;
		case 28: res = 1584; break;
		case 29: res = 2214; break;
		case 30: res = 2434; break;
		case 31: res = 2302; break;
		case 32: res = 2218; break;
		case 33: res = 2087; break;
		case 34: res = 1661; break;
		case 35: res = 1469; break;
		case 36: res = 2006; break;
		case 37: res = 2246; break;
		case 38: res = 2272; break;
		case 39: res = 2147; break;
		case 40: res = 2018; break;
		case 41: res = 1517; break;
		case 42: res = 1163; break;
		case 43: res = 1514; break;
		case 44: res = 1781; break;
		case 45: res = 1746; break;
		case 46: res = 1669; break;
		case 47: res = 1499; break;
		case 48: res = 1184; break;
		default: break;
	}
	return res;
}

#endif
