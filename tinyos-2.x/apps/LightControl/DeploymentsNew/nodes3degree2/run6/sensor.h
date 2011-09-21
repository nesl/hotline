#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 559; break;
		case 1: res = 634; break;
		case 2: res = 596; break;
		case 3: res = 646; break;
		case 4: res = 796; break;
		case 5: res = 719; break;
		case 6: res = 579; break;
		case 7: res = 610; break;
		case 8: res = 524; break;
		default: break;
	}
	return res;
}

#endif
