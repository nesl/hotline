#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 619; break;
		case 1: res = 677; break;
		case 2: res = 655; break;
		case 3: res = 647; break;
		case 4: res = 618; break;
		case 5: res = 644; break;
		case 6: res = 564; break;
		case 7: res = 694; break;
		case 8: res = 800; break;
		case 9: res = 768; break;
		case 10: res = 902; break;
		case 11: res = 861; break;
		case 12: res = 774; break;
		case 13: res = 743; break;
		case 14: res = 723; break;
		case 15: res = 809; break;
		case 16: res = 883; break;
		case 17: res = 809; break;
		case 18: res = 832; break;
		case 19: res = 778; break;
		case 20: res = 567; break;
		case 21: res = 726; break;
		case 22: res = 899; break;
		case 23: res = 751; break;
		case 24: res = 893; break;
		case 25: res = 716; break;
		case 26: res = 707; break;
		case 27: res = 647; break;
		case 28: res = 775; break;
		case 29: res = 798; break;
		case 30: res = 860; break;
		case 31: res = 721; break;
		case 32: res = 845; break;
		case 33: res = 766; break;
		case 34: res = 707; break;
		case 35: res = 628; break;
		case 36: res = 814; break;
		case 37: res = 755; break;
		case 38: res = 713; break;
		case 39: res = 706; break;
		case 40: res = 860; break;
		case 41: res = 649; break;
		case 42: res = 492; break;
		case 43: res = 646; break;
		case 44: res = 573; break;
		case 45: res = 649; break;
		case 46: res = 599; break;
		case 47: res = 547; break;
		case 48: res = 525; break;
		default: break;
	}
	return res;
}

#endif
