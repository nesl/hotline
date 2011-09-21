#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 835; break;
		case 1: res = 1073; break;
		case 2: res = 1152; break;
		case 3: res = 1117; break;
		case 4: res = 1121; break;
		case 5: res = 1075; break;
		case 6: res = 726; break;
		case 7: res = 1177; break;
		case 8: res = 1521; break;
		case 9: res = 1487; break;
		case 10: res = 1560; break;
		case 11: res = 1518; break;
		case 12: res = 1443; break;
		case 13: res = 1029; break;
		case 14: res = 1125; break;
		case 15: res = 1539; break;
		case 16: res = 1373; break;
		case 17: res = 1468; break;
		case 18: res = 1558; break;
		case 19: res = 1564; break;
		case 20: res = 1123; break;
		case 21: res = 1246; break;
		case 22: res = 1657; break;
		case 23: res = 1535; break;
		case 24: res = 1625; break;
		case 25: res = 1558; break;
		case 26: res = 1598; break;
		case 27: res = 1110; break;
		case 28: res = 1188; break;
		case 29: res = 1588; break;
		case 30: res = 1544; break;
		case 31: res = 1594; break;
		case 32: res = 1608; break;
		case 33: res = 1668; break;
		case 34: res = 1164; break;
		case 35: res = 1171; break;
		case 36: res = 1585; break;
		case 37: res = 1761; break;
		case 38: res = 1622; break;
		case 39: res = 1559; break;
		case 40: res = 1504; break;
		case 41: res = 1135; break;
		case 42: res = 751; break;
		case 43: res = 1158; break;
		case 44: res = 1205; break;
		case 45: res = 1120; break;
		case 46: res = 1112; break;
		case 47: res = 1143; break;
		case 48: res = 791; break;
		default: break;
	}
	return res;
}

#endif
