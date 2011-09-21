#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 478; break;
		case 1: res = 605; break;
		case 2: res = 675; break;
		case 3: res = 772; break;
		case 4: res = 577; break;
		case 5: res = 677; break;
		case 6: res = 719; break;
		case 7: res = 795; break;
		case 8: res = 742; break;
		case 9: res = 609; break;
		case 10: res = 738; break;
		case 11: res = 792; break;
		case 12: res = 732; break;
		case 13: res = 768; break;
		case 14: res = 657; break;
		case 15: res = 794; break;
		case 16: res = 806; break;
		case 17: res = 791; break;
		case 18: res = 791; break;
		case 19: res = 733; break;
		case 20: res = 649; break;
		case 21: res = 739; break;
		case 22: res = 675; break;
		case 23: res = 784; break;
		case 24: res = 695; break;
		default: break;
	}
	return res;
}

#endif
