#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 693; break;
		case 1: res = 1041; break;
		case 2: res = 738; break;
		case 3: res = 1001; break;
		case 4: res = 1434; break;
		case 5: res = 1007; break;
		case 6: res = 765; break;
		case 7: res = 961; break;
		case 8: res = 655; break;
		default: break;
	}
	return res;
}

#endif
