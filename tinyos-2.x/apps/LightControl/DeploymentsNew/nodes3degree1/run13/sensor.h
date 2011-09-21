#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 449; break;
		case 1: res = 526; break;
		case 2: res = 469; break;
		case 3: res = 424; break;
		case 4: res = 726; break;
		case 5: res = 531; break;
		case 6: res = 356; break;
		case 7: res = 574; break;
		case 8: res = 336; break;
		default: break;
	}
	return res;
}

#endif
