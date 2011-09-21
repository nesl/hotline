#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 720; break;
		case 1: res = 1010; break;
		case 2: res = 1033; break;
		case 3: res = 1116; break;
		case 4: res = 791; break;
		case 5: res = 1094; break;
		case 6: res = 1441; break;
		case 7: res = 1521; break;
		case 8: res = 1558; break;
		case 9: res = 1212; break;
		case 10: res = 1034; break;
		case 11: res = 1468; break;
		case 12: res = 1600; break;
		case 13: res = 1587; break;
		case 14: res = 1131; break;
		case 15: res = 1146; break;
		case 16: res = 1627; break;
		case 17: res = 1754; break;
		case 18: res = 1734; break;
		case 19: res = 1268; break;
		case 20: res = 750; break;
		case 21: res = 1087; break;
		case 22: res = 1187; break;
		case 23: res = 1247; break;
		case 24: res = 852; break;
		default: break;
	}
	return res;
}

#endif
