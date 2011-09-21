#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 639; break;
		case 1: res = 938; break;
		case 2: res = 1019; break;
		case 3: res = 1024; break;
		case 4: res = 935; break;
		case 5: res = 1038; break;
		case 6: res = 735; break;
		case 7: res = 1031; break;
		case 8: res = 1385; break;
		case 9: res = 1347; break;
		case 10: res = 1415; break;
		case 11: res = 1377; break;
		case 12: res = 1484; break;
		case 13: res = 1114; break;
		case 14: res = 1069; break;
		case 15: res = 1558; break;
		case 16: res = 1450; break;
		case 17: res = 1409; break;
		case 18: res = 1502; break;
		case 19: res = 1597; break;
		case 20: res = 1190; break;
		case 21: res = 1203; break;
		case 22: res = 1705; break;
		case 23: res = 1540; break;
		case 24: res = 1583; break;
		case 25: res = 1580; break;
		case 26: res = 1750; break;
		case 27: res = 1213; break;
		case 28: res = 1129; break;
		case 29: res = 1716; break;
		case 30: res = 1676; break;
		case 31: res = 1719; break;
		case 32: res = 1618; break;
		case 33: res = 1725; break;
		case 34: res = 1199; break;
		case 35: res = 1171; break;
		case 36: res = 1668; break;
		case 37: res = 1807; break;
		case 38: res = 1781; break;
		case 39: res = 1636; break;
		case 40: res = 1605; break;
		case 41: res = 1183; break;
		case 42: res = 814; break;
		case 43: res = 1257; break;
		case 44: res = 1299; break;
		case 45: res = 1253; break;
		case 46: res = 1153; break;
		case 47: res = 1159; break;
		case 48: res = 798; break;
		default: break;
	}
	return res;
}

#endif
