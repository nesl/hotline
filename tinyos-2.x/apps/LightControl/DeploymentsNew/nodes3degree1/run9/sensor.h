#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 430; break;
		case 1: res = 516; break;
		case 2: res = 421; break;
		case 3: res = 444; break;
		case 4: res = 642; break;
		case 5: res = 539; break;
		case 6: res = 328; break;
		case 7: res = 420; break;
		case 8: res = 379; break;
		default: break;
	}
	return res;
}

#endif
