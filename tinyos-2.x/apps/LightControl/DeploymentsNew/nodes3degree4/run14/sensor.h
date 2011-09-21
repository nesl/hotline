#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1265; break;
		case 1: res = 1509; break;
		case 2: res = 1234; break;
		case 3: res = 1523; break;
		case 4: res = 2000; break;
		case 5: res = 1550; break;
		case 6: res = 1272; break;
		case 7: res = 1481; break;
		case 8: res = 1296; break;
		default: break;
	}
	return res;
}

#endif
