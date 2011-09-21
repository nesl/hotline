#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 624; break;
		case 1: res = 638; break;
		case 2: res = 466; break;
		case 3: res = 652; break;
		case 4: res = 748; break;
		case 5: res = 582; break;
		case 6: res = 534; break;
		case 7: res = 589; break;
		case 8: res = 489; break;
		default: break;
	}
	return res;
}

#endif
