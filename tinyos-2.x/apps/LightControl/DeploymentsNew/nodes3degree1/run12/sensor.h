#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 447; break;
		case 1: res = 480; break;
		case 2: res = 437; break;
		case 3: res = 461; break;
		case 4: res = 709; break;
		case 5: res = 558; break;
		case 6: res = 332; break;
		case 7: res = 518; break;
		case 8: res = 374; break;
		default: break;
	}
	return res;
}

#endif
