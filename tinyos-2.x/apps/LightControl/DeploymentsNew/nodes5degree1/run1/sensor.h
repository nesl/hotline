#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 402; break;
		case 1: res = 491; break;
		case 2: res = 493; break;
		case 3: res = 534; break;
		case 4: res = 415; break;
		case 5: res = 538; break;
		case 6: res = 686; break;
		case 7: res = 620; break;
		case 8: res = 675; break;
		case 9: res = 564; break;
		case 10: res = 515; break;
		case 11: res = 622; break;
		case 12: res = 735; break;
		case 13: res = 743; break;
		case 14: res = 564; break;
		case 15: res = 531; break;
		case 16: res = 605; break;
		case 17: res = 696; break;
		case 18: res = 719; break;
		case 19: res = 433; break;
		case 20: res = 419; break;
		case 21: res = 544; break;
		case 22: res = 534; break;
		case 23: res = 508; break;
		case 24: res = 399; break;
		default: break;
	}
	return res;
}

#endif
