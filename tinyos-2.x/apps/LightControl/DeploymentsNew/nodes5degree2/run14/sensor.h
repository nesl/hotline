#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 578; break;
		case 1: res = 679; break;
		case 2: res = 679; break;
		case 3: res = 641; break;
		case 4: res = 511; break;
		case 5: res = 687; break;
		case 6: res = 834; break;
		case 7: res = 804; break;
		case 8: res = 853; break;
		case 9: res = 702; break;
		case 10: res = 655; break;
		case 11: res = 672; break;
		case 12: res = 787; break;
		case 13: res = 891; break;
		case 14: res = 751; break;
		case 15: res = 567; break;
		case 16: res = 733; break;
		case 17: res = 731; break;
		case 18: res = 759; break;
		case 19: res = 700; break;
		case 20: res = 537; break;
		case 21: res = 605; break;
		case 22: res = 625; break;
		case 23: res = 677; break;
		case 24: res = 512; break;
		default: break;
	}
	return res;
}

#endif
