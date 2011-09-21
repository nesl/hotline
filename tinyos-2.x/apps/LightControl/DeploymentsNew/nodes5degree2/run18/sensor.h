#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 507; break;
		case 1: res = 547; break;
		case 2: res = 545; break;
		case 3: res = 614; break;
		case 4: res = 487; break;
		case 5: res = 668; break;
		case 6: res = 733; break;
		case 7: res = 672; break;
		case 8: res = 667; break;
		case 9: res = 571; break;
		case 10: res = 783; break;
		case 11: res = 694; break;
		case 12: res = 687; break;
		case 13: res = 726; break;
		case 14: res = 628; break;
		case 15: res = 703; break;
		case 16: res = 814; break;
		case 17: res = 737; break;
		case 18: res = 830; break;
		case 19: res = 684; break;
		case 20: res = 657; break;
		case 21: res = 660; break;
		case 22: res = 693; break;
		case 23: res = 734; break;
		case 24: res = 609; break;
		default: break;
	}
	return res;
}

#endif
