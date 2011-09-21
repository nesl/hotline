#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1208; break;
		case 1: res = 1606; break;
		case 2: res = 1815; break;
		case 3: res = 1577; break;
		case 4: res = 1265; break;
		case 5: res = 1627; break;
		case 6: res = 2261; break;
		case 7: res = 2388; break;
		case 8: res = 2226; break;
		case 9: res = 1582; break;
		case 10: res = 1834; break;
		case 11: res = 2408; break;
		case 12: res = 2630; break;
		case 13: res = 2391; break;
		case 14: res = 1747; break;
		case 15: res = 1647; break;
		case 16: res = 2286; break;
		case 17: res = 2389; break;
		case 18: res = 2236; break;
		case 19: res = 1580; break;
		case 20: res = 1282; break;
		case 21: res = 1706; break;
		case 22: res = 1869; break;
		case 23: res = 1681; break;
		case 24: res = 1264; break;
		default: break;
	}
	return res;
}

#endif
