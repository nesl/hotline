#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 608; break;
		case 1: res = 730; break;
		case 2: res = 798; break;
		case 3: res = 731; break;
		case 4: res = 696; break;
		case 5: res = 682; break;
		case 6: res = 821; break;
		case 7: res = 814; break;
		case 8: res = 686; break;
		case 9: res = 547; break;
		case 10: res = 704; break;
		case 11: res = 788; break;
		case 12: res = 835; break;
		case 13: res = 775; break;
		case 14: res = 708; break;
		case 15: res = 758; break;
		case 16: res = 839; break;
		case 17: res = 886; break;
		case 18: res = 855; break;
		case 19: res = 614; break;
		case 20: res = 683; break;
		case 21: res = 809; break;
		case 22: res = 852; break;
		case 23: res = 730; break;
		case 24: res = 716; break;
		case 25: res = 793; break;
		case 26: res = 893; break;
		case 27: res = 832; break;
		case 28: res = 855; break;
		case 29: res = 620; break;
		case 30: res = 615; break;
		case 31: res = 788; break;
		case 32: res = 812; break;
		case 33: res = 742; break;
		case 34: res = 810; break;
		case 35: res = 915; break;
		case 36: res = 868; break;
		case 37: res = 820; break;
		case 38: res = 847; break;
		case 39: res = 709; break;
		case 40: res = 630; break;
		case 41: res = 817; break;
		case 42: res = 768; break;
		case 43: res = 747; break;
		case 44: res = 750; break;
		case 45: res = 846; break;
		case 46: res = 840; break;
		case 47: res = 763; break;
		case 48: res = 738; break;
		case 49: res = 648; break;
		case 50: res = 769; break;
		case 51: res = 786; break;
		case 52: res = 927; break;
		case 53: res = 814; break;
		case 54: res = 873; break;
		case 55: res = 887; break;
		case 56: res = 771; break;
		case 57: res = 756; break;
		case 58: res = 678; break;
		case 59: res = 631; break;
		case 60: res = 799; break;
		case 61: res = 907; break;
		case 62: res = 840; break;
		case 63: res = 802; break;
		case 64: res = 797; break;
		case 65: res = 820; break;
		case 66: res = 898; break;
		case 67: res = 754; break;
		case 68: res = 859; break;
		case 69: res = 607; break;
		case 70: res = 802; break;
		case 71: res = 858; break;
		case 72: res = 821; break;
		case 73: res = 810; break;
		case 74: res = 852; break;
		case 75: res = 850; break;
		case 76: res = 821; break;
		case 77: res = 881; break;
		case 78: res = 754; break;
		case 79: res = 668; break;
		case 80: res = 657; break;
		case 81: res = 777; break;
		case 82: res = 735; break;
		case 83: res = 731; break;
		case 84: res = 793; break;
		case 85: res = 825; break;
		case 86: res = 826; break;
		case 87: res = 868; break;
		case 88: res = 776; break;
		case 89: res = 620; break;
		case 90: res = 612; break;
		case 91: res = 613; break;
		case 92: res = 651; break;
		case 93: res = 713; break;
		case 94: res = 803; break;
		case 95: res = 717; break;
		case 96: res = 784; break;
		case 97: res = 786; break;
		case 98: res = 637; break;
		case 99: res = 540; break;
		default: break;
	}
	return res;
}

#endif
