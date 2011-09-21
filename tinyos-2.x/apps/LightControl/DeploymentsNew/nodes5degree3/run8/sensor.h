#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 813; break;
		case 1: res = 1126; break;
		case 2: res = 1180; break;
		case 3: res = 1141; break;
		case 4: res = 787; break;
		case 5: res = 1238; break;
		case 6: res = 1550; break;
		case 7: res = 1571; break;
		case 8: res = 1511; break;
		case 9: res = 1180; break;
		case 10: res = 1205; break;
		case 11: res = 1558; break;
		case 12: res = 1518; break;
		case 13: res = 1499; break;
		case 14: res = 1124; break;
		case 15: res = 1262; break;
		case 16: res = 1624; break;
		case 17: res = 1614; break;
		case 18: res = 1594; break;
		case 19: res = 1240; break;
		case 20: res = 839; break;
		case 21: res = 1090; break;
		case 22: res = 1110; break;
		case 23: res = 1161; break;
		case 24: res = 858; break;
		default: break;
	}
	return res;
}

#endif
