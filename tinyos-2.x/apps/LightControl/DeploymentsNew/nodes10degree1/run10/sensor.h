#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 436; break;
		case 1: res = 516; break;
		case 2: res = 541; break;
		case 3: res = 561; break;
		case 4: res = 505; break;
		case 5: res = 497; break;
		case 6: res = 476; break;
		case 7: res = 526; break;
		case 8: res = 651; break;
		case 9: res = 356; break;
		case 10: res = 630; break;
		case 11: res = 731; break;
		case 12: res = 719; break;
		case 13: res = 625; break;
		case 14: res = 710; break;
		case 15: res = 745; break;
		case 16: res = 777; break;
		case 17: res = 617; break;
		case 18: res = 689; break;
		case 19: res = 531; break;
		case 20: res = 653; break;
		case 21: res = 669; break;
		case 22: res = 688; break;
		case 23: res = 728; break;
		case 24: res = 730; break;
		case 25: res = 631; break;
		case 26: res = 687; break;
		case 27: res = 595; break;
		case 28: res = 724; break;
		case 29: res = 646; break;
		case 30: res = 543; break;
		case 31: res = 650; break;
		case 32: res = 607; break;
		case 33: res = 652; break;
		case 34: res = 653; break;
		case 35: res = 632; break;
		case 36: res = 652; break;
		case 37: res = 760; break;
		case 38: res = 719; break;
		case 39: res = 610; break;
		case 40: res = 511; break;
		case 41: res = 649; break;
		case 42: res = 738; break;
		case 43: res = 708; break;
		case 44: res = 644; break;
		case 45: res = 617; break;
		case 46: res = 645; break;
		case 47: res = 715; break;
		case 48: res = 707; break;
		case 49: res = 587; break;
		case 50: res = 518; break;
		case 51: res = 605; break;
		case 52: res = 703; break;
		case 53: res = 656; break;
		case 54: res = 741; break;
		case 55: res = 615; break;
		case 56: res = 608; break;
		case 57: res = 648; break;
		case 58: res = 616; break;
		case 59: res = 555; break;
		case 60: res = 613; break;
		case 61: res = 675; break;
		case 62: res = 782; break;
		case 63: res = 795; break;
		case 64: res = 724; break;
		case 65: res = 775; break;
		case 66: res = 628; break;
		case 67: res = 686; break;
		case 68: res = 622; break;
		case 69: res = 478; break;
		case 70: res = 549; break;
		case 71: res = 581; break;
		case 72: res = 669; break;
		case 73: res = 646; break;
		case 74: res = 619; break;
		case 75: res = 668; break;
		case 76: res = 709; break;
		case 77: res = 591; break;
		case 78: res = 638; break;
		case 79: res = 542; break;
		case 80: res = 601; break;
		case 81: res = 559; break;
		case 82: res = 653; break;
		case 83: res = 604; break;
		case 84: res = 687; break;
		case 85: res = 564; break;
		case 86: res = 643; break;
		case 87: res = 593; break;
		case 88: res = 612; break;
		case 89: res = 557; break;
		case 90: res = 451; break;
		case 91: res = 495; break;
		case 92: res = 584; break;
		case 93: res = 521; break;
		case 94: res = 508; break;
		case 95: res = 547; break;
		case 96: res = 554; break;
		case 97: res = 521; break;
		case 98: res = 522; break;
		case 99: res = 356; break;
		default: break;
	}
	return res;
}

#endif
