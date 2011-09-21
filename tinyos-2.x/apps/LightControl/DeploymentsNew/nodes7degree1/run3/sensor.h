#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 385; break;
		case 1: res = 497; break;
		case 2: res = 518; break;
		case 3: res = 539; break;
		case 4: res = 569; break;
		case 5: res = 559; break;
		case 6: res = 439; break;
		case 7: res = 624; break;
		case 8: res = 688; break;
		case 9: res = 688; break;
		case 10: res = 653; break;
		case 11: res = 633; break;
		case 12: res = 562; break;
		case 13: res = 544; break;
		case 14: res = 540; break;
		case 15: res = 792; break;
		case 16: res = 697; break;
		case 17: res = 632; break;
		case 18: res = 674; break;
		case 19: res = 579; break;
		case 20: res = 557; break;
		case 21: res = 488; break;
		case 22: res = 663; break;
		case 23: res = 661; break;
		case 24: res = 730; break;
		case 25: res = 727; break;
		case 26: res = 650; break;
		case 27: res = 624; break;
		case 28: res = 506; break;
		case 29: res = 647; break;
		case 30: res = 619; break;
		case 31: res = 608; break;
		case 32: res = 626; break;
		case 33: res = 629; break;
		case 34: res = 554; break;
		case 35: res = 596; break;
		case 36: res = 628; break;
		case 37: res = 672; break;
		case 38: res = 598; break;
		case 39: res = 685; break;
		case 40: res = 587; break;
		case 41: res = 594; break;
		case 42: res = 429; break;
		case 43: res = 523; break;
		case 44: res = 536; break;
		case 45: res = 529; break;
		case 46: res = 619; break;
		case 47: res = 509; break;
		case 48: res = 427; break;
		default: break;
	}
	return res;
}

#endif
