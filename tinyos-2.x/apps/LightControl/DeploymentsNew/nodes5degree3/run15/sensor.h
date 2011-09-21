#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 671; break;
		case 1: res = 935; break;
		case 2: res = 965; break;
		case 3: res = 1092; break;
		case 4: res = 799; break;
		case 5: res = 1046; break;
		case 6: res = 1355; break;
		case 7: res = 1349; break;
		case 8: res = 1464; break;
		case 9: res = 1152; break;
		case 10: res = 1015; break;
		case 11: res = 1436; break;
		case 12: res = 1442; break;
		case 13: res = 1470; break;
		case 14: res = 1008; break;
		case 15: res = 1141; break;
		case 16: res = 1565; break;
		case 17: res = 1550; break;
		case 18: res = 1554; break;
		case 19: res = 1111; break;
		case 20: res = 775; break;
		case 21: res = 1040; break;
		case 22: res = 1065; break;
		case 23: res = 1139; break;
		case 24: res = 789; break;
		default: break;
	}
	return res;
}

#endif
