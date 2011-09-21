#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 501; break;
		case 1: res = 597; break;
		case 2: res = 636; break;
		case 3: res = 769; break;
		case 4: res = 595; break;
		case 5: res = 643; break;
		case 6: res = 759; break;
		case 7: res = 795; break;
		case 8: res = 788; break;
		case 9: res = 723; break;
		case 10: res = 730; break;
		case 11: res = 744; break;
		case 12: res = 779; break;
		case 13: res = 863; break;
		case 14: res = 653; break;
		case 15: res = 641; break;
		case 16: res = 818; break;
		case 17: res = 791; break;
		case 18: res = 765; break;
		case 19: res = 687; break;
		case 20: res = 563; break;
		case 21: res = 610; break;
		case 22: res = 647; break;
		case 23: res = 740; break;
		case 24: res = 562; break;
		default: break;
	}
	return res;
}

#endif
