#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 585; break;
		case 1: res = 677; break;
		case 2: res = 562; break;
		case 3: res = 679; break;
		case 4: res = 859; break;
		case 5: res = 730; break;
		case 6: res = 572; break;
		case 7: res = 695; break;
		case 8: res = 571; break;
		default: break;
	}
	return res;
}

#endif
