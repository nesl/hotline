#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1077; break;
		case 1: res = 1585; break;
		case 2: res = 1786; break;
		case 3: res = 1722; break;
		case 4: res = 1374; break;
		case 5: res = 1496; break;
		case 6: res = 2105; break;
		case 7: res = 2433; break;
		case 8: res = 2354; break;
		case 9: res = 1749; break;
		case 10: res = 1678; break;
		case 11: res = 2214; break;
		case 12: res = 2503; break;
		case 13: res = 2437; break;
		case 14: res = 1852; break;
		case 15: res = 1566; break;
		case 16: res = 2132; break;
		case 17: res = 2301; break;
		case 18: res = 2147; break;
		case 19: res = 1590; break;
		case 20: res = 1341; break;
		case 21: res = 1731; break;
		case 22: res = 1769; break;
		case 23: res = 1656; break;
		case 24: res = 1289; break;
		default: break;
	}
	return res;
}

#endif
