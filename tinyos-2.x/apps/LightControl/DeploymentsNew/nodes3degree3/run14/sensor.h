#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 729; break;
		case 1: res = 1127; break;
		case 2: res = 767; break;
		case 3: res = 1059; break;
		case 4: res = 1593; break;
		case 5: res = 1137; break;
		case 6: res = 790; break;
		case 7: res = 1092; break;
		case 8: res = 832; break;
		default: break;
	}
	return res;
}

#endif
