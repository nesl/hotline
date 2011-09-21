#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 475; break;
		case 1: res = 486; break;
		case 2: res = 403; break;
		case 3: res = 504; break;
		case 4: res = 630; break;
		case 5: res = 537; break;
		case 6: res = 391; break;
		case 7: res = 464; break;
		case 8: res = 374; break;
		default: break;
	}
	return res;
}

#endif
