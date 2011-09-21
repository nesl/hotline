#ifndef _ZONE_DEP_H_
#define _ZONE_DEP_H_

void set_zone(zone_intset_t *z) {
	switch (TOS_NODE_ID) {
		case 0: {
			z->size = 3;
			z->element[0] = 0;
			z->element[1] = 1;
			z->element[2] = 7;
			break;
		}
		case 1: {
			z->size = 4;
			z->element[0] = 0;
			z->element[1] = 1;
			z->element[2] = 2;
			z->element[3] = 8;
			break;
		}
		case 2: {
			z->size = 4;
			z->element[0] = 1;
			z->element[1] = 2;
			z->element[2] = 3;
			z->element[3] = 9;
			break;
		}
		case 3: {
			z->size = 4;
			z->element[0] = 2;
			z->element[1] = 3;
			z->element[2] = 4;
			z->element[3] = 10;
			break;
		}
		case 4: {
			z->size = 4;
			z->element[0] = 3;
			z->element[1] = 4;
			z->element[2] = 5;
			z->element[3] = 11;
			break;
		}
		case 5: {
			z->size = 4;
			z->element[0] = 4;
			z->element[1] = 5;
			z->element[2] = 6;
			z->element[3] = 12;
			break;
		}
		case 6: {
			z->size = 3;
			z->element[0] = 5;
			z->element[1] = 6;
			z->element[2] = 13;
			break;
		}
		case 7: {
			z->size = 4;
			z->element[0] = 0;
			z->element[1] = 7;
			z->element[2] = 8;
			z->element[3] = 14;
			break;
		}
		case 8: {
			z->size = 5;
			z->element[0] = 1;
			z->element[1] = 7;
			z->element[2] = 8;
			z->element[3] = 9;
			z->element[4] = 15;
			break;
		}
		case 9: {
			z->size = 5;
			z->element[0] = 2;
			z->element[1] = 8;
			z->element[2] = 9;
			z->element[3] = 10;
			z->element[4] = 16;
			break;
		}
		case 10: {
			z->size = 5;
			z->element[0] = 3;
			z->element[1] = 9;
			z->element[2] = 10;
			z->element[3] = 11;
			z->element[4] = 17;
			break;
		}
		case 11: {
			z->size = 5;
			z->element[0] = 4;
			z->element[1] = 10;
			z->element[2] = 11;
			z->element[3] = 12;
			z->element[4] = 18;
			break;
		}
		case 12: {
			z->size = 5;
			z->element[0] = 5;
			z->element[1] = 11;
			z->element[2] = 12;
			z->element[3] = 13;
			z->element[4] = 19;
			break;
		}
		case 13: {
			z->size = 4;
			z->element[0] = 6;
			z->element[1] = 12;
			z->element[2] = 13;
			z->element[3] = 20;
			break;
		}
		case 14: {
			z->size = 4;
			z->element[0] = 7;
			z->element[1] = 14;
			z->element[2] = 15;
			z->element[3] = 21;
			break;
		}
		case 15: {
			z->size = 5;
			z->element[0] = 8;
			z->element[1] = 14;
			z->element[2] = 15;
			z->element[3] = 16;
			z->element[4] = 22;
			break;
		}
		case 16: {
			z->size = 5;
			z->element[0] = 9;
			z->element[1] = 15;
			z->element[2] = 16;
			z->element[3] = 17;
			z->element[4] = 23;
			break;
		}
		case 17: {
			z->size = 5;
			z->element[0] = 10;
			z->element[1] = 16;
			z->element[2] = 17;
			z->element[3] = 18;
			z->element[4] = 24;
			break;
		}
		case 18: {
			z->size = 5;
			z->element[0] = 11;
			z->element[1] = 17;
			z->element[2] = 18;
			z->element[3] = 19;
			z->element[4] = 25;
			break;
		}
		case 19: {
			z->size = 5;
			z->element[0] = 12;
			z->element[1] = 18;
			z->element[2] = 19;
			z->element[3] = 20;
			z->element[4] = 26;
			break;
		}
		case 20: {
			z->size = 4;
			z->element[0] = 13;
			z->element[1] = 19;
			z->element[2] = 20;
			z->element[3] = 27;
			break;
		}
		case 21: {
			z->size = 4;
			z->element[0] = 14;
			z->element[1] = 21;
			z->element[2] = 22;
			z->element[3] = 28;
			break;
		}
		case 22: {
			z->size = 5;
			z->element[0] = 15;
			z->element[1] = 21;
			z->element[2] = 22;
			z->element[3] = 23;
			z->element[4] = 29;
			break;
		}
		case 23: {
			z->size = 5;
			z->element[0] = 16;
			z->element[1] = 22;
			z->element[2] = 23;
			z->element[3] = 24;
			z->element[4] = 30;
			break;
		}
		case 24: {
			z->size = 5;
			z->element[0] = 17;
			z->element[1] = 23;
			z->element[2] = 24;
			z->element[3] = 25;
			z->element[4] = 31;
			break;
		}
		case 25: {
			z->size = 5;
			z->element[0] = 18;
			z->element[1] = 24;
			z->element[2] = 25;
			z->element[3] = 26;
			z->element[4] = 32;
			break;
		}
		case 26: {
			z->size = 5;
			z->element[0] = 19;
			z->element[1] = 25;
			z->element[2] = 26;
			z->element[3] = 27;
			z->element[4] = 33;
			break;
		}
		case 27: {
			z->size = 4;
			z->element[0] = 20;
			z->element[1] = 26;
			z->element[2] = 27;
			z->element[3] = 34;
			break;
		}
		case 28: {
			z->size = 4;
			z->element[0] = 21;
			z->element[1] = 28;
			z->element[2] = 29;
			z->element[3] = 35;
			break;
		}
		case 29: {
			z->size = 5;
			z->element[0] = 22;
			z->element[1] = 28;
			z->element[2] = 29;
			z->element[3] = 30;
			z->element[4] = 36;
			break;
		}
		case 30: {
			z->size = 5;
			z->element[0] = 23;
			z->element[1] = 29;
			z->element[2] = 30;
			z->element[3] = 31;
			z->element[4] = 37;
			break;
		}
		case 31: {
			z->size = 5;
			z->element[0] = 24;
			z->element[1] = 30;
			z->element[2] = 31;
			z->element[3] = 32;
			z->element[4] = 38;
			break;
		}
		case 32: {
			z->size = 5;
			z->element[0] = 25;
			z->element[1] = 31;
			z->element[2] = 32;
			z->element[3] = 33;
			z->element[4] = 39;
			break;
		}
		case 33: {
			z->size = 5;
			z->element[0] = 26;
			z->element[1] = 32;
			z->element[2] = 33;
			z->element[3] = 34;
			z->element[4] = 40;
			break;
		}
		case 34: {
			z->size = 4;
			z->element[0] = 27;
			z->element[1] = 33;
			z->element[2] = 34;
			z->element[3] = 41;
			break;
		}
		case 35: {
			z->size = 4;
			z->element[0] = 28;
			z->element[1] = 35;
			z->element[2] = 36;
			z->element[3] = 42;
			break;
		}
		case 36: {
			z->size = 5;
			z->element[0] = 29;
			z->element[1] = 35;
			z->element[2] = 36;
			z->element[3] = 37;
			z->element[4] = 43;
			break;
		}
		case 37: {
			z->size = 5;
			z->element[0] = 30;
			z->element[1] = 36;
			z->element[2] = 37;
			z->element[3] = 38;
			z->element[4] = 44;
			break;
		}
		case 38: {
			z->size = 5;
			z->element[0] = 31;
			z->element[1] = 37;
			z->element[2] = 38;
			z->element[3] = 39;
			z->element[4] = 45;
			break;
		}
		case 39: {
			z->size = 5;
			z->element[0] = 32;
			z->element[1] = 38;
			z->element[2] = 39;
			z->element[3] = 40;
			z->element[4] = 46;
			break;
		}
		case 40: {
			z->size = 5;
			z->element[0] = 33;
			z->element[1] = 39;
			z->element[2] = 40;
			z->element[3] = 41;
			z->element[4] = 47;
			break;
		}
		case 41: {
			z->size = 4;
			z->element[0] = 34;
			z->element[1] = 40;
			z->element[2] = 41;
			z->element[3] = 48;
			break;
		}
		case 42: {
			z->size = 3;
			z->element[0] = 35;
			z->element[1] = 42;
			z->element[2] = 43;
			break;
		}
		case 43: {
			z->size = 4;
			z->element[0] = 36;
			z->element[1] = 42;
			z->element[2] = 43;
			z->element[3] = 44;
			break;
		}
		case 44: {
			z->size = 4;
			z->element[0] = 37;
			z->element[1] = 43;
			z->element[2] = 44;
			z->element[3] = 45;
			break;
		}
		case 45: {
			z->size = 4;
			z->element[0] = 38;
			z->element[1] = 44;
			z->element[2] = 45;
			z->element[3] = 46;
			break;
		}
		case 46: {
			z->size = 4;
			z->element[0] = 39;
			z->element[1] = 45;
			z->element[2] = 46;
			z->element[3] = 47;
			break;
		}
		case 47: {
			z->size = 4;
			z->element[0] = 40;
			z->element[1] = 46;
			z->element[2] = 47;
			z->element[3] = 48;
			break;
		}
		case 48: {
			z->size = 3;
			z->element[0] = 41;
			z->element[1] = 47;
			z->element[2] = 48;
			break;
		}
		case 49: {
			z->size = 1;
			z->element[0] = 0;
			break;
		}
		case 50: {
			z->size = 1;
			z->element[0] = 1;
			break;
		}
		case 51: {
			z->size = 1;
			z->element[0] = 2;
			break;
		}
		case 52: {
			z->size = 1;
			z->element[0] = 3;
			break;
		}
		case 53: {
			z->size = 1;
			z->element[0] = 4;
			break;
		}
		case 54: {
			z->size = 1;
			z->element[0] = 5;
			break;
		}
		case 55: {
			z->size = 1;
			z->element[0] = 6;
			break;
		}
		case 56: {
			z->size = 1;
			z->element[0] = 7;
			break;
		}
		case 57: {
			z->size = 1;
			z->element[0] = 8;
			break;
		}
		case 58: {
			z->size = 1;
			z->element[0] = 9;
			break;
		}
		case 59: {
			z->size = 1;
			z->element[0] = 10;
			break;
		}
		case 60: {
			z->size = 1;
			z->element[0] = 11;
			break;
		}
		case 61: {
			z->size = 1;
			z->element[0] = 12;
			break;
		}
		case 62: {
			z->size = 1;
			z->element[0] = 13;
			break;
		}
		case 63: {
			z->size = 1;
			z->element[0] = 14;
			break;
		}
		case 64: {
			z->size = 1;
			z->element[0] = 15;
			break;
		}
		case 65: {
			z->size = 1;
			z->element[0] = 16;
			break;
		}
		case 66: {
			z->size = 1;
			z->element[0] = 17;
			break;
		}
		case 67: {
			z->size = 1;
			z->element[0] = 18;
			break;
		}
		case 68: {
			z->size = 1;
			z->element[0] = 19;
			break;
		}
		case 69: {
			z->size = 1;
			z->element[0] = 20;
			break;
		}
		case 70: {
			z->size = 1;
			z->element[0] = 21;
			break;
		}
		case 71: {
			z->size = 1;
			z->element[0] = 22;
			break;
		}
		case 72: {
			z->size = 1;
			z->element[0] = 23;
			break;
		}
		case 73: {
			z->size = 1;
			z->element[0] = 24;
			break;
		}
		case 74: {
			z->size = 1;
			z->element[0] = 25;
			break;
		}
		case 75: {
			z->size = 1;
			z->element[0] = 26;
			break;
		}
		case 76: {
			z->size = 1;
			z->element[0] = 27;
			break;
		}
		case 77: {
			z->size = 1;
			z->element[0] = 28;
			break;
		}
		case 78: {
			z->size = 1;
			z->element[0] = 29;
			break;
		}
		case 79: {
			z->size = 1;
			z->element[0] = 30;
			break;
		}
		case 80: {
			z->size = 1;
			z->element[0] = 31;
			break;
		}
		case 81: {
			z->size = 1;
			z->element[0] = 32;
			break;
		}
		case 82: {
			z->size = 1;
			z->element[0] = 33;
			break;
		}
		case 83: {
			z->size = 1;
			z->element[0] = 34;
			break;
		}
		case 84: {
			z->size = 1;
			z->element[0] = 35;
			break;
		}
		case 85: {
			z->size = 1;
			z->element[0] = 36;
			break;
		}
		case 86: {
			z->size = 1;
			z->element[0] = 37;
			break;
		}
		case 87: {
			z->size = 1;
			z->element[0] = 38;
			break;
		}
		case 88: {
			z->size = 1;
			z->element[0] = 39;
			break;
		}
		case 89: {
			z->size = 1;
			z->element[0] = 40;
			break;
		}
		case 90: {
			z->size = 1;
			z->element[0] = 41;
			break;
		}
		case 91: {
			z->size = 1;
			z->element[0] = 42;
			break;
		}
		case 92: {
			z->size = 1;
			z->element[0] = 43;
			break;
		}
		case 93: {
			z->size = 1;
			z->element[0] = 44;
			break;
		}
		case 94: {
			z->size = 1;
			z->element[0] = 45;
			break;
		}
		case 95: {
			z->size = 1;
			z->element[0] = 46;
			break;
		}
		case 96: {
			z->size = 1;
			z->element[0] = 47;
			break;
		}
		case 97: {
			z->size = 1;
			z->element[0] = 48;
			break;
		}
		default: z->size = 0; break;
	}
}

#endif
