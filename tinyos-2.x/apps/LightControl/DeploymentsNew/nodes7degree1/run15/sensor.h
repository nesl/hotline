#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 362; break;
		case 1: res = 505; break;
		case 2: res = 580; break;
		case 3: res = 608; break;
		case 4: res = 652; break;
		case 5: res = 595; break;
		case 6: res = 386; break;
		case 7: res = 586; break;
		case 8: res = 698; break;
		case 9: res = 738; break;
		case 10: res = 625; break;
		case 11: res = 645; break;
		case 12: res = 604; break;
		case 13: res = 457; break;
		case 14: res = 595; break;
		case 15: res = 754; break;
		case 16: res = 700; break;
		case 17: res = 636; break;
		case 18: res = 675; break;
		case 19: res = 572; break;
		case 20: res = 407; break;
		case 21: res = 581; break;
		case 22: res = 705; break;
		case 23: res = 689; break;
		case 24: res = 649; break;
		case 25: res = 675; break;
		case 26: res = 609; break;
		case 27: res = 552; break;
		case 28: res = 523; break;
		case 29: res = 688; break;
		case 30: res = 586; break;
		case 31: res = 623; break;
		case 32: res = 655; break;
		case 33: res = 609; break;
		case 34: res = 513; break;
		case 35: res = 531; break;
		case 36: res = 613; break;
		case 37: res = 618; break;
		case 38: res = 706; break;
		case 39: res = 687; break;
		case 40: res = 572; break;
		case 41: res = 527; break;
		case 42: res = 438; break;
		case 43: res = 644; break;
		case 44: res = 598; break;
		case 45: res = 526; break;
		case 46: res = 592; break;
		case 47: res = 582; break;
		case 48: res = 462; break;
		default: break;
	}
	return res;
}

#endif
