#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 407; break;
		case 1: res = 600; break;
		case 2: res = 595; break;
		case 3: res = 474; break;
		case 4: res = 378; break;
		case 5: res = 523; break;
		case 6: res = 776; break;
		case 7: res = 581; break;
		case 8: res = 616; break;
		case 9: res = 543; break;
		case 10: res = 586; break;
		case 11: res = 693; break;
		case 12: res = 650; break;
		case 13: res = 630; break;
		case 14: res = 488; break;
		case 15: res = 496; break;
		case 16: res = 664; break;
		case 17: res = 729; break;
		case 18: res = 727; break;
		case 19: res = 514; break;
		case 20: res = 319; break;
		case 21: res = 537; break;
		case 22: res = 592; break;
		case 23: res = 524; break;
		case 24: res = 384; break;
		default: break;
	}
	return res;
}

#endif
