#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 892; break;
		case 1: res = 1261; break;
		case 2: res = 821; break;
		case 3: res = 1287; break;
		case 4: res = 1766; break;
		case 5: res = 1193; break;
		case 6: res = 980; break;
		case 7: res = 1219; break;
		case 8: res = 843; break;
		default: break;
	}
	return res;
}

#endif
