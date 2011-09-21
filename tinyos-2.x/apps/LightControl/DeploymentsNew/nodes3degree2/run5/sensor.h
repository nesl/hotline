#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 584; break;
		case 1: res = 722; break;
		case 2: res = 529; break;
		case 3: res = 650; break;
		case 4: res = 757; break;
		case 5: res = 658; break;
		case 6: res = 570; break;
		case 7: res = 700; break;
		case 8: res = 526; break;
		default: break;
	}
	return res;
}

#endif
