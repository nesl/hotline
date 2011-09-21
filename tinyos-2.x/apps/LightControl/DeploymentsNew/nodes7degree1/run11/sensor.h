#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 442; break;
		case 1: res = 526; break;
		case 2: res = 444; break;
		case 3: res = 539; break;
		case 4: res = 598; break;
		case 5: res = 618; break;
		case 6: res = 404; break;
		case 7: res = 643; break;
		case 8: res = 734; break;
		case 9: res = 684; break;
		case 10: res = 707; break;
		case 11: res = 712; break;
		case 12: res = 624; break;
		case 13: res = 489; break;
		case 14: res = 511; break;
		case 15: res = 608; break;
		case 16: res = 623; break;
		case 17: res = 602; break;
		case 18: res = 765; break;
		case 19: res = 592; break;
		case 20: res = 511; break;
		case 21: res = 516; break;
		case 22: res = 561; break;
		case 23: res = 639; break;
		case 24: res = 626; break;
		case 25: res = 581; break;
		case 26: res = 546; break;
		case 27: res = 642; break;
		case 28: res = 597; break;
		case 29: res = 748; break;
		case 30: res = 716; break;
		case 31: res = 724; break;
		case 32: res = 643; break;
		case 33: res = 578; break;
		case 34: res = 474; break;
		case 35: res = 613; break;
		case 36: res = 695; break;
		case 37: res = 693; break;
		case 38: res = 561; break;
		case 39: res = 656; break;
		case 40: res = 674; break;
		case 41: res = 480; break;
		case 42: res = 407; break;
		case 43: res = 498; break;
		case 44: res = 478; break;
		case 45: res = 495; break;
		case 46: res = 566; break;
		case 47: res = 561; break;
		case 48: res = 406; break;
		default: break;
	}
	return res;
}

#endif
