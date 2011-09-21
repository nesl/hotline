#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 835; break;
		case 1: res = 1191; break;
		case 2: res = 1235; break;
		case 3: res = 1249; break;
		case 4: res = 1252; break;
		case 5: res = 1171; break;
		case 6: res = 1218; break;
		case 7: res = 1173; break;
		case 8: res = 1220; break;
		case 9: res = 844; break;
		case 10: res = 1142; break;
		case 11: res = 1592; break;
		case 12: res = 1754; break;
		case 13: res = 1727; break;
		case 14: res = 1732; break;
		case 15: res = 1636; break;
		case 16: res = 1707; break;
		case 17: res = 1697; break;
		case 18: res = 1610; break;
		case 19: res = 1091; break;
		case 20: res = 1213; break;
		case 21: res = 1653; break;
		case 22: res = 1754; break;
		case 23: res = 1649; break;
		case 24: res = 1610; break;
		case 25: res = 1601; break;
		case 26: res = 1596; break;
		case 27: res = 1588; break;
		case 28: res = 1584; break;
		case 29: res = 1144; break;
		case 30: res = 1130; break;
		case 31: res = 1597; break;
		case 32: res = 1578; break;
		case 33: res = 1453; break;
		case 34: res = 1477; break;
		case 35: res = 1495; break;
		case 36: res = 1492; break;
		case 37: res = 1512; break;
		case 38: res = 1444; break;
		case 39: res = 1041; break;
		case 40: res = 1160; break;
		case 41: res = 1644; break;
		case 42: res = 1603; break;
		case 43: res = 1563; break;
		case 44: res = 1537; break;
		case 45: res = 1515; break;
		case 46: res = 1463; break;
		case 47: res = 1413; break;
		case 48: res = 1510; break;
		case 49: res = 1148; break;
		case 50: res = 1144; break;
		case 51: res = 1619; break;
		case 52: res = 1742; break;
		case 53: res = 1655; break;
		case 54: res = 1700; break;
		case 55: res = 1525; break;
		case 56: res = 1531; break;
		case 57: res = 1416; break;
		case 58: res = 1500; break;
		case 59: res = 1105; break;
		case 60: res = 1221; break;
		case 61: res = 1704; break;
		case 62: res = 1721; break;
		case 63: res = 1690; break;
		case 64: res = 1702; break;
		case 65: res = 1616; break;
		case 66: res = 1543; break;
		case 67: res = 1495; break;
		case 68: res = 1633; break;
		case 69: res = 1147; break;
		case 70: res = 1256; break;
		case 71: res = 1644; break;
		case 72: res = 1602; break;
		case 73: res = 1511; break;
		case 74: res = 1664; break;
		case 75: res = 1655; break;
		case 76: res = 1657; break;
		case 77: res = 1582; break;
		case 78: res = 1610; break;
		case 79: res = 1094; break;
		case 80: res = 1122; break;
		case 81: res = 1514; break;
		case 82: res = 1526; break;
		case 83: res = 1514; break;
		case 84: res = 1662; break;
		case 85: res = 1574; break;
		case 86: res = 1676; break;
		case 87: res = 1626; break;
		case 88: res = 1620; break;
		case 89: res = 1054; break;
		case 90: res = 718; break;
		case 91: res = 1057; break;
		case 92: res = 1141; break;
		case 93: res = 1143; break;
		case 94: res = 1155; break;
		case 95: res = 1093; break;
		case 96: res = 1194; break;
		case 97: res = 1142; break;
		case 98: res = 1099; break;
		case 99: res = 845; break;
		default: break;
	}
	return res;
}

#endif