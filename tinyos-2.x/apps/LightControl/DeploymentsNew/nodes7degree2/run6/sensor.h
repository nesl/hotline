#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 570; break;
		case 1: res = 664; break;
		case 2: res = 669; break;
		case 3: res = 674; break;
		case 4: res = 576; break;
		case 5: res = 509; break;
		case 6: res = 470; break;
		case 7: res = 613; break;
		case 8: res = 710; break;
		case 9: res = 756; break;
		case 10: res = 888; break;
		case 11: res = 811; break;
		case 12: res = 718; break;
		case 13: res = 576; break;
		case 14: res = 567; break;
		case 15: res = 729; break;
		case 16: res = 746; break;
		case 17: res = 856; break;
		case 18: res = 811; break;
		case 19: res = 693; break;
		case 20: res = 535; break;
		case 21: res = 678; break;
		case 22: res = 736; break;
		case 23: res = 740; break;
		case 24: res = 831; break;
		case 25: res = 844; break;
		case 26: res = 683; break;
		case 27: res = 579; break;
		case 28: res = 729; break;
		case 29: res = 808; break;
		case 30: res = 726; break;
		case 31: res = 821; break;
		case 32: res = 824; break;
		case 33: res = 716; break;
		case 34: res = 649; break;
		case 35: res = 701; break;
		case 36: res = 891; break;
		case 37: res = 837; break;
		case 38: res = 772; break;
		case 39: res = 818; break;
		case 40: res = 828; break;
		case 41: res = 619; break;
		case 42: res = 593; break;
		case 43: res = 762; break;
		case 44: res = 686; break;
		case 45: res = 716; break;
		case 46: res = 665; break;
		case 47: res = 559; break;
		case 48: res = 564; break;
		default: break;
	}
	return res;
}

#endif
