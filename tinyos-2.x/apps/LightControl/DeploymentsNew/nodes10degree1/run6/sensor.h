#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 422; break;
		case 1: res = 563; break;
		case 2: res = 477; break;
		case 3: res = 522; break;
		case 4: res = 573; break;
		case 5: res = 565; break;
		case 6: res = 529; break;
		case 7: res = 551; break;
		case 8: res = 506; break;
		case 9: res = 302; break;
		case 10: res = 577; break;
		case 11: res = 743; break;
		case 12: res = 645; break;
		case 13: res = 689; break;
		case 14: res = 697; break;
		case 15: res = 598; break;
		case 16: res = 644; break;
		case 17: res = 609; break;
		case 18: res = 681; break;
		case 19: res = 500; break;
		case 20: res = 568; break;
		case 21: res = 692; break;
		case 22: res = 675; break;
		case 23: res = 785; break;
		case 24: res = 786; break;
		case 25: res = 670; break;
		case 26: res = 788; break;
		case 27: res = 623; break;
		case 28: res = 650; break;
		case 29: res = 506; break;
		case 30: res = 579; break;
		case 31: res = 749; break;
		case 32: res = 588; break;
		case 33: res = 608; break;
		case 34: res = 611; break;
		case 35: res = 648; break;
		case 36: res = 696; break;
		case 37: res = 664; break;
		case 38: res = 700; break;
		case 39: res = 528; break;
		case 40: res = 513; break;
		case 41: res = 697; break;
		case 42: res = 624; break;
		case 43: res = 702; break;
		case 44: res = 611; break;
		case 45: res = 527; break;
		case 46: res = 620; break;
		case 47: res = 612; break;
		case 48: res = 736; break;
		case 49: res = 602; break;
		case 50: res = 479; break;
		case 51: res = 642; break;
		case 52: res = 638; break;
		case 53: res = 692; break;
		case 54: res = 706; break;
		case 55: res = 659; break;
		case 56: res = 620; break;
		case 57: res = 621; break;
		case 58: res = 706; break;
		case 59: res = 568; break;
		case 60: res = 510; break;
		case 61: res = 713; break;
		case 62: res = 695; break;
		case 63: res = 609; break;
		case 64: res = 586; break;
		case 65: res = 678; break;
		case 66: res = 582; break;
		case 67: res = 697; break;
		case 68: res = 714; break;
		case 69: res = 470; break;
		case 70: res = 533; break;
		case 71: res = 653; break;
		case 72: res = 666; break;
		case 73: res = 638; break;
		case 74: res = 650; break;
		case 75: res = 663; break;
		case 76: res = 661; break;
		case 77: res = 672; break;
		case 78: res = 696; break;
		case 79: res = 506; break;
		case 80: res = 531; break;
		case 81: res = 619; break;
		case 82: res = 743; break;
		case 83: res = 630; break;
		case 84: res = 786; break;
		case 85: res = 672; break;
		case 86: res = 611; break;
		case 87: res = 720; break;
		case 88: res = 698; break;
		case 89: res = 491; break;
		case 90: res = 385; break;
		case 91: res = 511; break;
		case 92: res = 638; break;
		case 93: res = 520; break;
		case 94: res = 603; break;
		case 95: res = 570; break;
		case 96: res = 475; break;
		case 97: res = 592; break;
		case 98: res = 620; break;
		case 99: res = 364; break;
		default: break;
	}
	return res;
}

#endif
