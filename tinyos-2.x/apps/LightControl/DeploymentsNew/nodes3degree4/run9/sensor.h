#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1328; break;
		case 1: res = 1603; break;
		case 2: res = 1352; break;
		case 3: res = 1605; break;
		case 4: res = 2140; break;
		case 5: res = 1714; break;
		case 6: res = 1314; break;
		case 7: res = 1645; break;
		case 8: res = 1379; break;
		default: break;
	}
	return res;
}

#endif
