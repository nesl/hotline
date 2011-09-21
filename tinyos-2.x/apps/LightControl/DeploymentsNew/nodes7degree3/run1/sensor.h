#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 818; break;
		case 1: res = 1128; break;
		case 2: res = 1208; break;
		case 3: res = 1172; break;
		case 4: res = 1188; break;
		case 5: res = 1230; break;
		case 6: res = 816; break;
		case 7: res = 1101; break;
		case 8: res = 1547; break;
		case 9: res = 1571; break;
		case 10: res = 1698; break;
		case 11: res = 1640; break;
		case 12: res = 1623; break;
		case 13: res = 1102; break;
		case 14: res = 1073; break;
		case 15: res = 1601; break;
		case 16: res = 1598; break;
		case 17: res = 1737; break;
		case 18: res = 1713; break;
		case 19: res = 1565; break;
		case 20: res = 1012; break;
		case 21: res = 1167; break;
		case 22: res = 1669; break;
		case 23: res = 1569; break;
		case 24: res = 1715; break;
		case 25: res = 1575; break;
		case 26: res = 1558; break;
		case 27: res = 982; break;
		case 28: res = 1200; break;
		case 29: res = 1661; break;
		case 30: res = 1529; break;
		case 31: res = 1563; break;
		case 32: res = 1484; break;
		case 33: res = 1539; break;
		case 34: res = 1036; break;
		case 35: res = 1212; break;
		case 36: res = 1631; break;
		case 37: res = 1631; break;
		case 38: res = 1511; break;
		case 39: res = 1378; break;
		case 40: res = 1371; break;
		case 41: res = 1033; break;
		case 42: res = 824; break;
		case 43: res = 1203; break;
		case 44: res = 1133; break;
		case 45: res = 1071; break;
		case 46: res = 1018; break;
		case 47: res = 1040; break;
		case 48: res = 715; break;
		default: break;
	}
	return res;
}

#endif
