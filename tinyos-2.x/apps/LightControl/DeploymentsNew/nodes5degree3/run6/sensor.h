#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 921; break;
		case 1: res = 1325; break;
		case 2: res = 1284; break;
		case 3: res = 1266; break;
		case 4: res = 830; break;
		case 5: res = 1349; break;
		case 6: res = 1770; break;
		case 7: res = 1641; break;
		case 8: res = 1635; break;
		case 9: res = 1216; break;
		case 10: res = 1223; break;
		case 11: res = 1671; break;
		case 12: res = 1572; break;
		case 13: res = 1525; break;
		case 14: res = 1058; break;
		case 15: res = 1162; break;
		case 16: res = 1541; break;
		case 17: res = 1503; break;
		case 18: res = 1527; break;
		case 19: res = 1159; break;
		case 20: res = 713; break;
		case 21: res = 964; break;
		case 22: res = 1025; break;
		case 23: res = 1091; break;
		case 24: res = 771; break;
		default: break;
	}
	return res;
}

#endif
