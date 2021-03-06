#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 421; break;
		case 1: res = 597; break;
		case 2: res = 541; break;
		case 3: res = 516; break;
		case 4: res = 534; break;
		case 5: res = 548; break;
		case 6: res = 505; break;
		case 7: res = 510; break;
		case 8: res = 553; break;
		case 9: res = 347; break;
		case 10: res = 504; break;
		case 11: res = 707; break;
		case 12: res = 589; break;
		case 13: res = 564; break;
		case 14: res = 660; break;
		case 15: res = 608; break;
		case 16: res = 725; break;
		case 17: res = 690; break;
		case 18: res = 716; break;
		case 19: res = 531; break;
		case 20: res = 497; break;
		case 21: res = 711; break;
		case 22: res = 756; break;
		case 23: res = 766; break;
		case 24: res = 766; break;
		case 25: res = 617; break;
		case 26: res = 734; break;
		case 27: res = 716; break;
		case 28: res = 730; break;
		case 29: res = 520; break;
		case 30: res = 584; break;
		case 31: res = 707; break;
		case 32: res = 713; break;
		case 33: res = 686; break;
		case 34: res = 649; break;
		case 35: res = 634; break;
		case 36: res = 676; break;
		case 37: res = 683; break;
		case 38: res = 710; break;
		case 39: res = 609; break;
		case 40: res = 585; break;
		case 41: res = 659; break;
		case 42: res = 731; break;
		case 43: res = 648; break;
		case 44: res = 622; break;
		case 45: res = 584; break;
		case 46: res = 673; break;
		case 47: res = 675; break;
		case 48: res = 759; break;
		case 49: res = 613; break;
		case 50: res = 537; break;
		case 51: res = 595; break;
		case 52: res = 669; break;
		case 53: res = 706; break;
		case 54: res = 665; break;
		case 55: res = 576; break;
		case 56: res = 639; break;
		case 57: res = 627; break;
		case 58: res = 683; break;
		case 59: res = 524; break;
		case 60: res = 527; break;
		case 61: res = 624; break;
		case 62: res = 665; break;
		case 63: res = 715; break;
		case 64: res = 701; break;
		case 65: res = 706; break;
		case 66: res = 570; break;
		case 67: res = 677; break;
		case 68: res = 666; break;
		case 69: res = 458; break;
		case 70: res = 556; break;
		case 71: res = 668; break;
		case 72: res = 616; break;
		case 73: res = 731; break;
		case 74: res = 790; break;
		case 75: res = 713; break;
		case 76: res = 563; break;
		case 77: res = 599; break;
		case 78: res = 622; break;
		case 79: res = 472; break;
		case 80: res = 584; break;
		case 81: res = 719; break;
		case 82: res = 743; break;
		case 83: res = 677; break;
		case 84: res = 639; break;
		case 85: res = 677; break;
		case 86: res = 575; break;
		case 87: res = 630; break;
		case 88: res = 698; break;
		case 89: res = 508; break;
		case 90: res = 415; break;
		case 91: res = 506; break;
		case 92: res = 568; break;
		case 93: res = 569; break;
		case 94: res = 604; break;
		case 95: res = 657; break;
		case 96: res = 584; break;
		case 97: res = 479; break;
		case 98: res = 440; break;
		case 99: res = 309; break;
		default: break;
	}
	return res;
}

#endif
