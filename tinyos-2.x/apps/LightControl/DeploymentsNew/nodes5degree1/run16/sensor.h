#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 371; break;
		case 1: res = 440; break;
		case 2: res = 515; break;
		case 3: res = 454; break;
		case 4: res = 311; break;
		case 5: res = 541; break;
		case 6: res = 734; break;
		case 7: res = 675; break;
		case 8: res = 663; break;
		case 9: res = 500; break;
		case 10: res = 522; break;
		case 11: res = 722; break;
		case 12: res = 649; break;
		case 13: res = 704; break;
		case 14: res = 525; break;
		case 15: res = 533; break;
		case 16: res = 690; break;
		case 17: res = 663; break;
		case 18: res = 772; break;
		case 19: res = 507; break;
		case 20: res = 377; break;
		case 21: res = 456; break;
		case 22: res = 564; break;
		case 23: res = 503; break;
		case 24: res = 342; break;
		default: break;
	}
	return res;
}

#endif
