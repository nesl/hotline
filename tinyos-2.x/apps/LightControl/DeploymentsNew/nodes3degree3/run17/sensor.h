#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 765; break;
		case 1: res = 1033; break;
		case 2: res = 649; break;
		case 3: res = 1082; break;
		case 4: res = 1497; break;
		case 5: res = 1029; break;
		case 6: res = 764; break;
		case 7: res = 996; break;
		case 8: res = 740; break;
		default: break;
	}
	return res;
}

#endif
