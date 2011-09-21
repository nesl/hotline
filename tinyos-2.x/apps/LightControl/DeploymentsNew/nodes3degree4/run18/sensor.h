#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1240; break;
		case 1: res = 1447; break;
		case 2: res = 1305; break;
		case 3: res = 1363; break;
		case 4: res = 1940; break;
		case 5: res = 1556; break;
		case 6: res = 1193; break;
		case 7: res = 1416; break;
		case 8: res = 1286; break;
		default: break;
	}
	return res;
}

#endif
