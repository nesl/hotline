#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 564; break;
		case 1: res = 674; break;
		case 2: res = 537; break;
		case 3: res = 632; break;
		case 4: res = 685; break;
		case 5: res = 612; break;
		case 6: res = 553; break;
		case 7: res = 635; break;
		case 8: res = 440; break;
		default: break;
	}
	return res;
}

#endif
