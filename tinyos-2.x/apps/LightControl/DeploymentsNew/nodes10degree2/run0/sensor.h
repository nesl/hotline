#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 510; break;
		case 1: res = 639; break;
		case 2: res = 776; break;
		case 3: res = 730; break;
		case 4: res = 681; break;
		case 5: res = 601; break;
		case 6: res = 751; break;
		case 7: res = 776; break;
		case 8: res = 610; break;
		case 9: res = 601; break;
		case 10: res = 704; break;
		case 11: res = 820; break;
		case 12: res = 923; break;
		case 13: res = 886; break;
		case 14: res = 825; break;
		case 15: res = 722; break;
		case 16: res = 910; break;
		case 17: res = 841; break;
		case 18: res = 847; break;
		case 19: res = 667; break;
		case 20: res = 755; break;
		case 21: res = 823; break;
		case 22: res = 906; break;
		case 23: res = 885; break;
		case 24: res = 785; break;
		case 25: res = 724; break;
		case 26: res = 856; break;
		case 27: res = 747; break;
		case 28: res = 694; break;
		case 29: res = 620; break;
		case 30: res = 636; break;
		case 31: res = 725; break;
		case 32: res = 785; break;
		case 33: res = 852; break;
		case 34: res = 840; break;
		case 35: res = 774; break;
		case 36: res = 851; break;
		case 37: res = 745; break;
		case 38: res = 742; break;
		case 39: res = 657; break;
		case 40: res = 701; break;
		case 41: res = 760; break;
		case 42: res = 781; break;
		case 43: res = 796; break;
		case 44: res = 775; break;
		case 45: res = 762; break;
		case 46: res = 858; break;
		case 47: res = 835; break;
		case 48: res = 776; break;
		case 49: res = 649; break;
		case 50: res = 730; break;
		case 51: res = 720; break;
		case 52: res = 845; break;
		case 53: res = 884; break;
		case 54: res = 888; break;
		case 55: res = 868; break;
		case 56: res = 905; break;
		case 57: res = 815; break;
		case 58: res = 752; break;
		case 59: res = 656; break;
		case 60: res = 717; break;
		case 61: res = 770; break;
		case 62: res = 801; break;
		case 63: res = 797; break;
		case 64: res = 829; break;
		case 65: res = 910; break;
		case 66: res = 928; break;
		case 67: res = 895; break;
		case 68: res = 864; break;
		case 69: res = 629; break;
		case 70: res = 739; break;
		case 71: res = 835; break;
		case 72: res = 910; break;
		case 73: res = 893; break;
		case 74: res = 928; break;
		case 75: res = 908; break;
		case 76: res = 920; break;
		case 77: res = 850; break;
		case 78: res = 756; break;
		case 79: res = 646; break;
		case 80: res = 679; break;
		case 81: res = 831; break;
		case 82: res = 841; break;
		case 83: res = 810; break;
		case 84: res = 780; break;
		case 85: res = 794; break;
		case 86: res = 724; break;
		case 87: res = 826; break;
		case 88: res = 753; break;
		case 89: res = 636; break;
		case 90: res = 615; break;
		case 91: res = 650; break;
		case 92: res = 700; break;
		case 93: res = 685; break;
		case 94: res = 703; break;
		case 95: res = 640; break;
		case 96: res = 679; break;
		case 97: res = 760; break;
		case 98: res = 699; break;
		case 99: res = 590; break;
		default: break;
	}
	return res;
}

#endif
