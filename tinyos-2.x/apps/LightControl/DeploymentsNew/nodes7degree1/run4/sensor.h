#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 404; break;
		case 1: res = 448; break;
		case 2: res = 536; break;
		case 3: res = 515; break;
		case 4: res = 580; break;
		case 5: res = 658; break;
		case 6: res = 437; break;
		case 7: res = 561; break;
		case 8: res = 626; break;
		case 9: res = 731; break;
		case 10: res = 595; break;
		case 11: res = 654; break;
		case 12: res = 760; break;
		case 13: res = 565; break;
		case 14: res = 424; break;
		case 15: res = 558; break;
		case 16: res = 673; break;
		case 17: res = 612; break;
		case 18: res = 672; break;
		case 19: res = 672; break;
		case 20: res = 481; break;
		case 21: res = 539; break;
		case 22: res = 609; break;
		case 23: res = 631; break;
		case 24: res = 590; break;
		case 25: res = 697; break;
		case 26: res = 686; break;
		case 27: res = 574; break;
		case 28: res = 495; break;
		case 29: res = 631; break;
		case 30: res = 587; break;
		case 31: res = 551; break;
		case 32: res = 731; break;
		case 33: res = 730; break;
		case 34: res = 539; break;
		case 35: res = 555; break;
		case 36: res = 648; break;
		case 37: res = 562; break;
		case 38: res = 590; break;
		case 39: res = 694; break;
		case 40: res = 671; break;
		case 41: res = 587; break;
		case 42: res = 415; break;
		case 43: res = 543; break;
		case 44: res = 450; break;
		case 45: res = 548; break;
		case 46: res = 640; break;
		case 47: res = 620; break;
		case 48: res = 474; break;
		default: break;
	}
	return res;
}

#endif
