#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 695; break;
		case 1: res = 1066; break;
		case 2: res = 1130; break;
		case 3: res = 1154; break;
		case 4: res = 761; break;
		case 5: res = 1084; break;
		case 6: res = 1460; break;
		case 7: res = 1484; break;
		case 8: res = 1548; break;
		case 9: res = 1174; break;
		case 10: res = 1133; break;
		case 11: res = 1508; break;
		case 12: res = 1408; break;
		case 13: res = 1446; break;
		case 14: res = 1038; break;
		case 15: res = 1278; break;
		case 16: res = 1648; break;
		case 17: res = 1540; break;
		case 18: res = 1535; break;
		case 19: res = 1151; break;
		case 20: res = 871; break;
		case 21: res = 1113; break;
		case 22: res = 1048; break;
		case 23: res = 1041; break;
		case 24: res = 716; break;
		default: break;
	}
	return res;
}

#endif
