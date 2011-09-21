#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1246; break;
		case 1: res = 1605; break;
		case 2: res = 1679; break;
		case 3: res = 1575; break;
		case 4: res = 1229; break;
		case 5: res = 1647; break;
		case 6: res = 2108; break;
		case 7: res = 2161; break;
		case 8: res = 1999; break;
		case 9: res = 1552; break;
		case 10: res = 1781; break;
		case 11: res = 2239; break;
		case 12: res = 2233; break;
		case 13: res = 2093; break;
		case 14: res = 1683; break;
		case 15: res = 1681; break;
		case 16: res = 2046; break;
		case 17: res = 2128; break;
		case 18: res = 1973; break;
		case 19: res = 1482; break;
		case 20: res = 1331; break;
		case 21: res = 1632; break;
		case 22: res = 1630; break;
		case 23: res = 1576; break;
		case 24: res = 1203; break;
		default: break;
	}
	return res;
}

#endif
