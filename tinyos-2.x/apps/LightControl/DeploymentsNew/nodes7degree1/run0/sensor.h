#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 398; break;
		case 1: res = 588; break;
		case 2: res = 562; break;
		case 3: res = 551; break;
		case 4: res = 530; break;
		case 5: res = 547; break;
		case 6: res = 320; break;
		case 7: res = 593; break;
		case 8: res = 683; break;
		case 9: res = 676; break;
		case 10: res = 725; break;
		case 11: res = 728; break;
		case 12: res = 638; break;
		case 13: res = 450; break;
		case 14: res = 552; break;
		case 15: res = 606; break;
		case 16: res = 687; break;
		case 17: res = 744; break;
		case 18: res = 789; break;
		case 19: res = 672; break;
		case 20: res = 460; break;
		case 21: res = 626; break;
		case 22: res = 600; break;
		case 23: res = 660; break;
		case 24: res = 756; break;
		case 25: res = 726; break;
		case 26: res = 614; break;
		case 27: res = 588; break;
		case 28: res = 549; break;
		case 29: res = 686; break;
		case 30: res = 685; break;
		case 31: res = 629; break;
		case 32: res = 624; break;
		case 33: res = 584; break;
		case 34: res = 544; break;
		case 35: res = 555; break;
		case 36: res = 680; break;
		case 37: res = 648; break;
		case 38: res = 599; break;
		case 39: res = 715; break;
		case 40: res = 644; break;
		case 41: res = 551; break;
		case 42: res = 419; break;
		case 43: res = 579; break;
		case 44: res = 573; break;
		case 45: res = 501; break;
		case 46: res = 594; break;
		case 47: res = 535; break;
		case 48: res = 390; break;
		default: break;
	}
	return res;
}

#endif
