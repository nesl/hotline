#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 831; break;
		case 1: res = 1187; break;
		case 2: res = 1247; break;
		case 3: res = 1214; break;
		case 4: res = 1284; break;
		case 5: res = 1223; break;
		case 6: res = 1227; break;
		case 7: res = 1095; break;
		case 8: res = 1063; break;
		case 9: res = 735; break;
		case 10: res = 1196; break;
		case 11: res = 1695; break;
		case 12: res = 1828; break;
		case 13: res = 1699; break;
		case 14: res = 1699; break;
		case 15: res = 1601; break;
		case 16: res = 1685; break;
		case 17: res = 1669; break;
		case 18: res = 1540; break;
		case 19: res = 1024; break;
		case 20: res = 1231; break;
		case 21: res = 1670; break;
		case 22: res = 1743; break;
		case 23: res = 1606; break;
		case 24: res = 1542; break;
		case 25: res = 1589; break;
		case 26: res = 1621; break;
		case 27: res = 1732; break;
		case 28: res = 1709; break;
		case 29: res = 1221; break;
		case 30: res = 1162; break;
		case 31: res = 1668; break;
		case 32: res = 1625; break;
		case 33: res = 1523; break;
		case 34: res = 1443; break;
		case 35: res = 1493; break;
		case 36: res = 1517; break;
		case 37: res = 1635; break;
		case 38: res = 1621; break;
		case 39: res = 1188; break;
		case 40: res = 1197; break;
		case 41: res = 1624; break;
		case 42: res = 1531; break;
		case 43: res = 1578; break;
		case 44: res = 1551; break;
		case 45: res = 1626; break;
		case 46: res = 1584; break;
		case 47: res = 1602; break;
		case 48: res = 1693; break;
		case 49: res = 1322; break;
		case 50: res = 1244; break;
		case 51: res = 1681; break;
		case 52: res = 1705; break;
		case 53: res = 1634; break;
		case 54: res = 1676; break;
		case 55: res = 1538; break;
		case 56: res = 1638; break;
		case 57: res = 1618; break;
		case 58: res = 1690; break;
		case 59: res = 1232; break;
		case 60: res = 1242; break;
		case 61: res = 1682; break;
		case 62: res = 1716; break;
		case 63: res = 1614; break;
		case 64: res = 1673; break;
		case 65: res = 1610; break;
		case 66: res = 1588; break;
		case 67: res = 1665; break;
		case 68: res = 1797; break;
		case 69: res = 1298; break;
		case 70: res = 1170; break;
		case 71: res = 1605; break;
		case 72: res = 1661; break;
		case 73: res = 1528; break;
		case 74: res = 1649; break;
		case 75: res = 1582; break;
		case 76: res = 1526; break;
		case 77: res = 1534; break;
		case 78: res = 1731; break;
		case 79: res = 1255; break;
		case 80: res = 1054; break;
		case 81: res = 1478; break;
		case 82: res = 1521; break;
		case 83: res = 1483; break;
		case 84: res = 1628; break;
		case 85: res = 1512; break;
		case 86: res = 1542; break;
		case 87: res = 1526; break;
		case 88: res = 1667; break;
		case 89: res = 1119; break;
		case 90: res = 710; break;
		case 91: res = 1035; break;
		case 92: res = 1033; break;
		case 93: res = 1013; break;
		case 94: res = 1078; break;
		case 95: res = 1038; break;
		case 96: res = 1165; break;
		case 97: res = 1085; break;
		case 98: res = 1102; break;
		case 99: res = 786; break;
		default: break;
	}
	return res;
}

#endif