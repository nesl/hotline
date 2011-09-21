#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1245; break;
		case 1: res = 1479; break;
		case 2: res = 1269; break;
		case 3: res = 1481; break;
		case 4: res = 2013; break;
		case 5: res = 1608; break;
		case 6: res = 1250; break;
		case 7: res = 1526; break;
		case 8: res = 1325; break;
		default: break;
	}
	return res;
}

#endif
