#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 359; break;
		case 1: res = 546; break;
		case 2: res = 521; break;
		case 3: res = 554; break;
		case 4: res = 559; break;
		case 5: res = 615; break;
		case 6: res = 376; break;
		case 7: res = 510; break;
		case 8: res = 692; break;
		case 9: res = 659; break;
		case 10: res = 650; break;
		case 11: res = 611; break;
		case 12: res = 697; break;
		case 13: res = 518; break;
		case 14: res = 399; break;
		case 15: res = 636; break;
		case 16: res = 678; break;
		case 17: res = 608; break;
		case 18: res = 610; break;
		case 19: res = 589; break;
		case 20: res = 446; break;
		case 21: res = 463; break;
		case 22: res = 616; break;
		case 23: res = 574; break;
		case 24: res = 594; break;
		case 25: res = 597; break;
		case 26: res = 537; break;
		case 27: res = 496; break;
		case 28: res = 534; break;
		case 29: res = 678; break;
		case 30: res = 649; break;
		case 31: res = 594; break;
		case 32: res = 607; break;
		case 33: res = 648; break;
		case 34: res = 471; break;
		case 35: res = 595; break;
		case 36: res = 650; break;
		case 37: res = 610; break;
		case 38: res = 547; break;
		case 39: res = 689; break;
		case 40: res = 681; break;
		case 41: res = 563; break;
		case 42: res = 444; break;
		case 43: res = 558; break;
		case 44: res = 465; break;
		case 45: res = 509; break;
		case 46: res = 649; break;
		case 47: res = 583; break;
		case 48: res = 445; break;
		default: break;
	}
	return res;
}

#endif
