#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 378; break;
		case 1: res = 516; break;
		case 2: res = 564; break;
		case 3: res = 561; break;
		case 4: res = 577; break;
		case 5: res = 642; break;
		case 6: res = 376; break;
		case 7: res = 581; break;
		case 8: res = 696; break;
		case 9: res = 655; break;
		case 10: res = 642; break;
		case 11: res = 651; break;
		case 12: res = 736; break;
		case 13: res = 460; break;
		case 14: res = 533; break;
		case 15: res = 622; break;
		case 16: res = 658; break;
		case 17: res = 745; break;
		case 18: res = 620; break;
		case 19: res = 600; break;
		case 20: res = 496; break;
		case 21: res = 577; break;
		case 22: res = 699; break;
		case 23: res = 660; break;
		case 24: res = 676; break;
		case 25: res = 579; break;
		case 26: res = 587; break;
		case 27: res = 550; break;
		case 28: res = 547; break;
		case 29: res = 813; break;
		case 30: res = 649; break;
		case 31: res = 594; break;
		case 32: res = 606; break;
		case 33: res = 627; break;
		case 34: res = 528; break;
		case 35: res = 520; break;
		case 36: res = 696; break;
		case 37: res = 735; break;
		case 38: res = 653; break;
		case 39: res = 713; break;
		case 40: res = 559; break;
		case 41: res = 535; break;
		case 42: res = 412; break;
		case 43: res = 639; break;
		case 44: res = 594; break;
		case 45: res = 561; break;
		case 46: res = 601; break;
		case 47: res = 484; break;
		case 48: res = 410; break;
		default: break;
	}
	return res;
}

#endif
