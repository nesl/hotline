#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 490; break;
		case 1: res = 606; break;
		case 2: res = 483; break;
		case 3: res = 628; break;
		case 4: res = 748; break;
		case 5: res = 653; break;
		case 6: res = 606; break;
		case 7: res = 727; break;
		case 8: res = 528; break;
		default: break;
	}
	return res;
}

#endif
