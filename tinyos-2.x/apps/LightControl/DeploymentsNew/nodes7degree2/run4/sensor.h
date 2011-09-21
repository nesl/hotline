#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 613; break;
		case 1: res = 806; break;
		case 2: res = 625; break;
		case 3: res = 608; break;
		case 4: res = 631; break;
		case 5: res = 588; break;
		case 6: res = 539; break;
		case 7: res = 711; break;
		case 8: res = 812; break;
		case 9: res = 758; break;
		case 10: res = 715; break;
		case 11: res = 715; break;
		case 12: res = 846; break;
		case 13: res = 635; break;
		case 14: res = 637; break;
		case 15: res = 801; break;
		case 16: res = 796; break;
		case 17: res = 674; break;
		case 18: res = 766; break;
		case 19: res = 761; break;
		case 20: res = 662; break;
		case 21: res = 642; break;
		case 22: res = 836; break;
		case 23: res = 778; break;
		case 24: res = 850; break;
		case 25: res = 731; break;
		case 26: res = 765; break;
		case 27: res = 716; break;
		case 28: res = 686; break;
		case 29: res = 734; break;
		case 30: res = 885; break;
		case 31: res = 839; break;
		case 32: res = 816; break;
		case 33: res = 829; break;
		case 34: res = 676; break;
		case 35: res = 615; break;
		case 36: res = 802; break;
		case 37: res = 891; break;
		case 38: res = 769; break;
		case 39: res = 804; break;
		case 40: res = 726; break;
		case 41: res = 641; break;
		case 42: res = 506; break;
		case 43: res = 711; break;
		case 44: res = 685; break;
		case 45: res = 758; break;
		case 46: res = 620; break;
		case 47: res = 637; break;
		case 48: res = 539; break;
		default: break;
	}
	return res;
}

#endif
