#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 466; break;
		case 1: res = 640; break;
		case 2: res = 627; break;
		case 3: res = 584; break;
		case 4: res = 580; break;
		case 5: res = 662; break;
		case 6: res = 600; break;
		case 7: res = 629; break;
		case 8: res = 755; break;
		case 9: res = 771; break;
		case 10: res = 785; break;
		case 11: res = 796; break;
		case 12: res = 881; break;
		case 13: res = 719; break;
		case 14: res = 609; break;
		case 15: res = 831; break;
		case 16: res = 819; break;
		case 17: res = 757; break;
		case 18: res = 810; break;
		case 19: res = 759; break;
		case 20: res = 606; break;
		case 21: res = 671; break;
		case 22: res = 784; break;
		case 23: res = 665; break;
		case 24: res = 834; break;
		case 25: res = 705; break;
		case 26: res = 724; break;
		case 27: res = 679; break;
		case 28: res = 672; break;
		case 29: res = 802; break;
		case 30: res = 827; break;
		case 31: res = 700; break;
		case 32: res = 802; break;
		case 33: res = 740; break;
		case 34: res = 776; break;
		case 35: res = 614; break;
		case 36: res = 806; break;
		case 37: res = 722; break;
		case 38: res = 725; break;
		case 39: res = 634; break;
		case 40: res = 837; break;
		case 41: res = 679; break;
		case 42: res = 509; break;
		case 43: res = 663; break;
		case 44: res = 590; break;
		case 45: res = 578; break;
		case 46: res = 617; break;
		case 47: res = 596; break;
		case 48: res = 625; break;
		default: break;
	}
	return res;
}

#endif
