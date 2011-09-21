#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 571; break;
		case 1: res = 710; break;
		case 2: res = 604; break;
		case 3: res = 733; break;
		case 4: res = 529; break;
		case 5: res = 738; break;
		case 6: res = 747; break;
		case 7: res = 856; break;
		case 8: res = 764; break;
		case 9: res = 700; break;
		case 10: res = 725; break;
		case 11: res = 740; break;
		case 12: res = 712; break;
		case 13: res = 897; break;
		case 14: res = 688; break;
		case 15: res = 659; break;
		case 16: res = 685; break;
		case 17: res = 701; break;
		case 18: res = 702; break;
		case 19: res = 642; break;
		case 20: res = 574; break;
		case 21: res = 564; break;
		case 22: res = 572; break;
		case 23: res = 695; break;
		case 24: res = 570; break;
		default: break;
	}
	return res;
}

#endif
