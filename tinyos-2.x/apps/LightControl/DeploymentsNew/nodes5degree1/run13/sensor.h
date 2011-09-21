#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 376; break;
		case 1: res = 444; break;
		case 2: res = 509; break;
		case 3: res = 452; break;
		case 4: res = 369; break;
		case 5: res = 601; break;
		case 6: res = 703; break;
		case 7: res = 681; break;
		case 8: res = 653; break;
		case 9: res = 573; break;
		case 10: res = 522; break;
		case 11: res = 626; break;
		case 12: res = 763; break;
		case 13: res = 677; break;
		case 14: res = 532; break;
		case 15: res = 514; break;
		case 16: res = 643; break;
		case 17: res = 745; break;
		case 18: res = 750; break;
		case 19: res = 474; break;
		case 20: res = 418; break;
		case 21: res = 556; break;
		case 22: res = 546; break;
		case 23: res = 481; break;
		case 24: res = 379; break;
		default: break;
	}
	return res;
}

#endif
