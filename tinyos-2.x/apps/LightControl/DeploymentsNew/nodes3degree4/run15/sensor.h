#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1220; break;
		case 1: res = 1371; break;
		case 2: res = 1211; break;
		case 3: res = 1462; break;
		case 4: res = 1965; break;
		case 5: res = 1513; break;
		case 6: res = 1302; break;
		case 7: res = 1528; break;
		case 8: res = 1323; break;
		default: break;
	}
	return res;
}

#endif
