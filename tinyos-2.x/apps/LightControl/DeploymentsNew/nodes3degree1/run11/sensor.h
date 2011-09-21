#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 376; break;
		case 1: res = 456; break;
		case 2: res = 408; break;
		case 3: res = 392; break;
		case 4: res = 608; break;
		case 5: res = 430; break;
		case 6: res = 348; break;
		case 7: res = 522; break;
		case 8: res = 342; break;
		default: break;
	}
	return res;
}

#endif
