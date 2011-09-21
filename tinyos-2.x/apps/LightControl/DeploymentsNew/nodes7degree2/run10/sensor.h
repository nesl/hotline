#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 512; break;
		case 1: res = 597; break;
		case 2: res = 637; break;
		case 3: res = 716; break;
		case 4: res = 692; break;
		case 5: res = 597; break;
		case 6: res = 546; break;
		case 7: res = 683; break;
		case 8: res = 772; break;
		case 9: res = 806; break;
		case 10: res = 877; break;
		case 11: res = 871; break;
		case 12: res = 878; break;
		case 13: res = 642; break;
		case 14: res = 749; break;
		case 15: res = 904; break;
		case 16: res = 842; break;
		case 17: res = 822; break;
		case 18: res = 874; break;
		case 19: res = 786; break;
		case 20: res = 680; break;
		case 21: res = 778; break;
		case 22: res = 899; break;
		case 23: res = 787; break;
		case 24: res = 877; break;
		case 25: res = 789; break;
		case 26: res = 826; break;
		case 27: res = 658; break;
		case 28: res = 795; break;
		case 29: res = 856; break;
		case 30: res = 829; break;
		case 31: res = 790; break;
		case 32: res = 819; break;
		case 33: res = 711; break;
		case 34: res = 612; break;
		case 35: res = 740; break;
		case 36: res = 923; break;
		case 37: res = 898; break;
		case 38: res = 877; break;
		case 39: res = 805; break;
		case 40: res = 823; break;
		case 41: res = 576; break;
		case 42: res = 594; break;
		case 43: res = 783; break;
		case 44: res = 733; break;
		case 45: res = 803; break;
		case 46: res = 712; break;
		case 47: res = 651; break;
		case 48: res = 540; break;
		default: break;
	}
	return res;
}

#endif
