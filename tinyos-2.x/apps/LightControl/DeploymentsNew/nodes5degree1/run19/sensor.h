#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 423; break;
		case 1: res = 578; break;
		case 2: res = 522; break;
		case 3: res = 429; break;
		case 4: res = 359; break;
		case 5: res = 600; break;
		case 6: res = 794; break;
		case 7: res = 594; break;
		case 8: res = 619; break;
		case 9: res = 549; break;
		case 10: res = 547; break;
		case 11: res = 686; break;
		case 12: res = 643; break;
		case 13: res = 663; break;
		case 14: res = 605; break;
		case 15: res = 553; break;
		case 16: res = 667; break;
		case 17: res = 687; break;
		case 18: res = 644; break;
		case 19: res = 509; break;
		case 20: res = 467; break;
		case 21: res = 570; break;
		case 22: res = 500; break;
		case 23: res = 469; break;
		case 24: res = 434; break;
		default: break;
	}
	return res;
}

#endif
