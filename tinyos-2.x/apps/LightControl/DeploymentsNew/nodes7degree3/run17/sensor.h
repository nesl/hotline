#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 853; break;
		case 1: res = 1120; break;
		case 2: res = 1158; break;
		case 3: res = 1052; break;
		case 4: res = 1091; break;
		case 5: res = 1109; break;
		case 6: res = 824; break;
		case 7: res = 1104; break;
		case 8: res = 1462; break;
		case 9: res = 1513; break;
		case 10: res = 1554; break;
		case 11: res = 1547; break;
		case 12: res = 1486; break;
		case 13: res = 1109; break;
		case 14: res = 1054; break;
		case 15: res = 1510; break;
		case 16: res = 1449; break;
		case 17: res = 1481; break;
		case 18: res = 1501; break;
		case 19: res = 1483; break;
		case 20: res = 1043; break;
		case 21: res = 1142; break;
		case 22: res = 1525; break;
		case 23: res = 1514; break;
		case 24: res = 1627; break;
		case 25: res = 1527; break;
		case 26: res = 1512; break;
		case 27: res = 961; break;
		case 28: res = 1155; break;
		case 29: res = 1573; break;
		case 30: res = 1495; break;
		case 31: res = 1642; break;
		case 32: res = 1590; break;
		case 33: res = 1660; break;
		case 34: res = 1103; break;
		case 35: res = 1153; break;
		case 36: res = 1586; break;
		case 37: res = 1697; break;
		case 38: res = 1709; break;
		case 39: res = 1666; break;
		case 40: res = 1661; break;
		case 41: res = 1212; break;
		case 42: res = 752; break;
		case 43: res = 1213; break;
		case 44: res = 1181; break;
		case 45: res = 1194; break;
		case 46: res = 1183; break;
		case 47: res = 1294; break;
		case 48: res = 889; break;
		default: break;
	}
	return res;
}

#endif
