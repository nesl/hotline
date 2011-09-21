#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1266; break;
		case 1: res = 1406; break;
		case 2: res = 1172; break;
		case 3: res = 1463; break;
		case 4: res = 1881; break;
		case 5: res = 1417; break;
		case 6: res = 1236; break;
		case 7: res = 1382; break;
		case 8: res = 1169; break;
		default: break;
	}
	return res;
}

#endif
