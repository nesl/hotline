#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 425; break;
		case 1: res = 489; break;
		case 2: res = 517; break;
		case 3: res = 557; break;
		case 4: res = 656; break;
		case 5: res = 608; break;
		case 6: res = 378; break;
		case 7: res = 643; break;
		case 8: res = 733; break;
		case 9: res = 723; break;
		case 10: res = 632; break;
		case 11: res = 756; break;
		case 12: res = 664; break;
		case 13: res = 454; break;
		case 14: res = 529; break;
		case 15: res = 684; break;
		case 16: res = 656; break;
		case 17: res = 578; break;
		case 18: res = 751; break;
		case 19: res = 686; break;
		case 20: res = 507; break;
		case 21: res = 499; break;
		case 22: res = 596; break;
		case 23: res = 651; break;
		case 24: res = 585; break;
		case 25: res = 657; break;
		case 26: res = 659; break;
		case 27: res = 628; break;
		case 28: res = 516; break;
		case 29: res = 695; break;
		case 30: res = 738; break;
		case 31: res = 726; break;
		case 32: res = 658; break;
		case 33: res = 653; break;
		case 34: res = 581; break;
		case 35: res = 538; break;
		case 36: res = 587; break;
		case 37: res = 726; break;
		case 38: res = 710; break;
		case 39: res = 730; break;
		case 40: res = 709; break;
		case 41: res = 572; break;
		case 42: res = 432; break;
		case 43: res = 531; break;
		case 44: res = 537; break;
		case 45: res = 535; break;
		case 46: res = 602; break;
		case 47: res = 528; break;
		case 48: res = 362; break;
		default: break;
	}
	return res;
}

#endif
