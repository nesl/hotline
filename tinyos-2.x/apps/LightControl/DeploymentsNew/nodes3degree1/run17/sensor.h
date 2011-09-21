#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 422; break;
		case 1: res = 548; break;
		case 2: res = 513; break;
		case 3: res = 466; break;
		case 4: res = 735; break;
		case 5: res = 567; break;
		case 6: res = 319; break;
		case 7: res = 486; break;
		case 8: res = 359; break;
		default: break;
	}
	return res;
}

#endif
