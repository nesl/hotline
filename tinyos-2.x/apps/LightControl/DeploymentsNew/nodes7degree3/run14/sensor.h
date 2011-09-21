#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 742; break;
		case 1: res = 978; break;
		case 2: res = 1099; break;
		case 3: res = 1124; break;
		case 4: res = 1173; break;
		case 5: res = 1207; break;
		case 6: res = 832; break;
		case 7: res = 1062; break;
		case 8: res = 1410; break;
		case 9: res = 1496; break;
		case 10: res = 1597; break;
		case 11: res = 1613; break;
		case 12: res = 1613; break;
		case 13: res = 1206; break;
		case 14: res = 977; break;
		case 15: res = 1504; break;
		case 16: res = 1608; break;
		case 17: res = 1659; break;
		case 18: res = 1683; break;
		case 19: res = 1628; break;
		case 20: res = 1223; break;
		case 21: res = 1027; break;
		case 22: res = 1547; break;
		case 23: res = 1606; break;
		case 24: res = 1653; break;
		case 25: res = 1501; break;
		case 26: res = 1592; break;
		case 27: res = 1182; break;
		case 28: res = 1030; break;
		case 29: res = 1576; break;
		case 30: res = 1592; break;
		case 31: res = 1608; break;
		case 32: res = 1486; break;
		case 33: res = 1627; break;
		case 34: res = 1180; break;
		case 35: res = 1089; break;
		case 36: res = 1564; break;
		case 37: res = 1637; break;
		case 38: res = 1553; break;
		case 39: res = 1438; break;
		case 40: res = 1530; break;
		case 41: res = 1120; break;
		case 42: res = 725; break;
		case 43: res = 1170; break;
		case 44: res = 1133; break;
		case 45: res = 1131; break;
		case 46: res = 1081; break;
		case 47: res = 1140; break;
		case 48: res = 699; break;
		default: break;
	}
	return res;
}

#endif
