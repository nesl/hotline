#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 819; break;
		case 1: res = 1175; break;
		case 2: res = 770; break;
		case 3: res = 1125; break;
		case 4: res = 1608; break;
		case 5: res = 1135; break;
		case 6: res = 853; break;
		case 7: res = 1113; break;
		case 8: res = 831; break;
		default: break;
	}
	return res;
}

#endif
