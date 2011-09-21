#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 413; break;
		case 1: res = 449; break;
		case 2: res = 451; break;
		case 3: res = 522; break;
		case 4: res = 433; break;
		case 5: res = 600; break;
		case 6: res = 652; break;
		case 7: res = 620; break;
		case 8: res = 711; break;
		case 9: res = 536; break;
		case 10: res = 519; break;
		case 11: res = 662; break;
		case 12: res = 741; break;
		case 13: res = 698; break;
		case 14: res = 547; break;
		case 15: res = 515; break;
		case 16: res = 627; break;
		case 17: res = 761; break;
		case 18: res = 713; break;
		case 19: res = 463; break;
		case 20: res = 392; break;
		case 21: res = 525; break;
		case 22: res = 557; break;
		case 23: res = 441; break;
		case 24: res = 372; break;
		default: break;
	}
	return res;
}

#endif
