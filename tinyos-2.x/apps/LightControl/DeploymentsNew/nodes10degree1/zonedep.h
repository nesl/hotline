#ifndef _ZONE_DEP_H_
#define _ZONE_DEP_H_

void set_zone(zone_intset_t *z) {
	switch (TOS_NODE_ID) {
		case 0: {
			z->size = 2;
			z->element[0] = 0;
			z->element[1] = 9;
			break;
		}
		case 1: {
			z->size = 3;
			z->element[0] = 0;
			z->element[1] = 1;
			z->element[2] = 10;
			break;
		}
		case 2: {
			z->size = 3;
			z->element[0] = 1;
			z->element[1] = 2;
			z->element[2] = 11;
			break;
		}
		case 3: {
			z->size = 3;
			z->element[0] = 2;
			z->element[1] = 3;
			z->element[2] = 12;
			break;
		}
		case 4: {
			z->size = 3;
			z->element[0] = 3;
			z->element[1] = 4;
			z->element[2] = 13;
			break;
		}
		case 5: {
			z->size = 3;
			z->element[0] = 4;
			z->element[1] = 5;
			z->element[2] = 14;
			break;
		}
		case 6: {
			z->size = 3;
			z->element[0] = 5;
			z->element[1] = 6;
			z->element[2] = 15;
			break;
		}
		case 7: {
			z->size = 3;
			z->element[0] = 6;
			z->element[1] = 7;
			z->element[2] = 16;
			break;
		}
		case 8: {
			z->size = 3;
			z->element[0] = 7;
			z->element[1] = 8;
			z->element[2] = 17;
			break;
		}
		case 9: {
			z->size = 2;
			z->element[0] = 8;
			z->element[1] = 18;
			break;
		}
		case 10: {
			z->size = 3;
			z->element[0] = 9;
			z->element[1] = 19;
			z->element[2] = 28;
			break;
		}
		case 11: {
			z->size = 4;
			z->element[0] = 10;
			z->element[1] = 19;
			z->element[2] = 20;
			z->element[3] = 29;
			break;
		}
		case 12: {
			z->size = 4;
			z->element[0] = 11;
			z->element[1] = 20;
			z->element[2] = 21;
			z->element[3] = 30;
			break;
		}
		case 13: {
			z->size = 4;
			z->element[0] = 12;
			z->element[1] = 21;
			z->element[2] = 22;
			z->element[3] = 31;
			break;
		}
		case 14: {
			z->size = 4;
			z->element[0] = 13;
			z->element[1] = 22;
			z->element[2] = 23;
			z->element[3] = 32;
			break;
		}
		case 15: {
			z->size = 4;
			z->element[0] = 14;
			z->element[1] = 23;
			z->element[2] = 24;
			z->element[3] = 33;
			break;
		}
		case 16: {
			z->size = 4;
			z->element[0] = 15;
			z->element[1] = 24;
			z->element[2] = 25;
			z->element[3] = 34;
			break;
		}
		case 17: {
			z->size = 4;
			z->element[0] = 16;
			z->element[1] = 25;
			z->element[2] = 26;
			z->element[3] = 35;
			break;
		}
		case 18: {
			z->size = 4;
			z->element[0] = 17;
			z->element[1] = 26;
			z->element[2] = 27;
			z->element[3] = 36;
			break;
		}
		case 19: {
			z->size = 3;
			z->element[0] = 18;
			z->element[1] = 27;
			z->element[2] = 37;
			break;
		}
		case 20: {
			z->size = 3;
			z->element[0] = 28;
			z->element[1] = 38;
			z->element[2] = 47;
			break;
		}
		case 21: {
			z->size = 4;
			z->element[0] = 29;
			z->element[1] = 38;
			z->element[2] = 39;
			z->element[3] = 48;
			break;
		}
		case 22: {
			z->size = 4;
			z->element[0] = 30;
			z->element[1] = 39;
			z->element[2] = 40;
			z->element[3] = 49;
			break;
		}
		case 23: {
			z->size = 4;
			z->element[0] = 31;
			z->element[1] = 40;
			z->element[2] = 41;
			z->element[3] = 50;
			break;
		}
		case 24: {
			z->size = 4;
			z->element[0] = 32;
			z->element[1] = 41;
			z->element[2] = 42;
			z->element[3] = 51;
			break;
		}
		case 25: {
			z->size = 4;
			z->element[0] = 33;
			z->element[1] = 42;
			z->element[2] = 43;
			z->element[3] = 52;
			break;
		}
		case 26: {
			z->size = 4;
			z->element[0] = 34;
			z->element[1] = 43;
			z->element[2] = 44;
			z->element[3] = 53;
			break;
		}
		case 27: {
			z->size = 4;
			z->element[0] = 35;
			z->element[1] = 44;
			z->element[2] = 45;
			z->element[3] = 54;
			break;
		}
		case 28: {
			z->size = 4;
			z->element[0] = 36;
			z->element[1] = 45;
			z->element[2] = 46;
			z->element[3] = 55;
			break;
		}
		case 29: {
			z->size = 3;
			z->element[0] = 37;
			z->element[1] = 46;
			z->element[2] = 56;
			break;
		}
		case 30: {
			z->size = 3;
			z->element[0] = 47;
			z->element[1] = 57;
			z->element[2] = 66;
			break;
		}
		case 31: {
			z->size = 4;
			z->element[0] = 48;
			z->element[1] = 57;
			z->element[2] = 58;
			z->element[3] = 67;
			break;
		}
		case 32: {
			z->size = 4;
			z->element[0] = 49;
			z->element[1] = 58;
			z->element[2] = 59;
			z->element[3] = 68;
			break;
		}
		case 33: {
			z->size = 4;
			z->element[0] = 50;
			z->element[1] = 59;
			z->element[2] = 60;
			z->element[3] = 69;
			break;
		}
		case 34: {
			z->size = 4;
			z->element[0] = 51;
			z->element[1] = 60;
			z->element[2] = 61;
			z->element[3] = 70;
			break;
		}
		case 35: {
			z->size = 4;
			z->element[0] = 52;
			z->element[1] = 61;
			z->element[2] = 62;
			z->element[3] = 71;
			break;
		}
		case 36: {
			z->size = 4;
			z->element[0] = 53;
			z->element[1] = 62;
			z->element[2] = 63;
			z->element[3] = 72;
			break;
		}
		case 37: {
			z->size = 4;
			z->element[0] = 54;
			z->element[1] = 63;
			z->element[2] = 64;
			z->element[3] = 73;
			break;
		}
		case 38: {
			z->size = 4;
			z->element[0] = 55;
			z->element[1] = 64;
			z->element[2] = 65;
			z->element[3] = 74;
			break;
		}
		case 39: {
			z->size = 3;
			z->element[0] = 56;
			z->element[1] = 65;
			z->element[2] = 75;
			break;
		}
		case 40: {
			z->size = 3;
			z->element[0] = 66;
			z->element[1] = 76;
			z->element[2] = 85;
			break;
		}
		case 41: {
			z->size = 4;
			z->element[0] = 67;
			z->element[1] = 76;
			z->element[2] = 77;
			z->element[3] = 86;
			break;
		}
		case 42: {
			z->size = 4;
			z->element[0] = 68;
			z->element[1] = 77;
			z->element[2] = 78;
			z->element[3] = 87;
			break;
		}
		case 43: {
			z->size = 4;
			z->element[0] = 69;
			z->element[1] = 78;
			z->element[2] = 79;
			z->element[3] = 88;
			break;
		}
		case 44: {
			z->size = 4;
			z->element[0] = 70;
			z->element[1] = 79;
			z->element[2] = 80;
			z->element[3] = 89;
			break;
		}
		case 45: {
			z->size = 4;
			z->element[0] = 71;
			z->element[1] = 80;
			z->element[2] = 81;
			z->element[3] = 90;
			break;
		}
		case 46: {
			z->size = 4;
			z->element[0] = 72;
			z->element[1] = 81;
			z->element[2] = 82;
			z->element[3] = 91;
			break;
		}
		case 47: {
			z->size = 4;
			z->element[0] = 73;
			z->element[1] = 82;
			z->element[2] = 83;
			z->element[3] = 92;
			break;
		}
		case 48: {
			z->size = 4;
			z->element[0] = 74;
			z->element[1] = 83;
			z->element[2] = 84;
			z->element[3] = 93;
			break;
		}
		case 49: {
			z->size = 3;
			z->element[0] = 75;
			z->element[1] = 84;
			z->element[2] = 94;
			break;
		}
		case 50: {
			z->size = 3;
			z->element[0] = 85;
			z->element[1] = 95;
			z->element[2] = 104;
			break;
		}
		case 51: {
			z->size = 4;
			z->element[0] = 86;
			z->element[1] = 95;
			z->element[2] = 96;
			z->element[3] = 105;
			break;
		}
		case 52: {
			z->size = 4;
			z->element[0] = 87;
			z->element[1] = 96;
			z->element[2] = 97;
			z->element[3] = 106;
			break;
		}
		case 53: {
			z->size = 4;
			z->element[0] = 88;
			z->element[1] = 97;
			z->element[2] = 98;
			z->element[3] = 107;
			break;
		}
		case 54: {
			z->size = 4;
			z->element[0] = 89;
			z->element[1] = 98;
			z->element[2] = 99;
			z->element[3] = 108;
			break;
		}
		case 55: {
			z->size = 4;
			z->element[0] = 90;
			z->element[1] = 99;
			z->element[2] = 100;
			z->element[3] = 109;
			break;
		}
		case 56: {
			z->size = 4;
			z->element[0] = 91;
			z->element[1] = 100;
			z->element[2] = 101;
			z->element[3] = 110;
			break;
		}
		case 57: {
			z->size = 4;
			z->element[0] = 92;
			z->element[1] = 101;
			z->element[2] = 102;
			z->element[3] = 111;
			break;
		}
		case 58: {
			z->size = 4;
			z->element[0] = 93;
			z->element[1] = 102;
			z->element[2] = 103;
			z->element[3] = 112;
			break;
		}
		case 59: {
			z->size = 3;
			z->element[0] = 94;
			z->element[1] = 103;
			z->element[2] = 113;
			break;
		}
		case 60: {
			z->size = 3;
			z->element[0] = 104;
			z->element[1] = 114;
			z->element[2] = 123;
			break;
		}
		case 61: {
			z->size = 4;
			z->element[0] = 105;
			z->element[1] = 114;
			z->element[2] = 115;
			z->element[3] = 124;
			break;
		}
		case 62: {
			z->size = 4;
			z->element[0] = 106;
			z->element[1] = 115;
			z->element[2] = 116;
			z->element[3] = 125;
			break;
		}
		case 63: {
			z->size = 4;
			z->element[0] = 107;
			z->element[1] = 116;
			z->element[2] = 117;
			z->element[3] = 126;
			break;
		}
		case 64: {
			z->size = 4;
			z->element[0] = 108;
			z->element[1] = 117;
			z->element[2] = 118;
			z->element[3] = 127;
			break;
		}
		case 65: {
			z->size = 4;
			z->element[0] = 109;
			z->element[1] = 118;
			z->element[2] = 119;
			z->element[3] = 128;
			break;
		}
		case 66: {
			z->size = 4;
			z->element[0] = 110;
			z->element[1] = 119;
			z->element[2] = 120;
			z->element[3] = 129;
			break;
		}
		case 67: {
			z->size = 4;
			z->element[0] = 111;
			z->element[1] = 120;
			z->element[2] = 121;
			z->element[3] = 130;
			break;
		}
		case 68: {
			z->size = 4;
			z->element[0] = 112;
			z->element[1] = 121;
			z->element[2] = 122;
			z->element[3] = 131;
			break;
		}
		case 69: {
			z->size = 3;
			z->element[0] = 113;
			z->element[1] = 122;
			z->element[2] = 132;
			break;
		}
		case 70: {
			z->size = 3;
			z->element[0] = 123;
			z->element[1] = 133;
			z->element[2] = 142;
			break;
		}
		case 71: {
			z->size = 4;
			z->element[0] = 124;
			z->element[1] = 133;
			z->element[2] = 134;
			z->element[3] = 143;
			break;
		}
		case 72: {
			z->size = 4;
			z->element[0] = 125;
			z->element[1] = 134;
			z->element[2] = 135;
			z->element[3] = 144;
			break;
		}
		case 73: {
			z->size = 4;
			z->element[0] = 126;
			z->element[1] = 135;
			z->element[2] = 136;
			z->element[3] = 145;
			break;
		}
		case 74: {
			z->size = 4;
			z->element[0] = 127;
			z->element[1] = 136;
			z->element[2] = 137;
			z->element[3] = 146;
			break;
		}
		case 75: {
			z->size = 4;
			z->element[0] = 128;
			z->element[1] = 137;
			z->element[2] = 138;
			z->element[3] = 147;
			break;
		}
		case 76: {
			z->size = 4;
			z->element[0] = 129;
			z->element[1] = 138;
			z->element[2] = 139;
			z->element[3] = 148;
			break;
		}
		case 77: {
			z->size = 4;
			z->element[0] = 130;
			z->element[1] = 139;
			z->element[2] = 140;
			z->element[3] = 149;
			break;
		}
		case 78: {
			z->size = 4;
			z->element[0] = 131;
			z->element[1] = 140;
			z->element[2] = 141;
			z->element[3] = 150;
			break;
		}
		case 79: {
			z->size = 3;
			z->element[0] = 132;
			z->element[1] = 141;
			z->element[2] = 151;
			break;
		}
		case 80: {
			z->size = 3;
			z->element[0] = 142;
			z->element[1] = 152;
			z->element[2] = 161;
			break;
		}
		case 81: {
			z->size = 4;
			z->element[0] = 143;
			z->element[1] = 152;
			z->element[2] = 153;
			z->element[3] = 162;
			break;
		}
		case 82: {
			z->size = 4;
			z->element[0] = 144;
			z->element[1] = 153;
			z->element[2] = 154;
			z->element[3] = 163;
			break;
		}
		case 83: {
			z->size = 4;
			z->element[0] = 145;
			z->element[1] = 154;
			z->element[2] = 155;
			z->element[3] = 164;
			break;
		}
		case 84: {
			z->size = 4;
			z->element[0] = 146;
			z->element[1] = 155;
			z->element[2] = 156;
			z->element[3] = 165;
			break;
		}
		case 85: {
			z->size = 4;
			z->element[0] = 147;
			z->element[1] = 156;
			z->element[2] = 157;
			z->element[3] = 166;
			break;
		}
		case 86: {
			z->size = 4;
			z->element[0] = 148;
			z->element[1] = 157;
			z->element[2] = 158;
			z->element[3] = 167;
			break;
		}
		case 87: {
			z->size = 4;
			z->element[0] = 149;
			z->element[1] = 158;
			z->element[2] = 159;
			z->element[3] = 168;
			break;
		}
		case 88: {
			z->size = 4;
			z->element[0] = 150;
			z->element[1] = 159;
			z->element[2] = 160;
			z->element[3] = 169;
			break;
		}
		case 89: {
			z->size = 3;
			z->element[0] = 151;
			z->element[1] = 160;
			z->element[2] = 170;
			break;
		}
		case 90: {
			z->size = 2;
			z->element[0] = 161;
			z->element[1] = 171;
			break;
		}
		case 91: {
			z->size = 3;
			z->element[0] = 162;
			z->element[1] = 171;
			z->element[2] = 172;
			break;
		}
		case 92: {
			z->size = 3;
			z->element[0] = 163;
			z->element[1] = 172;
			z->element[2] = 173;
			break;
		}
		case 93: {
			z->size = 3;
			z->element[0] = 164;
			z->element[1] = 173;
			z->element[2] = 174;
			break;
		}
		case 94: {
			z->size = 3;
			z->element[0] = 165;
			z->element[1] = 174;
			z->element[2] = 175;
			break;
		}
		case 95: {
			z->size = 3;
			z->element[0] = 166;
			z->element[1] = 175;
			z->element[2] = 176;
			break;
		}
		case 96: {
			z->size = 3;
			z->element[0] = 167;
			z->element[1] = 176;
			z->element[2] = 177;
			break;
		}
		case 97: {
			z->size = 3;
			z->element[0] = 168;
			z->element[1] = 177;
			z->element[2] = 178;
			break;
		}
		case 98: {
			z->size = 3;
			z->element[0] = 169;
			z->element[1] = 178;
			z->element[2] = 179;
			break;
		}
		case 99: {
			z->size = 2;
			z->element[0] = 170;
			z->element[1] = 179;
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
		case 200: {
			z->size = 1;
			z->element[0] = 100;
			break;
		}
		case 201: {
			z->size = 1;
			z->element[0] = 101;
			break;
		}
		case 202: {
			z->size = 1;
			z->element[0] = 102;
			break;
		}
		case 203: {
			z->size = 1;
			z->element[0] = 103;
			break;
		}
		case 204: {
			z->size = 1;
			z->element[0] = 104;
			break;
		}
		case 205: {
			z->size = 1;
			z->element[0] = 105;
			break;
		}
		case 206: {
			z->size = 1;
			z->element[0] = 106;
			break;
		}
		case 207: {
			z->size = 1;
			z->element[0] = 107;
			break;
		}
		case 208: {
			z->size = 1;
			z->element[0] = 108;
			break;
		}
		case 209: {
			z->size = 1;
			z->element[0] = 109;
			break;
		}
		case 210: {
			z->size = 1;
			z->element[0] = 110;
			break;
		}
		case 211: {
			z->size = 1;
			z->element[0] = 111;
			break;
		}
		case 212: {
			z->size = 1;
			z->element[0] = 112;
			break;
		}
		case 213: {
			z->size = 1;
			z->element[0] = 113;
			break;
		}
		case 214: {
			z->size = 1;
			z->element[0] = 114;
			break;
		}
		case 215: {
			z->size = 1;
			z->element[0] = 115;
			break;
		}
		case 216: {
			z->size = 1;
			z->element[0] = 116;
			break;
		}
		case 217: {
			z->size = 1;
			z->element[0] = 117;
			break;
		}
		case 218: {
			z->size = 1;
			z->element[0] = 118;
			break;
		}
		case 219: {
			z->size = 1;
			z->element[0] = 119;
			break;
		}
		case 220: {
			z->size = 1;
			z->element[0] = 120;
			break;
		}
		case 221: {
			z->size = 1;
			z->element[0] = 121;
			break;
		}
		case 222: {
			z->size = 1;
			z->element[0] = 122;
			break;
		}
		case 223: {
			z->size = 1;
			z->element[0] = 123;
			break;
		}
		case 224: {
			z->size = 1;
			z->element[0] = 124;
			break;
		}
		case 225: {
			z->size = 1;
			z->element[0] = 125;
			break;
		}
		case 226: {
			z->size = 1;
			z->element[0] = 126;
			break;
		}
		case 227: {
			z->size = 1;
			z->element[0] = 127;
			break;
		}
		case 228: {
			z->size = 1;
			z->element[0] = 128;
			break;
		}
		case 229: {
			z->size = 1;
			z->element[0] = 129;
			break;
		}
		case 230: {
			z->size = 1;
			z->element[0] = 130;
			break;
		}
		case 231: {
			z->size = 1;
			z->element[0] = 131;
			break;
		}
		case 232: {
			z->size = 1;
			z->element[0] = 132;
			break;
		}
		case 233: {
			z->size = 1;
			z->element[0] = 133;
			break;
		}
		case 234: {
			z->size = 1;
			z->element[0] = 134;
			break;
		}
		case 235: {
			z->size = 1;
			z->element[0] = 135;
			break;
		}
		case 236: {
			z->size = 1;
			z->element[0] = 136;
			break;
		}
		case 237: {
			z->size = 1;
			z->element[0] = 137;
			break;
		}
		case 238: {
			z->size = 1;
			z->element[0] = 138;
			break;
		}
		case 239: {
			z->size = 1;
			z->element[0] = 139;
			break;
		}
		case 240: {
			z->size = 1;
			z->element[0] = 140;
			break;
		}
		case 241: {
			z->size = 1;
			z->element[0] = 141;
			break;
		}
		case 242: {
			z->size = 1;
			z->element[0] = 142;
			break;
		}
		case 243: {
			z->size = 1;
			z->element[0] = 143;
			break;
		}
		case 244: {
			z->size = 1;
			z->element[0] = 144;
			break;
		}
		case 245: {
			z->size = 1;
			z->element[0] = 145;
			break;
		}
		case 246: {
			z->size = 1;
			z->element[0] = 146;
			break;
		}
		case 247: {
			z->size = 1;
			z->element[0] = 147;
			break;
		}
		case 248: {
			z->size = 1;
			z->element[0] = 148;
			break;
		}
		case 249: {
			z->size = 1;
			z->element[0] = 149;
			break;
		}
		case 250: {
			z->size = 1;
			z->element[0] = 150;
			break;
		}
		case 251: {
			z->size = 1;
			z->element[0] = 151;
			break;
		}
		case 252: {
			z->size = 1;
			z->element[0] = 152;
			break;
		}
		case 253: {
			z->size = 1;
			z->element[0] = 153;
			break;
		}
		case 254: {
			z->size = 1;
			z->element[0] = 154;
			break;
		}
		case 255: {
			z->size = 1;
			z->element[0] = 155;
			break;
		}
		case 256: {
			z->size = 1;
			z->element[0] = 156;
			break;
		}
		case 257: {
			z->size = 1;
			z->element[0] = 157;
			break;
		}
		case 258: {
			z->size = 1;
			z->element[0] = 158;
			break;
		}
		case 259: {
			z->size = 1;
			z->element[0] = 159;
			break;
		}
		case 260: {
			z->size = 1;
			z->element[0] = 160;
			break;
		}
		case 261: {
			z->size = 1;
			z->element[0] = 161;
			break;
		}
		case 262: {
			z->size = 1;
			z->element[0] = 162;
			break;
		}
		case 263: {
			z->size = 1;
			z->element[0] = 163;
			break;
		}
		case 264: {
			z->size = 1;
			z->element[0] = 164;
			break;
		}
		case 265: {
			z->size = 1;
			z->element[0] = 165;
			break;
		}
		case 266: {
			z->size = 1;
			z->element[0] = 166;
			break;
		}
		case 267: {
			z->size = 1;
			z->element[0] = 167;
			break;
		}
		case 268: {
			z->size = 1;
			z->element[0] = 168;
			break;
		}
		case 269: {
			z->size = 1;
			z->element[0] = 169;
			break;
		}
		case 270: {
			z->size = 1;
			z->element[0] = 170;
			break;
		}
		case 271: {
			z->size = 1;
			z->element[0] = 171;
			break;
		}
		case 272: {
			z->size = 1;
			z->element[0] = 172;
			break;
		}
		case 273: {
			z->size = 1;
			z->element[0] = 173;
			break;
		}
		case 274: {
			z->size = 1;
			z->element[0] = 174;
			break;
		}
		case 275: {
			z->size = 1;
			z->element[0] = 175;
			break;
		}
		case 276: {
			z->size = 1;
			z->element[0] = 176;
			break;
		}
		case 277: {
			z->size = 1;
			z->element[0] = 177;
			break;
		}
		case 278: {
			z->size = 1;
			z->element[0] = 178;
			break;
		}
		case 279: {
			z->size = 1;
			z->element[0] = 179;
			break;
		}
		default: z->size = 0; break;
	}
}

#endif
