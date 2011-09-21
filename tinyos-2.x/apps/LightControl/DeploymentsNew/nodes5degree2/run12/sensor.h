#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 494; break;
		case 1: res = 675; break;
		case 2: res = 627; break;
		case 3: res = 712; break;
		case 4: res = 529; break;
		case 5: res = 623; break;
		case 6: res = 719; break;
		case 7: res = 795; break;
		case 8: res = 657; break;
		case 9: res = 591; break;
		case 10: res = 691; break;
		case 11: res = 802; break;
		case 12: res = 824; break;
		case 13: res = 805; break;
		case 14: res = 623; break;
		case 15: res = 657; break;
		case 16: res = 855; break;
		case 17: res = 866; break;
		case 18: res = 837; break;
		case 19: res = 691; break;
		case 20: res = 581; break;
		case 21: res = 638; break;
		case 22: res = 700; break;
		case 23: res = 779; break;
		case 24: res = 629; break;
		default: break;
	}
	return res;
}

#endif
