#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 561; break;
		case 1: res = 606; break;
		case 2: res = 622; break;
		case 3: res = 647; break;
		case 4: res = 516; break;
		case 5: res = 694; break;
		case 6: res = 725; break;
		case 7: res = 792; break;
		case 8: res = 824; break;
		case 9: res = 633; break;
		case 10: res = 686; break;
		case 11: res = 671; break;
		case 12: res = 733; break;
		case 13: res = 841; break;
		case 14: res = 720; break;
		case 15: res = 681; break;
		case 16: res = 768; break;
		case 17: res = 773; break;
		case 18: res = 777; break;
		case 19: res = 714; break;
		case 20: res = 634; break;
		case 21: res = 702; break;
		case 22: res = 623; break;
		case 23: res = 701; break;
		case 24: res = 569; break;
		default: break;
	}
	return res;
}

#endif
