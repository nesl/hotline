#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 576; break;
		case 1: res = 689; break;
		case 2: res = 688; break;
		case 3: res = 752; break;
		case 4: res = 659; break;
		case 5: res = 647; break;
		case 6: res = 589; break;
		case 7: res = 692; break;
		case 8: res = 825; break;
		case 9: res = 793; break;
		case 10: res = 874; break;
		case 11: res = 881; break;
		case 12: res = 910; break;
		case 13: res = 776; break;
		case 14: res = 650; break;
		case 15: res = 781; break;
		case 16: res = 715; break;
		case 17: res = 707; break;
		case 18: res = 826; break;
		case 19: res = 840; break;
		case 20: res = 674; break;
		case 21: res = 648; break;
		case 22: res = 781; break;
		case 23: res = 698; break;
		case 24: res = 753; break;
		case 25: res = 732; break;
		case 26: res = 743; break;
		case 27: res = 642; break;
		case 28: res = 682; break;
		case 29: res = 854; break;
		case 30: res = 812; break;
		case 31: res = 707; break;
		case 32: res = 743; break;
		case 33: res = 751; break;
		case 34: res = 577; break;
		case 35: res = 628; break;
		case 36: res = 775; break;
		case 37: res = 773; break;
		case 38: res = 660; break;
		case 39: res = 784; break;
		case 40: res = 809; break;
		case 41: res = 633; break;
		case 42: res = 499; break;
		case 43: res = 658; break;
		case 44: res = 558; break;
		case 45: res = 648; break;
		case 46: res = 652; break;
		case 47: res = 661; break;
		case 48: res = 519; break;
		default: break;
	}
	return res;
}

#endif
