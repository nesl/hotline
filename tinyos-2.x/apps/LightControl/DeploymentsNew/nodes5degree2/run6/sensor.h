#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 478; break;
		case 1: res = 634; break;
		case 2: res = 652; break;
		case 3: res = 707; break;
		case 4: res = 575; break;
		case 5: res = 594; break;
		case 6: res = 796; break;
		case 7: res = 785; break;
		case 8: res = 737; break;
		case 9: res = 585; break;
		case 10: res = 672; break;
		case 11: res = 829; break;
		case 12: res = 843; break;
		case 13: res = 861; break;
		case 14: res = 605; break;
		case 15: res = 671; break;
		case 16: res = 862; break;
		case 17: res = 786; break;
		case 18: res = 751; break;
		case 19: res = 684; break;
		case 20: res = 650; break;
		case 21: res = 672; break;
		case 22: res = 584; break;
		case 23: res = 699; break;
		case 24: res = 549; break;
		default: break;
	}
	return res;
}

#endif
