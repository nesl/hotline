#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 807; break;
		case 1: res = 1135; break;
		case 2: res = 1195; break;
		case 3: res = 1286; break;
		case 4: res = 924; break;
		case 5: res = 1220; break;
		case 6: res = 1558; break;
		case 7: res = 1584; break;
		case 8: res = 1658; break;
		case 9: res = 1315; break;
		case 10: res = 1151; break;
		case 11: res = 1545; break;
		case 12: res = 1522; break;
		case 13: res = 1614; break;
		case 14: res = 1172; break;
		case 15: res = 1140; break;
		case 16: res = 1538; break;
		case 17: res = 1538; break;
		case 18: res = 1577; break;
		case 19: res = 1148; break;
		case 20: res = 705; break;
		case 21: res = 1002; break;
		case 22: res = 1042; break;
		case 23: res = 1128; break;
		case 24: res = 731; break;
		default: break;
	}
	return res;
}

#endif
