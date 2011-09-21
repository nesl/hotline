#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 550; break;
		case 1: res = 667; break;
		case 2: res = 593; break;
		case 3: res = 651; break;
		case 4: res = 508; break;
		case 5: res = 790; break;
		case 6: res = 769; break;
		case 7: res = 767; break;
		case 8: res = 688; break;
		case 9: res = 662; break;
		case 10: res = 796; break;
		case 11: res = 755; break;
		case 12: res = 713; break;
		case 13: res = 812; break;
		case 14: res = 719; break;
		case 15: res = 701; break;
		case 16: res = 764; break;
		case 17: res = 780; break;
		case 18: res = 837; break;
		case 19: res = 772; break;
		case 20: res = 612; break;
		case 21: res = 646; break;
		case 22: res = 698; break;
		case 23: res = 791; break;
		case 24: res = 614; break;
		default: break;
	}
	return res;
}

#endif
