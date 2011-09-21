#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 415; break;
		case 1: res = 581; break;
		case 2: res = 562; break;
		case 3: res = 718; break;
		case 4: res = 485; break;
		case 5: res = 653; break;
		case 6: res = 669; break;
		case 7: res = 794; break;
		case 8: res = 711; break;
		case 9: res = 647; break;
		case 10: res = 735; break;
		case 11: res = 770; break;
		case 12: res = 699; break;
		case 13: res = 801; break;
		case 14: res = 662; break;
		case 15: res = 711; break;
		case 16: res = 835; break;
		case 17: res = 744; break;
		case 18: res = 757; break;
		case 19: res = 716; break;
		case 20: res = 646; break;
		case 21: res = 663; break;
		case 22: res = 665; break;
		case 23: res = 665; break;
		case 24: res = 588; break;
		default: break;
	}
	return res;
}

#endif
