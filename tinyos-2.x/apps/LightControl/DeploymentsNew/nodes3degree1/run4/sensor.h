#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 488; break;
		case 1: res = 508; break;
		case 2: res = 371; break;
		case 3: res = 536; break;
		case 4: res = 641; break;
		case 5: res = 437; break;
		case 6: res = 416; break;
		case 7: res = 475; break;
		case 8: res = 323; break;
		default: break;
	}
	return res;
}

#endif
