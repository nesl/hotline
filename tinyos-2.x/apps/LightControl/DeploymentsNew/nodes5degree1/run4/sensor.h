#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 389; break;
		case 1: res = 465; break;
		case 2: res = 545; break;
		case 3: res = 448; break;
		case 4: res = 313; break;
		case 5: res = 513; break;
		case 6: res = 740; break;
		case 7: res = 691; break;
		case 8: res = 570; break;
		case 9: res = 436; break;
		case 10: res = 531; break;
		case 11: res = 698; break;
		case 12: res = 685; break;
		case 13: res = 737; break;
		case 14: res = 509; break;
		case 15: res = 476; break;
		case 16: res = 665; break;
		case 17: res = 679; break;
		case 18: res = 630; break;
		case 19: res = 446; break;
		case 20: res = 391; break;
		case 21: res = 567; break;
		case 22: res = 596; break;
		case 23: res = 513; break;
		case 24: res = 445; break;
		default: break;
	}
	return res;
}

#endif
