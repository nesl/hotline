#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 388; break;
		case 1: res = 464; break;
		case 2: res = 530; break;
		case 3: res = 500; break;
		case 4: res = 308; break;
		case 5: res = 576; break;
		case 6: res = 723; break;
		case 7: res = 651; break;
		case 8: res = 666; break;
		case 9: res = 435; break;
		case 10: res = 555; break;
		case 11: res = 663; break;
		case 12: res = 728; break;
		case 13: res = 629; break;
		case 14: res = 524; break;
		case 15: res = 487; break;
		case 16: res = 647; break;
		case 17: res = 771; break;
		case 18: res = 731; break;
		case 19: res = 550; break;
		case 20: res = 348; break;
		case 21: res = 541; break;
		case 22: res = 627; break;
		case 23: res = 582; break;
		case 24: res = 412; break;
		default: break;
	}
	return res;
}

#endif
