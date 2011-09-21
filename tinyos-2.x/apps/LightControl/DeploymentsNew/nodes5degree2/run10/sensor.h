#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 466; break;
		case 1: res = 586; break;
		case 2: res = 666; break;
		case 3: res = 807; break;
		case 4: res = 634; break;
		case 5: res = 592; break;
		case 6: res = 761; break;
		case 7: res = 838; break;
		case 8: res = 911; break;
		case 9: res = 737; break;
		case 10: res = 664; break;
		case 11: res = 796; break;
		case 12: res = 816; break;
		case 13: res = 947; break;
		case 14: res = 727; break;
		case 15: res = 638; break;
		case 16: res = 736; break;
		case 17: res = 787; break;
		case 18: res = 759; break;
		case 19: res = 688; break;
		case 20: res = 560; break;
		case 21: res = 657; break;
		case 22: res = 575; break;
		case 23: res = 710; break;
		case 24: res = 542; break;
		default: break;
	}
	return res;
}

#endif
