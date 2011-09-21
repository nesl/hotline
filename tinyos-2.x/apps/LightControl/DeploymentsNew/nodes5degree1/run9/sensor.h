#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 355; break;
		case 1: res = 508; break;
		case 2: res = 642; break;
		case 3: res = 544; break;
		case 4: res = 332; break;
		case 5: res = 482; break;
		case 6: res = 647; break;
		case 7: res = 601; break;
		case 8: res = 675; break;
		case 9: res = 515; break;
		case 10: res = 531; break;
		case 11: res = 617; break;
		case 12: res = 608; break;
		case 13: res = 698; break;
		case 14: res = 569; break;
		case 15: res = 547; break;
		case 16: res = 567; break;
		case 17: res = 641; break;
		case 18: res = 603; break;
		case 19: res = 460; break;
		case 20: res = 431; break;
		case 21: res = 501; break;
		case 22: res = 556; break;
		case 23: res = 471; break;
		case 24: res = 405; break;
		default: break;
	}
	return res;
}

#endif
