#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 553; break;
		case 1: res = 738; break;
		case 2: res = 654; break;
		case 3: res = 681; break;
		case 4: res = 657; break;
		case 5: res = 713; break;
		case 6: res = 593; break;
		case 7: res = 639; break;
		case 8: res = 727; break;
		case 9: res = 782; break;
		case 10: res = 777; break;
		case 11: res = 855; break;
		case 12: res = 886; break;
		case 13: res = 730; break;
		case 14: res = 611; break;
		case 15: res = 832; break;
		case 16: res = 806; break;
		case 17: res = 819; break;
		case 18: res = 807; break;
		case 19: res = 892; break;
		case 20: res = 605; break;
		case 21: res = 700; break;
		case 22: res = 845; break;
		case 23: res = 847; break;
		case 24: res = 818; break;
		case 25: res = 780; break;
		case 26: res = 755; break;
		case 27: res = 677; break;
		case 28: res = 668; break;
		case 29: res = 749; break;
		case 30: res = 819; break;
		case 31: res = 788; break;
		case 32: res = 772; break;
		case 33: res = 804; break;
		case 34: res = 662; break;
		case 35: res = 570; break;
		case 36: res = 751; break;
		case 37: res = 764; break;
		case 38: res = 811; break;
		case 39: res = 761; break;
		case 40: res = 808; break;
		case 41: res = 626; break;
		case 42: res = 537; break;
		case 43: res = 670; break;
		case 44: res = 676; break;
		case 45: res = 712; break;
		case 46: res = 690; break;
		case 47: res = 568; break;
		case 48: res = 533; break;
		default: break;
	}
	return res;
}

#endif
