#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 877; break;
		case 1: res = 1277; break;
		case 2: res = 852; break;
		case 3: res = 1190; break;
		case 4: res = 1700; break;
		case 5: res = 1184; break;
		case 6: res = 863; break;
		case 7: res = 1131; break;
		case 8: res = 812; break;
		default: break;
	}
	return res;
}

#endif
