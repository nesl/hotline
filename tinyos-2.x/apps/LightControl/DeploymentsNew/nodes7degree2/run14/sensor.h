#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 532; break;
		case 1: res = 700; break;
		case 2: res = 632; break;
		case 3: res = 612; break;
		case 4: res = 582; break;
		case 5: res = 565; break;
		case 6: res = 530; break;
		case 7: res = 621; break;
		case 8: res = 727; break;
		case 9: res = 692; break;
		case 10: res = 801; break;
		case 11: res = 750; break;
		case 12: res = 876; break;
		case 13: res = 648; break;
		case 14: res = 647; break;
		case 15: res = 778; break;
		case 16: res = 796; break;
		case 17: res = 758; break;
		case 18: res = 871; break;
		case 19: res = 817; break;
		case 20: res = 597; break;
		case 21: res = 697; break;
		case 22: res = 854; break;
		case 23: res = 725; break;
		case 24: res = 877; break;
		case 25: res = 772; break;
		case 26: res = 765; break;
		case 27: res = 643; break;
		case 28: res = 743; break;
		case 29: res = 827; break;
		case 30: res = 839; break;
		case 31: res = 783; break;
		case 32: res = 768; break;
		case 33: res = 788; break;
		case 34: res = 685; break;
		case 35: res = 607; break;
		case 36: res = 773; break;
		case 37: res = 771; break;
		case 38: res = 692; break;
		case 39: res = 722; break;
		case 40: res = 793; break;
		case 41: res = 657; break;
		case 42: res = 449; break;
		case 43: res = 610; break;
		case 44: res = 593; break;
		case 45: res = 708; break;
		case 46: res = 666; break;
		case 47: res = 638; break;
		case 48: res = 595; break;
		default: break;
	}
	return res;
}

#endif
