#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 815; break;
		case 1: res = 1160; break;
		case 2: res = 1213; break;
		case 3: res = 1228; break;
		case 4: res = 1192; break;
		case 5: res = 1152; break;
		case 6: res = 804; break;
		case 7: res = 1157; break;
		case 8: res = 1562; break;
		case 9: res = 1593; break;
		case 10: res = 1692; break;
		case 11: res = 1664; break;
		case 12: res = 1556; break;
		case 13: res = 1115; break;
		case 14: res = 1179; break;
		case 15: res = 1637; break;
		case 16: res = 1663; break;
		case 17: res = 1662; break;
		case 18: res = 1732; break;
		case 19: res = 1573; break;
		case 20: res = 1100; break;
		case 21: res = 1171; break;
		case 22: res = 1545; break;
		case 23: res = 1599; break;
		case 24: res = 1628; break;
		case 25: res = 1629; break;
		case 26: res = 1613; break;
		case 27: res = 1114; break;
		case 28: res = 998; break;
		case 29: res = 1403; break;
		case 30: res = 1464; break;
		case 31: res = 1563; break;
		case 32: res = 1589; break;
		case 33: res = 1675; break;
		case 34: res = 1217; break;
		case 35: res = 919; break;
		case 36: res = 1247; break;
		case 37: res = 1451; break;
		case 38: res = 1564; break;
		case 39: res = 1603; break;
		case 40: res = 1664; break;
		case 41: res = 1260; break;
		case 42: res = 635; break;
		case 43: res = 975; break;
		case 44: res = 1009; break;
		case 45: res = 1129; break;
		case 46: res = 1188; break;
		case 47: res = 1275; break;
		case 48: res = 857; break;
		default: break;
	}
	return res;
}

#endif
