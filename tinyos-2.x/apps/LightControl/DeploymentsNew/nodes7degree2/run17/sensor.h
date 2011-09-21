#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 537; break;
		case 1: res = 715; break;
		case 2: res = 694; break;
		case 3: res = 670; break;
		case 4: res = 589; break;
		case 5: res = 531; break;
		case 6: res = 559; break;
		case 7: res = 629; break;
		case 8: res = 744; break;
		case 9: res = 857; break;
		case 10: res = 916; break;
		case 11: res = 771; break;
		case 12: res = 865; break;
		case 13: res = 728; break;
		case 14: res = 605; break;
		case 15: res = 808; break;
		case 16: res = 914; break;
		case 17: res = 831; break;
		case 18: res = 810; break;
		case 19: res = 772; break;
		case 20: res = 730; break;
		case 21: res = 636; break;
		case 22: res = 811; break;
		case 23: res = 798; break;
		case 24: res = 871; break;
		case 25: res = 735; break;
		case 26: res = 768; break;
		case 27: res = 693; break;
		case 28: res = 601; break;
		case 29: res = 651; break;
		case 30: res = 776; break;
		case 31: res = 758; break;
		case 32: res = 835; break;
		case 33: res = 799; break;
		case 34: res = 725; break;
		case 35: res = 554; break;
		case 36: res = 696; break;
		case 37: res = 726; break;
		case 38: res = 678; break;
		case 39: res = 697; break;
		case 40: res = 804; break;
		case 41: res = 578; break;
		case 42: res = 520; break;
		case 43: res = 698; break;
		case 44: res = 650; break;
		case 45: res = 651; break;
		case 46: res = 600; break;
		case 47: res = 524; break;
		case 48: res = 533; break;
		default: break;
	}
	return res;
}

#endif
