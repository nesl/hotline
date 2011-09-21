#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 488; break;
		case 1: res = 609; break;
		case 2: res = 647; break;
		case 3: res = 642; break;
		case 4: res = 619; break;
		case 5: res = 610; break;
		case 6: res = 545; break;
		case 7: res = 584; break;
		case 8: res = 745; break;
		case 9: res = 807; break;
		case 10: res = 829; break;
		case 11: res = 865; break;
		case 12: res = 839; break;
		case 13: res = 758; break;
		case 14: res = 624; break;
		case 15: res = 789; break;
		case 16: res = 806; break;
		case 17: res = 752; break;
		case 18: res = 781; break;
		case 19: res = 853; break;
		case 20: res = 692; break;
		case 21: res = 673; break;
		case 22: res = 824; break;
		case 23: res = 732; break;
		case 24: res = 691; break;
		case 25: res = 733; break;
		case 26: res = 741; break;
		case 27: res = 749; break;
		case 28: res = 722; break;
		case 29: res = 802; break;
		case 30: res = 740; break;
		case 31: res = 745; break;
		case 32: res = 752; break;
		case 33: res = 756; break;
		case 34: res = 669; break;
		case 35: res = 662; break;
		case 36: res = 811; break;
		case 37: res = 826; break;
		case 38: res = 762; break;
		case 39: res = 790; break;
		case 40: res = 757; break;
		case 41: res = 537; break;
		case 42: res = 527; break;
		case 43: res = 694; break;
		case 44: res = 606; break;
		case 45: res = 798; break;
		case 46: res = 756; break;
		case 47: res = 621; break;
		case 48: res = 527; break;
		default: break;
	}
	return res;
}

#endif
