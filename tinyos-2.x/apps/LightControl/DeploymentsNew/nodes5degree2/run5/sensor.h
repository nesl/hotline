#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 497; break;
		case 1: res = 656; break;
		case 2: res = 658; break;
		case 3: res = 695; break;
		case 4: res = 531; break;
		case 5: res = 653; break;
		case 6: res = 696; break;
		case 7: res = 783; break;
		case 8: res = 686; break;
		case 9: res = 649; break;
		case 10: res = 669; break;
		case 11: res = 758; break;
		case 12: res = 725; break;
		case 13: res = 790; break;
		case 14: res = 721; break;
		case 15: res = 638; break;
		case 16: res = 719; break;
		case 17: res = 788; break;
		case 18: res = 761; break;
		case 19: res = 741; break;
		case 20: res = 518; break;
		case 21: res = 589; break;
		case 22: res = 644; break;
		case 23: res = 702; break;
		case 24: res = 639; break;
		default: break;
	}
	return res;
}

#endif
