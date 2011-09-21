#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 697; break;
		case 1: res = 976; break;
		case 2: res = 1128; break;
		case 3: res = 1069; break;
		case 4: res = 1138; break;
		case 5: res = 1234; break;
		case 6: res = 954; break;
		case 7: res = 1003; break;
		case 8: res = 1365; break;
		case 9: res = 1466; break;
		case 10: res = 1456; break;
		case 11: res = 1569; break;
		case 12: res = 1703; break;
		case 13: res = 1376; break;
		case 14: res = 1021; break;
		case 15: res = 1540; break;
		case 16: res = 1546; break;
		case 17: res = 1519; break;
		case 18: res = 1642; break;
		case 19: res = 1786; break;
		case 20: res = 1364; break;
		case 21: res = 1127; break;
		case 22: res = 1637; break;
		case 23: res = 1559; break;
		case 24: res = 1586; break;
		case 25: res = 1488; break;
		case 26: res = 1659; break;
		case 27: res = 1199; break;
		case 28: res = 1120; break;
		case 29: res = 1633; break;
		case 30: res = 1575; break;
		case 31: res = 1643; break;
		case 32: res = 1577; break;
		case 33: res = 1717; break;
		case 34: res = 1226; break;
		case 35: res = 1095; break;
		case 36: res = 1486; break;
		case 37: res = 1645; break;
		case 38: res = 1629; break;
		case 39: res = 1597; break;
		case 40: res = 1541; break;
		case 41: res = 1144; break;
		case 42: res = 708; break;
		case 43: res = 1057; break;
		case 44: res = 1126; break;
		case 45: res = 1141; break;
		case 46: res = 1216; break;
		case 47: res = 1204; break;
		case 48: res = 802; break;
		default: break;
	}
	return res;
}

#endif
