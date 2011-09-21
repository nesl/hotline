#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1353; break;
		case 1: res = 1515; break;
		case 2: res = 1222; break;
		case 3: res = 1567; break;
		case 4: res = 1975; break;
		case 5: res = 1452; break;
		case 6: res = 1257; break;
		case 7: res = 1442; break;
		case 8: res = 1159; break;
		default: break;
	}
	return res;
}

#endif
