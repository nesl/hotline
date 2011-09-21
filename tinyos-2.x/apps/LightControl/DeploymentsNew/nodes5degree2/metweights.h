#ifndef _MET_WEIGHTS_H_
#define _MET_WEIGHTS_H_

float W(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 0: {
			switch (n1) {
				case 0: a=0.436869; break;
				case 1: a=0.125000; break;
				case 2: a=0.111111; break;
				case 5: a=0.125000; break;
				case 6: a=0.090909; break;
				case 10: a=0.111111; break;
				default: break;
			}
			break;
		}
		case 1: {
			switch (n1) {
				case 0: a=0.125000; break;
				case 1: a=0.256313; break;
				case 2: a=0.111111; break;
				case 3: a=0.125000; break;
				case 5: a=0.125000; break;
				case 6: a=0.090909; break;
				case 7: a=0.083333; break;
				case 11: a=0.083333; break;
				default: break;
			}
			break;
		}
		case 2: {
			switch (n1) {
				case 0: a=0.111111; break;
				case 1: a=0.111111; break;
				case 2: a=0.213481; break;
				case 3: a=0.111111; break;
				case 4: a=0.111111; break;
				case 6: a=0.090909; break;
				case 7: a=0.083333; break;
				case 8: a=0.090909; break;
				case 12: a=0.076923; break;
				default: break;
			}
			break;
		}
		case 3: {
			switch (n1) {
				case 1: a=0.125000; break;
				case 2: a=0.111111; break;
				case 3: a=0.256313; break;
				case 4: a=0.125000; break;
				case 7: a=0.083333; break;
				case 8: a=0.090909; break;
				case 9: a=0.125000; break;
				case 13: a=0.083333; break;
				default: break;
			}
			break;
		}
		case 4: {
			switch (n1) {
				case 2: a=0.111111; break;
				case 3: a=0.125000; break;
				case 4: a=0.436869; break;
				case 8: a=0.090909; break;
				case 9: a=0.125000; break;
				case 14: a=0.111111; break;
				default: break;
			}
			break;
		}
		case 5: {
			switch (n1) {
				case 0: a=0.125000; break;
				case 1: a=0.125000; break;
				case 5: a=0.256313; break;
				case 6: a=0.090909; break;
				case 7: a=0.083333; break;
				case 10: a=0.111111; break;
				case 11: a=0.083333; break;
				case 15: a=0.125000; break;
				default: break;
			}
			break;
		}
		case 6: {
			switch (n1) {
				case 0: a=0.090909; break;
				case 1: a=0.090909; break;
				case 2: a=0.090909; break;
				case 5: a=0.090909; break;
				case 6: a=0.120047; break;
				case 7: a=0.083333; break;
				case 8: a=0.090909; break;
				case 10: a=0.090909; break;
				case 11: a=0.083333; break;
				case 12: a=0.076923; break;
				case 16: a=0.090909; break;
				default: break;
			}
			break;
		}
		case 7: {
			switch (n1) {
				case 1: a=0.083333; break;
				case 2: a=0.083333; break;
				case 3: a=0.083333; break;
				case 5: a=0.083333; break;
				case 6: a=0.083333; break;
				case 7: a=0.089744; break;
				case 8: a=0.083333; break;
				case 9: a=0.083333; break;
				case 11: a=0.083333; break;
				case 12: a=0.076923; break;
				case 13: a=0.083333; break;
				case 17: a=0.083333; break;
				default: break;
			}
			break;
		}
		case 8: {
			switch (n1) {
				case 2: a=0.090909; break;
				case 3: a=0.090909; break;
				case 4: a=0.090909; break;
				case 6: a=0.090909; break;
				case 7: a=0.083333; break;
				case 8: a=0.120047; break;
				case 9: a=0.090909; break;
				case 12: a=0.076923; break;
				case 13: a=0.083333; break;
				case 14: a=0.090909; break;
				case 18: a=0.090909; break;
				default: break;
			}
			break;
		}
		case 9: {
			switch (n1) {
				case 3: a=0.125000; break;
				case 4: a=0.125000; break;
				case 7: a=0.083333; break;
				case 8: a=0.090909; break;
				case 9: a=0.256313; break;
				case 13: a=0.083333; break;
				case 14: a=0.111111; break;
				case 19: a=0.125000; break;
				default: break;
			}
			break;
		}
		case 10: {
			switch (n1) {
				case 0: a=0.111111; break;
				case 5: a=0.111111; break;
				case 6: a=0.090909; break;
				case 10: a=0.213481; break;
				case 11: a=0.083333; break;
				case 12: a=0.076923; break;
				case 15: a=0.111111; break;
				case 16: a=0.090909; break;
				case 20: a=0.111111; break;
				default: break;
			}
			break;
		}
		case 11: {
			switch (n1) {
				case 1: a=0.083333; break;
				case 5: a=0.083333; break;
				case 6: a=0.083333; break;
				case 7: a=0.083333; break;
				case 10: a=0.083333; break;
				case 11: a=0.089744; break;
				case 12: a=0.076923; break;
				case 13: a=0.083333; break;
				case 15: a=0.083333; break;
				case 16: a=0.083333; break;
				case 17: a=0.083333; break;
				case 21: a=0.083333; break;
				default: break;
			}
			break;
		}
		case 12: {
			switch (n1) {
				case 2: a=0.076923; break;
				case 6: a=0.076923; break;
				case 7: a=0.076923; break;
				case 8: a=0.076923; break;
				case 10: a=0.076923; break;
				case 11: a=0.076923; break;
				case 12: a=0.076923; break;
				case 13: a=0.076923; break;
				case 14: a=0.076923; break;
				case 16: a=0.076923; break;
				case 17: a=0.076923; break;
				case 18: a=0.076923; break;
				case 22: a=0.076923; break;
				default: break;
			}
			break;
		}
		case 13: {
			switch (n1) {
				case 3: a=0.083333; break;
				case 7: a=0.083333; break;
				case 8: a=0.083333; break;
				case 9: a=0.083333; break;
				case 11: a=0.083333; break;
				case 12: a=0.076923; break;
				case 13: a=0.089744; break;
				case 14: a=0.083333; break;
				case 17: a=0.083333; break;
				case 18: a=0.083333; break;
				case 19: a=0.083333; break;
				case 23: a=0.083333; break;
				default: break;
			}
			break;
		}
		case 14: {
			switch (n1) {
				case 4: a=0.111111; break;
				case 8: a=0.090909; break;
				case 9: a=0.111111; break;
				case 12: a=0.076923; break;
				case 13: a=0.083333; break;
				case 14: a=0.213481; break;
				case 18: a=0.090909; break;
				case 19: a=0.111111; break;
				case 24: a=0.111111; break;
				default: break;
			}
			break;
		}
		case 15: {
			switch (n1) {
				case 5: a=0.125000; break;
				case 10: a=0.111111; break;
				case 11: a=0.083333; break;
				case 15: a=0.256313; break;
				case 16: a=0.090909; break;
				case 17: a=0.083333; break;
				case 20: a=0.125000; break;
				case 21: a=0.125000; break;
				default: break;
			}
			break;
		}
		case 16: {
			switch (n1) {
				case 6: a=0.090909; break;
				case 10: a=0.090909; break;
				case 11: a=0.083333; break;
				case 12: a=0.076923; break;
				case 15: a=0.090909; break;
				case 16: a=0.120047; break;
				case 17: a=0.083333; break;
				case 18: a=0.090909; break;
				case 20: a=0.090909; break;
				case 21: a=0.090909; break;
				case 22: a=0.090909; break;
				default: break;
			}
			break;
		}
		case 17: {
			switch (n1) {
				case 7: a=0.083333; break;
				case 11: a=0.083333; break;
				case 12: a=0.076923; break;
				case 13: a=0.083333; break;
				case 15: a=0.083333; break;
				case 16: a=0.083333; break;
				case 17: a=0.089744; break;
				case 18: a=0.083333; break;
				case 19: a=0.083333; break;
				case 21: a=0.083333; break;
				case 22: a=0.083333; break;
				case 23: a=0.083333; break;
				default: break;
			}
			break;
		}
		case 18: {
			switch (n1) {
				case 8: a=0.090909; break;
				case 12: a=0.076923; break;
				case 13: a=0.083333; break;
				case 14: a=0.090909; break;
				case 16: a=0.090909; break;
				case 17: a=0.083333; break;
				case 18: a=0.120047; break;
				case 19: a=0.090909; break;
				case 22: a=0.090909; break;
				case 23: a=0.090909; break;
				case 24: a=0.090909; break;
				default: break;
			}
			break;
		}
		case 19: {
			switch (n1) {
				case 9: a=0.125000; break;
				case 13: a=0.083333; break;
				case 14: a=0.111111; break;
				case 17: a=0.083333; break;
				case 18: a=0.090909; break;
				case 19: a=0.256313; break;
				case 23: a=0.125000; break;
				case 24: a=0.125000; break;
				default: break;
			}
			break;
		}
		case 20: {
			switch (n1) {
				case 10: a=0.111111; break;
				case 15: a=0.125000; break;
				case 16: a=0.090909; break;
				case 20: a=0.436869; break;
				case 21: a=0.125000; break;
				case 22: a=0.111111; break;
				default: break;
			}
			break;
		}
		case 21: {
			switch (n1) {
				case 11: a=0.083333; break;
				case 15: a=0.125000; break;
				case 16: a=0.090909; break;
				case 17: a=0.083333; break;
				case 20: a=0.125000; break;
				case 21: a=0.256313; break;
				case 22: a=0.111111; break;
				case 23: a=0.125000; break;
				default: break;
			}
			break;
		}
		case 22: {
			switch (n1) {
				case 12: a=0.076923; break;
				case 16: a=0.090909; break;
				case 17: a=0.083333; break;
				case 18: a=0.090909; break;
				case 20: a=0.111111; break;
				case 21: a=0.111111; break;
				case 22: a=0.213481; break;
				case 23: a=0.111111; break;
				case 24: a=0.111111; break;
				default: break;
			}
			break;
		}
		case 23: {
			switch (n1) {
				case 13: a=0.083333; break;
				case 17: a=0.083333; break;
				case 18: a=0.090909; break;
				case 19: a=0.125000; break;
				case 21: a=0.125000; break;
				case 22: a=0.111111; break;
				case 23: a=0.256313; break;
				case 24: a=0.125000; break;
				default: break;
			}
			break;
		}
		case 24: {
			switch (n1) {
				case 14: a=0.111111; break;
				case 18: a=0.090909; break;
				case 19: a=0.125000; break;
				case 22: a=0.111111; break;
				case 23: a=0.125000; break;
				case 24: a=0.436869; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

#endif
