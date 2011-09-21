#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 889; break;
		case 1: res = 1325; break;
		case 2: res = 939; break;
		case 3: res = 1225; break;
		case 4: res = 1804; break;
		case 5: res = 1321; break;
		case 6: res = 925; break;
		case 7: res = 1242; break;
		case 8: res = 920; break;
		default: break;
	}
	return res;
}

#endif
