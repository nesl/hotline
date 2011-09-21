#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 412; break;
		case 1: res = 510; break;
		case 2: res = 472; break;
		case 3: res = 636; break;
		case 4: res = 598; break;
		case 5: res = 576; break;
		case 6: res = 344; break;
		case 7: res = 531; break;
		case 8: res = 669; break;
		case 9: res = 655; break;
		case 10: res = 796; break;
		case 11: res = 700; break;
		case 12: res = 653; break;
		case 13: res = 496; break;
		case 14: res = 479; break;
		case 15: res = 725; break;
		case 16: res = 738; break;
		case 17: res = 760; break;
		case 18: res = 757; break;
		case 19: res = 625; break;
		case 20: res = 509; break;
		case 21: res = 595; break;
		case 22: res = 719; break;
		case 23: res = 693; break;
		case 24: res = 693; break;
		case 25: res = 718; break;
		case 26: res = 628; break;
		case 27: res = 608; break;
		case 28: res = 504; break;
		case 29: res = 691; break;
		case 30: res = 615; break;
		case 31: res = 626; break;
		case 32: res = 689; break;
		case 33: res = 619; break;
		case 34: res = 493; break;
		case 35: res = 566; break;
		case 36: res = 611; break;
		case 37: res = 603; break;
		case 38: res = 626; break;
		case 39: res = 691; break;
		case 40: res = 539; break;
		case 41: res = 489; break;
		case 42: res = 451; break;
		case 43: res = 541; break;
		case 44: res = 483; break;
		case 45: res = 443; break;
		case 46: res = 517; break;
		case 47: res = 484; break;
		case 48: res = 459; break;
		default: break;
	}
	return res;
}

#endif
