#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 401; break;
		case 1: res = 487; break;
		case 2: res = 569; break;
		case 3: res = 458; break;
		case 4: res = 354; break;
		case 5: res = 650; break;
		case 6: res = 810; break;
		case 7: res = 644; break;
		case 8: res = 581; break;
		case 9: res = 477; break;
		case 10: res = 523; break;
		case 11: res = 661; break;
		case 12: res = 708; break;
		case 13: res = 687; break;
		case 14: res = 574; break;
		case 15: res = 532; break;
		case 16: res = 560; break;
		case 17: res = 626; break;
		case 18: res = 688; break;
		case 19: res = 564; break;
		case 20: res = 391; break;
		case 21: res = 512; break;
		case 22: res = 595; break;
		case 23: res = 557; break;
		case 24: res = 440; break;
		default: break;
	}
	return res;
}

#endif
