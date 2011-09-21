#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 430; break;
		case 1: res = 556; break;
		case 2: res = 499; break;
		case 3: res = 552; break;
		case 4: res = 566; break;
		case 5: res = 576; break;
		case 6: res = 374; break;
		case 7: res = 558; break;
		case 8: res = 590; break;
		case 9: res = 603; break;
		case 10: res = 669; break;
		case 11: res = 615; break;
		case 12: res = 697; break;
		case 13: res = 568; break;
		case 14: res = 452; break;
		case 15: res = 613; break;
		case 16: res = 670; break;
		case 17: res = 680; break;
		case 18: res = 679; break;
		case 19: res = 588; break;
		case 20: res = 503; break;
		case 21: res = 495; break;
		case 22: res = 625; break;
		case 23: res = 599; break;
		case 24: res = 628; break;
		case 25: res = 622; break;
		case 26: res = 597; break;
		case 27: res = 586; break;
		case 28: res = 548; break;
		case 29: res = 752; break;
		case 30: res = 687; break;
		case 31: res = 722; break;
		case 32: res = 651; break;
		case 33: res = 649; break;
		case 34: res = 525; break;
		case 35: res = 589; break;
		case 36: res = 798; break;
		case 37: res = 739; break;
		case 38: res = 671; break;
		case 39: res = 739; break;
		case 40: res = 711; break;
		case 41: res = 654; break;
		case 42: res = 388; break;
		case 43: res = 612; break;
		case 44: res = 629; break;
		case 45: res = 593; break;
		case 46: res = 609; break;
		case 47: res = 540; break;
		case 48: res = 480; break;
		default: break;
	}
	return res;
}

#endif
