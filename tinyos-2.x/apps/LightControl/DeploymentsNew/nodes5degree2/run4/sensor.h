#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 497; break;
		case 1: res = 654; break;
		case 2: res = 681; break;
		case 3: res = 675; break;
		case 4: res = 516; break;
		case 5: res = 706; break;
		case 6: res = 786; break;
		case 7: res = 859; break;
		case 8: res = 739; break;
		case 9: res = 601; break;
		case 10: res = 710; break;
		case 11: res = 814; break;
		case 12: res = 761; break;
		case 13: res = 741; break;
		case 14: res = 644; break;
		case 15: res = 714; break;
		case 16: res = 779; break;
		case 17: res = 782; break;
		case 18: res = 658; break;
		case 19: res = 640; break;
		case 20: res = 619; break;
		case 21: res = 726; break;
		case 22: res = 652; break;
		case 23: res = 649; break;
		case 24: res = 545; break;
		default: break;
	}
	return res;
}

#endif
