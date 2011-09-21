#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 382; break;
		case 1: res = 526; break;
		case 2: res = 538; break;
		case 3: res = 517; break;
		case 4: res = 368; break;
		case 5: res = 531; break;
		case 6: res = 701; break;
		case 7: res = 601; break;
		case 8: res = 758; break;
		case 9: res = 577; break;
		case 10: res = 484; break;
		case 11: res = 604; break;
		case 12: res = 607; break;
		case 13: res = 617; break;
		case 14: res = 565; break;
		case 15: res = 499; break;
		case 16: res = 679; break;
		case 17: res = 716; break;
		case 18: res = 723; break;
		case 19: res = 542; break;
		case 20: res = 351; break;
		case 21: res = 561; break;
		case 22: res = 575; break;
		case 23: res = 510; break;
		case 24: res = 406; break;
		default: break;
	}
	return res;
}

#endif
