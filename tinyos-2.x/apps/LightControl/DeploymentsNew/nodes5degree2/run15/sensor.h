#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 525; break;
		case 1: res = 635; break;
		case 2: res = 703; break;
		case 3: res = 717; break;
		case 4: res = 535; break;
		case 5: res = 658; break;
		case 6: res = 840; break;
		case 7: res = 782; break;
		case 8: res = 688; break;
		case 9: res = 563; break;
		case 10: res = 719; break;
		case 11: res = 862; break;
		case 12: res = 756; break;
		case 13: res = 757; break;
		case 14: res = 599; break;
		case 15: res = 665; break;
		case 16: res = 781; break;
		case 17: res = 704; break;
		case 18: res = 623; break;
		case 19: res = 689; break;
		case 20: res = 581; break;
		case 21: res = 668; break;
		case 22: res = 542; break;
		case 23: res = 635; break;
		case 24: res = 593; break;
		default: break;
	}
	return res;
}

#endif
