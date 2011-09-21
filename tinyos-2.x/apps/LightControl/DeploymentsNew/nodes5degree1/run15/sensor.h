#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 333; break;
		case 1: res = 510; break;
		case 2: res = 652; break;
		case 3: res = 582; break;
		case 4: res = 403; break;
		case 5: res = 536; break;
		case 6: res = 677; break;
		case 7: res = 659; break;
		case 8: res = 689; break;
		case 9: res = 520; break;
		case 10: res = 553; break;
		case 11: res = 725; break;
		case 12: res = 699; break;
		case 13: res = 719; break;
		case 14: res = 503; break;
		case 15: res = 491; break;
		case 16: res = 653; break;
		case 17: res = 636; break;
		case 18: res = 760; break;
		case 19: res = 545; break;
		case 20: res = 389; break;
		case 21: res = 481; break;
		case 22: res = 490; break;
		case 23: res = 486; break;
		case 24: res = 427; break;
		default: break;
	}
	return res;
}

#endif
