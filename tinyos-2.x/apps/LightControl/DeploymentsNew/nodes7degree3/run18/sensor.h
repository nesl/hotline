#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 825; break;
		case 1: res = 1111; break;
		case 2: res = 1076; break;
		case 3: res = 963; break;
		case 4: res = 989; break;
		case 5: res = 1167; break;
		case 6: res = 895; break;
		case 7: res = 1168; break;
		case 8: res = 1564; break;
		case 9: res = 1474; break;
		case 10: res = 1507; break;
		case 11: res = 1458; break;
		case 12: res = 1594; break;
		case 13: res = 1246; break;
		case 14: res = 1142; break;
		case 15: res = 1715; break;
		case 16: res = 1657; break;
		case 17: res = 1695; break;
		case 18: res = 1578; break;
		case 19: res = 1592; break;
		case 20: res = 1185; break;
		case 21: res = 1286; break;
		case 22: res = 1798; break;
		case 23: res = 1746; break;
		case 24: res = 1747; break;
		case 25: res = 1495; break;
		case 26: res = 1525; break;
		case 27: res = 1104; break;
		case 28: res = 1209; break;
		case 29: res = 1730; break;
		case 30: res = 1713; break;
		case 31: res = 1688; break;
		case 32: res = 1498; break;
		case 33: res = 1544; break;
		case 34: res = 1153; break;
		case 35: res = 1142; break;
		case 36: res = 1569; break;
		case 37: res = 1739; break;
		case 38: res = 1664; break;
		case 39: res = 1562; break;
		case 40: res = 1552; break;
		case 41: res = 1239; break;
		case 42: res = 680; break;
		case 43: res = 1095; break;
		case 44: res = 1182; break;
		case 45: res = 1208; break;
		case 46: res = 1170; break;
		case 47: res = 1192; break;
		case 48: res = 846; break;
		default: break;
	}
	return res;
}

#endif
