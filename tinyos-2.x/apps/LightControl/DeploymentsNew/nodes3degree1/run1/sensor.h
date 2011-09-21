#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 433; break;
		case 1: res = 491; break;
		case 2: res = 467; break;
		case 3: res = 507; break;
		case 4: res = 682; break;
		case 5: res = 581; break;
		case 6: res = 373; break;
		case 7: res = 504; break;
		case 8: res = 410; break;
		default: break;
	}
	return res;
}

#endif
