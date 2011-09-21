#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 390; break;
		case 1: res = 495; break;
		case 2: res = 514; break;
		case 3: res = 620; break;
		case 4: res = 584; break;
		case 5: res = 562; break;
		case 6: res = 536; break;
		case 7: res = 599; break;
		case 8: res = 632; break;
		case 9: res = 378; break;
		case 10: res = 491; break;
		case 11: res = 662; break;
		case 12: res = 582; break;
		case 13: res = 610; break;
		case 14: res = 672; break;
		case 15: res = 648; break;
		case 16: res = 576; break;
		case 17: res = 593; break;
		case 18: res = 659; break;
		case 19: res = 523; break;
		case 20: res = 607; break;
		case 21: res = 757; break;
		case 22: res = 684; break;
		case 23: res = 690; break;
		case 24: res = 682; break;
		case 25: res = 676; break;
		case 26: res = 750; break;
		case 27: res = 703; break;
		case 28: res = 676; break;
		case 29: res = 512; break;
		case 30: res = 656; break;
		case 31: res = 719; break;
		case 32: res = 646; break;
		case 33: res = 609; break;
		case 34: res = 579; break;
		case 35: res = 714; break;
		case 36: res = 733; break;
		case 37: res = 599; break;
		case 38: res = 639; break;
		case 39: res = 574; break;
		case 40: res = 550; break;
		case 41: res = 632; break;
		case 42: res = 656; break;
		case 43: res = 627; break;
		case 44: res = 599; break;
		case 45: res = 665; break;
		case 46: res = 728; break;
		case 47: res = 618; break;
		case 48: res = 680; break;
		case 49: res = 538; break;
		case 50: res = 477; break;
		case 51: res = 644; break;
		case 52: res = 683; break;
		case 53: res = 619; break;
		case 54: res = 666; break;
		case 55: res = 683; break;
		case 56: res = 605; break;
		case 57: res = 623; break;
		case 58: res = 710; break;
		case 59: res = 479; break;
		case 60: res = 524; break;
		case 61: res = 664; break;
		case 62: res = 661; break;
		case 63: res = 713; break;
		case 64: res = 678; break;
		case 65: res = 713; break;
		case 66: res = 631; break;
		case 67: res = 681; break;
		case 68: res = 652; break;
		case 69: res = 465; break;
		case 70: res = 590; break;
		case 71: res = 745; break;
		case 72: res = 630; break;
		case 73: res = 633; break;
		case 74: res = 600; break;
		case 75: res = 635; break;
		case 76: res = 673; break;
		case 77: res = 678; break;
		case 78: res = 671; break;
		case 79: res = 508; break;
		case 80: res = 620; break;
		case 81: res = 746; break;
		case 82: res = 633; break;
		case 83: res = 619; break;
		case 84: res = 739; break;
		case 85: res = 767; break;
		case 86: res = 730; break;
		case 87: res = 689; break;
		case 88: res = 716; break;
		case 89: res = 536; break;
		case 90: res = 443; break;
		case 91: res = 535; break;
		case 92: res = 514; break;
		case 93: res = 533; break;
		case 94: res = 564; break;
		case 95: res = 582; break;
		case 96: res = 580; break;
		case 97: res = 505; break;
		case 98: res = 537; break;
		case 99: res = 372; break;
		default: break;
	}
	return res;
}

#endif