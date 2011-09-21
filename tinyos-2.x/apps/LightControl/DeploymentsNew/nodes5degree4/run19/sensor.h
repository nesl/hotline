#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1058; break;
		case 1: res = 1389; break;
		case 2: res = 1518; break;
		case 3: res = 1395; break;
		case 4: res = 1253; break;
		case 5: res = 1400; break;
		case 6: res = 1770; break;
		case 7: res = 1883; break;
		case 8: res = 1960; break;
		case 9: res = 1537; break;
		case 10: res = 1461; break;
		case 11: res = 1768; break;
		case 12: res = 2064; break;
		case 13: res = 2060; break;
		case 14: res = 1725; break;
		case 15: res = 1224; break;
		case 16: res = 1732; break;
		case 17: res = 1881; break;
		case 18: res = 1965; break;
		case 19: res = 1532; break;
		case 20: res = 1026; break;
		case 21: res = 1347; break;
		case 22: res = 1521; break;
		case 23: res = 1519; break;
		case 24: res = 1324; break;
		default: break;
	}
	return res;
}

#endif
