#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 580; break;
		case 1: res = 706; break;
		case 2: res = 525; break;
		case 3: res = 698; break;
		case 4: res = 679; break;
		case 5: res = 665; break;
		case 6: res = 550; break;
		case 7: res = 655; break;
		case 8: res = 458; break;
		default: break;
	}
	return res;
}

#endif
