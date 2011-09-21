#ifndef _MET_WEIGHTS_H_
#define _MET_WEIGHTS_H_

float W(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 0: {
			switch (n1) {
				case 0: a=0.275861; break;
				case 1: a=0.055556; break;
				case 2: a=0.052632; break;
				case 3: a=0.055556; break;
				case 4: a=0.066667; break;
				case 5: a=0.055556; break;
				case 6: a=0.045455; break;
				case 7: a=0.043478; break;
				case 8: a=0.045455; break;
				case 10: a=0.052632; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 15: a=0.055556; break;
				case 16: a=0.045455; break;
				case 20: a=0.066667; break;
				default: break;
			}
			break;
		}
		case 1: {
			switch (n1) {
				case 0: a=0.055556; break;
				case 1: a=0.155571; break;
				case 2: a=0.052632; break;
				case 3: a=0.055556; break;
				case 4: a=0.055556; break;
				case 5: a=0.055556; break;
				case 6: a=0.045455; break;
				case 7: a=0.043478; break;
				case 8: a=0.045455; break;
				case 9: a=0.055556; break;
				case 10: a=0.052632; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 15: a=0.055556; break;
				case 16: a=0.045455; break;
				case 17: a=0.043478; break;
				case 21: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 2: {
			switch (n1) {
				case 0: a=0.052632; break;
				case 1: a=0.052632; break;
				case 2: a=0.130585; break;
				case 3: a=0.052632; break;
				case 4: a=0.052632; break;
				case 5: a=0.052632; break;
				case 6: a=0.045455; break;
				case 7: a=0.043478; break;
				case 8: a=0.045455; break;
				case 9: a=0.052632; break;
				case 10: a=0.052632; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 14: a=0.052632; break;
				case 16: a=0.045455; break;
				case 17: a=0.043478; break;
				case 18: a=0.045455; break;
				case 22: a=0.052632; break;
				default: break;
			}
			break;
		}
		case 3: {
			switch (n1) {
				case 0: a=0.055556; break;
				case 1: a=0.055556; break;
				case 2: a=0.052632; break;
				case 3: a=0.155571; break;
				case 4: a=0.055556; break;
				case 5: a=0.055556; break;
				case 6: a=0.045455; break;
				case 7: a=0.043478; break;
				case 8: a=0.045455; break;
				case 9: a=0.055556; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 14: a=0.052632; break;
				case 17: a=0.043478; break;
				case 18: a=0.045455; break;
				case 19: a=0.055556; break;
				case 23: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 4: {
			switch (n1) {
				case 0: a=0.066667; break;
				case 1: a=0.055556; break;
				case 2: a=0.052632; break;
				case 3: a=0.055556; break;
				case 4: a=0.275861; break;
				case 6: a=0.045455; break;
				case 7: a=0.043478; break;
				case 8: a=0.045455; break;
				case 9: a=0.055556; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 14: a=0.052632; break;
				case 18: a=0.045455; break;
				case 19: a=0.055556; break;
				case 24: a=0.066667; break;
				default: break;
			}
			break;
		}
		case 5: {
			switch (n1) {
				case 0: a=0.055556; break;
				case 1: a=0.055556; break;
				case 2: a=0.052632; break;
				case 3: a=0.055556; break;
				case 5: a=0.155571; break;
				case 6: a=0.045455; break;
				case 7: a=0.043478; break;
				case 8: a=0.045455; break;
				case 9: a=0.055556; break;
				case 10: a=0.052632; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 15: a=0.055556; break;
				case 16: a=0.045455; break;
				case 17: a=0.043478; break;
				case 20: a=0.055556; break;
				case 21: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 6: {
			switch (n1) {
				case 0: a=0.045455; break;
				case 1: a=0.045455; break;
				case 2: a=0.045455; break;
				case 3: a=0.045455; break;
				case 4: a=0.045455; break;
				case 5: a=0.045455; break;
				case 6: a=0.058814; break;
				case 7: a=0.043478; break;
				case 8: a=0.045455; break;
				case 9: a=0.045455; break;
				case 10: a=0.045455; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 14: a=0.045455; break;
				case 15: a=0.045455; break;
				case 16: a=0.045455; break;
				case 17: a=0.043478; break;
				case 18: a=0.045455; break;
				case 20: a=0.045455; break;
				case 21: a=0.045455; break;
				case 22: a=0.045455; break;
				default: break;
			}
			break;
		}
		case 7: {
			switch (n1) {
				case 0: a=0.043478; break;
				case 1: a=0.043478; break;
				case 2: a=0.043478; break;
				case 3: a=0.043478; break;
				case 4: a=0.043478; break;
				case 5: a=0.043478; break;
				case 6: a=0.043478; break;
				case 7: a=0.046957; break;
				case 8: a=0.043478; break;
				case 9: a=0.043478; break;
				case 10: a=0.043478; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 14: a=0.043478; break;
				case 15: a=0.043478; break;
				case 16: a=0.043478; break;
				case 17: a=0.043478; break;
				case 18: a=0.043478; break;
				case 19: a=0.043478; break;
				case 21: a=0.043478; break;
				case 22: a=0.043478; break;
				case 23: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 8: {
			switch (n1) {
				case 0: a=0.045455; break;
				case 1: a=0.045455; break;
				case 2: a=0.045455; break;
				case 3: a=0.045455; break;
				case 4: a=0.045455; break;
				case 5: a=0.045455; break;
				case 6: a=0.045455; break;
				case 7: a=0.043478; break;
				case 8: a=0.058814; break;
				case 9: a=0.045455; break;
				case 10: a=0.045455; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 14: a=0.045455; break;
				case 16: a=0.045455; break;
				case 17: a=0.043478; break;
				case 18: a=0.045455; break;
				case 19: a=0.045455; break;
				case 22: a=0.045455; break;
				case 23: a=0.045455; break;
				case 24: a=0.045455; break;
				default: break;
			}
			break;
		}
		case 9: {
			switch (n1) {
				case 1: a=0.055556; break;
				case 2: a=0.052632; break;
				case 3: a=0.055556; break;
				case 4: a=0.055556; break;
				case 5: a=0.055556; break;
				case 6: a=0.045455; break;
				case 7: a=0.043478; break;
				case 8: a=0.045455; break;
				case 9: a=0.155571; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 14: a=0.052632; break;
				case 17: a=0.043478; break;
				case 18: a=0.045455; break;
				case 19: a=0.055556; break;
				case 23: a=0.055556; break;
				case 24: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 10: {
			switch (n1) {
				case 0: a=0.052632; break;
				case 1: a=0.052632; break;
				case 2: a=0.052632; break;
				case 5: a=0.052632; break;
				case 6: a=0.045455; break;
				case 7: a=0.043478; break;
				case 8: a=0.045455; break;
				case 10: a=0.130585; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 14: a=0.052632; break;
				case 15: a=0.052632; break;
				case 16: a=0.045455; break;
				case 17: a=0.043478; break;
				case 18: a=0.045455; break;
				case 20: a=0.052632; break;
				case 21: a=0.052632; break;
				case 22: a=0.052632; break;
				default: break;
			}
			break;
		}
		case 11: {
			switch (n1) {
				case 0: a=0.043478; break;
				case 1: a=0.043478; break;
				case 2: a=0.043478; break;
				case 3: a=0.043478; break;
				case 5: a=0.043478; break;
				case 6: a=0.043478; break;
				case 7: a=0.043478; break;
				case 8: a=0.043478; break;
				case 9: a=0.043478; break;
				case 10: a=0.043478; break;
				case 11: a=0.046957; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 14: a=0.043478; break;
				case 15: a=0.043478; break;
				case 16: a=0.043478; break;
				case 17: a=0.043478; break;
				case 18: a=0.043478; break;
				case 19: a=0.043478; break;
				case 20: a=0.043478; break;
				case 21: a=0.043478; break;
				case 22: a=0.043478; break;
				case 23: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 12: {
			switch (n1) {
				case 0: a=0.040000; break;
				case 1: a=0.040000; break;
				case 2: a=0.040000; break;
				case 3: a=0.040000; break;
				case 4: a=0.040000; break;
				case 5: a=0.040000; break;
				case 6: a=0.040000; break;
				case 7: a=0.040000; break;
				case 8: a=0.040000; break;
				case 9: a=0.040000; break;
				case 10: a=0.040000; break;
				case 11: a=0.040000; break;
				case 12: a=0.040000; break;
				case 13: a=0.040000; break;
				case 14: a=0.040000; break;
				case 15: a=0.040000; break;
				case 16: a=0.040000; break;
				case 17: a=0.040000; break;
				case 18: a=0.040000; break;
				case 19: a=0.040000; break;
				case 20: a=0.040000; break;
				case 21: a=0.040000; break;
				case 22: a=0.040000; break;
				case 23: a=0.040000; break;
				case 24: a=0.040000; break;
				default: break;
			}
			break;
		}
		case 13: {
			switch (n1) {
				case 1: a=0.043478; break;
				case 2: a=0.043478; break;
				case 3: a=0.043478; break;
				case 4: a=0.043478; break;
				case 5: a=0.043478; break;
				case 6: a=0.043478; break;
				case 7: a=0.043478; break;
				case 8: a=0.043478; break;
				case 9: a=0.043478; break;
				case 10: a=0.043478; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.046957; break;
				case 14: a=0.043478; break;
				case 15: a=0.043478; break;
				case 16: a=0.043478; break;
				case 17: a=0.043478; break;
				case 18: a=0.043478; break;
				case 19: a=0.043478; break;
				case 21: a=0.043478; break;
				case 22: a=0.043478; break;
				case 23: a=0.043478; break;
				case 24: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 14: {
			switch (n1) {
				case 2: a=0.052632; break;
				case 3: a=0.052632; break;
				case 4: a=0.052632; break;
				case 6: a=0.045455; break;
				case 7: a=0.043478; break;
				case 8: a=0.045455; break;
				case 9: a=0.052632; break;
				case 10: a=0.052632; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 14: a=0.130585; break;
				case 16: a=0.045455; break;
				case 17: a=0.043478; break;
				case 18: a=0.045455; break;
				case 19: a=0.052632; break;
				case 22: a=0.052632; break;
				case 23: a=0.052632; break;
				case 24: a=0.052632; break;
				default: break;
			}
			break;
		}
		case 15: {
			switch (n1) {
				case 0: a=0.055556; break;
				case 1: a=0.055556; break;
				case 5: a=0.055556; break;
				case 6: a=0.045455; break;
				case 7: a=0.043478; break;
				case 10: a=0.052632; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 15: a=0.155571; break;
				case 16: a=0.045455; break;
				case 17: a=0.043478; break;
				case 18: a=0.045455; break;
				case 19: a=0.055556; break;
				case 20: a=0.055556; break;
				case 21: a=0.055556; break;
				case 22: a=0.052632; break;
				case 23: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 16: {
			switch (n1) {
				case 0: a=0.045455; break;
				case 1: a=0.045455; break;
				case 2: a=0.045455; break;
				case 5: a=0.045455; break;
				case 6: a=0.045455; break;
				case 7: a=0.043478; break;
				case 8: a=0.045455; break;
				case 10: a=0.045455; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 14: a=0.045455; break;
				case 15: a=0.045455; break;
				case 16: a=0.058814; break;
				case 17: a=0.043478; break;
				case 18: a=0.045455; break;
				case 19: a=0.045455; break;
				case 20: a=0.045455; break;
				case 21: a=0.045455; break;
				case 22: a=0.045455; break;
				case 23: a=0.045455; break;
				case 24: a=0.045455; break;
				default: break;
			}
			break;
		}
		case 17: {
			switch (n1) {
				case 1: a=0.043478; break;
				case 2: a=0.043478; break;
				case 3: a=0.043478; break;
				case 5: a=0.043478; break;
				case 6: a=0.043478; break;
				case 7: a=0.043478; break;
				case 8: a=0.043478; break;
				case 9: a=0.043478; break;
				case 10: a=0.043478; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 14: a=0.043478; break;
				case 15: a=0.043478; break;
				case 16: a=0.043478; break;
				case 17: a=0.046957; break;
				case 18: a=0.043478; break;
				case 19: a=0.043478; break;
				case 20: a=0.043478; break;
				case 21: a=0.043478; break;
				case 22: a=0.043478; break;
				case 23: a=0.043478; break;
				case 24: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 18: {
			switch (n1) {
				case 2: a=0.045455; break;
				case 3: a=0.045455; break;
				case 4: a=0.045455; break;
				case 6: a=0.045455; break;
				case 7: a=0.043478; break;
				case 8: a=0.045455; break;
				case 9: a=0.045455; break;
				case 10: a=0.045455; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 14: a=0.045455; break;
				case 15: a=0.045455; break;
				case 16: a=0.045455; break;
				case 17: a=0.043478; break;
				case 18: a=0.058814; break;
				case 19: a=0.045455; break;
				case 20: a=0.045455; break;
				case 21: a=0.045455; break;
				case 22: a=0.045455; break;
				case 23: a=0.045455; break;
				case 24: a=0.045455; break;
				default: break;
			}
			break;
		}
		case 19: {
			switch (n1) {
				case 3: a=0.055556; break;
				case 4: a=0.055556; break;
				case 7: a=0.043478; break;
				case 8: a=0.045455; break;
				case 9: a=0.055556; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 14: a=0.052632; break;
				case 15: a=0.055556; break;
				case 16: a=0.045455; break;
				case 17: a=0.043478; break;
				case 18: a=0.045455; break;
				case 19: a=0.155571; break;
				case 21: a=0.055556; break;
				case 22: a=0.052632; break;
				case 23: a=0.055556; break;
				case 24: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 20: {
			switch (n1) {
				case 0: a=0.066667; break;
				case 5: a=0.055556; break;
				case 6: a=0.045455; break;
				case 10: a=0.052632; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 15: a=0.055556; break;
				case 16: a=0.045455; break;
				case 17: a=0.043478; break;
				case 18: a=0.045455; break;
				case 20: a=0.275861; break;
				case 21: a=0.055556; break;
				case 22: a=0.052632; break;
				case 23: a=0.055556; break;
				case 24: a=0.066667; break;
				default: break;
			}
			break;
		}
		case 21: {
			switch (n1) {
				case 1: a=0.055556; break;
				case 5: a=0.055556; break;
				case 6: a=0.045455; break;
				case 7: a=0.043478; break;
				case 10: a=0.052632; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 15: a=0.055556; break;
				case 16: a=0.045455; break;
				case 17: a=0.043478; break;
				case 18: a=0.045455; break;
				case 19: a=0.055556; break;
				case 20: a=0.055556; break;
				case 21: a=0.155571; break;
				case 22: a=0.052632; break;
				case 23: a=0.055556; break;
				case 24: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 22: {
			switch (n1) {
				case 2: a=0.052632; break;
				case 6: a=0.045455; break;
				case 7: a=0.043478; break;
				case 8: a=0.045455; break;
				case 10: a=0.052632; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 14: a=0.052632; break;
				case 15: a=0.052632; break;
				case 16: a=0.045455; break;
				case 17: a=0.043478; break;
				case 18: a=0.045455; break;
				case 19: a=0.052632; break;
				case 20: a=0.052632; break;
				case 21: a=0.052632; break;
				case 22: a=0.130585; break;
				case 23: a=0.052632; break;
				case 24: a=0.052632; break;
				default: break;
			}
			break;
		}
		case 23: {
			switch (n1) {
				case 3: a=0.055556; break;
				case 7: a=0.043478; break;
				case 8: a=0.045455; break;
				case 9: a=0.055556; break;
				case 11: a=0.043478; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 14: a=0.052632; break;
				case 15: a=0.055556; break;
				case 16: a=0.045455; break;
				case 17: a=0.043478; break;
				case 18: a=0.045455; break;
				case 19: a=0.055556; break;
				case 20: a=0.055556; break;
				case 21: a=0.055556; break;
				case 22: a=0.052632; break;
				case 23: a=0.155571; break;
				case 24: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 24: {
			switch (n1) {
				case 4: a=0.066667; break;
				case 8: a=0.045455; break;
				case 9: a=0.055556; break;
				case 12: a=0.040000; break;
				case 13: a=0.043478; break;
				case 14: a=0.052632; break;
				case 16: a=0.045455; break;
				case 17: a=0.043478; break;
				case 18: a=0.045455; break;
				case 19: a=0.055556; break;
				case 20: a=0.066667; break;
				case 21: a=0.055556; break;
				case 22: a=0.052632; break;
				case 23: a=0.055556; break;
				case 24: a=0.275861; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

#endif
