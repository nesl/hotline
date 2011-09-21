#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 825; break;
		case 1: res = 1271; break;
		case 2: res = 1232; break;
		case 3: res = 1296; break;
		case 4: res = 840; break;
		case 5: res = 1108; break;
		case 6: res = 1642; break;
		case 7: res = 1610; break;
		case 8: res = 1670; break;
		case 9: res = 1167; break;
		case 10: res = 1070; break;
		case 11: res = 1598; break;
		case 12: res = 1533; break;
		case 13: res = 1568; break;
		case 14: res = 1039; break;
		case 15: res = 1057; break;
		case 16: res = 1505; break;
		case 17: res = 1473; break;
		case 18: res = 1504; break;
		case 19: res = 1054; break;
		case 20: res = 733; break;
		case 21: res = 993; break;
		case 22: res = 981; break;
		case 23: res = 1061; break;
		case 24: res = 721; break;
		default: break;
	}
	return res;
}

#endif
