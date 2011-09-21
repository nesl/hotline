#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 745; break;
		case 1: res = 1048; break;
		case 2: res = 681; break;
		case 3: res = 994; break;
		case 4: res = 1398; break;
		case 5: res = 962; break;
		case 6: res = 774; break;
		case 7: res = 975; break;
		case 8: res = 678; break;
		default: break;
	}
	return res;
}

#endif
