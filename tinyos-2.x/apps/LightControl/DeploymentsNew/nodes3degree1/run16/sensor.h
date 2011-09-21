#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 426; break;
		case 1: res = 524; break;
		case 2: res = 472; break;
		case 3: res = 565; break;
		case 4: res = 740; break;
		case 5: res = 516; break;
		case 6: res = 418; break;
		case 7: res = 519; break;
		case 8: res = 350; break;
		default: break;
	}
	return res;
}

#endif
