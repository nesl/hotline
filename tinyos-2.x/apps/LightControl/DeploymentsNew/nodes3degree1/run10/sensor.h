#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 443; break;
		case 1: res = 517; break;
		case 2: res = 436; break;
		case 3: res = 462; break;
		case 4: res = 692; break;
		case 5: res = 514; break;
		case 6: res = 287; break;
		case 7: res = 482; break;
		case 8: res = 399; break;
		default: break;
	}
	return res;
}

#endif
