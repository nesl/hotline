#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 532; break;
		case 1: res = 639; break;
		case 2: res = 556; break;
		case 3: res = 609; break;
		case 4: res = 715; break;
		case 5: res = 673; break;
		case 6: res = 526; break;
		case 7: res = 571; break;
		case 8: res = 458; break;
		default: break;
	}
	return res;
}

#endif
