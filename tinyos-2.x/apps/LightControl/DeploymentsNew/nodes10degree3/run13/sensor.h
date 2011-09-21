#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 758; break;
		case 1: res = 1162; break;
		case 2: res = 1252; break;
		case 3: res = 1341; break;
		case 4: res = 1311; break;
		case 5: res = 1310; break;
		case 6: res = 1277; break;
		case 7: res = 1142; break;
		case 8: res = 1040; break;
		case 9: res = 697; break;
		case 10: res = 1142; break;
		case 11: res = 1595; break;
		case 12: res = 1690; break;
		case 13: res = 1712; break;
		case 14: res = 1665; break;
		case 15: res = 1686; break;
		case 16: res = 1760; break;
		case 17: res = 1656; break;
		case 18: res = 1418; break;
		case 19: res = 915; break;
		case 20: res = 1269; break;
		case 21: res = 1638; break;
		case 22: res = 1650; break;
		case 23: res = 1596; break;
		case 24: res = 1519; break;
		case 25: res = 1549; break;
		case 26: res = 1584; break;
		case 27: res = 1553; break;
		case 28: res = 1477; break;
		case 29: res = 1019; break;
		case 30: res = 1242; break;
		case 31: res = 1660; break;
		case 32: res = 1548; break;
		case 33: res = 1345; break;
		case 34: res = 1295; break;
		case 35: res = 1348; break;
		case 36: res = 1518; break;
		case 37: res = 1564; break;
		case 38: res = 1560; break;
		case 39: res = 1100; break;
		case 40: res = 1257; break;
		case 41: res = 1709; break;
		case 42: res = 1642; break;
		case 43: res = 1551; break;
		case 44: res = 1473; break;
		case 45: res = 1428; break;
		case 46: res = 1460; break;
		case 47: res = 1436; break;
		case 48: res = 1594; break;
		case 49: res = 1203; break;
		case 50: res = 1200; break;
		case 51: res = 1619; break;
		case 52: res = 1697; break;
		case 53: res = 1553; break;
		case 54: res = 1574; break;
		case 55: res = 1414; break;
		case 56: res = 1519; break;
		case 57: res = 1443; break;
		case 58: res = 1573; break;
		case 59: res = 1170; break;
		case 60: res = 1169; break;
		case 61: res = 1583; break;
		case 62: res = 1587; break;
		case 63: res = 1552; break;
		case 64: res = 1553; break;
		case 65: res = 1541; break;
		case 66: res = 1486; break;
		case 67: res = 1511; break;
		case 68: res = 1598; break;
		case 69: res = 1189; break;
		case 70: res = 1070; break;
		case 71: res = 1472; break;
		case 72: res = 1489; break;
		case 73: res = 1419; break;
		case 74: res = 1462; break;
		case 75: res = 1606; break;
		case 76: res = 1541; break;
		case 77: res = 1543; break;
		case 78: res = 1574; break;
		case 79: res = 1211; break;
		case 80: res = 1031; break;
		case 81: res = 1436; break;
		case 82: res = 1402; break;
		case 83: res = 1437; break;
		case 84: res = 1563; break;
		case 85: res = 1607; break;
		case 86: res = 1629; break;
		case 87: res = 1622; break;
		case 88: res = 1608; break;
		case 89: res = 1134; break;
		case 90: res = 744; break;
		case 91: res = 1052; break;
		case 92: res = 1010; break;
		case 93: res = 1054; break;
		case 94: res = 1161; break;
		case 95: res = 1169; break;
		case 96: res = 1221; break;
		case 97: res = 1123; break;
		case 98: res = 1104; break;
		case 99: res = 849; break;
		default: break;
	}
	return res;
}

#endif