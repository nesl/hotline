#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 855; break;
		case 1: res = 1191; break;
		case 2: res = 793; break;
		case 3: res = 1197; break;
		case 4: res = 1696; break;
		case 5: res = 1181; break;
		case 6: res = 906; break;
		case 7: res = 1208; break;
		case 8: res = 873; break;
		default: break;
	}
	return res;
}

#endif
