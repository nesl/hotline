#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 377; break;
		case 1: res = 562; break;
		case 2: res = 586; break;
		case 3: res = 566; break;
		case 4: res = 603; break;
		case 5: res = 556; break;
		case 6: res = 360; break;
		case 7: res = 595; break;
		case 8: res = 705; break;
		case 9: res = 614; break;
		case 10: res = 618; break;
		case 11: res = 672; break;
		case 12: res = 632; break;
		case 13: res = 492; break;
		case 14: res = 539; break;
		case 15: res = 641; break;
		case 16: res = 649; break;
		case 17: res = 680; break;
		case 18: res = 704; break;
		case 19: res = 604; break;
		case 20: res = 466; break;
		case 21: res = 584; break;
		case 22: res = 669; break;
		case 23: res = 705; break;
		case 24: res = 720; break;
		case 25: res = 667; break;
		case 26: res = 493; break;
		case 27: res = 506; break;
		case 28: res = 486; break;
		case 29: res = 578; break;
		case 30: res = 660; break;
		case 31: res = 699; break;
		case 32: res = 747; break;
		case 33: res = 607; break;
		case 34: res = 450; break;
		case 35: res = 541; break;
		case 36: res = 660; break;
		case 37: res = 746; break;
		case 38: res = 666; break;
		case 39: res = 766; break;
		case 40: res = 650; break;
		case 41: res = 562; break;
		case 42: res = 417; break;
		case 43: res = 595; break;
		case 44: res = 575; break;
		case 45: res = 489; break;
		case 46: res = 551; break;
		case 47: res = 449; break;
		case 48: res = 372; break;
		default: break;
	}
	return res;
}

#endif
