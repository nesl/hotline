#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 370; break;
		case 1: res = 420; break;
		case 2: res = 487; break;
		case 3: res = 427; break;
		case 4: res = 376; break;
		case 5: res = 539; break;
		case 6: res = 640; break;
		case 7: res = 540; break;
		case 8: res = 554; break;
		case 9: res = 499; break;
		case 10: res = 541; break;
		case 11: res = 591; break;
		case 12: res = 615; break;
		case 13: res = 704; break;
		case 14: res = 521; break;
		case 15: res = 523; break;
		case 16: res = 619; break;
		case 17: res = 736; break;
		case 18: res = 734; break;
		case 19: res = 491; break;
		case 20: res = 379; break;
		case 21: res = 565; break;
		case 22: res = 648; break;
		case 23: res = 487; break;
		case 24: res = 375; break;
		default: break;
	}
	return res;
}

#endif
