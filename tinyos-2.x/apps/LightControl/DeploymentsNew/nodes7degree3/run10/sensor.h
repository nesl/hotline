#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 856; break;
		case 1: res = 1125; break;
		case 2: res = 1082; break;
		case 3: res = 1034; break;
		case 4: res = 1066; break;
		case 5: res = 1120; break;
		case 6: res = 812; break;
		case 7: res = 1127; break;
		case 8: res = 1488; break;
		case 9: res = 1424; break;
		case 10: res = 1485; break;
		case 11: res = 1470; break;
		case 12: res = 1498; break;
		case 13: res = 1136; break;
		case 14: res = 1042; break;
		case 15: res = 1519; break;
		case 16: res = 1495; break;
		case 17: res = 1554; break;
		case 18: res = 1577; break;
		case 19: res = 1543; break;
		case 20: res = 1147; break;
		case 21: res = 1177; break;
		case 22: res = 1564; break;
		case 23: res = 1510; break;
		case 24: res = 1595; break;
		case 25: res = 1566; break;
		case 26: res = 1663; break;
		case 27: res = 1194; break;
		case 28: res = 1162; break;
		case 29: res = 1530; break;
		case 30: res = 1493; break;
		case 31: res = 1555; break;
		case 32: res = 1599; break;
		case 33: res = 1660; break;
		case 34: res = 1223; break;
		case 35: res = 1224; break;
		case 36: res = 1570; break;
		case 37: res = 1611; break;
		case 38: res = 1560; break;
		case 39: res = 1602; break;
		case 40: res = 1623; break;
		case 41: res = 1223; break;
		case 42: res = 773; break;
		case 43: res = 1144; break;
		case 44: res = 1092; break;
		case 45: res = 1108; break;
		case 46: res = 1130; break;
		case 47: res = 1160; break;
		case 48: res = 759; break;
		default: break;
	}
	return res;
}

#endif
