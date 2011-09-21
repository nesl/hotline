#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 427; break;
		case 1: res = 601; break;
		case 2: res = 693; break;
		case 3: res = 811; break;
		case 4: res = 661; break;
		case 5: res = 626; break;
		case 6: res = 773; break;
		case 7: res = 881; break;
		case 8: res = 870; break;
		case 9: res = 749; break;
		case 10: res = 640; break;
		case 11: res = 786; break;
		case 12: res = 729; break;
		case 13: res = 834; break;
		case 14: res = 645; break;
		case 15: res = 603; break;
		case 16: res = 669; break;
		case 17: res = 752; break;
		case 18: res = 724; break;
		case 19: res = 691; break;
		case 20: res = 487; break;
		case 21: res = 578; break;
		case 22: res = 599; break;
		case 23: res = 771; break;
		case 24: res = 600; break;
		default: break;
	}
	return res;
}

#endif
