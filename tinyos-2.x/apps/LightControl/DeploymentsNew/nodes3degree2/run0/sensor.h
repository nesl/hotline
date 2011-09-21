#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 633; break;
		case 1: res = 758; break;
		case 2: res = 516; break;
		case 3: res = 733; break;
		case 4: res = 805; break;
		case 5: res = 643; break;
		case 6: res = 586; break;
		case 7: res = 703; break;
		case 8: res = 474; break;
		default: break;
	}
	return res;
}

#endif
