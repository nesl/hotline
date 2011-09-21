#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1252; break;
		case 1: res = 1390; break;
		case 2: res = 1118; break;
		case 3: res = 1388; break;
		case 4: res = 1795; break;
		case 5: res = 1341; break;
		case 6: res = 1158; break;
		case 7: res = 1265; break;
		case 8: res = 1051; break;
		default: break;
	}
	return res;
}

#endif
