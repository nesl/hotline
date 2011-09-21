#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1108; break;
		case 1: res = 1444; break;
		case 2: res = 1485; break;
		case 3: res = 1431; break;
		case 4: res = 1090; break;
		case 5: res = 1630; break;
		case 6: res = 2038; break;
		case 7: res = 2166; break;
		case 8: res = 1980; break;
		case 9: res = 1497; break;
		case 10: res = 1759; break;
		case 11: res = 2268; break;
		case 12: res = 2282; break;
		case 13: res = 2239; break;
		case 14: res = 1687; break;
		case 15: res = 1603; break;
		case 16: res = 1996; break;
		case 17: res = 2172; break;
		case 18: res = 1999; break;
		case 19: res = 1541; break;
		case 20: res = 1216; break;
		case 21: res = 1568; break;
		case 22: res = 1628; break;
		case 23: res = 1592; break;
		case 24: res = 1204; break;
		default: break;
	}
	return res;
}

#endif
