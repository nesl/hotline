#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 813; break;
		case 1: res = 1201; break;
		case 2: res = 818; break;
		case 3: res = 1116; break;
		case 4: res = 1603; break;
		case 5: res = 1143; break;
		case 6: res = 781; break;
		case 7: res = 1018; break;
		case 8: res = 751; break;
		default: break;
	}
	return res;
}

#endif
