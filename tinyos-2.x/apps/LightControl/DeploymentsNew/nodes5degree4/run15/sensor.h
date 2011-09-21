#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1231; break;
		case 1: res = 1715; break;
		case 2: res = 1841; break;
		case 3: res = 1637; break;
		case 4: res = 1291; break;
		case 5: res = 1547; break;
		case 6: res = 2128; break;
		case 7: res = 2388; break;
		case 8: res = 2243; break;
		case 9: res = 1605; break;
		case 10: res = 1585; break;
		case 11: res = 2092; break;
		case 12: res = 2520; break;
		case 13: res = 2376; break;
		case 14: res = 1663; break;
		case 15: res = 1367; break;
		case 16: res = 1921; break;
		case 17: res = 2145; break;
		case 18: res = 2116; break;
		case 19: res = 1570; break;
		case 20: res = 1024; break;
		case 21: res = 1516; break;
		case 22: res = 1619; break;
		case 23: res = 1600; break;
		case 24: res = 1193; break;
		default: break;
	}
	return res;
}

#endif
