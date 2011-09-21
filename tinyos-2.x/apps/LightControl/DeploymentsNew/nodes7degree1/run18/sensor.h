#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 325; break;
		case 1: res = 442; break;
		case 2: res = 562; break;
		case 3: res = 546; break;
		case 4: res = 559; break;
		case 5: res = 571; break;
		case 6: res = 318; break;
		case 7: res = 542; break;
		case 8: res = 692; break;
		case 9: res = 737; break;
		case 10: res = 655; break;
		case 11: res = 618; break;
		case 12: res = 669; break;
		case 13: res = 431; break;
		case 14: res = 474; break;
		case 15: res = 614; break;
		case 16: res = 695; break;
		case 17: res = 733; break;
		case 18: res = 704; break;
		case 19: res = 685; break;
		case 20: res = 479; break;
		case 21: res = 569; break;
		case 22: res = 585; break;
		case 23: res = 724; break;
		case 24: res = 729; break;
		case 25: res = 681; break;
		case 26: res = 636; break;
		case 27: res = 581; break;
		case 28: res = 616; break;
		case 29: res = 681; break;
		case 30: res = 666; break;
		case 31: res = 709; break;
		case 32: res = 634; break;
		case 33: res = 676; break;
		case 34: res = 495; break;
		case 35: res = 546; break;
		case 36: res = 613; break;
		case 37: res = 585; break;
		case 38: res = 702; break;
		case 39: res = 746; break;
		case 40: res = 692; break;
		case 41: res = 540; break;
		case 42: res = 390; break;
		case 43: res = 569; break;
		case 44: res = 513; break;
		case 45: res = 454; break;
		case 46: res = 572; break;
		case 47: res = 565; break;
		case 48: res = 447; break;
		default: break;
	}
	return res;
}

#endif
