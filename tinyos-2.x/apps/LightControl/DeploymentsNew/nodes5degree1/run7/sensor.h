#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 409; break;
		case 1: res = 468; break;
		case 2: res = 488; break;
		case 3: res = 415; break;
		case 4: res = 312; break;
		case 5: res = 526; break;
		case 6: res = 629; break;
		case 7: res = 598; break;
		case 8: res = 630; break;
		case 9: res = 471; break;
		case 10: res = 463; break;
		case 11: res = 692; break;
		case 12: res = 719; break;
		case 13: res = 773; break;
		case 14: res = 527; break;
		case 15: res = 519; break;
		case 16: res = 724; break;
		case 17: res = 662; break;
		case 18: res = 750; break;
		case 19: res = 492; break;
		case 20: res = 383; break;
		case 21: res = 534; break;
		case 22: res = 542; break;
		case 23: res = 513; break;
		case 24: res = 425; break;
		default: break;
	}
	return res;
}

#endif
