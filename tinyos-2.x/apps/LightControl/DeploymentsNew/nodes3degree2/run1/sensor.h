#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 512; break;
		case 1: res = 623; break;
		case 2: res = 525; break;
		case 3: res = 586; break;
		case 4: res = 764; break;
		case 5: res = 700; break;
		case 6: res = 528; break;
		case 7: res = 658; break;
		case 8: res = 551; break;
		default: break;
	}
	return res;
}

#endif
