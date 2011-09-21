#ifndef _ZONE_DEP_H_
#define _ZONE_DEP_H_

void set_zone(zone_intset_t *z) {
	switch (TOS_NODE_ID) {
		case 0: {
			z->size = 6;
			z->element[0] = 0;
			z->element[1] = 1;
			z->element[2] = 2;
			z->element[3] = 5;
			z->element[4] = 6;
			z->element[5] = 10;
			break;
		}
		case 1: {
			z->size = 8;
			z->element[0] = 0;
			z->element[1] = 1;
			z->element[2] = 2;
			z->element[3] = 3;
			z->element[4] = 5;
			z->element[5] = 6;
			z->element[6] = 7;
			z->element[7] = 11;
			break;
		}
		case 2: {
			z->size = 9;
			z->element[0] = 0;
			z->element[1] = 1;
			z->element[2] = 2;
			z->element[3] = 3;
			z->element[4] = 4;
			z->element[5] = 6;
			z->element[6] = 7;
			z->element[7] = 8;
			z->element[8] = 12;
			break;
		}
		case 3: {
			z->size = 8;
			z->element[0] = 1;
			z->element[1] = 2;
			z->element[2] = 3;
			z->element[3] = 4;
			z->element[4] = 7;
			z->element[5] = 8;
			z->element[6] = 9;
			z->element[7] = 13;
			break;
		}
		case 4: {
			z->size = 6;
			z->element[0] = 2;
			z->element[1] = 3;
			z->element[2] = 4;
			z->element[3] = 8;
			z->element[4] = 9;
			z->element[5] = 14;
			break;
		}
		case 5: {
			z->size = 8;
			z->element[0] = 0;
			z->element[1] = 1;
			z->element[2] = 5;
			z->element[3] = 6;
			z->element[4] = 7;
			z->element[5] = 10;
			z->element[6] = 11;
			z->element[7] = 15;
			break;
		}
		case 6: {
			z->size = 11;
			z->element[0] = 0;
			z->element[1] = 1;
			z->element[2] = 2;
			z->element[3] = 5;
			z->element[4] = 6;
			z->element[5] = 7;
			z->element[6] = 8;
			z->element[7] = 10;
			z->element[8] = 11;
			z->element[9] = 12;
			z->element[10] = 16;
			break;
		}
		case 7: {
			z->size = 12;
			z->element[0] = 1;
			z->element[1] = 2;
			z->element[2] = 3;
			z->element[3] = 5;
			z->element[4] = 6;
			z->element[5] = 7;
			z->element[6] = 8;
			z->element[7] = 9;
			z->element[8] = 11;
			z->element[9] = 12;
			z->element[10] = 13;
			z->element[11] = 17;
			break;
		}
		case 8: {
			z->size = 11;
			z->element[0] = 2;
			z->element[1] = 3;
			z->element[2] = 4;
			z->element[3] = 6;
			z->element[4] = 7;
			z->element[5] = 8;
			z->element[6] = 9;
			z->element[7] = 12;
			z->element[8] = 13;
			z->element[9] = 14;
			z->element[10] = 18;
			break;
		}
		case 9: {
			z->size = 8;
			z->element[0] = 3;
			z->element[1] = 4;
			z->element[2] = 7;
			z->element[3] = 8;
			z->element[4] = 9;
			z->element[5] = 13;
			z->element[6] = 14;
			z->element[7] = 19;
			break;
		}
		case 10: {
			z->size = 9;
			z->element[0] = 0;
			z->element[1] = 5;
			z->element[2] = 6;
			z->element[3] = 10;
			z->element[4] = 11;
			z->element[5] = 12;
			z->element[6] = 15;
			z->element[7] = 16;
			z->element[8] = 20;
			break;
		}
		case 11: {
			z->size = 12;
			z->element[0] = 1;
			z->element[1] = 5;
			z->element[2] = 6;
			z->element[3] = 7;
			z->element[4] = 10;
			z->element[5] = 11;
			z->element[6] = 12;
			z->element[7] = 13;
			z->element[8] = 15;
			z->element[9] = 16;
			z->element[10] = 17;
			z->element[11] = 21;
			break;
		}
		case 12: {
			z->size = 13;
			z->element[0] = 2;
			z->element[1] = 6;
			z->element[2] = 7;
			z->element[3] = 8;
			z->element[4] = 10;
			z->element[5] = 11;
			z->element[6] = 12;
			z->element[7] = 13;
			z->element[8] = 14;
			z->element[9] = 16;
			z->element[10] = 17;
			z->element[11] = 18;
			z->element[12] = 22;
			break;
		}
		case 13: {
			z->size = 12;
			z->element[0] = 3;
			z->element[1] = 7;
			z->element[2] = 8;
			z->element[3] = 9;
			z->element[4] = 11;
			z->element[5] = 12;
			z->element[6] = 13;
			z->element[7] = 14;
			z->element[8] = 17;
			z->element[9] = 18;
			z->element[10] = 19;
			z->element[11] = 23;
			break;
		}
		case 14: {
			z->size = 9;
			z->element[0] = 4;
			z->element[1] = 8;
			z->element[2] = 9;
			z->element[3] = 12;
			z->element[4] = 13;
			z->element[5] = 14;
			z->element[6] = 18;
			z->element[7] = 19;
			z->element[8] = 24;
			break;
		}
		case 15: {
			z->size = 8;
			z->element[0] = 5;
			z->element[1] = 10;
			z->element[2] = 11;
			z->element[3] = 15;
			z->element[4] = 16;
			z->element[5] = 17;
			z->element[6] = 20;
			z->element[7] = 21;
			break;
		}
		case 16: {
			z->size = 11;
			z->element[0] = 6;
			z->element[1] = 10;
			z->element[2] = 11;
			z->element[3] = 12;
			z->element[4] = 15;
			z->element[5] = 16;
			z->element[6] = 17;
			z->element[7] = 18;
			z->element[8] = 20;
			z->element[9] = 21;
			z->element[10] = 22;
			break;
		}
		case 17: {
			z->size = 12;
			z->element[0] = 7;
			z->element[1] = 11;
			z->element[2] = 12;
			z->element[3] = 13;
			z->element[4] = 15;
			z->element[5] = 16;
			z->element[6] = 17;
			z->element[7] = 18;
			z->element[8] = 19;
			z->element[9] = 21;
			z->element[10] = 22;
			z->element[11] = 23;
			break;
		}
		case 18: {
			z->size = 11;
			z->element[0] = 8;
			z->element[1] = 12;
			z->element[2] = 13;
			z->element[3] = 14;
			z->element[4] = 16;
			z->element[5] = 17;
			z->element[6] = 18;
			z->element[7] = 19;
			z->element[8] = 22;
			z->element[9] = 23;
			z->element[10] = 24;
			break;
		}
		case 19: {
			z->size = 8;
			z->element[0] = 9;
			z->element[1] = 13;
			z->element[2] = 14;
			z->element[3] = 17;
			z->element[4] = 18;
			z->element[5] = 19;
			z->element[6] = 23;
			z->element[7] = 24;
			break;
		}
		case 20: {
			z->size = 6;
			z->element[0] = 10;
			z->element[1] = 15;
			z->element[2] = 16;
			z->element[3] = 20;
			z->element[4] = 21;
			z->element[5] = 22;
			break;
		}
		case 21: {
			z->size = 8;
			z->element[0] = 11;
			z->element[1] = 15;
			z->element[2] = 16;
			z->element[3] = 17;
			z->element[4] = 20;
			z->element[5] = 21;
			z->element[6] = 22;
			z->element[7] = 23;
			break;
		}
		case 22: {
			z->size = 9;
			z->element[0] = 12;
			z->element[1] = 16;
			z->element[2] = 17;
			z->element[3] = 18;
			z->element[4] = 20;
			z->element[5] = 21;
			z->element[6] = 22;
			z->element[7] = 23;
			z->element[8] = 24;
			break;
		}
		case 23: {
			z->size = 8;
			z->element[0] = 13;
			z->element[1] = 17;
			z->element[2] = 18;
			z->element[3] = 19;
			z->element[4] = 21;
			z->element[5] = 22;
			z->element[6] = 23;
			z->element[7] = 24;
			break;
		}
		case 24: {
			z->size = 6;
			z->element[0] = 14;
			z->element[1] = 18;
			z->element[2] = 19;
			z->element[3] = 22;
			z->element[4] = 23;
			z->element[5] = 24;
			break;
		}
		case 25: {
			z->size = 1;
			z->element[0] = 0;
			break;
		}
		case 26: {
			z->size = 1;
			z->element[0] = 1;
			break;
		}
		case 27: {
			z->size = 1;
			z->element[0] = 2;
			break;
		}
		case 28: {
			z->size = 1;
			z->element[0] = 3;
			break;
		}
		case 29: {
			z->size = 1;
			z->element[0] = 4;
			break;
		}
		case 30: {
			z->size = 1;
			z->element[0] = 5;
			break;
		}
		case 31: {
			z->size = 1;
			z->element[0] = 6;
			break;
		}
		case 32: {
			z->size = 1;
			z->element[0] = 7;
			break;
		}
		case 33: {
			z->size = 1;
			z->element[0] = 8;
			break;
		}
		case 34: {
			z->size = 1;
			z->element[0] = 9;
			break;
		}
		case 35: {
			z->size = 1;
			z->element[0] = 10;
			break;
		}
		case 36: {
			z->size = 1;
			z->element[0] = 11;
			break;
		}
		case 37: {
			z->size = 1;
			z->element[0] = 12;
			break;
		}
		case 38: {
			z->size = 1;
			z->element[0] = 13;
			break;
		}
		case 39: {
			z->size = 1;
			z->element[0] = 14;
			break;
		}
		case 40: {
			z->size = 1;
			z->element[0] = 15;
			break;
		}
		case 41: {
			z->size = 1;
			z->element[0] = 16;
			break;
		}
		case 42: {
			z->size = 1;
			z->element[0] = 17;
			break;
		}
		case 43: {
			z->size = 1;
			z->element[0] = 18;
			break;
		}
		case 44: {
			z->size = 1;
			z->element[0] = 19;
			break;
		}
		case 45: {
			z->size = 1;
			z->element[0] = 20;
			break;
		}
		case 46: {
			z->size = 1;
			z->element[0] = 21;
			break;
		}
		case 47: {
			z->size = 1;
			z->element[0] = 22;
			break;
		}
		case 48: {
			z->size = 1;
			z->element[0] = 23;
			break;
		}
		case 49: {
			z->size = 1;
			z->element[0] = 24;
			break;
		}
		default: z->size = 0; break;
	}
}

#endif
