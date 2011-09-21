#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 420; break;
		case 1: res = 545; break;
		case 2: res = 573; break;
		case 3: res = 559; break;
		case 4: res = 561; break;
		case 5: res = 567; break;
		case 6: res = 421; break;
		case 7: res = 487; break;
		case 8: res = 596; break;
		case 9: res = 723; break;
		case 10: res = 693; break;
		case 11: res = 757; break;
		case 12: res = 675; break;
		case 13: res = 483; break;
		case 14: res = 444; break;
		case 15: res = 575; break;
		case 16: res = 703; break;
		case 17: res = 642; break;
		case 18: res = 650; break;
		case 19: res = 618; break;
		case 20: res = 463; break;
		case 21: res = 522; break;
		case 22: res = 529; break;
		case 23: res = 642; break;
		case 24: res = 706; break;
		case 25: res = 686; break;
		case 26: res = 555; break;
		case 27: res = 510; break;
		case 28: res = 544; break;
		case 29: res = 613; break;
		case 30: res = 684; break;
		case 31: res = 740; break;
		case 32: res = 615; break;
		case 33: res = 621; break;
		case 34: res = 545; break;
		case 35: res = 516; break;
		case 36: res = 575; break;
		case 37: res = 682; break;
		case 38: res = 758; break;
		case 39: res = 662; break;
		case 40: res = 555; break;
		case 41: res = 520; break;
		case 42: res = 383; break;
		case 43: res = 479; break;
		case 44: res = 458; break;
		case 45: res = 563; break;
		case 46: res = 590; break;
		case 47: res = 538; break;
		case 48: res = 426; break;
		default: break;
	}
	return res;
}

#endif
