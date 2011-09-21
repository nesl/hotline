#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 490; break;
		case 1: res = 643; break;
		case 2: res = 594; break;
		case 3: res = 650; break;
		case 4: res = 436; break;
		case 5: res = 665; break;
		case 6: res = 709; break;
		case 7: res = 827; break;
		case 8: res = 666; break;
		case 9: res = 562; break;
		case 10: res = 687; break;
		case 11: res = 737; break;
		case 12: res = 788; break;
		case 13: res = 889; break;
		case 14: res = 686; break;
		case 15: res = 630; break;
		case 16: res = 796; break;
		case 17: res = 779; break;
		case 18: res = 801; break;
		case 19: res = 757; break;
		case 20: res = 624; break;
		case 21: res = 604; break;
		case 22: res = 604; break;
		case 23: res = 656; break;
		case 24: res = 572; break;
		default: break;
	}
	return res;
}

#endif
