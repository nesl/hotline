#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 360; break;
		case 1: res = 509; break;
		case 2: res = 558; break;
		case 3: res = 563; break;
		case 4: res = 579; break;
		case 5: res = 579; break;
		case 6: res = 371; break;
		case 7: res = 557; break;
		case 8: res = 681; break;
		case 9: res = 670; break;
		case 10: res = 621; break;
		case 11: res = 666; break;
		case 12: res = 727; break;
		case 13: res = 538; break;
		case 14: res = 459; break;
		case 15: res = 648; break;
		case 16: res = 747; break;
		case 17: res = 575; break;
		case 18: res = 656; break;
		case 19: res = 584; break;
		case 20: res = 402; break;
		case 21: res = 525; break;
		case 22: res = 596; break;
		case 23: res = 716; break;
		case 24: res = 701; break;
		case 25: res = 662; break;
		case 26: res = 562; break;
		case 27: res = 580; break;
		case 28: res = 508; break;
		case 29: res = 737; break;
		case 30: res = 748; break;
		case 31: res = 663; break;
		case 32: res = 731; break;
		case 33: res = 676; break;
		case 34: res = 510; break;
		case 35: res = 576; break;
		case 36: res = 686; break;
		case 37: res = 775; break;
		case 38: res = 660; break;
		case 39: res = 692; break;
		case 40: res = 579; break;
		case 41: res = 462; break;
		case 42: res = 412; break;
		case 43: res = 578; break;
		case 44: res = 556; break;
		case 45: res = 510; break;
		case 46: res = 603; break;
		case 47: res = 510; break;
		case 48: res = 412; break;
		default: break;
	}
	return res;
}

#endif
