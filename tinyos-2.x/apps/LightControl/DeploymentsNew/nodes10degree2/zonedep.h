#ifndef _ZONE_DEP_H_
#define _ZONE_DEP_H_

void set_zone(zone_intset_t *z) {
	switch (TOS_NODE_ID) {
		case 0: {
			z->size = 3;
			z->element[0] = 0;
			z->element[1] = 1;
			z->element[2] = 10;
			break;
		}
		case 1: {
			z->size = 4;
			z->element[0] = 0;
			z->element[1] = 1;
			z->element[2] = 2;
			z->element[3] = 11;
			break;
		}
		case 2: {
			z->size = 4;
			z->element[0] = 1;
			z->element[1] = 2;
			z->element[2] = 3;
			z->element[3] = 12;
			break;
		}
		case 3: {
			z->size = 4;
			z->element[0] = 2;
			z->element[1] = 3;
			z->element[2] = 4;
			z->element[3] = 13;
			break;
		}
		case 4: {
			z->size = 4;
			z->element[0] = 3;
			z->element[1] = 4;
			z->element[2] = 5;
			z->element[3] = 14;
			break;
		}
		case 5: {
			z->size = 4;
			z->element[0] = 4;
			z->element[1] = 5;
			z->element[2] = 6;
			z->element[3] = 15;
			break;
		}
		case 6: {
			z->size = 4;
			z->element[0] = 5;
			z->element[1] = 6;
			z->element[2] = 7;
			z->element[3] = 16;
			break;
		}
		case 7: {
			z->size = 4;
			z->element[0] = 6;
			z->element[1] = 7;
			z->element[2] = 8;
			z->element[3] = 17;
			break;
		}
		case 8: {
			z->size = 4;
			z->element[0] = 7;
			z->element[1] = 8;
			z->element[2] = 9;
			z->element[3] = 18;
			break;
		}
		case 9: {
			z->size = 3;
			z->element[0] = 8;
			z->element[1] = 9;
			z->element[2] = 19;
			break;
		}
		case 10: {
			z->size = 4;
			z->element[0] = 0;
			z->element[1] = 10;
			z->element[2] = 11;
			z->element[3] = 20;
			break;
		}
		case 11: {
			z->size = 5;
			z->element[0] = 1;
			z->element[1] = 10;
			z->element[2] = 11;
			z->element[3] = 12;
			z->element[4] = 21;
			break;
		}
		case 12: {
			z->size = 5;
			z->element[0] = 2;
			z->element[1] = 11;
			z->element[2] = 12;
			z->element[3] = 13;
			z->element[4] = 22;
			break;
		}
		case 13: {
			z->size = 5;
			z->element[0] = 3;
			z->element[1] = 12;
			z->element[2] = 13;
			z->element[3] = 14;
			z->element[4] = 23;
			break;
		}
		case 14: {
			z->size = 5;
			z->element[0] = 4;
			z->element[1] = 13;
			z->element[2] = 14;
			z->element[3] = 15;
			z->element[4] = 24;
			break;
		}
		case 15: {
			z->size = 5;
			z->element[0] = 5;
			z->element[1] = 14;
			z->element[2] = 15;
			z->element[3] = 16;
			z->element[4] = 25;
			break;
		}
		case 16: {
			z->size = 5;
			z->element[0] = 6;
			z->element[1] = 15;
			z->element[2] = 16;
			z->element[3] = 17;
			z->element[4] = 26;
			break;
		}
		case 17: {
			z->size = 5;
			z->element[0] = 7;
			z->element[1] = 16;
			z->element[2] = 17;
			z->element[3] = 18;
			z->element[4] = 27;
			break;
		}
		case 18: {
			z->size = 5;
			z->element[0] = 8;
			z->element[1] = 17;
			z->element[2] = 18;
			z->element[3] = 19;
			z->element[4] = 28;
			break;
		}
		case 19: {
			z->size = 4;
			z->element[0] = 9;
			z->element[1] = 18;
			z->element[2] = 19;
			z->element[3] = 29;
			break;
		}
		case 20: {
			z->size = 4;
			z->element[0] = 10;
			z->element[1] = 20;
			z->element[2] = 21;
			z->element[3] = 30;
			break;
		}
		case 21: {
			z->size = 5;
			z->element[0] = 11;
			z->element[1] = 20;
			z->element[2] = 21;
			z->element[3] = 22;
			z->element[4] = 31;
			break;
		}
		case 22: {
			z->size = 5;
			z->element[0] = 12;
			z->element[1] = 21;
			z->element[2] = 22;
			z->element[3] = 23;
			z->element[4] = 32;
			break;
		}
		case 23: {
			z->size = 5;
			z->element[0] = 13;
			z->element[1] = 22;
			z->element[2] = 23;
			z->element[3] = 24;
			z->element[4] = 33;
			break;
		}
		case 24: {
			z->size = 5;
			z->element[0] = 14;
			z->element[1] = 23;
			z->element[2] = 24;
			z->element[3] = 25;
			z->element[4] = 34;
			break;
		}
		case 25: {
			z->size = 5;
			z->element[0] = 15;
			z->element[1] = 24;
			z->element[2] = 25;
			z->element[3] = 26;
			z->element[4] = 35;
			break;
		}
		case 26: {
			z->size = 5;
			z->element[0] = 16;
			z->element[1] = 25;
			z->element[2] = 26;
			z->element[3] = 27;
			z->element[4] = 36;
			break;
		}
		case 27: {
			z->size = 5;
			z->element[0] = 17;
			z->element[1] = 26;
			z->element[2] = 27;
			z->element[3] = 28;
			z->element[4] = 37;
			break;
		}
		case 28: {
			z->size = 5;
			z->element[0] = 18;
			z->element[1] = 27;
			z->element[2] = 28;
			z->element[3] = 29;
			z->element[4] = 38;
			break;
		}
		case 29: {
			z->size = 4;
			z->element[0] = 19;
			z->element[1] = 28;
			z->element[2] = 29;
			z->element[3] = 39;
			break;
		}
		case 30: {
			z->size = 4;
			z->element[0] = 20;
			z->element[1] = 30;
			z->element[2] = 31;
			z->element[3] = 40;
			break;
		}
		case 31: {
			z->size = 5;
			z->element[0] = 21;
			z->element[1] = 30;
			z->element[2] = 31;
			z->element[3] = 32;
			z->element[4] = 41;
			break;
		}
		case 32: {
			z->size = 5;
			z->element[0] = 22;
			z->element[1] = 31;
			z->element[2] = 32;
			z->element[3] = 33;
			z->element[4] = 42;
			break;
		}
		case 33: {
			z->size = 5;
			z->element[0] = 23;
			z->element[1] = 32;
			z->element[2] = 33;
			z->element[3] = 34;
			z->element[4] = 43;
			break;
		}
		case 34: {
			z->size = 5;
			z->element[0] = 24;
			z->element[1] = 33;
			z->element[2] = 34;
			z->element[3] = 35;
			z->element[4] = 44;
			break;
		}
		case 35: {
			z->size = 5;
			z->element[0] = 25;
			z->element[1] = 34;
			z->element[2] = 35;
			z->element[3] = 36;
			z->element[4] = 45;
			break;
		}
		case 36: {
			z->size = 5;
			z->element[0] = 26;
			z->element[1] = 35;
			z->element[2] = 36;
			z->element[3] = 37;
			z->element[4] = 46;
			break;
		}
		case 37: {
			z->size = 5;
			z->element[0] = 27;
			z->element[1] = 36;
			z->element[2] = 37;
			z->element[3] = 38;
			z->element[4] = 47;
			break;
		}
		case 38: {
			z->size = 5;
			z->element[0] = 28;
			z->element[1] = 37;
			z->element[2] = 38;
			z->element[3] = 39;
			z->element[4] = 48;
			break;
		}
		case 39: {
			z->size = 4;
			z->element[0] = 29;
			z->element[1] = 38;
			z->element[2] = 39;
			z->element[3] = 49;
			break;
		}
		case 40: {
			z->size = 4;
			z->element[0] = 30;
			z->element[1] = 40;
			z->element[2] = 41;
			z->element[3] = 50;
			break;
		}
		case 41: {
			z->size = 5;
			z->element[0] = 31;
			z->element[1] = 40;
			z->element[2] = 41;
			z->element[3] = 42;
			z->element[4] = 51;
			break;
		}
		case 42: {
			z->size = 5;
			z->element[0] = 32;
			z->element[1] = 41;
			z->element[2] = 42;
			z->element[3] = 43;
			z->element[4] = 52;
			break;
		}
		case 43: {
			z->size = 5;
			z->element[0] = 33;
			z->element[1] = 42;
			z->element[2] = 43;
			z->element[3] = 44;
			z->element[4] = 53;
			break;
		}
		case 44: {
			z->size = 5;
			z->element[0] = 34;
			z->element[1] = 43;
			z->element[2] = 44;
			z->element[3] = 45;
			z->element[4] = 54;
			break;
		}
		case 45: {
			z->size = 5;
			z->element[0] = 35;
			z->element[1] = 44;
			z->element[2] = 45;
			z->element[3] = 46;
			z->element[4] = 55;
			break;
		}
		case 46: {
			z->size = 5;
			z->element[0] = 36;
			z->element[1] = 45;
			z->element[2] = 46;
			z->element[3] = 47;
			z->element[4] = 56;
			break;
		}
		case 47: {
			z->size = 5;
			z->element[0] = 37;
			z->element[1] = 46;
			z->element[2] = 47;
			z->element[3] = 48;
			z->element[4] = 57;
			break;
		}
		case 48: {
			z->size = 5;
			z->element[0] = 38;
			z->element[1] = 47;
			z->element[2] = 48;
			z->element[3] = 49;
			z->element[4] = 58;
			break;
		}
		case 49: {
			z->size = 4;
			z->element[0] = 39;
			z->element[1] = 48;
			z->element[2] = 49;
			z->element[3] = 59;
			break;
		}
		case 50: {
			z->size = 4;
			z->element[0] = 40;
			z->element[1] = 50;
			z->element[2] = 51;
			z->element[3] = 60;
			break;
		}
		case 51: {
			z->size = 5;
			z->element[0] = 41;
			z->element[1] = 50;
			z->element[2] = 51;
			z->element[3] = 52;
			z->element[4] = 61;
			break;
		}
		case 52: {
			z->size = 5;
			z->element[0] = 42;
			z->element[1] = 51;
			z->element[2] = 52;
			z->element[3] = 53;
			z->element[4] = 62;
			break;
		}
		case 53: {
			z->size = 5;
			z->element[0] = 43;
			z->element[1] = 52;
			z->element[2] = 53;
			z->element[3] = 54;
			z->element[4] = 63;
			break;
		}
		case 54: {
			z->size = 5;
			z->element[0] = 44;
			z->element[1] = 53;
			z->element[2] = 54;
			z->element[3] = 55;
			z->element[4] = 64;
			break;
		}
		case 55: {
			z->size = 5;
			z->element[0] = 45;
			z->element[1] = 54;
			z->element[2] = 55;
			z->element[3] = 56;
			z->element[4] = 65;
			break;
		}
		case 56: {
			z->size = 5;
			z->element[0] = 46;
			z->element[1] = 55;
			z->element[2] = 56;
			z->element[3] = 57;
			z->element[4] = 66;
			break;
		}
		case 57: {
			z->size = 5;
			z->element[0] = 47;
			z->element[1] = 56;
			z->element[2] = 57;
			z->element[3] = 58;
			z->element[4] = 67;
			break;
		}
		case 58: {
			z->size = 5;
			z->element[0] = 48;
			z->element[1] = 57;
			z->element[2] = 58;
			z->element[3] = 59;
			z->element[4] = 68;
			break;
		}
		case 59: {
			z->size = 4;
			z->element[0] = 49;
			z->element[1] = 58;
			z->element[2] = 59;
			z->element[3] = 69;
			break;
		}
		case 60: {
			z->size = 4;
			z->element[0] = 50;
			z->element[1] = 60;
			z->element[2] = 61;
			z->element[3] = 70;
			break;
		}
		case 61: {
			z->size = 5;
			z->element[0] = 51;
			z->element[1] = 60;
			z->element[2] = 61;
			z->element[3] = 62;
			z->element[4] = 71;
			break;
		}
		case 62: {
			z->size = 5;
			z->element[0] = 52;
			z->element[1] = 61;
			z->element[2] = 62;
			z->element[3] = 63;
			z->element[4] = 72;
			break;
		}
		case 63: {
			z->size = 5;
			z->element[0] = 53;
			z->element[1] = 62;
			z->element[2] = 63;
			z->element[3] = 64;
			z->element[4] = 73;
			break;
		}
		case 64: {
			z->size = 5;
			z->element[0] = 54;
			z->element[1] = 63;
			z->element[2] = 64;
			z->element[3] = 65;
			z->element[4] = 74;
			break;
		}
		case 65: {
			z->size = 5;
			z->element[0] = 55;
			z->element[1] = 64;
			z->element[2] = 65;
			z->element[3] = 66;
			z->element[4] = 75;
			break;
		}
		case 66: {
			z->size = 5;
			z->element[0] = 56;
			z->element[1] = 65;
			z->element[2] = 66;
			z->element[3] = 67;
			z->element[4] = 76;
			break;
		}
		case 67: {
			z->size = 5;
			z->element[0] = 57;
			z->element[1] = 66;
			z->element[2] = 67;
			z->element[3] = 68;
			z->element[4] = 77;
			break;
		}
		case 68: {
			z->size = 5;
			z->element[0] = 58;
			z->element[1] = 67;
			z->element[2] = 68;
			z->element[3] = 69;
			z->element[4] = 78;
			break;
		}
		case 69: {
			z->size = 4;
			z->element[0] = 59;
			z->element[1] = 68;
			z->element[2] = 69;
			z->element[3] = 79;
			break;
		}
		case 70: {
			z->size = 4;
			z->element[0] = 60;
			z->element[1] = 70;
			z->element[2] = 71;
			z->element[3] = 80;
			break;
		}
		case 71: {
			z->size = 5;
			z->element[0] = 61;
			z->element[1] = 70;
			z->element[2] = 71;
			z->element[3] = 72;
			z->element[4] = 81;
			break;
		}
		case 72: {
			z->size = 5;
			z->element[0] = 62;
			z->element[1] = 71;
			z->element[2] = 72;
			z->element[3] = 73;
			z->element[4] = 82;
			break;
		}
		case 73: {
			z->size = 5;
			z->element[0] = 63;
			z->element[1] = 72;
			z->element[2] = 73;
			z->element[3] = 74;
			z->element[4] = 83;
			break;
		}
		case 74: {
			z->size = 5;
			z->element[0] = 64;
			z->element[1] = 73;
			z->element[2] = 74;
			z->element[3] = 75;
			z->element[4] = 84;
			break;
		}
		case 75: {
			z->size = 5;
			z->element[0] = 65;
			z->element[1] = 74;
			z->element[2] = 75;
			z->element[3] = 76;
			z->element[4] = 85;
			break;
		}
		case 76: {
			z->size = 5;
			z->element[0] = 66;
			z->element[1] = 75;
			z->element[2] = 76;
			z->element[3] = 77;
			z->element[4] = 86;
			break;
		}
		case 77: {
			z->size = 5;
			z->element[0] = 67;
			z->element[1] = 76;
			z->element[2] = 77;
			z->element[3] = 78;
			z->element[4] = 87;
			break;
		}
		case 78: {
			z->size = 5;
			z->element[0] = 68;
			z->element[1] = 77;
			z->element[2] = 78;
			z->element[3] = 79;
			z->element[4] = 88;
			break;
		}
		case 79: {
			z->size = 4;
			z->element[0] = 69;
			z->element[1] = 78;
			z->element[2] = 79;
			z->element[3] = 89;
			break;
		}
		case 80: {
			z->size = 4;
			z->element[0] = 70;
			z->element[1] = 80;
			z->element[2] = 81;
			z->element[3] = 90;
			break;
		}
		case 81: {
			z->size = 5;
			z->element[0] = 71;
			z->element[1] = 80;
			z->element[2] = 81;
			z->element[3] = 82;
			z->element[4] = 91;
			break;
		}
		case 82: {
			z->size = 5;
			z->element[0] = 72;
			z->element[1] = 81;
			z->element[2] = 82;
			z->element[3] = 83;
			z->element[4] = 92;
			break;
		}
		case 83: {
			z->size = 5;
			z->element[0] = 73;
			z->element[1] = 82;
			z->element[2] = 83;
			z->element[3] = 84;
			z->element[4] = 93;
			break;
		}
		case 84: {
			z->size = 5;
			z->element[0] = 74;
			z->element[1] = 83;
			z->element[2] = 84;
			z->element[3] = 85;
			z->element[4] = 94;
			break;
		}
		case 85: {
			z->size = 5;
			z->element[0] = 75;
			z->element[1] = 84;
			z->element[2] = 85;
			z->element[3] = 86;
			z->element[4] = 95;
			break;
		}
		case 86: {
			z->size = 5;
			z->element[0] = 76;
			z->element[1] = 85;
			z->element[2] = 86;
			z->element[3] = 87;
			z->element[4] = 96;
			break;
		}
		case 87: {
			z->size = 5;
			z->element[0] = 77;
			z->element[1] = 86;
			z->element[2] = 87;
			z->element[3] = 88;
			z->element[4] = 97;
			break;
		}
		case 88: {
			z->size = 5;
			z->element[0] = 78;
			z->element[1] = 87;
			z->element[2] = 88;
			z->element[3] = 89;
			z->element[4] = 98;
			break;
		}
		case 89: {
			z->size = 4;
			z->element[0] = 79;
			z->element[1] = 88;
			z->element[2] = 89;
			z->element[3] = 99;
			break;
		}
		case 90: {
			z->size = 3;
			z->element[0] = 80;
			z->element[1] = 90;
			z->element[2] = 91;
			break;
		}
		case 91: {
			z->size = 4;
			z->element[0] = 81;
			z->element[1] = 90;
			z->element[2] = 91;
			z->element[3] = 92;
			break;
		}
		case 92: {
			z->size = 4;
			z->element[0] = 82;
			z->element[1] = 91;
			z->element[2] = 92;
			z->element[3] = 93;
			break;
		}
		case 93: {
			z->size = 4;
			z->element[0] = 83;
			z->element[1] = 92;
			z->element[2] = 93;
			z->element[3] = 94;
			break;
		}
		case 94: {
			z->size = 4;
			z->element[0] = 84;
			z->element[1] = 93;
			z->element[2] = 94;
			z->element[3] = 95;
			break;
		}
		case 95: {
			z->size = 4;
			z->element[0] = 85;
			z->element[1] = 94;
			z->element[2] = 95;
			z->element[3] = 96;
			break;
		}
		case 96: {
			z->size = 4;
			z->element[0] = 86;
			z->element[1] = 95;
			z->element[2] = 96;
			z->element[3] = 97;
			break;
		}
		case 97: {
			z->size = 4;
			z->element[0] = 87;
			z->element[1] = 96;
			z->element[2] = 97;
			z->element[3] = 98;
			break;
		}
		case 98: {
			z->size = 4;
			z->element[0] = 88;
			z->element[1] = 97;
			z->element[2] = 98;
			z->element[3] = 99;
			break;
		}
		case 99: {
			z->size = 3;
			z->element[0] = 89;
			z->element[1] = 98;
			z->element[2] = 99;
			break;
		}
		case 100: {
			z->size = 1;
			z->element[0] = 0;
			break;
		}
		case 101: {
			z->size = 1;
			z->element[0] = 1;
			break;
		}
		case 102: {
			z->size = 1;
			z->element[0] = 2;
			break;
		}
		case 103: {
			z->size = 1;
			z->element[0] = 3;
			break;
		}
		case 104: {
			z->size = 1;
			z->element[0] = 4;
			break;
		}
		case 105: {
			z->size = 1;
			z->element[0] = 5;
			break;
		}
		case 106: {
			z->size = 1;
			z->element[0] = 6;
			break;
		}
		case 107: {
			z->size = 1;
			z->element[0] = 7;
			break;
		}
		case 108: {
			z->size = 1;
			z->element[0] = 8;
			break;
		}
		case 109: {
			z->size = 1;
			z->element[0] = 9;
			break;
		}
		case 110: {
			z->size = 1;
			z->element[0] = 10;
			break;
		}
		case 111: {
			z->size = 1;
			z->element[0] = 11;
			break;
		}
		case 112: {
			z->size = 1;
			z->element[0] = 12;
			break;
		}
		case 113: {
			z->size = 1;
			z->element[0] = 13;
			break;
		}
		case 114: {
			z->size = 1;
			z->element[0] = 14;
			break;
		}
		case 115: {
			z->size = 1;
			z->element[0] = 15;
			break;
		}
		case 116: {
			z->size = 1;
			z->element[0] = 16;
			break;
		}
		case 117: {
			z->size = 1;
			z->element[0] = 17;
			break;
		}
		case 118: {
			z->size = 1;
			z->element[0] = 18;
			break;
		}
		case 119: {
			z->size = 1;
			z->element[0] = 19;
			break;
		}
		case 120: {
			z->size = 1;
			z->element[0] = 20;
			break;
		}
		case 121: {
			z->size = 1;
			z->element[0] = 21;
			break;
		}
		case 122: {
			z->size = 1;
			z->element[0] = 22;
			break;
		}
		case 123: {
			z->size = 1;
			z->element[0] = 23;
			break;
		}
		case 124: {
			z->size = 1;
			z->element[0] = 24;
			break;
		}
		case 125: {
			z->size = 1;
			z->element[0] = 25;
			break;
		}
		case 126: {
			z->size = 1;
			z->element[0] = 26;
			break;
		}
		case 127: {
			z->size = 1;
			z->element[0] = 27;
			break;
		}
		case 128: {
			z->size = 1;
			z->element[0] = 28;
			break;
		}
		case 129: {
			z->size = 1;
			z->element[0] = 29;
			break;
		}
		case 130: {
			z->size = 1;
			z->element[0] = 30;
			break;
		}
		case 131: {
			z->size = 1;
			z->element[0] = 31;
			break;
		}
		case 132: {
			z->size = 1;
			z->element[0] = 32;
			break;
		}
		case 133: {
			z->size = 1;
			z->element[0] = 33;
			break;
		}
		case 134: {
			z->size = 1;
			z->element[0] = 34;
			break;
		}
		case 135: {
			z->size = 1;
			z->element[0] = 35;
			break;
		}
		case 136: {
			z->size = 1;
			z->element[0] = 36;
			break;
		}
		case 137: {
			z->size = 1;
			z->element[0] = 37;
			break;
		}
		case 138: {
			z->size = 1;
			z->element[0] = 38;
			break;
		}
		case 139: {
			z->size = 1;
			z->element[0] = 39;
			break;
		}
		case 140: {
			z->size = 1;
			z->element[0] = 40;
			break;
		}
		case 141: {
			z->size = 1;
			z->element[0] = 41;
			break;
		}
		case 142: {
			z->size = 1;
			z->element[0] = 42;
			break;
		}
		case 143: {
			z->size = 1;
			z->element[0] = 43;
			break;
		}
		case 144: {
			z->size = 1;
			z->element[0] = 44;
			break;
		}
		case 145: {
			z->size = 1;
			z->element[0] = 45;
			break;
		}
		case 146: {
			z->size = 1;
			z->element[0] = 46;
			break;
		}
		case 147: {
			z->size = 1;
			z->element[0] = 47;
			break;
		}
		case 148: {
			z->size = 1;
			z->element[0] = 48;
			break;
		}
		case 149: {
			z->size = 1;
			z->element[0] = 49;
			break;
		}
		case 150: {
			z->size = 1;
			z->element[0] = 50;
			break;
		}
		case 151: {
			z->size = 1;
			z->element[0] = 51;
			break;
		}
		case 152: {
			z->size = 1;
			z->element[0] = 52;
			break;
		}
		case 153: {
			z->size = 1;
			z->element[0] = 53;
			break;
		}
		case 154: {
			z->size = 1;
			z->element[0] = 54;
			break;
		}
		case 155: {
			z->size = 1;
			z->element[0] = 55;
			break;
		}
		case 156: {
			z->size = 1;
			z->element[0] = 56;
			break;
		}
		case 157: {
			z->size = 1;
			z->element[0] = 57;
			break;
		}
		case 158: {
			z->size = 1;
			z->element[0] = 58;
			break;
		}
		case 159: {
			z->size = 1;
			z->element[0] = 59;
			break;
		}
		case 160: {
			z->size = 1;
			z->element[0] = 60;
			break;
		}
		case 161: {
			z->size = 1;
			z->element[0] = 61;
			break;
		}
		case 162: {
			z->size = 1;
			z->element[0] = 62;
			break;
		}
		case 163: {
			z->size = 1;
			z->element[0] = 63;
			break;
		}
		case 164: {
			z->size = 1;
			z->element[0] = 64;
			break;
		}
		case 165: {
			z->size = 1;
			z->element[0] = 65;
			break;
		}
		case 166: {
			z->size = 1;
			z->element[0] = 66;
			break;
		}
		case 167: {
			z->size = 1;
			z->element[0] = 67;
			break;
		}
		case 168: {
			z->size = 1;
			z->element[0] = 68;
			break;
		}
		case 169: {
			z->size = 1;
			z->element[0] = 69;
			break;
		}
		case 170: {
			z->size = 1;
			z->element[0] = 70;
			break;
		}
		case 171: {
			z->size = 1;
			z->element[0] = 71;
			break;
		}
		case 172: {
			z->size = 1;
			z->element[0] = 72;
			break;
		}
		case 173: {
			z->size = 1;
			z->element[0] = 73;
			break;
		}
		case 174: {
			z->size = 1;
			z->element[0] = 74;
			break;
		}
		case 175: {
			z->size = 1;
			z->element[0] = 75;
			break;
		}
		case 176: {
			z->size = 1;
			z->element[0] = 76;
			break;
		}
		case 177: {
			z->size = 1;
			z->element[0] = 77;
			break;
		}
		case 178: {
			z->size = 1;
			z->element[0] = 78;
			break;
		}
		case 179: {
			z->size = 1;
			z->element[0] = 79;
			break;
		}
		case 180: {
			z->size = 1;
			z->element[0] = 80;
			break;
		}
		case 181: {
			z->size = 1;
			z->element[0] = 81;
			break;
		}
		case 182: {
			z->size = 1;
			z->element[0] = 82;
			break;
		}
		case 183: {
			z->size = 1;
			z->element[0] = 83;
			break;
		}
		case 184: {
			z->size = 1;
			z->element[0] = 84;
			break;
		}
		case 185: {
			z->size = 1;
			z->element[0] = 85;
			break;
		}
		case 186: {
			z->size = 1;
			z->element[0] = 86;
			break;
		}
		case 187: {
			z->size = 1;
			z->element[0] = 87;
			break;
		}
		case 188: {
			z->size = 1;
			z->element[0] = 88;
			break;
		}
		case 189: {
			z->size = 1;
			z->element[0] = 89;
			break;
		}
		case 190: {
			z->size = 1;
			z->element[0] = 90;
			break;
		}
		case 191: {
			z->size = 1;
			z->element[0] = 91;
			break;
		}
		case 192: {
			z->size = 1;
			z->element[0] = 92;
			break;
		}
		case 193: {
			z->size = 1;
			z->element[0] = 93;
			break;
		}
		case 194: {
			z->size = 1;
			z->element[0] = 94;
			break;
		}
		case 195: {
			z->size = 1;
			z->element[0] = 95;
			break;
		}
		case 196: {
			z->size = 1;
			z->element[0] = 96;
			break;
		}
		case 197: {
			z->size = 1;
			z->element[0] = 97;
			break;
		}
		case 198: {
			z->size = 1;
			z->element[0] = 98;
			break;
		}
		case 199: {
			z->size = 1;
			z->element[0] = 99;
			break;
		}
		default: z->size = 0; break;
	}
}

#endif
