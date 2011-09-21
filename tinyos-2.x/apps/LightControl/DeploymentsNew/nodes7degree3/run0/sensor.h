#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 783; break;
		case 1: res = 1088; break;
		case 2: res = 1098; break;
		case 3: res = 1062; break;
		case 4: res = 1028; break;
		case 5: res = 1059; break;
		case 6: res = 791; break;
		case 7: res = 1107; break;
		case 8: res = 1502; break;
		case 9: res = 1436; break;
		case 10: res = 1483; break;
		case 11: res = 1467; break;
		case 12: res = 1467; break;
		case 13: res = 1084; break;
		case 14: res = 1021; break;
		case 15: res = 1496; break;
		case 16: res = 1494; break;
		case 17: res = 1558; break;
		case 18: res = 1675; break;
		case 19: res = 1557; break;
		case 20: res = 1043; break;
		case 21: res = 1140; break;
		case 22: res = 1555; break;
		case 23: res = 1516; break;
		case 24: res = 1629; break;
		case 25: res = 1589; break;
		case 26: res = 1503; break;
		case 27: res = 908; break;
		case 28: res = 1078; break;
		case 29: res = 1568; break;
		case 30: res = 1615; break;
		case 31: res = 1731; break;
		case 32: res = 1690; break;
		case 33: res = 1619; break;
		case 34: res = 1051; break;
		case 35: res = 1069; break;
		case 36: res = 1517; break;
		case 37: res = 1655; break;
		case 38: res = 1700; break;
		case 39: res = 1661; break;
		case 40: res = 1593; break;
		case 41: res = 1105; break;
		case 42: res = 691; break;
		case 43: res = 1135; break;
		case 44: res = 1188; break;
		case 45: res = 1264; break;
		case 46: res = 1265; break;
		case 47: res = 1239; break;
		case 48: res = 766; break;
		default: break;
	}
	return res;
}

#endif
