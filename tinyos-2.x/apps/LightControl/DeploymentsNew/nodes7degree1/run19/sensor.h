#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 337; break;
		case 1: res = 460; break;
		case 2: res = 531; break;
		case 3: res = 536; break;
		case 4: res = 536; break;
		case 5: res = 526; break;
		case 6: res = 334; break;
		case 7: res = 557; break;
		case 8: res = 650; break;
		case 9: res = 697; break;
		case 10: res = 685; break;
		case 11: res = 687; break;
		case 12: res = 701; break;
		case 13: res = 513; break;
		case 14: res = 478; break;
		case 15: res = 664; break;
		case 16: res = 707; break;
		case 17: res = 612; break;
		case 18: res = 682; break;
		case 19: res = 665; break;
		case 20: res = 544; break;
		case 21: res = 512; break;
		case 22: res = 675; break;
		case 23: res = 747; break;
		case 24: res = 641; break;
		case 25: res = 603; break;
		case 26: res = 546; break;
		case 27: res = 532; break;
		case 28: res = 546; break;
		case 29: res = 718; break;
		case 30: res = 702; break;
		case 31: res = 637; break;
		case 32: res = 726; break;
		case 33: res = 655; break;
		case 34: res = 519; break;
		case 35: res = 542; break;
		case 36: res = 576; break;
		case 37: res = 638; break;
		case 38: res = 597; break;
		case 39: res = 674; break;
		case 40: res = 562; break;
		case 41: res = 583; break;
		case 42: res = 399; break;
		case 43: res = 585; break;
		case 44: res = 579; break;
		case 45: res = 478; break;
		case 46: res = 550; break;
		case 47: res = 596; break;
		case 48: res = 489; break;
		default: break;
	}
	return res;
}

#endif
