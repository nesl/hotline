#ifndef _ZONE_DEP_H_
#define _ZONE_DEP_H_

void set_zone(zone_intset_t *z) {
	switch (TOS_NODE_ID) {
		case 0: {
			z->size = 2;
			z->element[0] = 0;
			z->element[1] = 2;
			break;
		}
		case 1: {
			z->size = 3;
			z->element[0] = 0;
			z->element[1] = 1;
			z->element[2] = 3;
			break;
		}
		case 2: {
			z->size = 2;
			z->element[0] = 1;
			z->element[1] = 4;
			break;
		}
		case 3: {
			z->size = 3;
			z->element[0] = 2;
			z->element[1] = 5;
			z->element[2] = 7;
			break;
		}
		case 4: {
			z->size = 4;
			z->element[0] = 3;
			z->element[1] = 5;
			z->element[2] = 6;
			z->element[3] = 8;
			break;
		}
		case 5: {
			z->size = 3;
			z->element[0] = 4;
			z->element[1] = 6;
			z->element[2] = 9;
			break;
		}
		case 6: {
			z->size = 2;
			z->element[0] = 7;
			z->element[1] = 10;
			break;
		}
		case 7: {
			z->size = 3;
			z->element[0] = 8;
			z->element[1] = 10;
			z->element[2] = 11;
			break;
		}
		case 8: {
			z->size = 2;
			z->element[0] = 9;
			z->element[1] = 11;
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
		case 18: {
			z->size = 1;
			z->element[0] = 9;
			break;
		}
		case 19: {
			z->size = 1;
			z->element[0] = 10;
			break;
		}
		case 20: {
			z->size = 1;
			z->element[0] = 11;
			break;
		}
		default: z->size = 0; break;
	}
}

#endif
