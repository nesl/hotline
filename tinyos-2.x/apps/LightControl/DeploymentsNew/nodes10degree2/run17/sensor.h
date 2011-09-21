#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 521; break;
		case 1: res = 622; break;
		case 2: res = 718; break;
		case 3: res = 726; break;
		case 4: res = 767; break;
		case 5: res = 686; break;
		case 6: res = 768; break;
		case 7: res = 711; break;
		case 8: res = 594; break;
		case 9: res = 594; break;
		case 10: res = 704; break;
		case 11: res = 763; break;
		case 12: res = 828; break;
		case 13: res = 825; break;
		case 14: res = 841; break;
		case 15: res = 840; break;
		case 16: res = 858; break;
		case 17: res = 867; break;
		case 18: res = 829; break;
		case 19: res = 689; break;
		case 20: res = 716; break;
		case 21: res = 803; break;
		case 22: res = 846; break;
		case 23: res = 915; break;
		case 24: res = 824; break;
		case 25: res = 827; break;
		case 26: res = 854; break;
		case 27: res = 730; break;
		case 28: res = 665; break;
		case 29: res = 609; break;
		case 30: res = 661; break;
		case 31: res = 821; break;
		case 32: res = 771; break;
		case 33: res = 809; break;
		case 34: res = 904; break;
		case 35: res = 842; break;
		case 36: res = 752; break;
		case 37: res = 687; break;
		case 38: res = 724; break;
		case 39: res = 576; break;
		case 40: res = 802; break;
		case 41: res = 819; break;
		case 42: res = 742; break;
		case 43: res = 794; break;
		case 44: res = 765; break;
		case 45: res = 828; break;
		case 46: res = 783; break;
		case 47: res = 825; break;
		case 48: res = 708; break;
		case 49: res = 673; break;
		case 50: res = 760; break;
		case 51: res = 785; break;
		case 52: res = 814; break;
		case 53: res = 764; break;
		case 54: res = 849; break;
		case 55: res = 841; break;
		case 56: res = 830; break;
		case 57: res = 744; break;
		case 58: res = 865; break;
		case 59: res = 614; break;
		case 60: res = 694; break;
		case 61: res = 847; break;
		case 62: res = 765; break;
		case 63: res = 768; break;
		case 64: res = 722; break;
		case 65: res = 894; break;
		case 66: res = 886; break;
		case 67: res = 931; break;
		case 68: res = 817; break;
		case 69: res = 716; break;
		case 70: res = 667; break;
		case 71: res = 745; break;
		case 72: res = 874; break;
		case 73: res = 697; break;
		case 74: res = 785; break;
		case 75: res = 913; break;
		case 76: res = 898; break;
		case 77: res = 827; break;
		case 78: res = 819; break;
		case 79: res = 698; break;
		case 80: res = 557; break;
		case 81: res = 872; break;
		case 82: res = 773; break;
		case 83: res = 737; break;
		case 84: res = 797; break;
		case 85: res = 824; break;
		case 86: res = 779; break;
		case 87: res = 791; break;
		case 88: res = 773; break;
		case 89: res = 719; break;
		case 90: res = 557; break;
		case 91: res = 615; break;
		case 92: res = 708; break;
		case 93: res = 670; break;
		case 94: res = 729; break;
		case 95: res = 695; break;
		case 96: res = 590; break;
		case 97: res = 684; break;
		case 98: res = 608; break;
		case 99: res = 626; break;
		default: break;
	}
	return res;
}

#endif