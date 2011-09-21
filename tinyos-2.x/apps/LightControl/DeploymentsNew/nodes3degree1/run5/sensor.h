#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 413; break;
		case 1: res = 508; break;
		case 2: res = 470; break;
		case 3: res = 491; break;
		case 4: res = 675; break;
		case 5: res = 485; break;
		case 6: res = 334; break;
		case 7: res = 446; break;
		case 8: res = 320; break;
		default: break;
	}
	return res;
}

#endif
