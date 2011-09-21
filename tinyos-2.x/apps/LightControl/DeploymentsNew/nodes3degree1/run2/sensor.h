#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 431; break;
		case 1: res = 518; break;
		case 2: res = 477; break;
		case 3: res = 474; break;
		case 4: res = 742; break;
		case 5: res = 516; break;
		case 6: res = 312; break;
		case 7: res = 562; break;
		case 8: res = 391; break;
		default: break;
	}
	return res;
}

#endif
