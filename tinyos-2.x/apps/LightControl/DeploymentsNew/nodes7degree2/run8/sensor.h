#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 613; break;
		case 1: res = 713; break;
		case 2: res = 633; break;
		case 3: res = 679; break;
		case 4: res = 700; break;
		case 5: res = 637; break;
		case 6: res = 583; break;
		case 7: res = 782; break;
		case 8: res = 815; break;
		case 9: res = 706; break;
		case 10: res = 796; break;
		case 11: res = 802; break;
		case 12: res = 787; break;
		case 13: res = 715; break;
		case 14: res = 748; break;
		case 15: res = 851; break;
		case 16: res = 763; break;
		case 17: res = 674; break;
		case 18: res = 804; break;
		case 19: res = 706; break;
		case 20: res = 661; break;
		case 21: res = 739; break;
		case 22: res = 854; break;
		case 23: res = 649; break;
		case 24: res = 836; break;
		case 25: res = 718; break;
		case 26: res = 799; break;
		case 27: res = 727; break;
		case 28: res = 787; break;
		case 29: res = 810; break;
		case 30: res = 870; break;
		case 31: res = 697; break;
		case 32: res = 901; break;
		case 33: res = 845; break;
		case 34: res = 775; break;
		case 35: res = 629; break;
		case 36: res = 879; break;
		case 37: res = 782; break;
		case 38: res = 803; break;
		case 39: res = 784; break;
		case 40: res = 941; break;
		case 41: res = 678; break;
		case 42: res = 497; break;
		case 43: res = 671; break;
		case 44: res = 699; break;
		case 45: res = 715; break;
		case 46: res = 726; break;
		case 47: res = 680; break;
		case 48: res = 568; break;
		default: break;
	}
	return res;
}

#endif
