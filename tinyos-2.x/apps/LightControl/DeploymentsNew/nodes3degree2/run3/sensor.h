#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 599; break;
		case 1: res = 696; break;
		case 2: res = 580; break;
		case 3: res = 731; break;
		case 4: res = 840; break;
		case 5: res = 732; break;
		case 6: res = 616; break;
		case 7: res = 686; break;
		case 8: res = 546; break;
		default: break;
	}
	return res;
}

#endif
