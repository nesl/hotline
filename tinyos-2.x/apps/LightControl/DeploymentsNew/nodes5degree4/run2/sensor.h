#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1084; break;
		case 1: res = 1418; break;
		case 2: res = 1554; break;
		case 3: res = 1401; break;
		case 4: res = 1171; break;
		case 5: res = 1506; break;
		case 6: res = 1944; break;
		case 7: res = 1986; break;
		case 8: res = 1848; break;
		case 9: res = 1370; break;
		case 10: res = 1673; break;
		case 11: res = 2012; break;
		case 12: res = 2170; break;
		case 13: res = 1922; break;
		case 14: res = 1463; break;
		case 15: res = 1463; break;
		case 16: res = 1956; break;
		case 17: res = 1981; break;
		case 18: res = 1779; break;
		case 19: res = 1237; break;
		case 20: res = 1170; break;
		case 21: res = 1520; break;
		case 22: res = 1536; break;
		case 23: res = 1426; break;
		case 24: res = 1085; break;
		default: break;
	}
	return res;
}

#endif
