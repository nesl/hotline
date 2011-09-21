#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 432; break;
		case 1: res = 606; break;
		case 2: res = 587; break;
		case 3: res = 630; break;
		case 4: res = 626; break;
		case 5: res = 625; break;
		case 6: res = 606; break;
		case 7: res = 640; break;
		case 8: res = 716; break;
		case 9: res = 753; break;
		case 10: res = 801; break;
		case 11: res = 852; break;
		case 12: res = 961; break;
		case 13: res = 755; break;
		case 14: res = 627; break;
		case 15: res = 883; break;
		case 16: res = 780; break;
		case 17: res = 793; break;
		case 18: res = 858; break;
		case 19: res = 868; break;
		case 20: res = 669; break;
		case 21: res = 674; break;
		case 22: res = 850; break;
		case 23: res = 809; break;
		case 24: res = 879; break;
		case 25: res = 793; break;
		case 26: res = 746; break;
		case 27: res = 630; break;
		case 28: res = 639; break;
		case 29: res = 798; break;
		case 30: res = 886; break;
		case 31: res = 784; break;
		case 32: res = 810; break;
		case 33: res = 731; break;
		case 34: res = 665; break;
		case 35: res = 565; break;
		case 36: res = 797; break;
		case 37: res = 820; break;
		case 38: res = 862; break;
		case 39: res = 790; break;
		case 40: res = 916; break;
		case 41: res = 706; break;
		case 42: res = 471; break;
		case 43: res = 650; break;
		case 44: res = 675; break;
		case 45: res = 755; break;
		case 46: res = 780; break;
		case 47: res = 712; break;
		case 48: res = 662; break;
		default: break;
	}
	return res;
}

#endif
