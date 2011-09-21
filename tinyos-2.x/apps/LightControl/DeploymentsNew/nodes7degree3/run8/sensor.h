#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 808; break;
		case 1: res = 1086; break;
		case 2: res = 1080; break;
		case 3: res = 1012; break;
		case 4: res = 996; break;
		case 5: res = 1146; break;
		case 6: res = 858; break;
		case 7: res = 1187; break;
		case 8: res = 1604; break;
		case 9: res = 1542; break;
		case 10: res = 1488; break;
		case 11: res = 1425; break;
		case 12: res = 1541; break;
		case 13: res = 1224; break;
		case 14: res = 1121; break;
		case 15: res = 1680; break;
		case 16: res = 1666; break;
		case 17: res = 1572; break;
		case 18: res = 1588; break;
		case 19: res = 1569; break;
		case 20: res = 1189; break;
		case 21: res = 1287; break;
		case 22: res = 1765; break;
		case 23: res = 1668; break;
		case 24: res = 1616; break;
		case 25: res = 1627; break;
		case 26: res = 1630; break;
		case 27: res = 1128; break;
		case 28: res = 1202; break;
		case 29: res = 1680; break;
		case 30: res = 1576; break;
		case 31: res = 1610; break;
		case 32: res = 1605; break;
		case 33: res = 1647; break;
		case 34: res = 1150; break;
		case 35: res = 1162; break;
		case 36: res = 1550; break;
		case 37: res = 1572; break;
		case 38: res = 1539; break;
		case 39: res = 1536; break;
		case 40: res = 1620; break;
		case 41: res = 1266; break;
		case 42: res = 692; break;
		case 43: res = 1080; break;
		case 44: res = 1087; break;
		case 45: res = 1132; break;
		case 46: res = 1111; break;
		case 47: res = 1196; break;
		case 48: res = 863; break;
		default: break;
	}
	return res;
}

#endif
