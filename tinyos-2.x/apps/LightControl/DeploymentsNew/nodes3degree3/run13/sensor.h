#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 777; break;
		case 1: res = 1090; break;
		case 2: res = 724; break;
		case 3: res = 1074; break;
		case 4: res = 1558; break;
		case 5: res = 1136; break;
		case 6: res = 810; break;
		case 7: res = 1096; break;
		case 8: res = 870; break;
		default: break;
	}
	return res;
}

#endif
