#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 902; break;
		case 1: res = 1158; break;
		case 2: res = 1176; break;
		case 3: res = 1097; break;
		case 4: res = 1089; break;
		case 5: res = 1117; break;
		case 6: res = 794; break;
		case 7: res = 1218; break;
		case 8: res = 1576; break;
		case 9: res = 1597; break;
		case 10: res = 1590; break;
		case 11: res = 1602; break;
		case 12: res = 1562; break;
		case 13: res = 1180; break;
		case 14: res = 1126; break;
		case 15: res = 1632; break;
		case 16: res = 1620; break;
		case 17: res = 1686; break;
		case 18: res = 1710; break;
		case 19: res = 1557; break;
		case 20: res = 1082; break;
		case 21: res = 1154; break;
		case 22: res = 1613; break;
		case 23: res = 1585; break;
		case 24: res = 1706; break;
		case 25: res = 1632; break;
		case 26: res = 1553; break;
		case 27: res = 994; break;
		case 28: res = 1089; break;
		case 29: res = 1566; break;
		case 30: res = 1466; break;
		case 31: res = 1604; break;
		case 32: res = 1563; break;
		case 33: res = 1545; break;
		case 34: res = 1006; break;
		case 35: res = 1112; break;
		case 36: res = 1509; break;
		case 37: res = 1570; break;
		case 38: res = 1474; break;
		case 39: res = 1472; break;
		case 40: res = 1500; break;
		case 41: res = 1155; break;
		case 42: res = 772; break;
		case 43: res = 1146; break;
		case 44: res = 1092; break;
		case 45: res = 1005; break;
		case 46: res = 1022; break;
		case 47: res = 1111; break;
		case 48: res = 822; break;
		default: break;
	}
	return res;
}

#endif
