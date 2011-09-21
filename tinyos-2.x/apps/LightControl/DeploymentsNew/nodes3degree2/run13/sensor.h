#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 614; break;
		case 1: res = 713; break;
		case 2: res = 583; break;
		case 3: res = 712; break;
		case 4: res = 793; break;
		case 5: res = 730; break;
		case 6: res = 631; break;
		case 7: res = 734; break;
		case 8: res = 575; break;
		default: break;
	}
	return res;
}

#endif
