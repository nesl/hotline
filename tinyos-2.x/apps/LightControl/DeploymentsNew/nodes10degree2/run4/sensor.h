#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 490; break;
		case 1: res = 611; break;
		case 2: res = 647; break;
		case 3: res = 614; break;
		case 4: res = 646; break;
		case 5: res = 651; break;
		case 6: res = 701; break;
		case 7: res = 791; break;
		case 8: res = 687; break;
		case 9: res = 638; break;
		case 10: res = 750; break;
		case 11: res = 689; break;
		case 12: res = 791; break;
		case 13: res = 697; break;
		case 14: res = 775; break;
		case 15: res = 721; break;
		case 16: res = 863; break;
		case 17: res = 895; break;
		case 18: res = 914; break;
		case 19: res = 759; break;
		case 20: res = 718; break;
		case 21: res = 846; break;
		case 22: res = 709; break;
		case 23: res = 746; break;
		case 24: res = 722; break;
		case 25: res = 728; break;
		case 26: res = 751; break;
		case 27: res = 740; break;
		case 28: res = 821; break;
		case 29: res = 664; break;
		case 30: res = 706; break;
		case 31: res = 749; break;
		case 32: res = 773; break;
		case 33: res = 746; break;
		case 34: res = 876; break;
		case 35: res = 839; break;
		case 36: res = 740; break;
		case 37: res = 781; break;
		case 38: res = 797; break;
		case 39: res = 739; break;
		case 40: res = 737; break;
		case 41: res = 835; break;
		case 42: res = 690; break;
		case 43: res = 706; break;
		case 44: res = 710; break;
		case 45: res = 695; break;
		case 46: res = 755; break;
		case 47: res = 738; break;
		case 48: res = 805; break;
		case 49: res = 722; break;
		case 50: res = 700; break;
		case 51: res = 735; break;
		case 52: res = 770; break;
		case 53: res = 740; break;
		case 54: res = 748; break;
		case 55: res = 787; break;
		case 56: res = 725; break;
		case 57: res = 763; break;
		case 58: res = 726; break;
		case 59: res = 705; break;
		case 60: res = 747; break;
		case 61: res = 864; break;
		case 62: res = 813; break;
		case 63: res = 771; break;
		case 64: res = 802; break;
		case 65: res = 805; break;
		case 66: res = 947; break;
		case 67: res = 882; break;
		case 68: res = 852; break;
		case 69: res = 717; break;
		case 70: res = 755; break;
		case 71: res = 789; break;
		case 72: res = 889; break;
		case 73: res = 838; break;
		case 74: res = 829; break;
		case 75: res = 877; break;
		case 76: res = 939; break;
		case 77: res = 918; break;
		case 78: res = 797; break;
		case 79: res = 755; break;
		case 80: res = 657; break;
		case 81: res = 840; break;
		case 82: res = 877; break;
		case 83: res = 808; break;
		case 84: res = 860; break;
		case 85: res = 850; break;
		case 86: res = 910; break;
		case 87: res = 946; break;
		case 88: res = 846; break;
		case 89: res = 733; break;
		case 90: res = 642; break;
		case 91: res = 673; break;
		case 92: res = 708; break;
		case 93: res = 703; break;
		case 94: res = 695; break;
		case 95: res = 703; break;
		case 96: res = 766; break;
		case 97: res = 823; break;
		case 98: res = 650; break;
		case 99: res = 619; break;
		default: break;
	}
	return res;
}

#endif
