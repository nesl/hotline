#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1205; break;
		case 1: res = 1407; break;
		case 2: res = 1256; break;
		case 3: res = 1420; break;
		case 4: res = 1954; break;
		case 5: res = 1540; break;
		case 6: res = 1194; break;
		case 7: res = 1494; break;
		case 8: res = 1291; break;
		default: break;
	}
	return res;
}

#endif
