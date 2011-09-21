#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1192; break;
		case 1: res = 1291; break;
		case 2: res = 1039; break;
		case 3: res = 1386; break;
		case 4: res = 1749; break;
		case 5: res = 1270; break;
		case 6: res = 1195; break;
		case 7: res = 1289; break;
		case 8: res = 1063; break;
		default: break;
	}
	return res;
}

#endif
