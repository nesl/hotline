#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 491; break;
		case 1: res = 590; break;
		case 2: res = 599; break;
		case 3: res = 690; break;
		case 4: res = 557; break;
		case 5: res = 676; break;
		case 6: res = 782; break;
		case 7: res = 813; break;
		case 8: res = 749; break;
		case 9: res = 669; break;
		case 10: res = 630; break;
		case 11: res = 752; break;
		case 12: res = 830; break;
		case 13: res = 886; break;
		case 14: res = 728; break;
		case 15: res = 594; break;
		case 16: res = 764; break;
		case 17: res = 805; break;
		case 18: res = 852; break;
		case 19: res = 781; break;
		case 20: res = 571; break;
		case 21: res = 641; break;
		case 22: res = 668; break;
		case 23: res = 712; break;
		case 24: res = 626; break;
		default: break;
	}
	return res;
}

#endif
