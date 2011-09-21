#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 591; break;
		case 1: res = 617; break;
		case 2: res = 490; break;
		case 3: res = 667; break;
		case 4: res = 778; break;
		case 5: res = 573; break;
		case 6: res = 645; break;
		case 7: res = 703; break;
		case 8: res = 531; break;
		default: break;
	}
	return res;
}

#endif
