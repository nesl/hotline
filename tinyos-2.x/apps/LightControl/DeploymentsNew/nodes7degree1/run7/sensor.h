#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 321; break;
		case 1: res = 481; break;
		case 2: res = 522; break;
		case 3: res = 590; break;
		case 4: res = 607; break;
		case 5: res = 624; break;
		case 6: res = 354; break;
		case 7: res = 551; break;
		case 8: res = 719; break;
		case 9: res = 660; break;
		case 10: res = 678; break;
		case 11: res = 646; break;
		case 12: res = 635; break;
		case 13: res = 408; break;
		case 14: res = 475; break;
		case 15: res = 622; break;
		case 16: res = 674; break;
		case 17: res = 564; break;
		case 18: res = 657; break;
		case 19: res = 690; break;
		case 20: res = 450; break;
		case 21: res = 607; break;
		case 22: res = 712; break;
		case 23: res = 676; break;
		case 24: res = 644; break;
		case 25: res = 660; break;
		case 26: res = 666; break;
		case 27: res = 521; break;
		case 28: res = 516; break;
		case 29: res = 737; break;
		case 30: res = 647; break;
		case 31: res = 671; break;
		case 32: res = 661; break;
		case 33: res = 729; break;
		case 34: res = 503; break;
		case 35: res = 531; break;
		case 36: res = 577; break;
		case 37: res = 620; break;
		case 38: res = 708; break;
		case 39: res = 743; break;
		case 40: res = 728; break;
		case 41: res = 544; break;
		case 42: res = 398; break;
		case 43: res = 499; break;
		case 44: res = 460; break;
		case 45: res = 552; break;
		case 46: res = 660; break;
		case 47: res = 594; break;
		case 48: res = 421; break;
		default: break;
	}
	return res;
}

#endif
