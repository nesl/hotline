#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1168; break;
		case 1: res = 1528; break;
		case 2: res = 1605; break;
		case 3: res = 1627; break;
		case 4: res = 1599; break;
		case 5: res = 1308; break;
		case 6: res = 1071; break;
		case 7: res = 1610; break;
		case 8: res = 2064; break;
		case 9: res = 2170; break;
		case 10: res = 2173; break;
		case 11: res = 2171; break;
		case 12: res = 1996; break;
		case 13: res = 1369; break;
		case 14: res = 1717; break;
		case 15: res = 2111; break;
		case 16: res = 2348; break;
		case 17: res = 2297; break;
		case 18: res = 2410; break;
		case 19: res = 2166; break;
		case 20: res = 1567; break;
		case 21: res = 1702; break;
		case 22: res = 2071; break;
		case 23: res = 2368; break;
		case 24: res = 2394; break;
		case 25: res = 2391; break;
		case 26: res = 2095; break;
		case 27: res = 1598; break;
		case 28: res = 1592; break;
		case 29: res = 2239; break;
		case 30: res = 2288; break;
		case 31: res = 2416; break;
		case 32: res = 2394; break;
		case 33: res = 2116; break;
		case 34: res = 1486; break;
		case 35: res = 1531; break;
		case 36: res = 1924; break;
		case 37: res = 2178; break;
		case 38: res = 2224; break;
		case 39: res = 2255; break;
		case 40: res = 1909; break;
		case 41: res = 1295; break;
		case 42: res = 1114; break;
		case 43: res = 1427; break;
		case 44: res = 1611; break;
		case 45: res = 1662; break;
		case 46: res = 1502; break;
		case 47: res = 1335; break;
		case 48: res = 998; break;
		default: break;
	}
	return res;
}

#endif
