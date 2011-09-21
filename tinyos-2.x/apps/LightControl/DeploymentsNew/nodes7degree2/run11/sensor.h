#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 486; break;
		case 1: res = 623; break;
		case 2: res = 617; break;
		case 3: res = 668; break;
		case 4: res = 571; break;
		case 5: res = 546; break;
		case 6: res = 549; break;
		case 7: res = 603; break;
		case 8: res = 726; break;
		case 9: res = 797; break;
		case 10: res = 851; break;
		case 11: res = 788; break;
		case 12: res = 836; break;
		case 13: res = 706; break;
		case 14: res = 697; break;
		case 15: res = 851; break;
		case 16: res = 898; break;
		case 17: res = 861; break;
		case 18: res = 824; break;
		case 19: res = 844; break;
		case 20: res = 724; break;
		case 21: res = 740; break;
		case 22: res = 900; break;
		case 23: res = 807; break;
		case 24: res = 846; break;
		case 25: res = 737; break;
		case 26: res = 754; break;
		case 27: res = 768; break;
		case 28: res = 790; break;
		case 29: res = 852; break;
		case 30: res = 802; break;
		case 31: res = 754; break;
		case 32: res = 660; break;
		case 33: res = 785; break;
		case 34: res = 698; break;
		case 35: res = 724; break;
		case 36: res = 913; break;
		case 37: res = 855; break;
		case 38: res = 697; break;
		case 39: res = 705; break;
		case 40: res = 788; break;
		case 41: res = 649; break;
		case 42: res = 593; break;
		case 43: res = 780; break;
		case 44: res = 691; break;
		case 45: res = 712; break;
		case 46: res = 604; break;
		case 47: res = 573; break;
		case 48: res = 528; break;
		default: break;
	}
	return res;
}

#endif
