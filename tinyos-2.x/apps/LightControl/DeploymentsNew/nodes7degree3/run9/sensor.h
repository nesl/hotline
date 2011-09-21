#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 699; break;
		case 1: res = 947; break;
		case 2: res = 1081; break;
		case 3: res = 1094; break;
		case 4: res = 1050; break;
		case 5: res = 1124; break;
		case 6: res = 833; break;
		case 7: res = 1011; break;
		case 8: res = 1391; break;
		case 9: res = 1520; break;
		case 10: res = 1620; break;
		case 11: res = 1516; break;
		case 12: res = 1497; break;
		case 13: res = 1131; break;
		case 14: res = 1045; break;
		case 15: res = 1618; break;
		case 16: res = 1661; break;
		case 17: res = 1687; break;
		case 18: res = 1570; break;
		case 19: res = 1528; break;
		case 20: res = 1092; break;
		case 21: res = 1286; break;
		case 22: res = 1838; break;
		case 23: res = 1766; break;
		case 24: res = 1827; break;
		case 25: res = 1613; break;
		case 26: res = 1582; break;
		case 27: res = 1025; break;
		case 28: res = 1261; break;
		case 29: res = 1830; break;
		case 30: res = 1674; break;
		case 31: res = 1799; break;
		case 32: res = 1593; break;
		case 33: res = 1666; break;
		case 34: res = 1095; break;
		case 35: res = 1219; break;
		case 36: res = 1693; break;
		case 37: res = 1723; break;
		case 38: res = 1718; break;
		case 39: res = 1568; break;
		case 40: res = 1524; break;
		case 41: res = 1057; break;
		case 42: res = 777; break;
		case 43: res = 1221; break;
		case 44: res = 1173; break;
		case 45: res = 1193; break;
		case 46: res = 1107; break;
		case 47: res = 1117; break;
		case 48: res = 678; break;
		default: break;
	}
	return res;
}

#endif
