#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 746; break;
		case 1: res = 1197; break;
		case 2: res = 863; break;
		case 3: res = 1027; break;
		case 4: res = 1648; break;
		case 5: res = 1250; break;
		case 6: res = 744; break;
		case 7: res = 1086; break;
		case 8: res = 862; break;
		default: break;
	}
	return res;
}

#endif
