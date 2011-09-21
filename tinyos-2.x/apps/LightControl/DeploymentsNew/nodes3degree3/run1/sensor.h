#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 783; break;
		case 1: res = 1140; break;
		case 2: res = 792; break;
		case 3: res = 1098; break;
		case 4: res = 1636; break;
		case 5: res = 1178; break;
		case 6: res = 833; break;
		case 7: res = 1168; break;
		case 8: res = 876; break;
		default: break;
	}
	return res;
}

#endif
