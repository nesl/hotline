#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 808; break;
		case 1: res = 1086; break;
		case 2: res = 1201; break;
		case 3: res = 1167; break;
		case 4: res = 1158; break;
		case 5: res = 1125; break;
		case 6: res = 801; break;
		case 7: res = 1189; break;
		case 8: res = 1590; break;
		case 9: res = 1649; break;
		case 10: res = 1737; break;
		case 11: res = 1724; break;
		case 12: res = 1644; break;
		case 13: res = 1209; break;
		case 14: res = 1156; break;
		case 15: res = 1646; break;
		case 16: res = 1646; break;
		case 17: res = 1749; break;
		case 18: res = 1828; break;
		case 19: res = 1722; break;
		case 20: res = 1222; break;
		case 21: res = 1264; break;
		case 22: res = 1713; break;
		case 23: res = 1659; break;
		case 24: res = 1779; break;
		case 25: res = 1738; break;
		case 26: res = 1758; break;
		case 27: res = 1205; break;
		case 28: res = 1153; break;
		case 29: res = 1597; break;
		case 30: res = 1535; break;
		case 31: res = 1695; break;
		case 32: res = 1659; break;
		case 33: res = 1717; break;
		case 34: res = 1199; break;
		case 35: res = 1148; break;
		case 36: res = 1550; break;
		case 37: res = 1600; break;
		case 38: res = 1588; break;
		case 39: res = 1528; break;
		case 40: res = 1609; break;
		case 41: res = 1216; break;
		case 42: res = 763; break;
		case 43: res = 1184; break;
		case 44: res = 1105; break;
		case 45: res = 1072; break;
		case 46: res = 978; break;
		case 47: res = 1090; break;
		case 48: res = 748; break;
		default: break;
	}
	return res;
}

#endif
