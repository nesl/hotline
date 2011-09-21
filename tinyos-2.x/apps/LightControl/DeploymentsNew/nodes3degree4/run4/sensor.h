#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1171; break;
		case 1: res = 1368; break;
		case 2: res = 1244; break;
		case 3: res = 1300; break;
		case 4: res = 1833; break;
		case 5: res = 1435; break;
		case 6: res = 1145; break;
		case 7: res = 1301; break;
		case 8: res = 1241; break;
		default: break;
	}
	return res;
}

#endif
