#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 546; break;
		case 1: res = 684; break;
		case 2: res = 652; break;
		case 3: res = 647; break;
		case 4: res = 686; break;
		case 5: res = 724; break;
		case 6: res = 649; break;
		case 7: res = 667; break;
		case 8: res = 895; break;
		case 9: res = 766; break;
		case 10: res = 864; break;
		case 11: res = 793; break;
		case 12: res = 833; break;
		case 13: res = 751; break;
		case 14: res = 679; break;
		case 15: res = 863; break;
		case 16: res = 896; break;
		case 17: res = 793; break;
		case 18: res = 825; break;
		case 19: res = 803; break;
		case 20: res = 622; break;
		case 21: res = 695; break;
		case 22: res = 898; break;
		case 23: res = 816; break;
		case 24: res = 961; break;
		case 25: res = 858; break;
		case 26: res = 811; break;
		case 27: res = 767; break;
		case 28: res = 698; break;
		case 29: res = 799; break;
		case 30: res = 850; break;
		case 31: res = 854; break;
		case 32: res = 856; break;
		case 33: res = 863; break;
		case 34: res = 691; break;
		case 35: res = 600; break;
		case 36: res = 696; break;
		case 37: res = 799; break;
		case 38: res = 783; break;
		case 39: res = 784; break;
		case 40: res = 791; break;
		case 41: res = 578; break;
		case 42: res = 484; break;
		case 43: res = 634; break;
		case 44: res = 621; break;
		case 45: res = 771; break;
		case 46: res = 712; break;
		case 47: res = 600; break;
		case 48: res = 492; break;
		default: break;
	}
	return res;
}

#endif
