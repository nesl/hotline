#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 539; break;
		case 1: res = 664; break;
		case 2: res = 723; break;
		case 3: res = 729; break;
		case 4: res = 697; break;
		case 5: res = 640; break;
		case 6: res = 681; break;
		case 7: res = 677; break;
		case 8: res = 609; break;
		case 9: res = 590; break;
		case 10: res = 754; break;
		case 11: res = 753; break;
		case 12: res = 810; break;
		case 13: res = 772; break;
		case 14: res = 772; break;
		case 15: res = 711; break;
		case 16: res = 751; break;
		case 17: res = 797; break;
		case 18: res = 819; break;
		case 19: res = 638; break;
		case 20: res = 748; break;
		case 21: res = 836; break;
		case 22: res = 794; break;
		case 23: res = 778; break;
		case 24: res = 729; break;
		case 25: res = 819; break;
		case 26: res = 840; break;
		case 27: res = 723; break;
		case 28: res = 713; break;
		case 29: res = 658; break;
		case 30: res = 761; break;
		case 31: res = 788; break;
		case 32: res = 767; break;
		case 33: res = 761; break;
		case 34: res = 768; break;
		case 35: res = 820; break;
		case 36: res = 823; break;
		case 37: res = 719; break;
		case 38: res = 724; break;
		case 39: res = 657; break;
		case 40: res = 729; break;
		case 41: res = 858; break;
		case 42: res = 808; break;
		case 43: res = 764; break;
		case 44: res = 675; break;
		case 45: res = 749; break;
		case 46: res = 838; break;
		case 47: res = 756; break;
		case 48: res = 786; break;
		case 49: res = 730; break;
		case 50: res = 686; break;
		case 51: res = 719; break;
		case 52: res = 829; break;
		case 53: res = 884; break;
		case 54: res = 758; break;
		case 55: res = 767; break;
		case 56: res = 778; break;
		case 57: res = 782; break;
		case 58: res = 770; break;
		case 59: res = 808; break;
		case 60: res = 719; break;
		case 61: res = 716; break;
		case 62: res = 858; break;
		case 63: res = 762; break;
		case 64: res = 819; break;
		case 65: res = 859; break;
		case 66: res = 850; break;
		case 67: res = 806; break;
		case 68: res = 838; break;
		case 69: res = 720; break;
		case 70: res = 698; break;
		case 71: res = 806; break;
		case 72: res = 736; break;
		case 73: res = 825; break;
		case 74: res = 755; break;
		case 75: res = 823; break;
		case 76: res = 879; break;
		case 77: res = 753; break;
		case 78: res = 733; break;
		case 79: res = 681; break;
		case 80: res = 717; break;
		case 81: res = 716; break;
		case 82: res = 790; break;
		case 83: res = 624; break;
		case 84: res = 755; break;
		case 85: res = 758; break;
		case 86: res = 775; break;
		case 87: res = 891; break;
		case 88: res = 775; break;
		case 89: res = 669; break;
		case 90: res = 628; break;
		case 91: res = 643; break;
		case 92: res = 581; break;
		case 93: res = 677; break;
		case 94: res = 645; break;
		case 95: res = 697; break;
		case 96: res = 735; break;
		case 97: res = 817; break;
		case 98: res = 686; break;
		case 99: res = 606; break;
		default: break;
	}
	return res;
}

#endif