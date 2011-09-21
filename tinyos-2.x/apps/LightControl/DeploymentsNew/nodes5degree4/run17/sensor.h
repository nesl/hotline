#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1083; break;
		case 1: res = 1486; break;
		case 2: res = 1561; break;
		case 3: res = 1443; break;
		case 4: res = 1121; break;
		case 5: res = 1512; break;
		case 6: res = 1970; break;
		case 7: res = 2192; break;
		case 8: res = 2013; break;
		case 9: res = 1505; break;
		case 10: res = 1574; break;
		case 11: res = 2274; break;
		case 12: res = 2364; break;
		case 13: res = 2194; break;
		case 14: res = 1556; break;
		case 15: res = 1471; break;
		case 16: res = 2036; break;
		case 17: res = 2328; break;
		case 18: res = 2077; break;
		case 19: res = 1498; break;
		case 20: res = 1183; break;
		case 21: res = 1701; break;
		case 22: res = 1815; break;
		case 23: res = 1705; break;
		case 24: res = 1197; break;
		default: break;
	}
	return res;
}

#endif
