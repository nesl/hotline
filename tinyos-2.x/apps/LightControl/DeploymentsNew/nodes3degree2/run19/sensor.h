#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 563; break;
		case 1: res = 773; break;
		case 2: res = 558; break;
		case 3: res = 716; break;
		case 4: res = 765; break;
		case 5: res = 697; break;
		case 6: res = 572; break;
		case 7: res = 711; break;
		case 8: res = 473; break;
		default: break;
	}
	return res;
}

#endif
