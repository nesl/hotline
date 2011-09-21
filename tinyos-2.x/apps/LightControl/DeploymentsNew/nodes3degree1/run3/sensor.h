#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 415; break;
		case 1: res = 546; break;
		case 2: res = 434; break;
		case 3: res = 479; break;
		case 4: res = 675; break;
		case 5: res = 457; break;
		case 6: res = 417; break;
		case 7: res = 569; break;
		case 8: res = 390; break;
		default: break;
	}
	return res;
}

#endif
