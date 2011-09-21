#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 422; break;
		case 1: res = 564; break;
		case 2: res = 430; break;
		case 3: res = 479; break;
		case 4: res = 762; break;
		case 5: res = 485; break;
		case 6: res = 345; break;
		case 7: res = 520; break;
		case 8: res = 371; break;
		default: break;
	}
	return res;
}

#endif
