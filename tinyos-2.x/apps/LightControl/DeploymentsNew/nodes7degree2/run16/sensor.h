#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 534; break;
		case 1: res = 662; break;
		case 2: res = 692; break;
		case 3: res = 735; break;
		case 4: res = 725; break;
		case 5: res = 601; break;
		case 6: res = 568; break;
		case 7: res = 650; break;
		case 8: res = 780; break;
		case 9: res = 799; break;
		case 10: res = 877; break;
		case 11: res = 852; break;
		case 12: res = 889; break;
		case 13: res = 685; break;
		case 14: res = 689; break;
		case 15: res = 867; break;
		case 16: res = 836; break;
		case 17: res = 800; break;
		case 18: res = 867; break;
		case 19: res = 823; break;
		case 20: res = 725; break;
		case 21: res = 722; break;
		case 22: res = 896; break;
		case 23: res = 867; break;
		case 24: res = 852; break;
		case 25: res = 829; break;
		case 26: res = 886; break;
		case 27: res = 714; break;
		case 28: res = 719; break;
		case 29: res = 862; break;
		case 30: res = 910; break;
		case 31: res = 762; break;
		case 32: res = 805; break;
		case 33: res = 795; break;
		case 34: res = 691; break;
		case 35: res = 609; break;
		case 36: res = 894; break;
		case 37: res = 839; break;
		case 38: res = 711; break;
		case 39: res = 744; break;
		case 40: res = 804; break;
		case 41: res = 576; break;
		case 42: res = 539; break;
		case 43: res = 730; break;
		case 44: res = 708; break;
		case 45: res = 716; break;
		case 46: res = 683; break;
		case 47: res = 615; break;
		case 48: res = 534; break;
		default: break;
	}
	return res;
}

#endif
