#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 404; break;
		case 1: res = 444; break;
		case 2: res = 381; break;
		case 3: res = 416; break;
		case 4: res = 584; break;
		case 5: res = 462; break;
		case 6: res = 361; break;
		case 7: res = 496; break;
		case 8: res = 371; break;
		default: break;
	}
	return res;
}

#endif
