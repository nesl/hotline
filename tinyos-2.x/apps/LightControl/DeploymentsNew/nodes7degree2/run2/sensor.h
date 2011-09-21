#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 499; break;
		case 1: res = 748; break;
		case 2: res = 689; break;
		case 3: res = 691; break;
		case 4: res = 590; break;
		case 5: res = 602; break;
		case 6: res = 532; break;
		case 7: res = 651; break;
		case 8: res = 824; break;
		case 9: res = 840; break;
		case 10: res = 874; break;
		case 11: res = 860; break;
		case 12: res = 838; break;
		case 13: res = 659; break;
		case 14: res = 659; break;
		case 15: res = 831; break;
		case 16: res = 844; break;
		case 17: res = 785; break;
		case 18: res = 890; break;
		case 19: res = 865; break;
		case 20: res = 626; break;
		case 21: res = 693; break;
		case 22: res = 836; break;
		case 23: res = 729; break;
		case 24: res = 858; break;
		case 25: res = 865; break;
		case 26: res = 848; break;
		case 27: res = 708; break;
		case 28: res = 696; break;
		case 29: res = 744; break;
		case 30: res = 794; break;
		case 31: res = 814; break;
		case 32: res = 798; break;
		case 33: res = 823; break;
		case 34: res = 699; break;
		case 35: res = 608; break;
		case 36: res = 691; break;
		case 37: res = 838; break;
		case 38: res = 689; break;
		case 39: res = 797; break;
		case 40: res = 802; break;
		case 41: res = 618; break;
		case 42: res = 499; break;
		case 43: res = 697; break;
		case 44: res = 634; break;
		case 45: res = 749; break;
		case 46: res = 604; break;
		case 47: res = 565; break;
		case 48: res = 520; break;
		default: break;
	}
	return res;
}

#endif
