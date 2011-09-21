#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 640; break;
		case 1: res = 967; break;
		case 2: res = 687; break;
		case 3: res = 943; break;
		case 4: res = 1408; break;
		case 5: res = 1017; break;
		case 6: res = 748; break;
		case 7: res = 1017; break;
		case 8: res = 744; break;
		default: break;
	}
	return res;
}

#endif
