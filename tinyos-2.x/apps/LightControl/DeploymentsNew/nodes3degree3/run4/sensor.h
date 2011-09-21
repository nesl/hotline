#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 620; break;
		case 1: res = 964; break;
		case 2: res = 688; break;
		case 3: res = 867; break;
		case 4: res = 1346; break;
		case 5: res = 1012; break;
		case 6: res = 655; break;
		case 7: res = 906; break;
		case 8: res = 704; break;
		default: break;
	}
	return res;
}

#endif
