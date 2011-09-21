#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 607; break;
		case 1: res = 685; break;
		case 2: res = 635; break;
		case 3: res = 736; break;
		case 4: res = 700; break;
		case 5: res = 608; break;
		case 6: res = 576; break;
		case 7: res = 717; break;
		case 8: res = 823; break;
		case 9: res = 784; break;
		case 10: res = 920; break;
		case 11: res = 861; break;
		case 12: res = 844; break;
		case 13: res = 663; break;
		case 14: res = 767; break;
		case 15: res = 831; break;
		case 16: res = 868; break;
		case 17: res = 822; break;
		case 18: res = 845; break;
		case 19: res = 739; break;
		case 20: res = 650; break;
		case 21: res = 713; break;
		case 22: res = 857; break;
		case 23: res = 729; break;
		case 24: res = 939; break;
		case 25: res = 814; break;
		case 26: res = 836; break;
		case 27: res = 695; break;
		case 28: res = 754; break;
		case 29: res = 758; break;
		case 30: res = 829; break;
		case 31: res = 785; break;
		case 32: res = 812; break;
		case 33: res = 767; break;
		case 34: res = 603; break;
		case 35: res = 673; break;
		case 36: res = 816; break;
		case 37: res = 830; break;
		case 38: res = 773; break;
		case 39: res = 732; break;
		case 40: res = 777; break;
		case 41: res = 576; break;
		case 42: res = 485; break;
		case 43: res = 692; break;
		case 44: res = 653; break;
		case 45: res = 725; break;
		case 46: res = 687; break;
		case 47: res = 688; break;
		case 48: res = 566; break;
		default: break;
	}
	return res;
}

#endif
