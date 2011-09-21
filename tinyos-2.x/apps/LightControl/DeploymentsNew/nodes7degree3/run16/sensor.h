#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 843; break;
		case 1: res = 1039; break;
		case 2: res = 1068; break;
		case 3: res = 1086; break;
		case 4: res = 1250; break;
		case 5: res = 1273; break;
		case 6: res = 870; break;
		case 7: res = 1198; break;
		case 8: res = 1458; break;
		case 9: res = 1391; break;
		case 10: res = 1536; break;
		case 11: res = 1709; break;
		case 12: res = 1692; break;
		case 13: res = 1211; break;
		case 14: res = 1094; break;
		case 15: res = 1465; break;
		case 16: res = 1442; break;
		case 17: res = 1557; break;
		case 18: res = 1774; break;
		case 19: res = 1697; break;
		case 20: res = 1207; break;
		case 21: res = 1080; break;
		case 22: res = 1420; break;
		case 23: res = 1462; break;
		case 24: res = 1588; break;
		case 25: res = 1690; break;
		case 26: res = 1689; break;
		case 27: res = 1183; break;
		case 28: res = 1061; break;
		case 29: res = 1468; break;
		case 30: res = 1496; break;
		case 31: res = 1607; break;
		case 32: res = 1653; break;
		case 33: res = 1651; break;
		case 34: res = 1136; break;
		case 35: res = 1188; break;
		case 36: res = 1534; break;
		case 37: res = 1554; break;
		case 38: res = 1492; break;
		case 39: res = 1454; break;
		case 40: res = 1398; break;
		case 41: res = 1010; break;
		case 42: res = 806; break;
		case 43: res = 1169; break;
		case 44: res = 1044; break;
		case 45: res = 1035; break;
		case 46: res = 974; break;
		case 47: res = 987; break;
		case 48: res = 611; break;
		default: break;
	}
	return res;
}

#endif
