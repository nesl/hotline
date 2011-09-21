#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 397; break;
		case 1: res = 519; break;
		case 2: res = 492; break;
		case 3: res = 520; break;
		case 4: res = 501; break;
		case 5: res = 505; break;
		case 6: res = 538; break;
		case 7: res = 576; break;
		case 8: res = 548; break;
		case 9: res = 403; break;
		case 10: res = 495; break;
		case 11: res = 582; break;
		case 12: res = 679; break;
		case 13: res = 607; break;
		case 14: res = 693; break;
		case 15: res = 631; break;
		case 16: res = 598; break;
		case 17: res = 638; break;
		case 18: res = 601; break;
		case 19: res = 472; break;
		case 20: res = 512; break;
		case 21: res = 699; break;
		case 22: res = 787; break;
		case 23: res = 665; break;
		case 24: res = 690; break;
		case 25: res = 641; break;
		case 26: res = 719; break;
		case 27: res = 693; break;
		case 28: res = 683; break;
		case 29: res = 508; break;
		case 30: res = 577; break;
		case 31: res = 741; break;
		case 32: res = 580; break;
		case 33: res = 677; break;
		case 34: res = 602; break;
		case 35: res = 674; break;
		case 36: res = 715; break;
		case 37: res = 691; break;
		case 38: res = 673; break;
		case 39: res = 584; break;
		case 40: res = 490; break;
		case 41: res = 704; break;
		case 42: res = 750; break;
		case 43: res = 676; break;
		case 44: res = 638; break;
		case 45: res = 648; break;
		case 46: res = 687; break;
		case 47: res = 696; break;
		case 48: res = 708; break;
		case 49: res = 580; break;
		case 50: res = 387; break;
		case 51: res = 584; break;
		case 52: res = 675; break;
		case 53: res = 544; break;
		case 54: res = 667; break;
		case 55: res = 677; break;
		case 56: res = 682; break;
		case 57: res = 807; break;
		case 58: res = 700; break;
		case 59: res = 516; break;
		case 60: res = 500; break;
		case 61: res = 718; break;
		case 62: res = 736; break;
		case 63: res = 688; break;
		case 64: res = 651; break;
		case 65: res = 762; break;
		case 66: res = 721; break;
		case 67: res = 751; break;
		case 68: res = 609; break;
		case 69: res = 453; break;
		case 70: res = 545; break;
		case 71: res = 639; break;
		case 72: res = 616; break;
		case 73: res = 623; break;
		case 74: res = 619; break;
		case 75: res = 604; break;
		case 76: res = 672; break;
		case 77: res = 599; break;
		case 78: res = 681; break;
		case 79: res = 518; break;
		case 80: res = 588; break;
		case 81: res = 685; break;
		case 82: res = 712; break;
		case 83: res = 604; break;
		case 84: res = 746; break;
		case 85: res = 652; break;
		case 86: res = 645; break;
		case 87: res = 732; break;
		case 88: res = 707; break;
		case 89: res = 532; break;
		case 90: res = 392; break;
		case 91: res = 512; break;
		case 92: res = 579; break;
		case 93: res = 563; break;
		case 94: res = 645; break;
		case 95: res = 617; break;
		case 96: res = 523; break;
		case 97: res = 541; break;
		case 98: res = 551; break;
		case 99: res = 390; break;
		default: break;
	}
	return res;
}

#endif