#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 590; break;
		case 1: res = 722; break;
		case 2: res = 572; break;
		case 3: res = 689; break;
		case 4: res = 830; break;
		case 5: res = 738; break;
		case 6: res = 533; break;
		case 7: res = 651; break;
		case 8: res = 538; break;
		default: break;
	}
	return res;
}

#endif
