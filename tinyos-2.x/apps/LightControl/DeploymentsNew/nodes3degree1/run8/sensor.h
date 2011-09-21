#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 421; break;
		case 1: res = 499; break;
		case 2: res = 507; break;
		case 3: res = 486; break;
		case 4: res = 635; break;
		case 5: res = 557; break;
		case 6: res = 364; break;
		case 7: res = 421; break;
		case 8: res = 318; break;
		default: break;
	}
	return res;
}

#endif
