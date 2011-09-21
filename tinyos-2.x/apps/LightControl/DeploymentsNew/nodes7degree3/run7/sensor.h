#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 842; break;
		case 1: res = 1131; break;
		case 2: res = 1212; break;
		case 3: res = 1087; break;
		case 4: res = 1022; break;
		case 5: res = 1038; break;
		case 6: res = 769; break;
		case 7: res = 1169; break;
		case 8: res = 1516; break;
		case 9: res = 1533; break;
		case 10: res = 1467; break;
		case 11: res = 1457; break;
		case 12: res = 1481; break;
		case 13: res = 1142; break;
		case 14: res = 1039; break;
		case 15: res = 1504; break;
		case 16: res = 1530; break;
		case 17: res = 1448; break;
		case 18: res = 1531; break;
		case 19: res = 1548; break;
		case 20: res = 1176; break;
		case 21: res = 1200; break;
		case 22: res = 1668; break;
		case 23: res = 1608; break;
		case 24: res = 1594; break;
		case 25: res = 1468; break;
		case 26: res = 1502; break;
		case 27: res = 1065; break;
		case 28: res = 1139; break;
		case 29: res = 1686; break;
		case 30: res = 1684; break;
		case 31: res = 1716; break;
		case 32: res = 1514; break;
		case 33: res = 1540; break;
		case 34: res = 1095; break;
		case 35: res = 1101; break;
		case 36: res = 1528; break;
		case 37: res = 1666; break;
		case 38: res = 1681; break;
		case 39: res = 1561; break;
		case 40: res = 1502; break;
		case 41: res = 1091; break;
		case 42: res = 656; break;
		case 43: res = 1054; break;
		case 44: res = 1150; break;
		case 45: res = 1227; break;
		case 46: res = 1198; break;
		case 47: res = 1170; break;
		case 48: res = 748; break;
		default: break;
	}
	return res;
}

#endif
