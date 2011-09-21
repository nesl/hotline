#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 558; break;
		case 1: res = 677; break;
		case 2: res = 708; break;
		case 3: res = 630; break;
		case 4: res = 585; break;
		case 5: res = 571; break;
		case 6: res = 545; break;
		case 7: res = 669; break;
		case 8: res = 785; break;
		case 9: res = 813; break;
		case 10: res = 850; break;
		case 11: res = 786; break;
		case 12: res = 829; break;
		case 13: res = 646; break;
		case 14: res = 724; break;
		case 15: res = 794; break;
		case 16: res = 857; break;
		case 17: res = 829; break;
		case 18: res = 891; break;
		case 19: res = 791; break;
		case 20: res = 596; break;
		case 21: res = 713; break;
		case 22: res = 836; break;
		case 23: res = 734; break;
		case 24: res = 877; break;
		case 25: res = 839; break;
		case 26: res = 825; break;
		case 27: res = 694; break;
		case 28: res = 789; break;
		case 29: res = 772; break;
		case 30: res = 806; break;
		case 31: res = 799; break;
		case 32: res = 889; break;
		case 33: res = 893; break;
		case 34: res = 728; break;
		case 35: res = 630; break;
		case 36: res = 837; break;
		case 37: res = 802; break;
		case 38: res = 799; break;
		case 39: res = 815; break;
		case 40: res = 864; break;
		case 41: res = 674; break;
		case 42: res = 503; break;
		case 43: res = 626; break;
		case 44: res = 626; break;
		case 45: res = 738; break;
		case 46: res = 664; break;
		case 47: res = 625; break;
		case 48: res = 548; break;
		default: break;
	}
	return res;
}

#endif
