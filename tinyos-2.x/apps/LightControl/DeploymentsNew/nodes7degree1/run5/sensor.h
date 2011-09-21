#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 399; break;
		case 1: res = 492; break;
		case 2: res = 595; break;
		case 3: res = 576; break;
		case 4: res = 631; break;
		case 5: res = 571; break;
		case 6: res = 381; break;
		case 7: res = 580; break;
		case 8: res = 612; break;
		case 9: res = 698; break;
		case 10: res = 613; break;
		case 11: res = 700; break;
		case 12: res = 550; break;
		case 13: res = 477; break;
		case 14: res = 492; break;
		case 15: res = 670; break;
		case 16: res = 745; break;
		case 17: res = 681; break;
		case 18: res = 791; break;
		case 19: res = 625; break;
		case 20: res = 456; break;
		case 21: res = 610; break;
		case 22: res = 642; break;
		case 23: res = 688; break;
		case 24: res = 725; break;
		case 25: res = 661; break;
		case 26: res = 643; break;
		case 27: res = 536; break;
		case 28: res = 549; break;
		case 29: res = 714; break;
		case 30: res = 737; break;
		case 31: res = 741; break;
		case 32: res = 717; break;
		case 33: res = 685; break;
		case 34: res = 512; break;
		case 35: res = 504; break;
		case 36: res = 662; break;
		case 37: res = 707; break;
		case 38: res = 632; break;
		case 39: res = 777; break;
		case 40: res = 655; break;
		case 41: res = 534; break;
		case 42: res = 422; break;
		case 43: res = 597; break;
		case 44: res = 583; break;
		case 45: res = 487; break;
		case 46: res = 558; break;
		case 47: res = 556; break;
		case 48: res = 439; break;
		default: break;
	}
	return res;
}

#endif
