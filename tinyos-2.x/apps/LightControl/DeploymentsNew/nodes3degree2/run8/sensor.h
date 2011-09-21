#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 613; break;
		case 1: res = 608; break;
		case 2: res = 505; break;
		case 3: res = 669; break;
		case 4: res = 787; break;
		case 5: res = 656; break;
		case 6: res = 587; break;
		case 7: res = 635; break;
		case 8: res = 564; break;
		default: break;
	}
	return res;
}

#endif
