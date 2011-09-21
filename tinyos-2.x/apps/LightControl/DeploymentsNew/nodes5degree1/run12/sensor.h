#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 363; break;
		case 1: res = 438; break;
		case 2: res = 559; break;
		case 3: res = 522; break;
		case 4: res = 295; break;
		case 5: res = 546; break;
		case 6: res = 752; break;
		case 7: res = 689; break;
		case 8: res = 694; break;
		case 9: res = 476; break;
		case 10: res = 466; break;
		case 11: res = 612; break;
		case 12: res = 662; break;
		case 13: res = 708; break;
		case 14: res = 610; break;
		case 15: res = 516; break;
		case 16: res = 608; break;
		case 17: res = 614; break;
		case 18: res = 692; break;
		case 19: res = 594; break;
		case 20: res = 460; break;
		case 21: res = 583; break;
		case 22: res = 519; break;
		case 23: res = 515; break;
		case 24: res = 472; break;
		default: break;
	}
	return res;
}

#endif
