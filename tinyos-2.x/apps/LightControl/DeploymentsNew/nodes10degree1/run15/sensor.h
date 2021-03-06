#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 403; break;
		case 1: res = 531; break;
		case 2: res = 507; break;
		case 3: res = 489; break;
		case 4: res = 567; break;
		case 5: res = 549; break;
		case 6: res = 593; break;
		case 7: res = 598; break;
		case 8: res = 540; break;
		case 9: res = 384; break;
		case 10: res = 557; break;
		case 11: res = 771; break;
		case 12: res = 773; break;
		case 13: res = 596; break;
		case 14: res = 681; break;
		case 15: res = 623; break;
		case 16: res = 763; break;
		case 17: res = 635; break;
		case 18: res = 582; break;
		case 19: res = 585; break;
		case 20: res = 489; break;
		case 21: res = 643; break;
		case 22: res = 707; break;
		case 23: res = 632; break;
		case 24: res = 705; break;
		case 25: res = 633; break;
		case 26: res = 751; break;
		case 27: res = 817; break;
		case 28: res = 675; break;
		case 29: res = 545; break;
		case 30: res = 577; break;
		case 31: res = 696; break;
		case 32: res = 650; break;
		case 33: res = 688; break;
		case 34: res = 690; break;
		case 35: res = 729; break;
		case 36: res = 681; break;
		case 37: res = 765; break;
		case 38: res = 742; break;
		case 39: res = 593; break;
		case 40: res = 538; break;
		case 41: res = 660; break;
		case 42: res = 648; break;
		case 43: res = 712; break;
		case 44: res = 693; break;
		case 45: res = 587; break;
		case 46: res = 617; break;
		case 47: res = 682; break;
		case 48: res = 716; break;
		case 49: res = 493; break;
		case 50: res = 548; break;
		case 51: res = 641; break;
		case 52: res = 685; break;
		case 53: res = 665; break;
		case 54: res = 677; break;
		case 55: res = 661; break;
		case 56: res = 705; break;
		case 57: res = 690; break;
		case 58: res = 697; break;
		case 59: res = 514; break;
		case 60: res = 592; break;
		case 61: res = 658; break;
		case 62: res = 717; break;
		case 63: res = 766; break;
		case 64: res = 645; break;
		case 65: res = 677; break;
		case 66: res = 612; break;
		case 67: res = 667; break;
		case 68: res = 753; break;
		case 69: res = 513; break;
		case 70: res = 543; break;
		case 71: res = 631; break;
		case 72: res = 597; break;
		case 73: res = 689; break;
		case 74: res = 598; break;
		case 75: res = 647; break;
		case 76: res = 670; break;
		case 77: res = 566; break;
		case 78: res = 703; break;
		case 79: res = 540; break;
		case 80: res = 572; break;
		case 81: res = 617; break;
		case 82: res = 712; break;
		case 83: res = 652; break;
		case 84: res = 655; break;
		case 85: res = 584; break;
		case 86: res = 538; break;
		case 87: res = 559; break;
		case 88: res = 566; break;
		case 89: res = 523; break;
		case 90: res = 490; break;
		case 91: res = 520; break;
		case 92: res = 522; break;
		case 93: res = 530; break;
		case 94: res = 609; break;
		case 95: res = 530; break;
		case 96: res = 449; break;
		case 97: res = 547; break;
		case 98: res = 529; break;
		case 99: res = 354; break;
		default: break;
	}
	return res;
}

#endif
