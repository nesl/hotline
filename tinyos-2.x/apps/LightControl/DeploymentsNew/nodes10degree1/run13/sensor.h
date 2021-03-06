#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 398; break;
		case 1: res = 461; break;
		case 2: res = 488; break;
		case 3: res = 540; break;
		case 4: res = 541; break;
		case 5: res = 528; break;
		case 6: res = 462; break;
		case 7: res = 535; break;
		case 8: res = 516; break;
		case 9: res = 366; break;
		case 10: res = 554; break;
		case 11: res = 611; break;
		case 12: res = 615; break;
		case 13: res = 698; break;
		case 14: res = 737; break;
		case 15: res = 605; break;
		case 16: res = 760; break;
		case 17: res = 767; break;
		case 18: res = 679; break;
		case 19: res = 506; break;
		case 20: res = 546; break;
		case 21: res = 691; break;
		case 22: res = 699; break;
		case 23: res = 636; break;
		case 24: res = 783; break;
		case 25: res = 686; break;
		case 26: res = 738; break;
		case 27: res = 766; break;
		case 28: res = 732; break;
		case 29: res = 538; break;
		case 30: res = 506; break;
		case 31: res = 787; break;
		case 32: res = 711; break;
		case 33: res = 657; break;
		case 34: res = 677; break;
		case 35: res = 706; break;
		case 36: res = 652; break;
		case 37: res = 627; break;
		case 38: res = 622; break;
		case 39: res = 533; break;
		case 40: res = 501; break;
		case 41: res = 792; break;
		case 42: res = 683; break;
		case 43: res = 657; break;
		case 44: res = 700; break;
		case 45: res = 582; break;
		case 46: res = 630; break;
		case 47: res = 639; break;
		case 48: res = 712; break;
		case 49: res = 528; break;
		case 50: res = 428; break;
		case 51: res = 641; break;
		case 52: res = 669; break;
		case 53: res = 703; break;
		case 54: res = 752; break;
		case 55: res = 642; break;
		case 56: res = 604; break;
		case 57: res = 691; break;
		case 58: res = 594; break;
		case 59: res = 538; break;
		case 60: res = 506; break;
		case 61: res = 633; break;
		case 62: res = 620; break;
		case 63: res = 705; break;
		case 64: res = 622; break;
		case 65: res = 674; break;
		case 66: res = 538; break;
		case 67: res = 663; break;
		case 68: res = 601; break;
		case 69: res = 444; break;
		case 70: res = 578; break;
		case 71: res = 592; break;
		case 72: res = 528; break;
		case 73: res = 615; break;
		case 74: res = 593; break;
		case 75: res = 590; break;
		case 76: res = 616; break;
		case 77: res = 536; break;
		case 78: res = 638; break;
		case 79: res = 415; break;
		case 80: res = 583; break;
		case 81: res = 640; break;
		case 82: res = 673; break;
		case 83: res = 588; break;
		case 84: res = 760; break;
		case 85: res = 694; break;
		case 86: res = 709; break;
		case 87: res = 728; break;
		case 88: res = 686; break;
		case 89: res = 510; break;
		case 90: res = 454; break;
		case 91: res = 595; break;
		case 92: res = 642; break;
		case 93: res = 490; break;
		case 94: res = 563; break;
		case 95: res = 589; break;
		case 96: res = 554; break;
		case 97: res = 544; break;
		case 98: res = 530; break;
		case 99: res = 403; break;
		default: break;
	}
	return res;
}

#endif
