#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1231; break;
		case 1: res = 1305; break;
		case 2: res = 1116; break;
		case 3: res = 1397; break;
		case 4: res = 1830; break;
		case 5: res = 1342; break;
		case 6: res = 1244; break;
		case 7: res = 1347; break;
		case 8: res = 1152; break;
		default: break;
	}
	return res;
}

#endif
