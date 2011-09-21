#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 787; break;
		case 1: res = 1131; break;
		case 2: res = 746; break;
		case 3: res = 1066; break;
		case 4: res = 1551; break;
		case 5: res = 1067; break;
		case 6: res = 750; break;
		case 7: res = 1029; break;
		case 8: res = 739; break;
		default: break;
	}
	return res;
}

#endif
