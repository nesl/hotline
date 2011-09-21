#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1215; break;
		case 1: res = 1336; break;
		case 2: res = 1085; break;
		case 3: res = 1380; break;
		case 4: res = 1779; break;
		case 5: res = 1361; break;
		case 6: res = 1162; break;
		case 7: res = 1337; break;
		case 8: res = 1074; break;
		default: break;
	}
	return res;
}

#endif
