#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 443; break;
		case 1: res = 479; break;
		case 2: res = 535; break;
		case 3: res = 498; break;
		case 4: res = 399; break;
		case 5: res = 593; break;
		case 6: res = 699; break;
		case 7: res = 588; break;
		case 8: res = 660; break;
		case 9: res = 518; break;
		case 10: res = 485; break;
		case 11: res = 662; break;
		case 12: res = 682; break;
		case 13: res = 753; break;
		case 14: res = 572; break;
		case 15: res = 483; break;
		case 16: res = 579; break;
		case 17: res = 764; break;
		case 18: res = 677; break;
		case 19: res = 454; break;
		case 20: res = 430; break;
		case 21: res = 540; break;
		case 22: res = 587; break;
		case 23: res = 500; break;
		case 24: res = 420; break;
		default: break;
	}
	return res;
}

#endif
