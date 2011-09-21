#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 624; break;
		case 1: res = 717; break;
		case 2: res = 525; break;
		case 3: res = 721; break;
		case 4: res = 824; break;
		case 5: res = 622; break;
		case 6: res = 609; break;
		case 7: res = 655; break;
		case 8: res = 439; break;
		default: break;
	}
	return res;
}

#endif
