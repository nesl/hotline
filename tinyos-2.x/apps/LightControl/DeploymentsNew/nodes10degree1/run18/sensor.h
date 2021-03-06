#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 402; break;
		case 1: res = 530; break;
		case 2: res = 541; break;
		case 3: res = 503; break;
		case 4: res = 575; break;
		case 5: res = 530; break;
		case 6: res = 502; break;
		case 7: res = 489; break;
		case 8: res = 571; break;
		case 9: res = 425; break;
		case 10: res = 608; break;
		case 11: res = 683; break;
		case 12: res = 752; break;
		case 13: res = 658; break;
		case 14: res = 738; break;
		case 15: res = 665; break;
		case 16: res = 701; break;
		case 17: res = 627; break;
		case 18: res = 580; break;
		case 19: res = 531; break;
		case 20: res = 668; break;
		case 21: res = 682; break;
		case 22: res = 674; break;
		case 23: res = 624; break;
		case 24: res = 749; break;
		case 25: res = 680; break;
		case 26: res = 616; break;
		case 27: res = 674; break;
		case 28: res = 626; break;
		case 29: res = 549; break;
		case 30: res = 620; break;
		case 31: res = 705; break;
		case 32: res = 578; break;
		case 33: res = 589; break;
		case 34: res = 698; break;
		case 35: res = 700; break;
		case 36: res = 674; break;
		case 37: res = 671; break;
		case 38: res = 635; break;
		case 39: res = 591; break;
		case 40: res = 465; break;
		case 41: res = 587; break;
		case 42: res = 624; break;
		case 43: res = 645; break;
		case 44: res = 578; break;
		case 45: res = 542; break;
		case 46: res = 666; break;
		case 47: res = 650; break;
		case 48: res = 657; break;
		case 49: res = 562; break;
		case 50: res = 476; break;
		case 51: res = 632; break;
		case 52: res = 667; break;
		case 53: res = 674; break;
		case 54: res = 667; break;
		case 55: res = 646; break;
		case 56: res = 634; break;
		case 57: res = 600; break;
		case 58: res = 601; break;
		case 59: res = 498; break;
		case 60: res = 518; break;
		case 61: res = 669; break;
		case 62: res = 704; break;
		case 63: res = 743; break;
		case 64: res = 629; break;
		case 65: res = 578; break;
		case 66: res = 641; break;
		case 67: res = 754; break;
		case 68: res = 637; break;
		case 69: res = 445; break;
		case 70: res = 600; break;
		case 71: res = 709; break;
		case 72: res = 613; break;
		case 73: res = 682; break;
		case 74: res = 664; break;
		case 75: res = 575; break;
		case 76: res = 636; break;
		case 77: res = 633; break;
		case 78: res = 637; break;
		case 79: res = 452; break;
		case 80: res = 620; break;
		case 81: res = 780; break;
		case 82: res = 730; break;
		case 83: res = 647; break;
		case 84: res = 701; break;
		case 85: res = 639; break;
		case 86: res = 614; break;
		case 87: res = 617; break;
		case 88: res = 652; break;
		case 89: res = 526; break;
		case 90: res = 424; break;
		case 91: res = 591; break;
		case 92: res = 621; break;
		case 93: res = 524; break;
		case 94: res = 511; break;
		case 95: res = 559; break;
		case 96: res = 565; break;
		case 97: res = 531; break;
		case 98: res = 517; break;
		case 99: res = 428; break;
		default: break;
	}
	return res;
}

#endif
