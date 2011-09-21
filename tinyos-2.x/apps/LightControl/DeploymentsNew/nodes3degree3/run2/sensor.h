#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 827; break;
		case 1: res = 1117; break;
		case 2: res = 694; break;
		case 3: res = 1065; break;
		case 4: res = 1454; break;
		case 5: res = 960; break;
		case 6: res = 746; break;
		case 7: res = 938; break;
		case 8: res = 649; break;
		default: break;
	}
	return res;
}

#endif
