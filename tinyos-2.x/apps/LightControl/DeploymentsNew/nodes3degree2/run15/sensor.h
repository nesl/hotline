#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 509; break;
		case 1: res = 616; break;
		case 2: res = 556; break;
		case 3: res = 608; break;
		case 4: res = 789; break;
		case 5: res = 681; break;
		case 6: res = 552; break;
		case 7: res = 627; break;
		case 8: res = 522; break;
		default: break;
	}
	return res;
}

#endif
