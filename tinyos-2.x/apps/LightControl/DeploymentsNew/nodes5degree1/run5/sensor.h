#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 363; break;
		case 1: res = 518; break;
		case 2: res = 638; break;
		case 3: res = 580; break;
		case 4: res = 397; break;
		case 5: res = 530; break;
		case 6: res = 733; break;
		case 7: res = 662; break;
		case 8: res = 747; break;
		case 9: res = 585; break;
		case 10: res = 532; break;
		case 11: res = 654; break;
		case 12: res = 632; break;
		case 13: res = 648; break;
		case 14: res = 588; break;
		case 15: res = 578; break;
		case 16: res = 664; break;
		case 17: res = 717; break;
		case 18: res = 675; break;
		case 19: res = 509; break;
		case 20: res = 380; break;
		case 21: res = 500; break;
		case 22: res = 555; break;
		case 23: res = 494; break;
		case 24: res = 410; break;
		default: break;
	}
	return res;
}

#endif
