#ifndef _MET_WEIGHTS_H_
#define _MET_WEIGHTS_H_

float W(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 0: {
			switch (n1) {
				case 0: a=0.500000; break;
				case 1: a=0.250000; break;
				case 7: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 1: {
			switch (n1) {
				case 0: a=0.250000; break;
				case 1: a=0.300000; break;
				case 2: a=0.250000; break;
				case 8: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 2: {
			switch (n1) {
				case 1: a=0.250000; break;
				case 2: a=0.300000; break;
				case 3: a=0.250000; break;
				case 9: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 3: {
			switch (n1) {
				case 2: a=0.250000; break;
				case 3: a=0.300000; break;
				case 4: a=0.250000; break;
				case 10: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 4: {
			switch (n1) {
				case 3: a=0.250000; break;
				case 4: a=0.300000; break;
				case 5: a=0.250000; break;
				case 11: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 5: {
			switch (n1) {
				case 4: a=0.250000; break;
				case 5: a=0.300000; break;
				case 6: a=0.250000; break;
				case 12: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 6: {
			switch (n1) {
				case 5: a=0.250000; break;
				case 6: a=0.500000; break;
				case 13: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 7: {
			switch (n1) {
				case 0: a=0.250000; break;
				case 7: a=0.300000; break;
				case 8: a=0.200000; break;
				case 14: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 8: {
			switch (n1) {
				case 1: a=0.200000; break;
				case 7: a=0.200000; break;
				case 8: a=0.200000; break;
				case 9: a=0.200000; break;
				case 15: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 9: {
			switch (n1) {
				case 2: a=0.200000; break;
				case 8: a=0.200000; break;
				case 9: a=0.200000; break;
				case 10: a=0.200000; break;
				case 16: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 10: {
			switch (n1) {
				case 3: a=0.200000; break;
				case 9: a=0.200000; break;
				case 10: a=0.200000; break;
				case 11: a=0.200000; break;
				case 17: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 11: {
			switch (n1) {
				case 4: a=0.200000; break;
				case 10: a=0.200000; break;
				case 11: a=0.200000; break;
				case 12: a=0.200000; break;
				case 18: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 12: {
			switch (n1) {
				case 5: a=0.200000; break;
				case 11: a=0.200000; break;
				case 12: a=0.200000; break;
				case 13: a=0.200000; break;
				case 19: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 13: {
			switch (n1) {
				case 6: a=0.250000; break;
				case 12: a=0.200000; break;
				case 13: a=0.300000; break;
				case 20: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 14: {
			switch (n1) {
				case 7: a=0.250000; break;
				case 14: a=0.300000; break;
				case 15: a=0.200000; break;
				case 21: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 15: {
			switch (n1) {
				case 8: a=0.200000; break;
				case 14: a=0.200000; break;
				case 15: a=0.200000; break;
				case 16: a=0.200000; break;
				case 22: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 16: {
			switch (n1) {
				case 9: a=0.200000; break;
				case 15: a=0.200000; break;
				case 16: a=0.200000; break;
				case 17: a=0.200000; break;
				case 23: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 17: {
			switch (n1) {
				case 10: a=0.200000; break;
				case 16: a=0.200000; break;
				case 17: a=0.200000; break;
				case 18: a=0.200000; break;
				case 24: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 18: {
			switch (n1) {
				case 11: a=0.200000; break;
				case 17: a=0.200000; break;
				case 18: a=0.200000; break;
				case 19: a=0.200000; break;
				case 25: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 19: {
			switch (n1) {
				case 12: a=0.200000; break;
				case 18: a=0.200000; break;
				case 19: a=0.200000; break;
				case 20: a=0.200000; break;
				case 26: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 20: {
			switch (n1) {
				case 13: a=0.250000; break;
				case 19: a=0.200000; break;
				case 20: a=0.300000; break;
				case 27: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 21: {
			switch (n1) {
				case 14: a=0.250000; break;
				case 21: a=0.300000; break;
				case 22: a=0.200000; break;
				case 28: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 22: {
			switch (n1) {
				case 15: a=0.200000; break;
				case 21: a=0.200000; break;
				case 22: a=0.200000; break;
				case 23: a=0.200000; break;
				case 29: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 23: {
			switch (n1) {
				case 16: a=0.200000; break;
				case 22: a=0.200000; break;
				case 23: a=0.200000; break;
				case 24: a=0.200000; break;
				case 30: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 24: {
			switch (n1) {
				case 17: a=0.200000; break;
				case 23: a=0.200000; break;
				case 24: a=0.200000; break;
				case 25: a=0.200000; break;
				case 31: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 25: {
			switch (n1) {
				case 18: a=0.200000; break;
				case 24: a=0.200000; break;
				case 25: a=0.200000; break;
				case 26: a=0.200000; break;
				case 32: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 26: {
			switch (n1) {
				case 19: a=0.200000; break;
				case 25: a=0.200000; break;
				case 26: a=0.200000; break;
				case 27: a=0.200000; break;
				case 33: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 27: {
			switch (n1) {
				case 20: a=0.250000; break;
				case 26: a=0.200000; break;
				case 27: a=0.300000; break;
				case 34: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 28: {
			switch (n1) {
				case 21: a=0.250000; break;
				case 28: a=0.300000; break;
				case 29: a=0.200000; break;
				case 35: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 29: {
			switch (n1) {
				case 22: a=0.200000; break;
				case 28: a=0.200000; break;
				case 29: a=0.200000; break;
				case 30: a=0.200000; break;
				case 36: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 30: {
			switch (n1) {
				case 23: a=0.200000; break;
				case 29: a=0.200000; break;
				case 30: a=0.200000; break;
				case 31: a=0.200000; break;
				case 37: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 31: {
			switch (n1) {
				case 24: a=0.200000; break;
				case 30: a=0.200000; break;
				case 31: a=0.200000; break;
				case 32: a=0.200000; break;
				case 38: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 32: {
			switch (n1) {
				case 25: a=0.200000; break;
				case 31: a=0.200000; break;
				case 32: a=0.200000; break;
				case 33: a=0.200000; break;
				case 39: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 33: {
			switch (n1) {
				case 26: a=0.200000; break;
				case 32: a=0.200000; break;
				case 33: a=0.200000; break;
				case 34: a=0.200000; break;
				case 40: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 34: {
			switch (n1) {
				case 27: a=0.250000; break;
				case 33: a=0.200000; break;
				case 34: a=0.300000; break;
				case 41: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 35: {
			switch (n1) {
				case 28: a=0.250000; break;
				case 35: a=0.300000; break;
				case 36: a=0.200000; break;
				case 42: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 36: {
			switch (n1) {
				case 29: a=0.200000; break;
				case 35: a=0.200000; break;
				case 36: a=0.200000; break;
				case 37: a=0.200000; break;
				case 43: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 37: {
			switch (n1) {
				case 30: a=0.200000; break;
				case 36: a=0.200000; break;
				case 37: a=0.200000; break;
				case 38: a=0.200000; break;
				case 44: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 38: {
			switch (n1) {
				case 31: a=0.200000; break;
				case 37: a=0.200000; break;
				case 38: a=0.200000; break;
				case 39: a=0.200000; break;
				case 45: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 39: {
			switch (n1) {
				case 32: a=0.200000; break;
				case 38: a=0.200000; break;
				case 39: a=0.200000; break;
				case 40: a=0.200000; break;
				case 46: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 40: {
			switch (n1) {
				case 33: a=0.200000; break;
				case 39: a=0.200000; break;
				case 40: a=0.200000; break;
				case 41: a=0.200000; break;
				case 47: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 41: {
			switch (n1) {
				case 34: a=0.250000; break;
				case 40: a=0.200000; break;
				case 41: a=0.300000; break;
				case 48: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 42: {
			switch (n1) {
				case 35: a=0.250000; break;
				case 42: a=0.500000; break;
				case 43: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 43: {
			switch (n1) {
				case 36: a=0.200000; break;
				case 42: a=0.250000; break;
				case 43: a=0.300000; break;
				case 44: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 44: {
			switch (n1) {
				case 37: a=0.200000; break;
				case 43: a=0.250000; break;
				case 44: a=0.300000; break;
				case 45: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 45: {
			switch (n1) {
				case 38: a=0.200000; break;
				case 44: a=0.250000; break;
				case 45: a=0.300000; break;
				case 46: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 46: {
			switch (n1) {
				case 39: a=0.200000; break;
				case 45: a=0.250000; break;
				case 46: a=0.300000; break;
				case 47: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 47: {
			switch (n1) {
				case 40: a=0.200000; break;
				case 46: a=0.250000; break;
				case 47: a=0.300000; break;
				case 48: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 48: {
			switch (n1) {
				case 41: a=0.250000; break;
				case 47: a=0.250000; break;
				case 48: a=0.500000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

#endif
