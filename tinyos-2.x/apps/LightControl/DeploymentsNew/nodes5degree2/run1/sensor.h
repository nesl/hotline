#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 454; break;
		case 1: res = 597; break;
		case 2: res = 611; break;
		case 3: res = 697; break;
		case 4: res = 503; break;
		case 5: res = 642; break;
		case 6: res = 686; break;
		case 7: res = 770; break;
		case 8: res = 749; break;
		case 9: res = 618; break;
		case 10: res = 647; break;
		case 11: res = 691; break;
		case 12: res = 684; break;
		case 13: res = 804; break;
		case 14: res = 660; break;
		case 15: res = 612; break;
		case 16: res = 715; break;
		case 17: res = 695; break;
		case 18: res = 644; break;
		case 19: res = 644; break;
		case 20: res = 595; break;
		case 21: res = 690; break;
		case 22: res = 633; break;
		case 23: res = 673; break;
		case 24: res = 524; break;
		default: break;
	}
	return res;
}

#endif
