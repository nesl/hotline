#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1117; break;
		case 1: res = 1245; break;
		case 2: res = 1129; break;
		case 3: res = 1295; break;
		case 4: res = 1765; break;
		case 5: res = 1351; break;
		case 6: res = 1135; break;
		case 7: res = 1324; break;
		case 8: res = 1192; break;
		default: break;
	}
	return res;
}

#endif
