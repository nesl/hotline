#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 1187; break;
		case 1: res = 1324; break;
		case 2: res = 1095; break;
		case 3: res = 1334; break;
		case 4: res = 1735; break;
		case 5: res = 1328; break;
		case 6: res = 1107; break;
		case 7: res = 1260; break;
		case 8: res = 1046; break;
		default: break;
	}
	return res;
}

#endif
