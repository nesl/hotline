#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 861; break;
		case 1: res = 1128; break;
		case 2: res = 1117; break;
		case 3: res = 1125; break;
		case 4: res = 1191; break;
		case 5: res = 1289; break;
		case 6: res = 914; break;
		case 7: res = 1206; break;
		case 8: res = 1592; break;
		case 9: res = 1474; break;
		case 10: res = 1574; break;
		case 11: res = 1607; break;
		case 12: res = 1712; break;
		case 13: res = 1270; break;
		case 14: res = 1121; break;
		case 15: res = 1638; break;
		case 16: res = 1452; break;
		case 17: res = 1522; break;
		case 18: res = 1601; break;
		case 19: res = 1671; break;
		case 20: res = 1178; break;
		case 21: res = 1222; break;
		case 22: res = 1721; break;
		case 23: res = 1569; break;
		case 24: res = 1557; break;
		case 25: res = 1484; break;
		case 26: res = 1547; break;
		case 27: res = 1023; break;
		case 28: res = 1156; break;
		case 29: res = 1652; break;
		case 30: res = 1540; break;
		case 31: res = 1501; break;
		case 32: res = 1490; break;
		case 33: res = 1578; break;
		case 34: res = 1066; break;
		case 35: res = 1203; break;
		case 36: res = 1606; break;
		case 37: res = 1613; break;
		case 38: res = 1406; break;
		case 39: res = 1406; break;
		case 40: res = 1450; break;
		case 41: res = 1088; break;
		case 42: res = 823; break;
		case 43: res = 1169; break;
		case 44: res = 1065; break;
		case 45: res = 941; break;
		case 46: res = 1015; break;
		case 47: res = 1099; break;
		case 48: res = 749; break;
		default: break;
	}
	return res;
}

#endif
