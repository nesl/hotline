#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1149; break;
		case 1: res = 1432; break;
		case 2: res = 1238; break;
		case 3: res = 1354; break;
		case 4: res = 1880; break;
		case 5: res = 1554; break;
		case 6: res = 1095; break;
		case 7: res = 1415; break;
		case 8: res = 1223; break;
		default: break;
	}
	return res;
}

#endif
