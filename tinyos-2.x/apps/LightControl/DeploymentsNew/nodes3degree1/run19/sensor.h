#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 377; break;
		case 1: res = 473; break;
		case 2: res = 426; break;
		case 3: res = 487; break;
		case 4: res = 661; break;
		case 5: res = 503; break;
		case 6: res = 379; break;
		case 7: res = 492; break;
		case 8: res = 395; break;
		default: break;
	}
	return res;
}

#endif
