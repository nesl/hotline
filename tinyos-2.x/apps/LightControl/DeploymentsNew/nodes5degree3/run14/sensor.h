#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 786; break;
		case 1: res = 1129; break;
		case 2: res = 1222; break;
		case 3: res = 1164; break;
		case 4: res = 803; break;
		case 5: res = 1143; break;
		case 6: res = 1504; break;
		case 7: res = 1623; break;
		case 8: res = 1565; break;
		case 9: res = 1228; break;
		case 10: res = 1030; break;
		case 11: res = 1468; break;
		case 12: res = 1546; break;
		case 13: res = 1511; break;
		case 14: res = 1066; break;
		case 15: res = 1089; break;
		case 16: res = 1523; break;
		case 17: res = 1607; break;
		case 18: res = 1582; break;
		case 19: res = 1155; break;
		case 20: res = 719; break;
		case 21: res = 1039; break;
		case 22: res = 1101; break;
		case 23: res = 1121; break;
		case 24: res = 737; break;
		default: break;
	}
	return res;
}

#endif
