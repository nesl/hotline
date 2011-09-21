#ifndef _MET_WEIGHTS_H_
#define _MET_WEIGHTS_H_

float W(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 0: {
			switch (n1) {
				case 0: a=0.500000; break;
				case 1: a=0.250000; break;
				case 3: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 1: {
			switch (n1) {
				case 0: a=0.250000; break;
				case 1: a=0.300000; break;
				case 2: a=0.250000; break;
				case 4: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 2: {
			switch (n1) {
				case 1: a=0.250000; break;
				case 2: a=0.500000; break;
				case 5: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 3: {
			switch (n1) {
				case 0: a=0.250000; break;
				case 3: a=0.300000; break;
				case 4: a=0.200000; break;
				case 6: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 4: {
			switch (n1) {
				case 1: a=0.200000; break;
				case 3: a=0.200000; break;
				case 4: a=0.200000; break;
				case 5: a=0.200000; break;
				case 7: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 5: {
			switch (n1) {
				case 2: a=0.250000; break;
				case 4: a=0.200000; break;
				case 5: a=0.300000; break;
				case 8: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 6: {
			switch (n1) {
				case 3: a=0.250000; break;
				case 6: a=0.500000; break;
				case 7: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 7: {
			switch (n1) {
				case 4: a=0.200000; break;
				case 6: a=0.250000; break;
				case 7: a=0.300000; break;
				case 8: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 8: {
			switch (n1) {
				case 5: a=0.250000; break;
				case 7: a=0.250000; break;
				case 8: a=0.500000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

#endif
