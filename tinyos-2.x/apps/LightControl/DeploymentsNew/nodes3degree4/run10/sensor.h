#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1315; break;
		case 1: res = 1529; break;
		case 2: res = 1354; break;
		case 3: res = 1513; break;
		case 4: res = 2045; break;
		case 5: res = 1602; break;
		case 6: res = 1239; break;
		case 7: res = 1513; break;
		case 8: res = 1322; break;
		default: break;
	}
	return res;
}

#endif
