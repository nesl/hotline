#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 362; break;
		case 1: res = 530; break;
		case 2: res = 519; break;
		case 3: res = 443; break;
		case 4: res = 370; break;
		case 5: res = 524; break;
		case 6: res = 680; break;
		case 7: res = 540; break;
		case 8: res = 644; break;
		case 9: res = 596; break;
		case 10: res = 445; break;
		case 11: res = 595; break;
		case 12: res = 727; break;
		case 13: res = 709; break;
		case 14: res = 576; break;
		case 15: res = 489; break;
		case 16: res = 603; break;
		case 17: res = 757; break;
		case 18: res = 649; break;
		case 19: res = 418; break;
		case 20: res = 417; break;
		case 21: res = 486; break;
		case 22: res = 563; break;
		case 23: res = 508; break;
		case 24: res = 379; break;
		default: break;
	}
	return res;
}

#endif
