#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 885; break;
		case 1: res = 1149; break;
		case 2: res = 1226; break;
		case 3: res = 1206; break;
		case 4: res = 1171; break;
		case 5: res = 1071; break;
		case 6: res = 712; break;
		case 7: res = 1264; break;
		case 8: res = 1583; break;
		case 9: res = 1527; break;
		case 10: res = 1629; break;
		case 11: res = 1632; break;
		case 12: res = 1509; break;
		case 13: res = 1030; break;
		case 14: res = 1166; break;
		case 15: res = 1554; break;
		case 16: res = 1465; break;
		case 17: res = 1526; break;
		case 18: res = 1710; break;
		case 19: res = 1668; break;
		case 20: res = 1171; break;
		case 21: res = 1192; break;
		case 22: res = 1533; break;
		case 23: res = 1410; break;
		case 24: res = 1452; break;
		case 25: res = 1529; break;
		case 26: res = 1665; break;
		case 27: res = 1202; break;
		case 28: res = 1095; break;
		case 29: res = 1456; break;
		case 30: res = 1382; break;
		case 31: res = 1407; break;
		case 32: res = 1453; break;
		case 33: res = 1609; break;
		case 34: res = 1201; break;
		case 35: res = 1194; break;
		case 36: res = 1489; break;
		case 37: res = 1444; break;
		case 38: res = 1396; break;
		case 39: res = 1379; break;
		case 40: res = 1447; break;
		case 41: res = 1084; break;
		case 42: res = 790; break;
		case 43: res = 1095; break;
		case 44: res = 990; break;
		case 45: res = 1027; break;
		case 46: res = 1022; break;
		case 47: res = 1070; break;
		case 48: res = 669; break;
		default: break;
	}
	return res;
}

#endif
