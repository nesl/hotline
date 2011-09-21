#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1409; break;
		case 1: res = 1573; break;
		case 2: res = 1331; break;
		case 3: res = 1553; break;
		case 4: res = 2027; break;
		case 5: res = 1537; break;
		case 6: res = 1258; break;
		case 7: res = 1429; break;
		case 8: res = 1224; break;
		default: break;
	}
	return res;
}

#endif
