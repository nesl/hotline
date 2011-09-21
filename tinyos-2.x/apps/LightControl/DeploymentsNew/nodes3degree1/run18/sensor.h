#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 423; break;
		case 1: res = 560; break;
		case 2: res = 424; break;
		case 3: res = 474; break;
		case 4: res = 657; break;
		case 5: res = 460; break;
		case 6: res = 406; break;
		case 7: res = 461; break;
		case 8: res = 326; break;
		default: break;
	}
	return res;
}

#endif
