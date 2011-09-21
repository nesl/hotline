#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 598; break;
		case 1: res = 718; break;
		case 2: res = 774; break;
		case 3: res = 736; break;
		case 4: res = 771; break;
		case 5: res = 676; break;
		case 6: res = 708; break;
		case 7: res = 681; break;
		case 8: res = 626; break;
		case 9: res = 630; break;
		case 10: res = 731; break;
		case 11: res = 786; break;
		case 12: res = 848; break;
		case 13: res = 865; break;
		case 14: res = 787; break;
		case 15: res = 745; break;
		case 16: res = 742; break;
		case 17: res = 733; break;
		case 18: res = 765; break;
		case 19: res = 666; break;
		case 20: res = 681; break;
		case 21: res = 782; break;
		case 22: res = 880; break;
		case 23: res = 833; break;
		case 24: res = 794; break;
		case 25: res = 773; break;
		case 26: res = 876; break;
		case 27: res = 729; break;
		case 28: res = 656; break;
		case 29: res = 586; break;
		case 30: res = 695; break;
		case 31: res = 759; break;
		case 32: res = 768; break;
		case 33: res = 833; break;
		case 34: res = 807; break;
		case 35: res = 898; break;
		case 36: res = 914; break;
		case 37: res = 809; break;
		case 38: res = 798; break;
		case 39: res = 614; break;
		case 40: res = 694; break;
		case 41: res = 786; break;
		case 42: res = 695; break;
		case 43: res = 825; break;
		case 44: res = 746; break;
		case 45: res = 755; break;
		case 46: res = 885; break;
		case 47: res = 846; break;
		case 48: res = 723; break;
		case 49: res = 647; break;
		case 50: res = 704; break;
		case 51: res = 646; break;
		case 52: res = 861; break;
		case 53: res = 807; break;
		case 54: res = 850; break;
		case 55: res = 797; break;
		case 56: res = 807; break;
		case 57: res = 754; break;
		case 58: res = 754; break;
		case 59: res = 607; break;
		case 60: res = 663; break;
		case 61: res = 863; break;
		case 62: res = 744; break;
		case 63: res = 830; break;
		case 64: res = 787; break;
		case 65: res = 888; break;
		case 66: res = 898; break;
		case 67: res = 886; break;
		case 68: res = 867; break;
		case 69: res = 677; break;
		case 70: res = 675; break;
		case 71: res = 741; break;
		case 72: res = 822; break;
		case 73: res = 772; break;
		case 74: res = 830; break;
		case 75: res = 906; break;
		case 76: res = 822; break;
		case 77: res = 787; break;
		case 78: res = 820; break;
		case 79: res = 705; break;
		case 80: res = 574; break;
		case 81: res = 765; break;
		case 82: res = 821; break;
		case 83: res = 726; break;
		case 84: res = 874; break;
		case 85: res = 877; break;
		case 86: res = 742; break;
		case 87: res = 805; break;
		case 88: res = 843; break;
		case 89: res = 733; break;
		case 90: res = 556; break;
		case 91: res = 604; break;
		case 92: res = 638; break;
		case 93: res = 718; break;
		case 94: res = 713; break;
		case 95: res = 771; break;
		case 96: res = 676; break;
		case 97: res = 726; break;
		case 98: res = 674; break;
		case 99: res = 633; break;
		default: break;
	}
	return res;
}

#endif
