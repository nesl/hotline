#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 821; break;
		case 1: res = 1183; break;
		case 2: res = 1175; break;
		case 3: res = 1206; break;
		case 4: res = 824; break;
		case 5: res = 1178; break;
		case 6: res = 1564; break;
		case 7: res = 1533; break;
		case 8: res = 1598; break;
		case 9: res = 1222; break;
		case 10: res = 1210; break;
		case 11: res = 1666; break;
		case 12: res = 1653; break;
		case 13: res = 1643; break;
		case 14: res = 1148; break;
		case 15: res = 1173; break;
		case 16: res = 1652; break;
		case 17: res = 1679; break;
		case 18: res = 1694; break;
		case 19: res = 1207; break;
		case 20: res = 798; break;
		case 21: res = 1125; break;
		case 22: res = 1179; break;
		case 23: res = 1214; break;
		case 24: res = 809; break;
		default: break;
	}
	return res;
}

#endif
