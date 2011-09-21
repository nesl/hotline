#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1404; break;
		case 1: res = 1784; break;
		case 2: res = 1909; break;
		case 3: res = 1671; break;
		case 4: res = 1402; break;
		case 5: res = 1798; break;
		case 6: res = 2337; break;
		case 7: res = 2405; break;
		case 8: res = 2229; break;
		case 9: res = 1658; break;
		case 10: res = 1897; break;
		case 11: res = 2347; break;
		case 12: res = 2463; break;
		case 13: res = 2256; break;
		case 14: res = 1677; break;
		case 15: res = 1701; break;
		case 16: res = 2195; break;
		case 17: res = 2182; break;
		case 18: res = 2017; break;
		case 19: res = 1489; break;
		case 20: res = 1340; break;
		case 21: res = 1742; break;
		case 22: res = 1740; break;
		case 23: res = 1581; break;
		case 24: res = 1196; break;
		default: break;
	}
	return res;
}

#endif
