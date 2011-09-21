#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 447; break;
		case 1: res = 436; break;
		case 2: res = 394; break;
		case 3: res = 488; break;
		case 4: res = 565; break;
		case 5: res = 445; break;
		case 6: res = 367; break;
		case 7: res = 468; break;
		case 8: res = 346; break;
		default: break;
	}
	return res;
}

#endif
