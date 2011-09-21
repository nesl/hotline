#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 428; break;
		case 1: res = 546; break;
		case 2: res = 424; break;
		case 3: res = 496; break;
		case 4: res = 755; break;
		case 5: res = 532; break;
		case 6: res = 349; break;
		case 7: res = 520; break;
		case 8: res = 421; break;
		default: break;
	}
	return res;
}

#endif
