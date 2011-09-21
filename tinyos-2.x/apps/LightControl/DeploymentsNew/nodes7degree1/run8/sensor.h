#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 369; break;
		case 1: res = 440; break;
		case 2: res = 430; break;
		case 3: res = 600; break;
		case 4: res = 642; break;
		case 5: res = 601; break;
		case 6: res = 405; break;
		case 7: res = 619; break;
		case 8: res = 718; break;
		case 9: res = 621; break;
		case 10: res = 613; break;
		case 11: res = 635; break;
		case 12: res = 623; break;
		case 13: res = 520; break;
		case 14: res = 510; break;
		case 15: res = 703; break;
		case 16: res = 706; break;
		case 17: res = 659; break;
		case 18: res = 654; break;
		case 19: res = 577; break;
		case 20: res = 554; break;
		case 21: res = 507; break;
		case 22: res = 561; break;
		case 23: res = 576; break;
		case 24: res = 703; break;
		case 25: res = 701; break;
		case 26: res = 558; break;
		case 27: res = 559; break;
		case 28: res = 503; break;
		case 29: res = 620; break;
		case 30: res = 527; break;
		case 31: res = 604; break;
		case 32: res = 699; break;
		case 33: res = 659; break;
		case 34: res = 498; break;
		case 35: res = 577; break;
		case 36: res = 645; break;
		case 37: res = 569; break;
		case 38: res = 594; break;
		case 39: res = 683; break;
		case 40: res = 633; break;
		case 41: res = 532; break;
		case 42: res = 411; break;
		case 43: res = 587; break;
		case 44: res = 517; break;
		case 45: res = 453; break;
		case 46: res = 515; break;
		case 47: res = 565; break;
		case 48: res = 456; break;
		default: break;
	}
	return res;
}

#endif
