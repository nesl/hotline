#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 800; break;
		case 1: res = 1045; break;
		case 2: res = 1054; break;
		case 3: res = 1120; break;
		case 4: res = 1196; break;
		case 5: res = 1204; break;
		case 6: res = 798; break;
		case 7: res = 1189; break;
		case 8: res = 1494; break;
		case 9: res = 1424; break;
		case 10: res = 1574; break;
		case 11: res = 1648; break;
		case 12: res = 1644; break;
		case 13: res = 1153; break;
		case 14: res = 1157; break;
		case 15: res = 1605; break;
		case 16: res = 1495; break;
		case 17: res = 1584; break;
		case 18: res = 1660; break;
		case 19: res = 1656; break;
		case 20: res = 1117; break;
		case 21: res = 1235; break;
		case 22: res = 1670; break;
		case 23: res = 1483; break;
		case 24: res = 1566; break;
		case 25: res = 1469; break;
		case 26: res = 1551; break;
		case 27: res = 1001; break;
		case 28: res = 1143; break;
		case 29: res = 1646; break;
		case 30: res = 1459; break;
		case 31: res = 1550; break;
		case 32: res = 1433; break;
		case 33: res = 1545; break;
		case 34: res = 1030; break;
		case 35: res = 1085; break;
		case 36: res = 1549; break;
		case 37: res = 1628; break;
		case 38: res = 1608; break;
		case 39: res = 1463; break;
		case 40: res = 1429; break;
		case 41: res = 1058; break;
		case 42: res = 749; break;
		case 43: res = 1209; break;
		case 44: res = 1204; break;
		case 45: res = 1206; break;
		case 46: res = 1105; break;
		case 47: res = 1098; break;
		case 48: res = 727; break;
		default: break;
	}
	return res;
}

#endif
