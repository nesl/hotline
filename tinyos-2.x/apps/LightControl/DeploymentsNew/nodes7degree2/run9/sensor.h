#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 497; break;
		case 1: res = 658; break;
		case 2: res = 648; break;
		case 3: res = 670; break;
		case 4: res = 611; break;
		case 5: res = 623; break;
		case 6: res = 538; break;
		case 7: res = 661; break;
		case 8: res = 817; break;
		case 9: res = 827; break;
		case 10: res = 835; break;
		case 11: res = 852; break;
		case 12: res = 888; break;
		case 13: res = 693; break;
		case 14: res = 709; break;
		case 15: res = 867; break;
		case 16: res = 862; break;
		case 17: res = 741; break;
		case 18: res = 862; break;
		case 19: res = 816; break;
		case 20: res = 609; break;
		case 21: res = 675; break;
		case 22: res = 952; break;
		case 23: res = 813; break;
		case 24: res = 909; break;
		case 25: res = 849; break;
		case 26: res = 797; break;
		case 27: res = 634; break;
		case 28: res = 720; break;
		case 29: res = 825; break;
		case 30: res = 878; break;
		case 31: res = 872; break;
		case 32: res = 880; break;
		case 33: res = 775; break;
		case 34: res = 674; break;
		case 35: res = 611; break;
		case 36: res = 889; break;
		case 37: res = 871; break;
		case 38: res = 851; break;
		case 39: res = 859; break;
		case 40: res = 852; break;
		case 41: res = 675; break;
		case 42: res = 553; break;
		case 43: res = 767; break;
		case 44: res = 726; break;
		case 45: res = 818; break;
		case 46: res = 751; break;
		case 47: res = 639; break;
		case 48: res = 600; break;
		default: break;
	}
	return res;
}

#endif
