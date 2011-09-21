#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 576; break;
		case 1: res = 691; break;
		case 2: res = 554; break;
		case 3: res = 599; break;
		case 4: res = 588; break;
		case 5: res = 534; break;
		case 6: res = 470; break;
		case 7: res = 782; break;
		case 8: res = 839; break;
		case 9: res = 719; break;
		case 10: res = 799; break;
		case 11: res = 808; break;
		case 12: res = 752; break;
		case 13: res = 595; break;
		case 14: res = 708; break;
		case 15: res = 925; break;
		case 16: res = 836; break;
		case 17: res = 795; break;
		case 18: res = 809; break;
		case 19: res = 800; break;
		case 20: res = 564; break;
		case 21: res = 697; break;
		case 22: res = 942; break;
		case 23: res = 887; break;
		case 24: res = 950; break;
		case 25: res = 827; break;
		case 26: res = 793; break;
		case 27: res = 684; break;
		case 28: res = 682; break;
		case 29: res = 848; break;
		case 30: res = 972; break;
		case 31: res = 847; break;
		case 32: res = 822; break;
		case 33: res = 839; break;
		case 34: res = 721; break;
		case 35: res = 601; break;
		case 36: res = 794; break;
		case 37: res = 765; break;
		case 38: res = 686; break;
		case 39: res = 633; break;
		case 40: res = 804; break;
		case 41: res = 674; break;
		case 42: res = 575; break;
		case 43: res = 709; break;
		case 44: res = 656; break;
		case 45: res = 666; break;
		case 46: res = 577; break;
		case 47: res = 587; break;
		case 48: res = 610; break;
		default: break;
	}
	return res;
}

#endif
