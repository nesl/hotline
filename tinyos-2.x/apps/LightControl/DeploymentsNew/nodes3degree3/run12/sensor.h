#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 810; break;
		case 1: res = 1176; break;
		case 2: res = 792; break;
		case 3: res = 1067; break;
		case 4: res = 1520; break;
		case 5: res = 1078; break;
		case 6: res = 771; break;
		case 7: res = 945; break;
		case 8: res = 660; break;
		default: break;
	}
	return res;
}

#endif
