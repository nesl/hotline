#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 893; break;
		case 1: res = 1283; break;
		case 2: res = 1245; break;
		case 3: res = 1223; break;
		case 4: res = 795; break;
		case 5: res = 1313; break;
		case 6: res = 1746; break;
		case 7: res = 1628; break;
		case 8: res = 1549; break;
		case 9: res = 1122; break;
		case 10: res = 1131; break;
		case 11: res = 1586; break;
		case 12: res = 1528; break;
		case 13: res = 1528; break;
		case 14: res = 1059; break;
		case 15: res = 1208; break;
		case 16: res = 1659; break;
		case 17: res = 1587; break;
		case 18: res = 1587; break;
		case 19: res = 1136; break;
		case 20: res = 796; break;
		case 21: res = 1085; break;
		case 22: res = 1081; break;
		case 23: res = 1172; break;
		case 24: res = 799; break;
		default: break;
	}
	return res;
}

#endif
