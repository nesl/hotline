#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 421; break;
		case 1: res = 522; break;
		case 2: res = 478; break;
		case 3: res = 574; break;
		case 4: res = 581; break;
		case 5: res = 617; break;
		case 6: res = 366; break;
		case 7: res = 541; break;
		case 8: res = 562; break;
		case 9: res = 653; break;
		case 10: res = 676; break;
		case 11: res = 686; break;
		case 12: res = 737; break;
		case 13: res = 526; break;
		case 14: res = 534; break;
		case 15: res = 657; break;
		case 16: res = 677; break;
		case 17: res = 620; break;
		case 18: res = 614; break;
		case 19: res = 545; break;
		case 20: res = 528; break;
		case 21: res = 590; break;
		case 22: res = 699; break;
		case 23: res = 647; break;
		case 24: res = 760; break;
		case 25: res = 614; break;
		case 26: res = 553; break;
		case 27: res = 614; break;
		case 28: res = 523; break;
		case 29: res = 733; break;
		case 30: res = 623; break;
		case 31: res = 633; break;
		case 32: res = 660; break;
		case 33: res = 586; break;
		case 34: res = 473; break;
		case 35: res = 471; break;
		case 36: res = 560; break;
		case 37: res = 669; break;
		case 38: res = 625; break;
		case 39: res = 712; break;
		case 40: res = 568; break;
		case 41: res = 464; break;
		case 42: res = 381; break;
		case 43: res = 477; break;
		case 44: res = 545; break;
		case 45: res = 590; break;
		case 46: res = 627; break;
		case 47: res = 531; break;
		case 48: res = 379; break;
		default: break;
	}
	return res;
}

#endif
