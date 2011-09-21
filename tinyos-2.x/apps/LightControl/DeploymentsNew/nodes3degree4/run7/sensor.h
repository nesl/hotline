#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1385; break;
		case 1: res = 1509; break;
		case 2: res = 1227; break;
		case 3: res = 1587; break;
		case 4: res = 1950; break;
		case 5: res = 1432; break;
		case 6: res = 1235; break;
		case 7: res = 1427; break;
		case 8: res = 1108; break;
		default: break;
	}
	return res;
}

#endif
