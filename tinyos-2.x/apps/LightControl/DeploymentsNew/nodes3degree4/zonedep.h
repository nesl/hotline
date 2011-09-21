#ifndef _ZONE_DEP_H_
#define _ZONE_DEP_H_

void set_zone(zone_intset_t *z) {
	switch (TOS_NODE_ID) {
		case 0: {
			z->size = 6;
			z->element[0] = 0;
			z->element[1] = 1;
			z->element[2] = 2;
			z->element[3] = 3;
			z->element[4] = 4;
			z->element[5] = 6;
			break;
		}
		case 1: {
			z->size = 7;
			z->element[0] = 0;
			z->element[1] = 1;
			z->element[2] = 2;
			z->element[3] = 3;
			z->element[4] = 4;
			z->element[5] = 5;
			z->element[6] = 7;
			break;
		}
		case 2: {
			z->size = 6;
			z->element[0] = 0;
			z->element[1] = 1;
			z->element[2] = 2;
			z->element[3] = 4;
			z->element[4] = 5;
			z->element[5] = 8;
			break;
		}
		case 3: {
			z->size = 7;
			z->element[0] = 0;
			z->element[1] = 1;
			z->element[2] = 3;
			z->element[3] = 4;
			z->element[4] = 5;
			z->element[5] = 6;
			z->element[6] = 7;
			break;
		}
		case 4: {
			z->size = 9;
			z->element[0] = 0;
			z->element[1] = 1;
			z->element[2] = 2;
			z->element[3] = 3;
			z->element[4] = 4;
			z->element[5] = 5;
			z->element[6] = 6;
			z->element[7] = 7;
			z->element[8] = 8;
			break;
		}
		case 5: {
			z->size = 7;
			z->element[0] = 1;
			z->element[1] = 2;
			z->element[2] = 3;
			z->element[3] = 4;
			z->element[4] = 5;
			z->element[5] = 7;
			z->element[6] = 8;
			break;
		}
		case 6: {
			z->size = 6;
			z->element[0] = 0;
			z->element[1] = 3;
			z->element[2] = 4;
			z->element[3] = 6;
			z->element[4] = 7;
			z->element[5] = 8;
			break;
		}
		case 7: {
			z->size = 7;
			z->element[0] = 1;
			z->element[1] = 3;
			z->element[2] = 4;
			z->element[3] = 5;
			z->element[4] = 6;
			z->element[5] = 7;
			z->element[6] = 8;
			break;
		}
		case 8: {
			z->size = 6;
			z->element[0] = 2;
			z->element[1] = 4;
			z->element[2] = 5;
			z->element[3] = 6;
			z->element[4] = 7;
			z->element[5] = 8;
			break;
		}
		case 9: {
			z->size = 1;
			z->element[0] = 0;
			break;
		}
		case 10: {
			z->size = 1;
			z->element[0] = 1;
			break;
		}
		case 11: {
			z->size = 1;
			z->element[0] = 2;
			break;
		}
		case 12: {
			z->size = 1;
			z->element[0] = 3;
			break;
		}
		case 13: {
			z->size = 1;
			z->element[0] = 4;
			break;
		}
		case 14: {
			z->size = 1;
			z->element[0] = 5;
			break;
		}
		case 15: {
			z->size = 1;
			z->element[0] = 6;
			break;
		}
		case 16: {
			z->size = 1;
			z->element[0] = 7;
			break;
		}
		case 17: {
			z->size = 1;
			z->element[0] = 8;
			break;
		}
		default: z->size = 0; break;
	}
}

#endif
