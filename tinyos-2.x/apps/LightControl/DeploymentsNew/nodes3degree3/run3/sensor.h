#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 726; break;
		case 1: res = 1096; break;
		case 2: res = 752; break;
		case 3: res = 1047; break;
		case 4: res = 1522; break;
		case 5: res = 1085; break;
		case 6: res = 804; break;
		case 7: res = 1035; break;
		case 8: res = 766; break;
		default: break;
	}
	return res;
}

#endif
