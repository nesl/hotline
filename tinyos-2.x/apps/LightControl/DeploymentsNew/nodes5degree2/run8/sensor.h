#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 508; break;
		case 1: res = 679; break;
		case 2: res = 628; break;
		case 3: res = 700; break;
		case 4: res = 579; break;
		case 5: res = 690; break;
		case 6: res = 760; break;
		case 7: res = 755; break;
		case 8: res = 790; break;
		case 9: res = 653; break;
		case 10: res = 723; break;
		case 11: res = 731; break;
		case 12: res = 770; break;
		case 13: res = 821; break;
		case 14: res = 686; break;
		case 15: res = 673; break;
		case 16: res = 754; break;
		case 17: res = 762; break;
		case 18: res = 838; break;
		case 19: res = 694; break;
		case 20: res = 579; break;
		case 21: res = 589; break;
		case 22: res = 645; break;
		case 23: res = 786; break;
		case 24: res = 589; break;
		default: break;
	}
	return res;
}

#endif
