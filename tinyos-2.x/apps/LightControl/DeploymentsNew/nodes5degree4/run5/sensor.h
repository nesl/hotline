#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1106; break;
		case 1: res = 1552; break;
		case 2: res = 1704; break;
		case 3: res = 1510; break;
		case 4: res = 1223; break;
		case 5: res = 1594; break;
		case 6: res = 2165; break;
		case 7: res = 2276; break;
		case 8: res = 2126; break;
		case 9: res = 1526; break;
		case 10: res = 1741; break;
		case 11: res = 2275; break;
		case 12: res = 2447; break;
		case 13: res = 2225; break;
		case 14: res = 1644; break;
		case 15: res = 1497; break;
		case 16: res = 2151; break;
		case 17: res = 2214; break;
		case 18: res = 2017; break;
		case 19: res = 1432; break;
		case 20: res = 1230; break;
		case 21: res = 1650; break;
		case 22: res = 1750; break;
		case 23: res = 1550; break;
		case 24: res = 1222; break;
		default: break;
	}
	return res;
}

#endif
