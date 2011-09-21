#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 569; break;
		case 1: res = 711; break;
		case 2: res = 696; break;
		case 3: res = 778; break;
		case 4: res = 573; break;
		case 5: res = 785; break;
		case 6: res = 813; break;
		case 7: res = 778; break;
		case 8: res = 716; break;
		case 9: res = 609; break;
		case 10: res = 772; break;
		case 11: res = 818; break;
		case 12: res = 787; break;
		case 13: res = 767; break;
		case 14: res = 668; break;
		case 15: res = 684; break;
		case 16: res = 794; break;
		case 17: res = 783; break;
		case 18: res = 822; break;
		case 19: res = 684; break;
		case 20: res = 543; break;
		case 21: res = 622; break;
		case 22: res = 679; break;
		case 23: res = 702; break;
		case 24: res = 593; break;
		default: break;
	}
	return res;
}

#endif
