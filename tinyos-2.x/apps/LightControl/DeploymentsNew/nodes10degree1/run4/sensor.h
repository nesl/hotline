#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 442; break;
		case 1: res = 586; break;
		case 2: res = 547; break;
		case 3: res = 563; break;
		case 4: res = 553; break;
		case 5: res = 563; break;
		case 6: res = 589; break;
		case 7: res = 667; break;
		case 8: res = 547; break;
		case 9: res = 345; break;
		case 10: res = 610; break;
		case 11: res = 745; break;
		case 12: res = 661; break;
		case 13: res = 593; break;
		case 14: res = 744; break;
		case 15: res = 664; break;
		case 16: res = 666; break;
		case 17: res = 721; break;
		case 18: res = 662; break;
		case 19: res = 549; break;
		case 20: res = 619; break;
		case 21: res = 724; break;
		case 22: res = 728; break;
		case 23: res = 689; break;
		case 24: res = 638; break;
		case 25: res = 604; break;
		case 26: res = 711; break;
		case 27: res = 673; break;
		case 28: res = 675; break;
		case 29: res = 564; break;
		case 30: res = 617; break;
		case 31: res = 795; break;
		case 32: res = 566; break;
		case 33: res = 611; break;
		case 34: res = 612; break;
		case 35: res = 638; break;
		case 36: res = 709; break;
		case 37: res = 716; break;
		case 38: res = 683; break;
		case 39: res = 548; break;
		case 40: res = 572; break;
		case 41: res = 739; break;
		case 42: res = 625; break;
		case 43: res = 636; break;
		case 44: res = 654; break;
		case 45: res = 676; break;
		case 46: res = 643; break;
		case 47: res = 639; break;
		case 48: res = 630; break;
		case 49: res = 535; break;
		case 50: res = 508; break;
		case 51: res = 609; break;
		case 52: res = 638; break;
		case 53: res = 710; break;
		case 54: res = 705; break;
		case 55: res = 678; break;
		case 56: res = 590; break;
		case 57: res = 741; break;
		case 58: res = 646; break;
		case 59: res = 483; break;
		case 60: res = 555; break;
		case 61: res = 629; break;
		case 62: res = 641; break;
		case 63: res = 804; break;
		case 64: res = 680; break;
		case 65: res = 724; break;
		case 66: res = 573; break;
		case 67: res = 632; break;
		case 68: res = 691; break;
		case 69: res = 547; break;
		case 70: res = 527; break;
		case 71: res = 541; break;
		case 72: res = 602; break;
		case 73: res = 679; break;
		case 74: res = 551; break;
		case 75: res = 666; break;
		case 76: res = 668; break;
		case 77: res = 699; break;
		case 78: res = 705; break;
		case 79: res = 596; break;
		case 80: res = 574; break;
		case 81: res = 639; break;
		case 82: res = 721; break;
		case 83: res = 645; break;
		case 84: res = 768; break;
		case 85: res = 681; break;
		case 86: res = 591; break;
		case 87: res = 667; break;
		case 88: res = 595; break;
		case 89: res = 504; break;
		case 90: res = 508; break;
		case 91: res = 629; break;
		case 92: res = 607; break;
		case 93: res = 544; break;
		case 94: res = 647; break;
		case 95: res = 616; break;
		case 96: res = 595; break;
		case 97: res = 590; break;
		case 98: res = 573; break;
		case 99: res = 380; break;
		default: break;
	}
	return res;
}

#endif
