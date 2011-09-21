#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1197; break;
		case 1: res = 1437; break;
		case 2: res = 1278; break;
		case 3: res = 1301; break;
		case 4: res = 1814; break;
		case 5: res = 1457; break;
		case 6: res = 1021; break;
		case 7: res = 1253; break;
		case 8: res = 1139; break;
		default: break;
	}
	return res;
}

#endif
