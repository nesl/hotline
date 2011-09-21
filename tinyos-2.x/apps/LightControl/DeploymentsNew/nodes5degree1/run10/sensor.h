#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 445; break;
		case 1: res = 490; break;
		case 2: res = 479; break;
		case 3: res = 483; break;
		case 4: res = 287; break;
		case 5: res = 609; break;
		case 6: res = 696; break;
		case 7: res = 565; break;
		case 8: res = 581; break;
		case 9: res = 466; break;
		case 10: res = 564; break;
		case 11: res = 684; break;
		case 12: res = 729; break;
		case 13: res = 698; break;
		case 14: res = 615; break;
		case 15: res = 496; break;
		case 16: res = 664; break;
		case 17: res = 771; break;
		case 18: res = 749; break;
		case 19: res = 530; break;
		case 20: res = 328; break;
		case 21: res = 448; break;
		case 22: res = 540; break;
		case 23: res = 548; break;
		case 24: res = 450; break;
		default: break;
	}
	return res;
}

#endif
