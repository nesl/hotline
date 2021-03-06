#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 424; break;
		case 1: res = 577; break;
		case 2: res = 554; break;
		case 3: res = 502; break;
		case 4: res = 420; break;
		case 5: res = 524; break;
		case 6: res = 535; break;
		case 7: res = 601; break;
		case 8: res = 533; break;
		case 9: res = 400; break;
		case 10: res = 571; break;
		case 11: res = 665; break;
		case 12: res = 642; break;
		case 13: res = 622; break;
		case 14: res = 621; break;
		case 15: res = 662; break;
		case 16: res = 692; break;
		case 17: res = 680; break;
		case 18: res = 734; break;
		case 19: res = 581; break;
		case 20: res = 553; break;
		case 21: res = 729; break;
		case 22: res = 755; break;
		case 23: res = 742; break;
		case 24: res = 705; break;
		case 25: res = 686; break;
		case 26: res = 718; break;
		case 27: res = 653; break;
		case 28: res = 717; break;
		case 29: res = 450; break;
		case 30: res = 581; break;
		case 31: res = 781; break;
		case 32: res = 655; break;
		case 33: res = 704; break;
		case 34: res = 606; break;
		case 35: res = 641; break;
		case 36: res = 718; break;
		case 37: res = 702; break;
		case 38: res = 714; break;
		case 39: res = 543; break;
		case 40: res = 484; break;
		case 41: res = 680; break;
		case 42: res = 736; break;
		case 43: res = 751; break;
		case 44: res = 704; break;
		case 45: res = 532; break;
		case 46: res = 659; break;
		case 47: res = 709; break;
		case 48: res = 578; break;
		case 49: res = 477; break;
		case 50: res = 416; break;
		case 51: res = 678; break;
		case 52: res = 737; break;
		case 53: res = 662; break;
		case 54: res = 736; break;
		case 55: res = 635; break;
		case 56: res = 616; break;
		case 57: res = 738; break;
		case 58: res = 532; break;
		case 59: res = 485; break;
		case 60: res = 536; break;
		case 61: res = 737; break;
		case 62: res = 622; break;
		case 63: res = 646; break;
		case 64: res = 681; break;
		case 65: res = 658; break;
		case 66: res = 601; break;
		case 67: res = 653; break;
		case 68: res = 670; break;
		case 69: res = 571; break;
		case 70: res = 610; break;
		case 71: res = 657; break;
		case 72: res = 540; break;
		case 73: res = 632; break;
		case 74: res = 728; break;
		case 75: res = 731; break;
		case 76: res = 671; break;
		case 77: res = 525; break;
		case 78: res = 624; break;
		case 79: res = 528; break;
		case 80: res = 599; break;
		case 81: res = 670; break;
		case 82: res = 706; break;
		case 83: res = 591; break;
		case 84: res = 688; break;
		case 85: res = 799; break;
		case 86: res = 656; break;
		case 87: res = 632; break;
		case 88: res = 548; break;
		case 89: res = 457; break;
		case 90: res = 453; break;
		case 91: res = 522; break;
		case 92: res = 505; break;
		case 93: res = 515; break;
		case 94: res = 540; break;
		case 95: res = 594; break;
		case 96: res = 611; break;
		case 97: res = 663; break;
		case 98: res = 546; break;
		case 99: res = 330; break;
		default: break;
	}
	return res;
}

#endif
