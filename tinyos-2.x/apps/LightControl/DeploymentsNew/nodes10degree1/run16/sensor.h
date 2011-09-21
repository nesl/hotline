#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 414; break;
		case 1: res = 544; break;
		case 2: res = 523; break;
		case 3: res = 517; break;
		case 4: res = 491; break;
		case 5: res = 516; break;
		case 6: res = 468; break;
		case 7: res = 532; break;
		case 8: res = 544; break;
		case 9: res = 393; break;
		case 10: res = 587; break;
		case 11: res = 732; break;
		case 12: res = 698; break;
		case 13: res = 636; break;
		case 14: res = 623; break;
		case 15: res = 570; break;
		case 16: res = 609; break;
		case 17: res = 658; break;
		case 18: res = 724; break;
		case 19: res = 596; break;
		case 20: res = 579; break;
		case 21: res = 719; break;
		case 22: res = 741; break;
		case 23: res = 649; break;
		case 24: res = 696; break;
		case 25: res = 649; break;
		case 26: res = 725; break;
		case 27: res = 692; break;
		case 28: res = 745; break;
		case 29: res = 545; break;
		case 30: res = 609; break;
		case 31: res = 710; break;
		case 32: res = 584; break;
		case 33: res = 625; break;
		case 34: res = 580; break;
		case 35: res = 618; break;
		case 36: res = 695; break;
		case 37: res = 686; break;
		case 38: res = 652; break;
		case 39: res = 546; break;
		case 40: res = 490; break;
		case 41: res = 587; break;
		case 42: res = 708; break;
		case 43: res = 729; break;
		case 44: res = 649; break;
		case 45: res = 644; break;
		case 46: res = 681; break;
		case 47: res = 693; break;
		case 48: res = 627; break;
		case 49: res = 586; break;
		case 50: res = 478; break;
		case 51: res = 628; break;
		case 52: res = 730; break;
		case 53: res = 709; break;
		case 54: res = 715; break;
		case 55: res = 788; break;
		case 56: res = 722; break;
		case 57: res = 654; break;
		case 58: res = 594; break;
		case 59: res = 556; break;
		case 60: res = 542; break;
		case 61: res = 770; break;
		case 62: res = 723; break;
		case 63: res = 718; break;
		case 64: res = 678; break;
		case 65: res = 730; break;
		case 66: res = 554; break;
		case 67: res = 719; break;
		case 68: res = 697; break;
		case 69: res = 499; break;
		case 70: res = 586; break;
		case 71: res = 675; break;
		case 72: res = 609; break;
		case 73: res = 616; break;
		case 74: res = 668; break;
		case 75: res = 710; break;
		case 76: res = 685; break;
		case 77: res = 744; break;
		case 78: res = 572; break;
		case 79: res = 470; break;
		case 80: res = 557; break;
		case 81: res = 629; break;
		case 82: res = 685; break;
		case 83: res = 600; break;
		case 84: res = 674; break;
		case 85: res = 630; break;
		case 86: res = 674; break;
		case 87: res = 626; break;
		case 88: res = 598; break;
		case 89: res = 502; break;
		case 90: res = 440; break;
		case 91: res = 535; break;
		case 92: res = 520; break;
		case 93: res = 500; break;
		case 94: res = 594; break;
		case 95: res = 595; break;
		case 96: res = 647; break;
		case 97: res = 527; break;
		case 98: res = 500; break;
		case 99: res = 325; break;
		default: break;
	}
	return res;
}

#endif
