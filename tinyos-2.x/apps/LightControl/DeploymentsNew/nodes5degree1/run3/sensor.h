#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 433; break;
		case 1: res = 585; break;
		case 2: res = 543; break;
		case 3: res = 495; break;
		case 4: res = 306; break;
		case 5: res = 564; break;
		case 6: res = 644; break;
		case 7: res = 548; break;
		case 8: res = 620; break;
		case 9: res = 472; break;
		case 10: res = 468; break;
		case 11: res = 640; break;
		case 12: res = 639; break;
		case 13: res = 578; break;
		case 14: res = 552; break;
		case 15: res = 457; break;
		case 16: res = 564; break;
		case 17: res = 671; break;
		case 18: res = 672; break;
		case 19: res = 488; break;
		case 20: res = 376; break;
		case 21: res = 486; break;
		case 22: res = 574; break;
		case 23: res = 483; break;
		case 24: res = 414; break;
		default: break;
	}
	return res;
}

#endif
