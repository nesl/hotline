#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 551; break;
		case 1: res = 732; break;
		case 2: res = 593; break;
		case 3: res = 680; break;
		case 4: res = 810; break;
		case 5: res = 704; break;
		case 6: res = 591; break;
		case 7: res = 702; break;
		case 8: res = 506; break;
		default: break;
	}
	return res;
}

#endif
