#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 824; break;
		case 1: res = 1209; break;
		case 2: res = 1186; break;
		case 3: res = 1142; break;
		case 4: res = 705; break;
		case 5: res = 1139; break;
		case 6: res = 1580; break;
		case 7: res = 1547; break;
		case 8: res = 1548; break;
		case 9: res = 1087; break;
		case 10: res = 1092; break;
		case 11: res = 1586; break;
		case 12: res = 1613; break;
		case 13: res = 1604; break;
		case 14: res = 1069; break;
		case 15: res = 1150; break;
		case 16: res = 1653; break;
		case 17: res = 1703; break;
		case 18: res = 1728; break;
		case 19: res = 1209; break;
		case 20: res = 823; break;
		case 21: res = 1163; break;
		case 22: res = 1216; break;
		case 23: res = 1242; break;
		case 24: res = 818; break;
		default: break;
	}
	return res;
}

#endif
