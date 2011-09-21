#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 554; break;
		case 1: res = 640; break;
		case 2: res = 519; break;
		case 3: res = 659; break;
		case 4: res = 836; break;
		case 5: res = 676; break;
		case 6: res = 578; break;
		case 7: res = 656; break;
		case 8: res = 547; break;
		default: break;
	}
	return res;
}

#endif
