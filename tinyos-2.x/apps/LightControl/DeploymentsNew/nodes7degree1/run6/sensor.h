#ifndef _SENSOR_H_
#define _SENSOR_H_

uint16_t sensor() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 386; break;
		case 1: res = 526; break;
		case 2: res = 519; break;
		case 3: res = 496; break;
		case 4: res = 548; break;
		case 5: res = 601; break;
		case 6: res = 352; break;
		case 7: res = 560; break;
		case 8: res = 637; break;
		case 9: res = 649; break;
		case 10: res = 685; break;
		case 11: res = 717; break;
		case 12: res = 783; break;
		case 13: res = 541; break;
		case 14: res = 417; break;
		case 15: res = 612; break;
		case 16: res = 699; break;
		case 17: res = 650; break;
		case 18: res = 610; break;
		case 19: res = 620; break;
		case 20: res = 561; break;
		case 21: res = 495; break;
		case 22: res = 558; break;
		case 23: res = 665; break;
		case 24: res = 629; break;
		case 25: res = 708; break;
		case 26: res = 640; break;
		case 27: res = 625; break;
		case 28: res = 518; break;
		case 29: res = 566; break;
		case 30: res = 659; break;
		case 31: res = 640; break;
		case 32: res = 784; break;
		case 33: res = 646; break;
		case 34: res = 522; break;
		case 35: res = 606; break;
		case 36: res = 618; break;
		case 37: res = 612; break;
		case 38: res = 661; break;
		case 39: res = 726; break;
		case 40: res = 673; break;
		case 41: res = 602; break;
		case 42: res = 397; break;
		case 43: res = 483; break;
		case 44: res = 481; break;
		case 45: res = 584; break;
		case 46: res = 546; break;
		case 47: res = 559; break;
		case 48: res = 481; break;
		default: break;
	}
	return res;
}

#endif
