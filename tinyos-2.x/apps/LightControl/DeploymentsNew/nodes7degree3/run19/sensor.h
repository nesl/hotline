#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 842; break;
		case 1: res = 1101; break;
		case 2: res = 1088; break;
		case 3: res = 1079; break;
		case 4: res = 1153; break;
		case 5: res = 1218; break;
		case 6: res = 821; break;
		case 7: res = 1111; break;
		case 8: res = 1414; break;
		case 9: res = 1396; break;
		case 10: res = 1553; break;
		case 11: res = 1682; break;
		case 12: res = 1685; break;
		case 13: res = 1194; break;
		case 14: res = 1119; break;
		case 15: res = 1568; break;
		case 16: res = 1498; break;
		case 17: res = 1618; break;
		case 18: res = 1743; break;
		case 19: res = 1684; break;
		case 20: res = 1170; break;
		case 21: res = 1177; break;
		case 22: res = 1613; break;
		case 23: res = 1530; break;
		case 24: res = 1605; break;
		case 25: res = 1579; break;
		case 26: res = 1614; break;
		case 27: res = 1086; break;
		case 28: res = 1169; break;
		case 29: res = 1684; break;
		case 30: res = 1509; break;
		case 31: res = 1481; break;
		case 32: res = 1387; break;
		case 33: res = 1583; break;
		case 34: res = 1143; break;
		case 35: res = 1084; break;
		case 36: res = 1477; break;
		case 37: res = 1521; break;
		case 38: res = 1476; break;
		case 39: res = 1437; break;
		case 40: res = 1558; break;
		case 41: res = 1189; break;
		case 42: res = 696; break;
		case 43: res = 1080; break;
		case 44: res = 1056; break;
		case 45: res = 1123; break;
		case 46: res = 1109; break;
		case 47: res = 1216; break;
		case 48: res = 826; break;
		default: break;
	}
	return res;
}

#endif
