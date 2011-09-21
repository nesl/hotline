#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 806; break;
		case 1: res = 1166; break;
		case 2: res = 1177; break;
		case 3: res = 1083; break;
		case 4: res = 682; break;
		case 5: res = 1152; break;
		case 6: res = 1557; break;
		case 7: res = 1575; break;
		case 8: res = 1533; break;
		case 9: res = 1119; break;
		case 10: res = 1104; break;
		case 11: res = 1545; break;
		case 12: res = 1553; break;
		case 13: res = 1645; break;
		case 14: res = 1169; break;
		case 15: res = 1181; break;
		case 16: res = 1666; break;
		case 17: res = 1662; break;
		case 18: res = 1789; break;
		case 19: res = 1305; break;
		case 20: res = 827; break;
		case 21: res = 1142; break;
		case 22: res = 1122; break;
		case 23: res = 1257; break;
		case 24: res = 867; break;
		default: break;
	}
	return res;
}

#endif
