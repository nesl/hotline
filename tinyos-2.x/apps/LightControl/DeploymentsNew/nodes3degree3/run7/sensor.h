#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 640; break;
		case 1: res = 1028; break;
		case 2: res = 750; break;
		case 3: res = 930; break;
		case 4: res = 1445; break;
		case 5: res = 1090; break;
		case 6: res = 745; break;
		case 7: res = 990; break;
		case 8: res = 751; break;
		default: break;
	}
	return res;
}

#endif
