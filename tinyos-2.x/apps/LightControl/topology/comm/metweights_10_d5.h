#ifndef _MET_WEIGHTS_H_
#define _MET_WEIGHTS_H_

float W(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 0: {
			switch (n1) {
				case 0: a=0.444883; break;
				case 1: a=0.071429; break;
				case 2: a=0.058824; break;
				case 3: a=0.055556; break;
				case 10: a=0.071429; break;
				case 11: a=0.055556; break;
				case 12: a=0.045455; break;
				case 20: a=0.058824; break;
				case 21: a=0.045455; break;
				case 22: a=0.037037; break;
				case 30: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 1: {
			switch (n1) {
				case 0: a=0.071429; break;
				case 1: a=0.322212; break;
				case 2: a=0.058824; break;
				case 3: a=0.055556; break;
				case 4: a=0.055556; break;
				case 10: a=0.071429; break;
				case 11: a=0.055556; break;
				case 12: a=0.045455; break;
				case 13: a=0.043478; break;
				case 20: a=0.058824; break;
				case 21: a=0.045455; break;
				case 22: a=0.037037; break;
				case 23: a=0.035714; break;
				case 31: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 2: {
			switch (n1) {
				case 0: a=0.058824; break;
				case 1: a=0.058824; break;
				case 2: a=0.220438; break;
				case 3: a=0.055556; break;
				case 4: a=0.055556; break;
				case 5: a=0.055556; break;
				case 10: a=0.058824; break;
				case 11: a=0.055556; break;
				case 12: a=0.045455; break;
				case 13: a=0.043478; break;
				case 14: a=0.043478; break;
				case 20: a=0.058824; break;
				case 21: a=0.045455; break;
				case 22: a=0.037037; break;
				case 23: a=0.035714; break;
				case 24: a=0.035714; break;
				case 32: a=0.035714; break;
				default: break;
			}
			break;
		}
		case 3: {
			switch (n1) {
				case 0: a=0.055556; break;
				case 1: a=0.055556; break;
				case 2: a=0.055556; break;
				case 3: a=0.211105; break;
				case 4: a=0.055556; break;
				case 5: a=0.055556; break;
				case 6: a=0.055556; break;
				case 11: a=0.055556; break;
				case 12: a=0.045455; break;
				case 13: a=0.043478; break;
				case 14: a=0.043478; break;
				case 15: a=0.043478; break;
				case 21: a=0.045455; break;
				case 22: a=0.037037; break;
				case 23: a=0.035714; break;
				case 24: a=0.035714; break;
				case 25: a=0.035714; break;
				case 33: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 4: {
			switch (n1) {
				case 1: a=0.055556; break;
				case 2: a=0.055556; break;
				case 3: a=0.055556; break;
				case 4: a=0.232922; break;
				case 5: a=0.055556; break;
				case 6: a=0.055556; break;
				case 7: a=0.055556; break;
				case 12: a=0.045455; break;
				case 13: a=0.043478; break;
				case 14: a=0.043478; break;
				case 15: a=0.043478; break;
				case 16: a=0.043478; break;
				case 22: a=0.037037; break;
				case 23: a=0.035714; break;
				case 24: a=0.035714; break;
				case 25: a=0.035714; break;
				case 26: a=0.035714; break;
				case 34: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 5: {
			switch (n1) {
				case 2: a=0.055556; break;
				case 3: a=0.055556; break;
				case 4: a=0.055556; break;
				case 5: a=0.232922; break;
				case 6: a=0.055556; break;
				case 7: a=0.055556; break;
				case 8: a=0.055556; break;
				case 13: a=0.043478; break;
				case 14: a=0.043478; break;
				case 15: a=0.043478; break;
				case 16: a=0.043478; break;
				case 17: a=0.045455; break;
				case 23: a=0.035714; break;
				case 24: a=0.035714; break;
				case 25: a=0.035714; break;
				case 26: a=0.035714; break;
				case 27: a=0.037037; break;
				case 35: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 6: {
			switch (n1) {
				case 3: a=0.055556; break;
				case 4: a=0.055556; break;
				case 5: a=0.055556; break;
				case 6: a=0.211105; break;
				case 7: a=0.055556; break;
				case 8: a=0.055556; break;
				case 9: a=0.055556; break;
				case 14: a=0.043478; break;
				case 15: a=0.043478; break;
				case 16: a=0.043478; break;
				case 17: a=0.045455; break;
				case 18: a=0.055556; break;
				case 24: a=0.035714; break;
				case 25: a=0.035714; break;
				case 26: a=0.035714; break;
				case 27: a=0.037037; break;
				case 28: a=0.045455; break;
				case 36: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 7: {
			switch (n1) {
				case 4: a=0.055556; break;
				case 5: a=0.055556; break;
				case 6: a=0.055556; break;
				case 7: a=0.220438; break;
				case 8: a=0.058824; break;
				case 9: a=0.058824; break;
				case 15: a=0.043478; break;
				case 16: a=0.043478; break;
				case 17: a=0.045455; break;
				case 18: a=0.055556; break;
				case 19: a=0.058824; break;
				case 25: a=0.035714; break;
				case 26: a=0.035714; break;
				case 27: a=0.037037; break;
				case 28: a=0.045455; break;
				case 29: a=0.058824; break;
				case 37: a=0.035714; break;
				default: break;
			}
			break;
		}
		case 8: {
			switch (n1) {
				case 5: a=0.055556; break;
				case 6: a=0.055556; break;
				case 7: a=0.058824; break;
				case 8: a=0.322212; break;
				case 9: a=0.071429; break;
				case 16: a=0.043478; break;
				case 17: a=0.045455; break;
				case 18: a=0.055556; break;
				case 19: a=0.071429; break;
				case 26: a=0.035714; break;
				case 27: a=0.037037; break;
				case 28: a=0.045455; break;
				case 29: a=0.058824; break;
				case 38: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 9: {
			switch (n1) {
				case 6: a=0.055556; break;
				case 7: a=0.058824; break;
				case 8: a=0.071429; break;
				case 9: a=0.444883; break;
				case 17: a=0.045455; break;
				case 18: a=0.055556; break;
				case 19: a=0.071429; break;
				case 27: a=0.037037; break;
				case 28: a=0.045455; break;
				case 29: a=0.058824; break;
				case 39: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 10: {
			switch (n1) {
				case 0: a=0.071429; break;
				case 1: a=0.071429; break;
				case 2: a=0.058824; break;
				case 10: a=0.322212; break;
				case 11: a=0.055556; break;
				case 12: a=0.045455; break;
				case 13: a=0.043478; break;
				case 20: a=0.058824; break;
				case 21: a=0.045455; break;
				case 22: a=0.037037; break;
				case 30: a=0.055556; break;
				case 31: a=0.043478; break;
				case 32: a=0.035714; break;
				case 40: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 11: {
			switch (n1) {
				case 0: a=0.055556; break;
				case 1: a=0.055556; break;
				case 2: a=0.055556; break;
				case 3: a=0.055556; break;
				case 10: a=0.055556; break;
				case 11: a=0.203341; break;
				case 12: a=0.045455; break;
				case 13: a=0.043478; break;
				case 14: a=0.043478; break;
				case 20: a=0.055556; break;
				case 21: a=0.045455; break;
				case 22: a=0.037037; break;
				case 23: a=0.035714; break;
				case 30: a=0.055556; break;
				case 31: a=0.043478; break;
				case 32: a=0.035714; break;
				case 33: a=0.034483; break;
				case 41: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 12: {
			switch (n1) {
				case 0: a=0.045455; break;
				case 1: a=0.045455; break;
				case 2: a=0.045455; break;
				case 3: a=0.045455; break;
				case 4: a=0.045455; break;
				case 10: a=0.045455; break;
				case 11: a=0.045455; break;
				case 12: a=0.122682; break;
				case 13: a=0.043478; break;
				case 14: a=0.043478; break;
				case 15: a=0.043478; break;
				case 20: a=0.045455; break;
				case 21: a=0.045455; break;
				case 22: a=0.037037; break;
				case 23: a=0.035714; break;
				case 24: a=0.035714; break;
				case 30: a=0.045455; break;
				case 31: a=0.043478; break;
				case 32: a=0.035714; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 42: a=0.035714; break;
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
				case 10: a=0.043478; break;
				case 11: a=0.043478; break;
				case 12: a=0.043478; break;
				case 13: a=0.116957; break;
				case 14: a=0.043478; break;
				case 15: a=0.043478; break;
				case 16: a=0.043478; break;
				case 21: a=0.043478; break;
				case 22: a=0.037037; break;
				case 23: a=0.035714; break;
				case 24: a=0.035714; break;
				case 25: a=0.035714; break;
				case 31: a=0.043478; break;
				case 32: a=0.035714; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 43: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 14: {
			switch (n1) {
				case 2: a=0.043478; break;
				case 3: a=0.043478; break;
				case 4: a=0.043478; break;
				case 5: a=0.043478; break;
				case 6: a=0.043478; break;
				case 11: a=0.043478; break;
				case 12: a=0.043478; break;
				case 13: a=0.043478; break;
				case 14: a=0.133717; break;
				case 15: a=0.043478; break;
				case 16: a=0.043478; break;
				case 17: a=0.043478; break;
				case 22: a=0.037037; break;
				case 23: a=0.035714; break;
				case 24: a=0.035714; break;
				case 25: a=0.035714; break;
				case 26: a=0.035714; break;
				case 32: a=0.035714; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 44: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 15: {
			switch (n1) {
				case 3: a=0.043478; break;
				case 4: a=0.043478; break;
				case 5: a=0.043478; break;
				case 6: a=0.043478; break;
				case 7: a=0.043478; break;
				case 12: a=0.043478; break;
				case 13: a=0.043478; break;
				case 14: a=0.043478; break;
				case 15: a=0.133717; break;
				case 16: a=0.043478; break;
				case 17: a=0.043478; break;
				case 18: a=0.043478; break;
				case 23: a=0.035714; break;
				case 24: a=0.035714; break;
				case 25: a=0.035714; break;
				case 26: a=0.035714; break;
				case 27: a=0.037037; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 37: a=0.035714; break;
				case 45: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 16: {
			switch (n1) {
				case 4: a=0.043478; break;
				case 5: a=0.043478; break;
				case 6: a=0.043478; break;
				case 7: a=0.043478; break;
				case 8: a=0.043478; break;
				case 13: a=0.043478; break;
				case 14: a=0.043478; break;
				case 15: a=0.043478; break;
				case 16: a=0.116957; break;
				case 17: a=0.043478; break;
				case 18: a=0.043478; break;
				case 19: a=0.043478; break;
				case 24: a=0.035714; break;
				case 25: a=0.035714; break;
				case 26: a=0.035714; break;
				case 27: a=0.037037; break;
				case 28: a=0.043478; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 37: a=0.035714; break;
				case 38: a=0.043478; break;
				case 46: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 17: {
			switch (n1) {
				case 5: a=0.045455; break;
				case 6: a=0.045455; break;
				case 7: a=0.045455; break;
				case 8: a=0.045455; break;
				case 9: a=0.045455; break;
				case 14: a=0.043478; break;
				case 15: a=0.043478; break;
				case 16: a=0.043478; break;
				case 17: a=0.122682; break;
				case 18: a=0.045455; break;
				case 19: a=0.045455; break;
				case 25: a=0.035714; break;
				case 26: a=0.035714; break;
				case 27: a=0.037037; break;
				case 28: a=0.045455; break;
				case 29: a=0.045455; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 37: a=0.035714; break;
				case 38: a=0.043478; break;
				case 39: a=0.045455; break;
				case 47: a=0.035714; break;
				default: break;
			}
			break;
		}
		case 18: {
			switch (n1) {
				case 6: a=0.055556; break;
				case 7: a=0.055556; break;
				case 8: a=0.055556; break;
				case 9: a=0.055556; break;
				case 15: a=0.043478; break;
				case 16: a=0.043478; break;
				case 17: a=0.045455; break;
				case 18: a=0.203341; break;
				case 19: a=0.055556; break;
				case 26: a=0.035714; break;
				case 27: a=0.037037; break;
				case 28: a=0.045455; break;
				case 29: a=0.055556; break;
				case 36: a=0.034483; break;
				case 37: a=0.035714; break;
				case 38: a=0.043478; break;
				case 39: a=0.055556; break;
				case 48: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 19: {
			switch (n1) {
				case 7: a=0.058824; break;
				case 8: a=0.071429; break;
				case 9: a=0.071429; break;
				case 16: a=0.043478; break;
				case 17: a=0.045455; break;
				case 18: a=0.055556; break;
				case 19: a=0.322212; break;
				case 27: a=0.037037; break;
				case 28: a=0.045455; break;
				case 29: a=0.058824; break;
				case 37: a=0.035714; break;
				case 38: a=0.043478; break;
				case 39: a=0.055556; break;
				case 49: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 20: {
			switch (n1) {
				case 0: a=0.058824; break;
				case 1: a=0.058824; break;
				case 2: a=0.058824; break;
				case 10: a=0.058824; break;
				case 11: a=0.055556; break;
				case 12: a=0.045455; break;
				case 20: a=0.220438; break;
				case 21: a=0.045455; break;
				case 22: a=0.037037; break;
				case 23: a=0.035714; break;
				case 30: a=0.055556; break;
				case 31: a=0.043478; break;
				case 32: a=0.035714; break;
				case 40: a=0.055556; break;
				case 41: a=0.043478; break;
				case 42: a=0.035714; break;
				case 50: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 21: {
			switch (n1) {
				case 0: a=0.045455; break;
				case 1: a=0.045455; break;
				case 2: a=0.045455; break;
				case 3: a=0.045455; break;
				case 10: a=0.045455; break;
				case 11: a=0.045455; break;
				case 12: a=0.045455; break;
				case 13: a=0.043478; break;
				case 20: a=0.045455; break;
				case 21: a=0.122682; break;
				case 22: a=0.037037; break;
				case 23: a=0.035714; break;
				case 24: a=0.035714; break;
				case 30: a=0.045455; break;
				case 31: a=0.043478; break;
				case 32: a=0.035714; break;
				case 33: a=0.034483; break;
				case 40: a=0.045455; break;
				case 41: a=0.043478; break;
				case 42: a=0.035714; break;
				case 43: a=0.034483; break;
				case 51: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 22: {
			switch (n1) {
				case 0: a=0.037037; break;
				case 1: a=0.037037; break;
				case 2: a=0.037037; break;
				case 3: a=0.037037; break;
				case 4: a=0.037037; break;
				case 10: a=0.037037; break;
				case 11: a=0.037037; break;
				case 12: a=0.037037; break;
				case 13: a=0.037037; break;
				case 14: a=0.037037; break;
				case 20: a=0.037037; break;
				case 21: a=0.037037; break;
				case 22: a=0.055191; break;
				case 23: a=0.035714; break;
				case 24: a=0.035714; break;
				case 25: a=0.035714; break;
				case 30: a=0.037037; break;
				case 31: a=0.037037; break;
				case 32: a=0.035714; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 40: a=0.037037; break;
				case 41: a=0.037037; break;
				case 42: a=0.035714; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 52: a=0.035714; break;
				default: break;
			}
			break;
		}
		case 23: {
			switch (n1) {
				case 1: a=0.035714; break;
				case 2: a=0.035714; break;
				case 3: a=0.035714; break;
				case 4: a=0.035714; break;
				case 5: a=0.035714; break;
				case 11: a=0.035714; break;
				case 12: a=0.035714; break;
				case 13: a=0.035714; break;
				case 14: a=0.035714; break;
				case 15: a=0.035714; break;
				case 20: a=0.035714; break;
				case 21: a=0.035714; break;
				case 22: a=0.035714; break;
				case 23: a=0.044335; break;
				case 24: a=0.035714; break;
				case 25: a=0.035714; break;
				case 26: a=0.035714; break;
				case 31: a=0.035714; break;
				case 32: a=0.035714; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 41: a=0.035714; break;
				case 42: a=0.035714; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 53: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 24: {
			switch (n1) {
				case 2: a=0.035714; break;
				case 3: a=0.035714; break;
				case 4: a=0.035714; break;
				case 5: a=0.035714; break;
				case 6: a=0.035714; break;
				case 12: a=0.035714; break;
				case 13: a=0.035714; break;
				case 14: a=0.035714; break;
				case 15: a=0.035714; break;
				case 16: a=0.035714; break;
				case 21: a=0.035714; break;
				case 22: a=0.035714; break;
				case 23: a=0.035714; break;
				case 24: a=0.046798; break;
				case 25: a=0.035714; break;
				case 26: a=0.035714; break;
				case 27: a=0.035714; break;
				case 32: a=0.035714; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 42: a=0.035714; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 54: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 25: {
			switch (n1) {
				case 3: a=0.035714; break;
				case 4: a=0.035714; break;
				case 5: a=0.035714; break;
				case 6: a=0.035714; break;
				case 7: a=0.035714; break;
				case 13: a=0.035714; break;
				case 14: a=0.035714; break;
				case 15: a=0.035714; break;
				case 16: a=0.035714; break;
				case 17: a=0.035714; break;
				case 22: a=0.035714; break;
				case 23: a=0.035714; break;
				case 24: a=0.035714; break;
				case 25: a=0.046798; break;
				case 26: a=0.035714; break;
				case 27: a=0.035714; break;
				case 28: a=0.035714; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 37: a=0.035714; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 47: a=0.035714; break;
				case 55: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 26: {
			switch (n1) {
				case 4: a=0.035714; break;
				case 5: a=0.035714; break;
				case 6: a=0.035714; break;
				case 7: a=0.035714; break;
				case 8: a=0.035714; break;
				case 14: a=0.035714; break;
				case 15: a=0.035714; break;
				case 16: a=0.035714; break;
				case 17: a=0.035714; break;
				case 18: a=0.035714; break;
				case 23: a=0.035714; break;
				case 24: a=0.035714; break;
				case 25: a=0.035714; break;
				case 26: a=0.044335; break;
				case 27: a=0.035714; break;
				case 28: a=0.035714; break;
				case 29: a=0.035714; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 37: a=0.035714; break;
				case 38: a=0.035714; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 47: a=0.035714; break;
				case 48: a=0.035714; break;
				case 56: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 27: {
			switch (n1) {
				case 5: a=0.037037; break;
				case 6: a=0.037037; break;
				case 7: a=0.037037; break;
				case 8: a=0.037037; break;
				case 9: a=0.037037; break;
				case 15: a=0.037037; break;
				case 16: a=0.037037; break;
				case 17: a=0.037037; break;
				case 18: a=0.037037; break;
				case 19: a=0.037037; break;
				case 24: a=0.035714; break;
				case 25: a=0.035714; break;
				case 26: a=0.035714; break;
				case 27: a=0.055191; break;
				case 28: a=0.037037; break;
				case 29: a=0.037037; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 37: a=0.035714; break;
				case 38: a=0.037037; break;
				case 39: a=0.037037; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 47: a=0.035714; break;
				case 48: a=0.037037; break;
				case 49: a=0.037037; break;
				case 57: a=0.035714; break;
				default: break;
			}
			break;
		}
		case 28: {
			switch (n1) {
				case 6: a=0.045455; break;
				case 7: a=0.045455; break;
				case 8: a=0.045455; break;
				case 9: a=0.045455; break;
				case 16: a=0.043478; break;
				case 17: a=0.045455; break;
				case 18: a=0.045455; break;
				case 19: a=0.045455; break;
				case 25: a=0.035714; break;
				case 26: a=0.035714; break;
				case 27: a=0.037037; break;
				case 28: a=0.122682; break;
				case 29: a=0.045455; break;
				case 36: a=0.034483; break;
				case 37: a=0.035714; break;
				case 38: a=0.043478; break;
				case 39: a=0.045455; break;
				case 46: a=0.034483; break;
				case 47: a=0.035714; break;
				case 48: a=0.043478; break;
				case 49: a=0.045455; break;
				case 58: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 29: {
			switch (n1) {
				case 7: a=0.058824; break;
				case 8: a=0.058824; break;
				case 9: a=0.058824; break;
				case 17: a=0.045455; break;
				case 18: a=0.055556; break;
				case 19: a=0.058824; break;
				case 26: a=0.035714; break;
				case 27: a=0.037037; break;
				case 28: a=0.045455; break;
				case 29: a=0.220438; break;
				case 37: a=0.035714; break;
				case 38: a=0.043478; break;
				case 39: a=0.055556; break;
				case 47: a=0.035714; break;
				case 48: a=0.043478; break;
				case 49: a=0.055556; break;
				case 59: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 30: {
			switch (n1) {
				case 0: a=0.055556; break;
				case 10: a=0.055556; break;
				case 11: a=0.055556; break;
				case 12: a=0.045455; break;
				case 20: a=0.055556; break;
				case 21: a=0.045455; break;
				case 22: a=0.037037; break;
				case 30: a=0.211105; break;
				case 31: a=0.043478; break;
				case 32: a=0.035714; break;
				case 33: a=0.034483; break;
				case 40: a=0.055556; break;
				case 41: a=0.043478; break;
				case 42: a=0.035714; break;
				case 50: a=0.055556; break;
				case 51: a=0.043478; break;
				case 52: a=0.035714; break;
				case 60: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 31: {
			switch (n1) {
				case 1: a=0.043478; break;
				case 10: a=0.043478; break;
				case 11: a=0.043478; break;
				case 12: a=0.043478; break;
				case 13: a=0.043478; break;
				case 20: a=0.043478; break;
				case 21: a=0.043478; break;
				case 22: a=0.037037; break;
				case 23: a=0.035714; break;
				case 30: a=0.043478; break;
				case 31: a=0.116957; break;
				case 32: a=0.035714; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 40: a=0.043478; break;
				case 41: a=0.043478; break;
				case 42: a=0.035714; break;
				case 43: a=0.034483; break;
				case 50: a=0.043478; break;
				case 51: a=0.043478; break;
				case 52: a=0.035714; break;
				case 53: a=0.034483; break;
				case 61: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 32: {
			switch (n1) {
				case 2: a=0.035714; break;
				case 10: a=0.035714; break;
				case 11: a=0.035714; break;
				case 12: a=0.035714; break;
				case 13: a=0.035714; break;
				case 14: a=0.035714; break;
				case 20: a=0.035714; break;
				case 21: a=0.035714; break;
				case 22: a=0.035714; break;
				case 23: a=0.035714; break;
				case 24: a=0.035714; break;
				case 30: a=0.035714; break;
				case 31: a=0.035714; break;
				case 32: a=0.044335; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 40: a=0.035714; break;
				case 41: a=0.035714; break;
				case 42: a=0.035714; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 50: a=0.035714; break;
				case 51: a=0.035714; break;
				case 52: a=0.035714; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 62: a=0.035714; break;
				default: break;
			}
			break;
		}
		case 33: {
			switch (n1) {
				case 3: a=0.034483; break;
				case 11: a=0.034483; break;
				case 12: a=0.034483; break;
				case 13: a=0.034483; break;
				case 14: a=0.034483; break;
				case 15: a=0.034483; break;
				case 21: a=0.034483; break;
				case 22: a=0.034483; break;
				case 23: a=0.034483; break;
				case 24: a=0.034483; break;
				case 25: a=0.034483; break;
				case 30: a=0.034483; break;
				case 31: a=0.034483; break;
				case 32: a=0.034483; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 41: a=0.034483; break;
				case 42: a=0.034483; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 51: a=0.034483; break;
				case 52: a=0.034483; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 63: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 34: {
			switch (n1) {
				case 4: a=0.034483; break;
				case 12: a=0.034483; break;
				case 13: a=0.034483; break;
				case 14: a=0.034483; break;
				case 15: a=0.034483; break;
				case 16: a=0.034483; break;
				case 22: a=0.034483; break;
				case 23: a=0.034483; break;
				case 24: a=0.034483; break;
				case 25: a=0.034483; break;
				case 26: a=0.034483; break;
				case 31: a=0.034483; break;
				case 32: a=0.034483; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 37: a=0.034483; break;
				case 42: a=0.034483; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 52: a=0.034483; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 64: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 35: {
			switch (n1) {
				case 5: a=0.034483; break;
				case 13: a=0.034483; break;
				case 14: a=0.034483; break;
				case 15: a=0.034483; break;
				case 16: a=0.034483; break;
				case 17: a=0.034483; break;
				case 23: a=0.034483; break;
				case 24: a=0.034483; break;
				case 25: a=0.034483; break;
				case 26: a=0.034483; break;
				case 27: a=0.034483; break;
				case 32: a=0.034483; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 37: a=0.034483; break;
				case 38: a=0.034483; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 47: a=0.034483; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 57: a=0.034483; break;
				case 65: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 36: {
			switch (n1) {
				case 6: a=0.034483; break;
				case 14: a=0.034483; break;
				case 15: a=0.034483; break;
				case 16: a=0.034483; break;
				case 17: a=0.034483; break;
				case 18: a=0.034483; break;
				case 24: a=0.034483; break;
				case 25: a=0.034483; break;
				case 26: a=0.034483; break;
				case 27: a=0.034483; break;
				case 28: a=0.034483; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 37: a=0.034483; break;
				case 38: a=0.034483; break;
				case 39: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 47: a=0.034483; break;
				case 48: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 57: a=0.034483; break;
				case 58: a=0.034483; break;
				case 66: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 37: {
			switch (n1) {
				case 7: a=0.035714; break;
				case 15: a=0.035714; break;
				case 16: a=0.035714; break;
				case 17: a=0.035714; break;
				case 18: a=0.035714; break;
				case 19: a=0.035714; break;
				case 25: a=0.035714; break;
				case 26: a=0.035714; break;
				case 27: a=0.035714; break;
				case 28: a=0.035714; break;
				case 29: a=0.035714; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 37: a=0.044335; break;
				case 38: a=0.035714; break;
				case 39: a=0.035714; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 47: a=0.035714; break;
				case 48: a=0.035714; break;
				case 49: a=0.035714; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 57: a=0.035714; break;
				case 58: a=0.035714; break;
				case 59: a=0.035714; break;
				case 67: a=0.035714; break;
				default: break;
			}
			break;
		}
		case 38: {
			switch (n1) {
				case 8: a=0.043478; break;
				case 16: a=0.043478; break;
				case 17: a=0.043478; break;
				case 18: a=0.043478; break;
				case 19: a=0.043478; break;
				case 26: a=0.035714; break;
				case 27: a=0.037037; break;
				case 28: a=0.043478; break;
				case 29: a=0.043478; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 37: a=0.035714; break;
				case 38: a=0.116957; break;
				case 39: a=0.043478; break;
				case 46: a=0.034483; break;
				case 47: a=0.035714; break;
				case 48: a=0.043478; break;
				case 49: a=0.043478; break;
				case 56: a=0.034483; break;
				case 57: a=0.035714; break;
				case 58: a=0.043478; break;
				case 59: a=0.043478; break;
				case 68: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 39: {
			switch (n1) {
				case 9: a=0.055556; break;
				case 17: a=0.045455; break;
				case 18: a=0.055556; break;
				case 19: a=0.055556; break;
				case 27: a=0.037037; break;
				case 28: a=0.045455; break;
				case 29: a=0.055556; break;
				case 36: a=0.034483; break;
				case 37: a=0.035714; break;
				case 38: a=0.043478; break;
				case 39: a=0.211105; break;
				case 47: a=0.035714; break;
				case 48: a=0.043478; break;
				case 49: a=0.055556; break;
				case 57: a=0.035714; break;
				case 58: a=0.043478; break;
				case 59: a=0.055556; break;
				case 69: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 40: {
			switch (n1) {
				case 10: a=0.055556; break;
				case 20: a=0.055556; break;
				case 21: a=0.045455; break;
				case 22: a=0.037037; break;
				case 30: a=0.055556; break;
				case 31: a=0.043478; break;
				case 32: a=0.035714; break;
				case 40: a=0.232922; break;
				case 41: a=0.043478; break;
				case 42: a=0.035714; break;
				case 43: a=0.034483; break;
				case 50: a=0.055556; break;
				case 51: a=0.043478; break;
				case 52: a=0.035714; break;
				case 60: a=0.055556; break;
				case 61: a=0.043478; break;
				case 62: a=0.035714; break;
				case 70: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 41: {
			switch (n1) {
				case 11: a=0.043478; break;
				case 20: a=0.043478; break;
				case 21: a=0.043478; break;
				case 22: a=0.037037; break;
				case 23: a=0.035714; break;
				case 30: a=0.043478; break;
				case 31: a=0.043478; break;
				case 32: a=0.035714; break;
				case 33: a=0.034483; break;
				case 40: a=0.043478; break;
				case 41: a=0.133717; break;
				case 42: a=0.035714; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 50: a=0.043478; break;
				case 51: a=0.043478; break;
				case 52: a=0.035714; break;
				case 53: a=0.034483; break;
				case 60: a=0.043478; break;
				case 61: a=0.043478; break;
				case 62: a=0.035714; break;
				case 63: a=0.034483; break;
				case 71: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 42: {
			switch (n1) {
				case 12: a=0.035714; break;
				case 20: a=0.035714; break;
				case 21: a=0.035714; break;
				case 22: a=0.035714; break;
				case 23: a=0.035714; break;
				case 24: a=0.035714; break;
				case 30: a=0.035714; break;
				case 31: a=0.035714; break;
				case 32: a=0.035714; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 40: a=0.035714; break;
				case 41: a=0.035714; break;
				case 42: a=0.046798; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 50: a=0.035714; break;
				case 51: a=0.035714; break;
				case 52: a=0.035714; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 60: a=0.035714; break;
				case 61: a=0.035714; break;
				case 62: a=0.035714; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 72: a=0.035714; break;
				default: break;
			}
			break;
		}
		case 43: {
			switch (n1) {
				case 13: a=0.034483; break;
				case 21: a=0.034483; break;
				case 22: a=0.034483; break;
				case 23: a=0.034483; break;
				case 24: a=0.034483; break;
				case 25: a=0.034483; break;
				case 31: a=0.034483; break;
				case 32: a=0.034483; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 40: a=0.034483; break;
				case 41: a=0.034483; break;
				case 42: a=0.034483; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 51: a=0.034483; break;
				case 52: a=0.034483; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 61: a=0.034483; break;
				case 62: a=0.034483; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 73: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 44: {
			switch (n1) {
				case 14: a=0.034483; break;
				case 22: a=0.034483; break;
				case 23: a=0.034483; break;
				case 24: a=0.034483; break;
				case 25: a=0.034483; break;
				case 26: a=0.034483; break;
				case 32: a=0.034483; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 41: a=0.034483; break;
				case 42: a=0.034483; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 47: a=0.034483; break;
				case 52: a=0.034483; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 62: a=0.034483; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 74: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 45: {
			switch (n1) {
				case 15: a=0.034483; break;
				case 23: a=0.034483; break;
				case 24: a=0.034483; break;
				case 25: a=0.034483; break;
				case 26: a=0.034483; break;
				case 27: a=0.034483; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 37: a=0.034483; break;
				case 42: a=0.034483; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 47: a=0.034483; break;
				case 48: a=0.034483; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 57: a=0.034483; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 67: a=0.034483; break;
				case 75: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 46: {
			switch (n1) {
				case 16: a=0.034483; break;
				case 24: a=0.034483; break;
				case 25: a=0.034483; break;
				case 26: a=0.034483; break;
				case 27: a=0.034483; break;
				case 28: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 37: a=0.034483; break;
				case 38: a=0.034483; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 47: a=0.034483; break;
				case 48: a=0.034483; break;
				case 49: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 57: a=0.034483; break;
				case 58: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 67: a=0.034483; break;
				case 68: a=0.034483; break;
				case 76: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 47: {
			switch (n1) {
				case 17: a=0.035714; break;
				case 25: a=0.035714; break;
				case 26: a=0.035714; break;
				case 27: a=0.035714; break;
				case 28: a=0.035714; break;
				case 29: a=0.035714; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 37: a=0.035714; break;
				case 38: a=0.035714; break;
				case 39: a=0.035714; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 47: a=0.046798; break;
				case 48: a=0.035714; break;
				case 49: a=0.035714; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 57: a=0.035714; break;
				case 58: a=0.035714; break;
				case 59: a=0.035714; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 67: a=0.035714; break;
				case 68: a=0.035714; break;
				case 69: a=0.035714; break;
				case 77: a=0.035714; break;
				default: break;
			}
			break;
		}
		case 48: {
			switch (n1) {
				case 18: a=0.043478; break;
				case 26: a=0.035714; break;
				case 27: a=0.037037; break;
				case 28: a=0.043478; break;
				case 29: a=0.043478; break;
				case 36: a=0.034483; break;
				case 37: a=0.035714; break;
				case 38: a=0.043478; break;
				case 39: a=0.043478; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 47: a=0.035714; break;
				case 48: a=0.133717; break;
				case 49: a=0.043478; break;
				case 56: a=0.034483; break;
				case 57: a=0.035714; break;
				case 58: a=0.043478; break;
				case 59: a=0.043478; break;
				case 66: a=0.034483; break;
				case 67: a=0.035714; break;
				case 68: a=0.043478; break;
				case 69: a=0.043478; break;
				case 78: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 49: {
			switch (n1) {
				case 19: a=0.055556; break;
				case 27: a=0.037037; break;
				case 28: a=0.045455; break;
				case 29: a=0.055556; break;
				case 37: a=0.035714; break;
				case 38: a=0.043478; break;
				case 39: a=0.055556; break;
				case 46: a=0.034483; break;
				case 47: a=0.035714; break;
				case 48: a=0.043478; break;
				case 49: a=0.232922; break;
				case 57: a=0.035714; break;
				case 58: a=0.043478; break;
				case 59: a=0.055556; break;
				case 67: a=0.035714; break;
				case 68: a=0.043478; break;
				case 69: a=0.055556; break;
				case 79: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 50: {
			switch (n1) {
				case 20: a=0.055556; break;
				case 30: a=0.055556; break;
				case 31: a=0.043478; break;
				case 32: a=0.035714; break;
				case 40: a=0.055556; break;
				case 41: a=0.043478; break;
				case 42: a=0.035714; break;
				case 50: a=0.232922; break;
				case 51: a=0.043478; break;
				case 52: a=0.035714; break;
				case 53: a=0.034483; break;
				case 60: a=0.055556; break;
				case 61: a=0.043478; break;
				case 62: a=0.035714; break;
				case 70: a=0.055556; break;
				case 71: a=0.045455; break;
				case 72: a=0.037037; break;
				case 80: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 51: {
			switch (n1) {
				case 21: a=0.043478; break;
				case 30: a=0.043478; break;
				case 31: a=0.043478; break;
				case 32: a=0.035714; break;
				case 33: a=0.034483; break;
				case 40: a=0.043478; break;
				case 41: a=0.043478; break;
				case 42: a=0.035714; break;
				case 43: a=0.034483; break;
				case 50: a=0.043478; break;
				case 51: a=0.133717; break;
				case 52: a=0.035714; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 60: a=0.043478; break;
				case 61: a=0.043478; break;
				case 62: a=0.035714; break;
				case 63: a=0.034483; break;
				case 70: a=0.043478; break;
				case 71: a=0.043478; break;
				case 72: a=0.037037; break;
				case 73: a=0.035714; break;
				case 81: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 52: {
			switch (n1) {
				case 22: a=0.035714; break;
				case 30: a=0.035714; break;
				case 31: a=0.035714; break;
				case 32: a=0.035714; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 40: a=0.035714; break;
				case 41: a=0.035714; break;
				case 42: a=0.035714; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 50: a=0.035714; break;
				case 51: a=0.035714; break;
				case 52: a=0.046798; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 60: a=0.035714; break;
				case 61: a=0.035714; break;
				case 62: a=0.035714; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 70: a=0.035714; break;
				case 71: a=0.035714; break;
				case 72: a=0.035714; break;
				case 73: a=0.035714; break;
				case 74: a=0.035714; break;
				case 82: a=0.035714; break;
				default: break;
			}
			break;
		}
		case 53: {
			switch (n1) {
				case 23: a=0.034483; break;
				case 31: a=0.034483; break;
				case 32: a=0.034483; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 41: a=0.034483; break;
				case 42: a=0.034483; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 50: a=0.034483; break;
				case 51: a=0.034483; break;
				case 52: a=0.034483; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 61: a=0.034483; break;
				case 62: a=0.034483; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 71: a=0.034483; break;
				case 72: a=0.034483; break;
				case 73: a=0.034483; break;
				case 74: a=0.034483; break;
				case 75: a=0.034483; break;
				case 83: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 54: {
			switch (n1) {
				case 24: a=0.034483; break;
				case 32: a=0.034483; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 42: a=0.034483; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 51: a=0.034483; break;
				case 52: a=0.034483; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 57: a=0.034483; break;
				case 62: a=0.034483; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 72: a=0.034483; break;
				case 73: a=0.034483; break;
				case 74: a=0.034483; break;
				case 75: a=0.034483; break;
				case 76: a=0.034483; break;
				case 84: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 55: {
			switch (n1) {
				case 25: a=0.034483; break;
				case 33: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 37: a=0.034483; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 47: a=0.034483; break;
				case 52: a=0.034483; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 57: a=0.034483; break;
				case 58: a=0.034483; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 67: a=0.034483; break;
				case 73: a=0.034483; break;
				case 74: a=0.034483; break;
				case 75: a=0.034483; break;
				case 76: a=0.034483; break;
				case 77: a=0.034483; break;
				case 85: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 56: {
			switch (n1) {
				case 26: a=0.034483; break;
				case 34: a=0.034483; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 37: a=0.034483; break;
				case 38: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 47: a=0.034483; break;
				case 48: a=0.034483; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 57: a=0.034483; break;
				case 58: a=0.034483; break;
				case 59: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 67: a=0.034483; break;
				case 68: a=0.034483; break;
				case 74: a=0.034483; break;
				case 75: a=0.034483; break;
				case 76: a=0.034483; break;
				case 77: a=0.034483; break;
				case 78: a=0.034483; break;
				case 86: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 57: {
			switch (n1) {
				case 27: a=0.035714; break;
				case 35: a=0.034483; break;
				case 36: a=0.034483; break;
				case 37: a=0.035714; break;
				case 38: a=0.035714; break;
				case 39: a=0.035714; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 47: a=0.035714; break;
				case 48: a=0.035714; break;
				case 49: a=0.035714; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 57: a=0.046798; break;
				case 58: a=0.035714; break;
				case 59: a=0.035714; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 67: a=0.035714; break;
				case 68: a=0.035714; break;
				case 69: a=0.035714; break;
				case 75: a=0.035714; break;
				case 76: a=0.035714; break;
				case 77: a=0.035714; break;
				case 78: a=0.035714; break;
				case 79: a=0.035714; break;
				case 87: a=0.035714; break;
				default: break;
			}
			break;
		}
		case 58: {
			switch (n1) {
				case 28: a=0.043478; break;
				case 36: a=0.034483; break;
				case 37: a=0.035714; break;
				case 38: a=0.043478; break;
				case 39: a=0.043478; break;
				case 46: a=0.034483; break;
				case 47: a=0.035714; break;
				case 48: a=0.043478; break;
				case 49: a=0.043478; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 57: a=0.035714; break;
				case 58: a=0.133717; break;
				case 59: a=0.043478; break;
				case 66: a=0.034483; break;
				case 67: a=0.035714; break;
				case 68: a=0.043478; break;
				case 69: a=0.043478; break;
				case 76: a=0.035714; break;
				case 77: a=0.037037; break;
				case 78: a=0.043478; break;
				case 79: a=0.043478; break;
				case 88: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 59: {
			switch (n1) {
				case 29: a=0.055556; break;
				case 37: a=0.035714; break;
				case 38: a=0.043478; break;
				case 39: a=0.055556; break;
				case 47: a=0.035714; break;
				case 48: a=0.043478; break;
				case 49: a=0.055556; break;
				case 56: a=0.034483; break;
				case 57: a=0.035714; break;
				case 58: a=0.043478; break;
				case 59: a=0.232922; break;
				case 67: a=0.035714; break;
				case 68: a=0.043478; break;
				case 69: a=0.055556; break;
				case 77: a=0.037037; break;
				case 78: a=0.045455; break;
				case 79: a=0.055556; break;
				case 89: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 60: {
			switch (n1) {
				case 30: a=0.055556; break;
				case 40: a=0.055556; break;
				case 41: a=0.043478; break;
				case 42: a=0.035714; break;
				case 50: a=0.055556; break;
				case 51: a=0.043478; break;
				case 52: a=0.035714; break;
				case 60: a=0.211105; break;
				case 61: a=0.043478; break;
				case 62: a=0.035714; break;
				case 63: a=0.034483; break;
				case 70: a=0.055556; break;
				case 71: a=0.045455; break;
				case 72: a=0.037037; break;
				case 80: a=0.055556; break;
				case 81: a=0.055556; break;
				case 82: a=0.045455; break;
				case 90: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 61: {
			switch (n1) {
				case 31: a=0.043478; break;
				case 40: a=0.043478; break;
				case 41: a=0.043478; break;
				case 42: a=0.035714; break;
				case 43: a=0.034483; break;
				case 50: a=0.043478; break;
				case 51: a=0.043478; break;
				case 52: a=0.035714; break;
				case 53: a=0.034483; break;
				case 60: a=0.043478; break;
				case 61: a=0.116957; break;
				case 62: a=0.035714; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 70: a=0.043478; break;
				case 71: a=0.043478; break;
				case 72: a=0.037037; break;
				case 73: a=0.035714; break;
				case 80: a=0.043478; break;
				case 81: a=0.043478; break;
				case 82: a=0.043478; break;
				case 83: a=0.043478; break;
				case 91: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 62: {
			switch (n1) {
				case 32: a=0.035714; break;
				case 40: a=0.035714; break;
				case 41: a=0.035714; break;
				case 42: a=0.035714; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 50: a=0.035714; break;
				case 51: a=0.035714; break;
				case 52: a=0.035714; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 60: a=0.035714; break;
				case 61: a=0.035714; break;
				case 62: a=0.044335; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 70: a=0.035714; break;
				case 71: a=0.035714; break;
				case 72: a=0.035714; break;
				case 73: a=0.035714; break;
				case 74: a=0.035714; break;
				case 80: a=0.035714; break;
				case 81: a=0.035714; break;
				case 82: a=0.035714; break;
				case 83: a=0.035714; break;
				case 84: a=0.035714; break;
				case 92: a=0.035714; break;
				default: break;
			}
			break;
		}
		case 63: {
			switch (n1) {
				case 33: a=0.034483; break;
				case 41: a=0.034483; break;
				case 42: a=0.034483; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 51: a=0.034483; break;
				case 52: a=0.034483; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 60: a=0.034483; break;
				case 61: a=0.034483; break;
				case 62: a=0.034483; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 71: a=0.034483; break;
				case 72: a=0.034483; break;
				case 73: a=0.034483; break;
				case 74: a=0.034483; break;
				case 75: a=0.034483; break;
				case 81: a=0.034483; break;
				case 82: a=0.034483; break;
				case 83: a=0.034483; break;
				case 84: a=0.034483; break;
				case 85: a=0.034483; break;
				case 93: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 64: {
			switch (n1) {
				case 34: a=0.034483; break;
				case 42: a=0.034483; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 52: a=0.034483; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 61: a=0.034483; break;
				case 62: a=0.034483; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 67: a=0.034483; break;
				case 72: a=0.034483; break;
				case 73: a=0.034483; break;
				case 74: a=0.034483; break;
				case 75: a=0.034483; break;
				case 76: a=0.034483; break;
				case 82: a=0.034483; break;
				case 83: a=0.034483; break;
				case 84: a=0.034483; break;
				case 85: a=0.034483; break;
				case 86: a=0.034483; break;
				case 94: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 65: {
			switch (n1) {
				case 35: a=0.034483; break;
				case 43: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 47: a=0.034483; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 57: a=0.034483; break;
				case 62: a=0.034483; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 67: a=0.034483; break;
				case 68: a=0.034483; break;
				case 73: a=0.034483; break;
				case 74: a=0.034483; break;
				case 75: a=0.034483; break;
				case 76: a=0.034483; break;
				case 77: a=0.034483; break;
				case 83: a=0.034483; break;
				case 84: a=0.034483; break;
				case 85: a=0.034483; break;
				case 86: a=0.034483; break;
				case 87: a=0.034483; break;
				case 95: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 66: {
			switch (n1) {
				case 36: a=0.034483; break;
				case 44: a=0.034483; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 47: a=0.034483; break;
				case 48: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 57: a=0.034483; break;
				case 58: a=0.034483; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 67: a=0.034483; break;
				case 68: a=0.034483; break;
				case 69: a=0.034483; break;
				case 74: a=0.034483; break;
				case 75: a=0.034483; break;
				case 76: a=0.034483; break;
				case 77: a=0.034483; break;
				case 78: a=0.034483; break;
				case 84: a=0.034483; break;
				case 85: a=0.034483; break;
				case 86: a=0.034483; break;
				case 87: a=0.034483; break;
				case 88: a=0.034483; break;
				case 96: a=0.034483; break;
				default: break;
			}
			break;
		}
		case 67: {
			switch (n1) {
				case 37: a=0.035714; break;
				case 45: a=0.034483; break;
				case 46: a=0.034483; break;
				case 47: a=0.035714; break;
				case 48: a=0.035714; break;
				case 49: a=0.035714; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 57: a=0.035714; break;
				case 58: a=0.035714; break;
				case 59: a=0.035714; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 67: a=0.044335; break;
				case 68: a=0.035714; break;
				case 69: a=0.035714; break;
				case 75: a=0.035714; break;
				case 76: a=0.035714; break;
				case 77: a=0.035714; break;
				case 78: a=0.035714; break;
				case 79: a=0.035714; break;
				case 85: a=0.035714; break;
				case 86: a=0.035714; break;
				case 87: a=0.035714; break;
				case 88: a=0.035714; break;
				case 89: a=0.035714; break;
				case 97: a=0.035714; break;
				default: break;
			}
			break;
		}
		case 68: {
			switch (n1) {
				case 38: a=0.043478; break;
				case 46: a=0.034483; break;
				case 47: a=0.035714; break;
				case 48: a=0.043478; break;
				case 49: a=0.043478; break;
				case 56: a=0.034483; break;
				case 57: a=0.035714; break;
				case 58: a=0.043478; break;
				case 59: a=0.043478; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 67: a=0.035714; break;
				case 68: a=0.116957; break;
				case 69: a=0.043478; break;
				case 76: a=0.035714; break;
				case 77: a=0.037037; break;
				case 78: a=0.043478; break;
				case 79: a=0.043478; break;
				case 86: a=0.043478; break;
				case 87: a=0.043478; break;
				case 88: a=0.043478; break;
				case 89: a=0.043478; break;
				case 98: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 69: {
			switch (n1) {
				case 39: a=0.055556; break;
				case 47: a=0.035714; break;
				case 48: a=0.043478; break;
				case 49: a=0.055556; break;
				case 57: a=0.035714; break;
				case 58: a=0.043478; break;
				case 59: a=0.055556; break;
				case 66: a=0.034483; break;
				case 67: a=0.035714; break;
				case 68: a=0.043478; break;
				case 69: a=0.211105; break;
				case 77: a=0.037037; break;
				case 78: a=0.045455; break;
				case 79: a=0.055556; break;
				case 87: a=0.045455; break;
				case 88: a=0.055556; break;
				case 89: a=0.055556; break;
				case 99: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 70: {
			switch (n1) {
				case 40: a=0.055556; break;
				case 50: a=0.055556; break;
				case 51: a=0.043478; break;
				case 52: a=0.035714; break;
				case 60: a=0.055556; break;
				case 61: a=0.043478; break;
				case 62: a=0.035714; break;
				case 70: a=0.220438; break;
				case 71: a=0.045455; break;
				case 72: a=0.037037; break;
				case 73: a=0.035714; break;
				case 80: a=0.058824; break;
				case 81: a=0.055556; break;
				case 82: a=0.045455; break;
				case 90: a=0.058824; break;
				case 91: a=0.058824; break;
				case 92: a=0.058824; break;
				default: break;
			}
			break;
		}
		case 71: {
			switch (n1) {
				case 41: a=0.043478; break;
				case 50: a=0.045455; break;
				case 51: a=0.043478; break;
				case 52: a=0.035714; break;
				case 53: a=0.034483; break;
				case 60: a=0.045455; break;
				case 61: a=0.043478; break;
				case 62: a=0.035714; break;
				case 63: a=0.034483; break;
				case 70: a=0.045455; break;
				case 71: a=0.122682; break;
				case 72: a=0.037037; break;
				case 73: a=0.035714; break;
				case 74: a=0.035714; break;
				case 80: a=0.045455; break;
				case 81: a=0.045455; break;
				case 82: a=0.045455; break;
				case 83: a=0.043478; break;
				case 90: a=0.045455; break;
				case 91: a=0.045455; break;
				case 92: a=0.045455; break;
				case 93: a=0.045455; break;
				default: break;
			}
			break;
		}
		case 72: {
			switch (n1) {
				case 42: a=0.035714; break;
				case 50: a=0.037037; break;
				case 51: a=0.037037; break;
				case 52: a=0.035714; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 60: a=0.037037; break;
				case 61: a=0.037037; break;
				case 62: a=0.035714; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 70: a=0.037037; break;
				case 71: a=0.037037; break;
				case 72: a=0.055191; break;
				case 73: a=0.035714; break;
				case 74: a=0.035714; break;
				case 75: a=0.035714; break;
				case 80: a=0.037037; break;
				case 81: a=0.037037; break;
				case 82: a=0.037037; break;
				case 83: a=0.037037; break;
				case 84: a=0.037037; break;
				case 90: a=0.037037; break;
				case 91: a=0.037037; break;
				case 92: a=0.037037; break;
				case 93: a=0.037037; break;
				case 94: a=0.037037; break;
				default: break;
			}
			break;
		}
		case 73: {
			switch (n1) {
				case 43: a=0.034483; break;
				case 51: a=0.035714; break;
				case 52: a=0.035714; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 61: a=0.035714; break;
				case 62: a=0.035714; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 70: a=0.035714; break;
				case 71: a=0.035714; break;
				case 72: a=0.035714; break;
				case 73: a=0.044335; break;
				case 74: a=0.035714; break;
				case 75: a=0.035714; break;
				case 76: a=0.035714; break;
				case 81: a=0.035714; break;
				case 82: a=0.035714; break;
				case 83: a=0.035714; break;
				case 84: a=0.035714; break;
				case 85: a=0.035714; break;
				case 91: a=0.035714; break;
				case 92: a=0.035714; break;
				case 93: a=0.035714; break;
				case 94: a=0.035714; break;
				case 95: a=0.035714; break;
				default: break;
			}
			break;
		}
		case 74: {
			switch (n1) {
				case 44: a=0.034483; break;
				case 52: a=0.035714; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 62: a=0.035714; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 71: a=0.035714; break;
				case 72: a=0.035714; break;
				case 73: a=0.035714; break;
				case 74: a=0.046798; break;
				case 75: a=0.035714; break;
				case 76: a=0.035714; break;
				case 77: a=0.035714; break;
				case 82: a=0.035714; break;
				case 83: a=0.035714; break;
				case 84: a=0.035714; break;
				case 85: a=0.035714; break;
				case 86: a=0.035714; break;
				case 92: a=0.035714; break;
				case 93: a=0.035714; break;
				case 94: a=0.035714; break;
				case 95: a=0.035714; break;
				case 96: a=0.035714; break;
				default: break;
			}
			break;
		}
		case 75: {
			switch (n1) {
				case 45: a=0.034483; break;
				case 53: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 57: a=0.035714; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 67: a=0.035714; break;
				case 72: a=0.035714; break;
				case 73: a=0.035714; break;
				case 74: a=0.035714; break;
				case 75: a=0.046798; break;
				case 76: a=0.035714; break;
				case 77: a=0.035714; break;
				case 78: a=0.035714; break;
				case 83: a=0.035714; break;
				case 84: a=0.035714; break;
				case 85: a=0.035714; break;
				case 86: a=0.035714; break;
				case 87: a=0.035714; break;
				case 93: a=0.035714; break;
				case 94: a=0.035714; break;
				case 95: a=0.035714; break;
				case 96: a=0.035714; break;
				case 97: a=0.035714; break;
				default: break;
			}
			break;
		}
		case 76: {
			switch (n1) {
				case 46: a=0.034483; break;
				case 54: a=0.034483; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 57: a=0.035714; break;
				case 58: a=0.035714; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 67: a=0.035714; break;
				case 68: a=0.035714; break;
				case 73: a=0.035714; break;
				case 74: a=0.035714; break;
				case 75: a=0.035714; break;
				case 76: a=0.044335; break;
				case 77: a=0.035714; break;
				case 78: a=0.035714; break;
				case 79: a=0.035714; break;
				case 84: a=0.035714; break;
				case 85: a=0.035714; break;
				case 86: a=0.035714; break;
				case 87: a=0.035714; break;
				case 88: a=0.035714; break;
				case 94: a=0.035714; break;
				case 95: a=0.035714; break;
				case 96: a=0.035714; break;
				case 97: a=0.035714; break;
				case 98: a=0.035714; break;
				default: break;
			}
			break;
		}
		case 77: {
			switch (n1) {
				case 47: a=0.035714; break;
				case 55: a=0.034483; break;
				case 56: a=0.034483; break;
				case 57: a=0.035714; break;
				case 58: a=0.037037; break;
				case 59: a=0.037037; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 67: a=0.035714; break;
				case 68: a=0.037037; break;
				case 69: a=0.037037; break;
				case 74: a=0.035714; break;
				case 75: a=0.035714; break;
				case 76: a=0.035714; break;
				case 77: a=0.055191; break;
				case 78: a=0.037037; break;
				case 79: a=0.037037; break;
				case 85: a=0.037037; break;
				case 86: a=0.037037; break;
				case 87: a=0.037037; break;
				case 88: a=0.037037; break;
				case 89: a=0.037037; break;
				case 95: a=0.037037; break;
				case 96: a=0.037037; break;
				case 97: a=0.037037; break;
				case 98: a=0.037037; break;
				case 99: a=0.037037; break;
				default: break;
			}
			break;
		}
		case 78: {
			switch (n1) {
				case 48: a=0.043478; break;
				case 56: a=0.034483; break;
				case 57: a=0.035714; break;
				case 58: a=0.043478; break;
				case 59: a=0.045455; break;
				case 66: a=0.034483; break;
				case 67: a=0.035714; break;
				case 68: a=0.043478; break;
				case 69: a=0.045455; break;
				case 75: a=0.035714; break;
				case 76: a=0.035714; break;
				case 77: a=0.037037; break;
				case 78: a=0.122682; break;
				case 79: a=0.045455; break;
				case 86: a=0.043478; break;
				case 87: a=0.045455; break;
				case 88: a=0.045455; break;
				case 89: a=0.045455; break;
				case 96: a=0.045455; break;
				case 97: a=0.045455; break;
				case 98: a=0.045455; break;
				case 99: a=0.045455; break;
				default: break;
			}
			break;
		}
		case 79: {
			switch (n1) {
				case 49: a=0.055556; break;
				case 57: a=0.035714; break;
				case 58: a=0.043478; break;
				case 59: a=0.055556; break;
				case 67: a=0.035714; break;
				case 68: a=0.043478; break;
				case 69: a=0.055556; break;
				case 76: a=0.035714; break;
				case 77: a=0.037037; break;
				case 78: a=0.045455; break;
				case 79: a=0.220438; break;
				case 87: a=0.045455; break;
				case 88: a=0.055556; break;
				case 89: a=0.058824; break;
				case 97: a=0.058824; break;
				case 98: a=0.058824; break;
				case 99: a=0.058824; break;
				default: break;
			}
			break;
		}
		case 80: {
			switch (n1) {
				case 50: a=0.055556; break;
				case 60: a=0.055556; break;
				case 61: a=0.043478; break;
				case 62: a=0.035714; break;
				case 70: a=0.058824; break;
				case 71: a=0.045455; break;
				case 72: a=0.037037; break;
				case 80: a=0.322212; break;
				case 81: a=0.055556; break;
				case 82: a=0.045455; break;
				case 83: a=0.043478; break;
				case 90: a=0.071429; break;
				case 91: a=0.071429; break;
				case 92: a=0.058824; break;
				default: break;
			}
			break;
		}
		case 81: {
			switch (n1) {
				case 51: a=0.043478; break;
				case 60: a=0.055556; break;
				case 61: a=0.043478; break;
				case 62: a=0.035714; break;
				case 63: a=0.034483; break;
				case 70: a=0.055556; break;
				case 71: a=0.045455; break;
				case 72: a=0.037037; break;
				case 73: a=0.035714; break;
				case 80: a=0.055556; break;
				case 81: a=0.203341; break;
				case 82: a=0.045455; break;
				case 83: a=0.043478; break;
				case 84: a=0.043478; break;
				case 90: a=0.055556; break;
				case 91: a=0.055556; break;
				case 92: a=0.055556; break;
				case 93: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 82: {
			switch (n1) {
				case 52: a=0.035714; break;
				case 60: a=0.045455; break;
				case 61: a=0.043478; break;
				case 62: a=0.035714; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 70: a=0.045455; break;
				case 71: a=0.045455; break;
				case 72: a=0.037037; break;
				case 73: a=0.035714; break;
				case 74: a=0.035714; break;
				case 80: a=0.045455; break;
				case 81: a=0.045455; break;
				case 82: a=0.122682; break;
				case 83: a=0.043478; break;
				case 84: a=0.043478; break;
				case 85: a=0.043478; break;
				case 90: a=0.045455; break;
				case 91: a=0.045455; break;
				case 92: a=0.045455; break;
				case 93: a=0.045455; break;
				case 94: a=0.045455; break;
				default: break;
			}
			break;
		}
		case 83: {
			switch (n1) {
				case 53: a=0.034483; break;
				case 61: a=0.043478; break;
				case 62: a=0.035714; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 71: a=0.043478; break;
				case 72: a=0.037037; break;
				case 73: a=0.035714; break;
				case 74: a=0.035714; break;
				case 75: a=0.035714; break;
				case 80: a=0.043478; break;
				case 81: a=0.043478; break;
				case 82: a=0.043478; break;
				case 83: a=0.116957; break;
				case 84: a=0.043478; break;
				case 85: a=0.043478; break;
				case 86: a=0.043478; break;
				case 91: a=0.043478; break;
				case 92: a=0.043478; break;
				case 93: a=0.043478; break;
				case 94: a=0.043478; break;
				case 95: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 84: {
			switch (n1) {
				case 54: a=0.034483; break;
				case 62: a=0.035714; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 72: a=0.037037; break;
				case 73: a=0.035714; break;
				case 74: a=0.035714; break;
				case 75: a=0.035714; break;
				case 76: a=0.035714; break;
				case 81: a=0.043478; break;
				case 82: a=0.043478; break;
				case 83: a=0.043478; break;
				case 84: a=0.133717; break;
				case 85: a=0.043478; break;
				case 86: a=0.043478; break;
				case 87: a=0.043478; break;
				case 92: a=0.043478; break;
				case 93: a=0.043478; break;
				case 94: a=0.043478; break;
				case 95: a=0.043478; break;
				case 96: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 85: {
			switch (n1) {
				case 55: a=0.034483; break;
				case 63: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 67: a=0.035714; break;
				case 73: a=0.035714; break;
				case 74: a=0.035714; break;
				case 75: a=0.035714; break;
				case 76: a=0.035714; break;
				case 77: a=0.037037; break;
				case 82: a=0.043478; break;
				case 83: a=0.043478; break;
				case 84: a=0.043478; break;
				case 85: a=0.133717; break;
				case 86: a=0.043478; break;
				case 87: a=0.043478; break;
				case 88: a=0.043478; break;
				case 93: a=0.043478; break;
				case 94: a=0.043478; break;
				case 95: a=0.043478; break;
				case 96: a=0.043478; break;
				case 97: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 86: {
			switch (n1) {
				case 56: a=0.034483; break;
				case 64: a=0.034483; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 67: a=0.035714; break;
				case 68: a=0.043478; break;
				case 74: a=0.035714; break;
				case 75: a=0.035714; break;
				case 76: a=0.035714; break;
				case 77: a=0.037037; break;
				case 78: a=0.043478; break;
				case 83: a=0.043478; break;
				case 84: a=0.043478; break;
				case 85: a=0.043478; break;
				case 86: a=0.116957; break;
				case 87: a=0.043478; break;
				case 88: a=0.043478; break;
				case 89: a=0.043478; break;
				case 94: a=0.043478; break;
				case 95: a=0.043478; break;
				case 96: a=0.043478; break;
				case 97: a=0.043478; break;
				case 98: a=0.043478; break;
				default: break;
			}
			break;
		}
		case 87: {
			switch (n1) {
				case 57: a=0.035714; break;
				case 65: a=0.034483; break;
				case 66: a=0.034483; break;
				case 67: a=0.035714; break;
				case 68: a=0.043478; break;
				case 69: a=0.045455; break;
				case 75: a=0.035714; break;
				case 76: a=0.035714; break;
				case 77: a=0.037037; break;
				case 78: a=0.045455; break;
				case 79: a=0.045455; break;
				case 84: a=0.043478; break;
				case 85: a=0.043478; break;
				case 86: a=0.043478; break;
				case 87: a=0.122682; break;
				case 88: a=0.045455; break;
				case 89: a=0.045455; break;
				case 95: a=0.045455; break;
				case 96: a=0.045455; break;
				case 97: a=0.045455; break;
				case 98: a=0.045455; break;
				case 99: a=0.045455; break;
				default: break;
			}
			break;
		}
		case 88: {
			switch (n1) {
				case 58: a=0.043478; break;
				case 66: a=0.034483; break;
				case 67: a=0.035714; break;
				case 68: a=0.043478; break;
				case 69: a=0.055556; break;
				case 76: a=0.035714; break;
				case 77: a=0.037037; break;
				case 78: a=0.045455; break;
				case 79: a=0.055556; break;
				case 85: a=0.043478; break;
				case 86: a=0.043478; break;
				case 87: a=0.045455; break;
				case 88: a=0.203341; break;
				case 89: a=0.055556; break;
				case 96: a=0.055556; break;
				case 97: a=0.055556; break;
				case 98: a=0.055556; break;
				case 99: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 89: {
			switch (n1) {
				case 59: a=0.055556; break;
				case 67: a=0.035714; break;
				case 68: a=0.043478; break;
				case 69: a=0.055556; break;
				case 77: a=0.037037; break;
				case 78: a=0.045455; break;
				case 79: a=0.058824; break;
				case 86: a=0.043478; break;
				case 87: a=0.045455; break;
				case 88: a=0.055556; break;
				case 89: a=0.322212; break;
				case 97: a=0.058824; break;
				case 98: a=0.071429; break;
				case 99: a=0.071429; break;
				default: break;
			}
			break;
		}
		case 90: {
			switch (n1) {
				case 60: a=0.055556; break;
				case 70: a=0.058824; break;
				case 71: a=0.045455; break;
				case 72: a=0.037037; break;
				case 80: a=0.071429; break;
				case 81: a=0.055556; break;
				case 82: a=0.045455; break;
				case 90: a=0.444883; break;
				case 91: a=0.071429; break;
				case 92: a=0.058824; break;
				case 93: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 91: {
			switch (n1) {
				case 61: a=0.043478; break;
				case 70: a=0.058824; break;
				case 71: a=0.045455; break;
				case 72: a=0.037037; break;
				case 73: a=0.035714; break;
				case 80: a=0.071429; break;
				case 81: a=0.055556; break;
				case 82: a=0.045455; break;
				case 83: a=0.043478; break;
				case 90: a=0.071429; break;
				case 91: a=0.322212; break;
				case 92: a=0.058824; break;
				case 93: a=0.055556; break;
				case 94: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 92: {
			switch (n1) {
				case 62: a=0.035714; break;
				case 70: a=0.058824; break;
				case 71: a=0.045455; break;
				case 72: a=0.037037; break;
				case 73: a=0.035714; break;
				case 74: a=0.035714; break;
				case 80: a=0.058824; break;
				case 81: a=0.055556; break;
				case 82: a=0.045455; break;
				case 83: a=0.043478; break;
				case 84: a=0.043478; break;
				case 90: a=0.058824; break;
				case 91: a=0.058824; break;
				case 92: a=0.220438; break;
				case 93: a=0.055556; break;
				case 94: a=0.055556; break;
				case 95: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 93: {
			switch (n1) {
				case 63: a=0.034483; break;
				case 71: a=0.045455; break;
				case 72: a=0.037037; break;
				case 73: a=0.035714; break;
				case 74: a=0.035714; break;
				case 75: a=0.035714; break;
				case 81: a=0.055556; break;
				case 82: a=0.045455; break;
				case 83: a=0.043478; break;
				case 84: a=0.043478; break;
				case 85: a=0.043478; break;
				case 90: a=0.055556; break;
				case 91: a=0.055556; break;
				case 92: a=0.055556; break;
				case 93: a=0.211105; break;
				case 94: a=0.055556; break;
				case 95: a=0.055556; break;
				case 96: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 94: {
			switch (n1) {
				case 64: a=0.034483; break;
				case 72: a=0.037037; break;
				case 73: a=0.035714; break;
				case 74: a=0.035714; break;
				case 75: a=0.035714; break;
				case 76: a=0.035714; break;
				case 82: a=0.045455; break;
				case 83: a=0.043478; break;
				case 84: a=0.043478; break;
				case 85: a=0.043478; break;
				case 86: a=0.043478; break;
				case 91: a=0.055556; break;
				case 92: a=0.055556; break;
				case 93: a=0.055556; break;
				case 94: a=0.232922; break;
				case 95: a=0.055556; break;
				case 96: a=0.055556; break;
				case 97: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 95: {
			switch (n1) {
				case 65: a=0.034483; break;
				case 73: a=0.035714; break;
				case 74: a=0.035714; break;
				case 75: a=0.035714; break;
				case 76: a=0.035714; break;
				case 77: a=0.037037; break;
				case 83: a=0.043478; break;
				case 84: a=0.043478; break;
				case 85: a=0.043478; break;
				case 86: a=0.043478; break;
				case 87: a=0.045455; break;
				case 92: a=0.055556; break;
				case 93: a=0.055556; break;
				case 94: a=0.055556; break;
				case 95: a=0.232922; break;
				case 96: a=0.055556; break;
				case 97: a=0.055556; break;
				case 98: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 96: {
			switch (n1) {
				case 66: a=0.034483; break;
				case 74: a=0.035714; break;
				case 75: a=0.035714; break;
				case 76: a=0.035714; break;
				case 77: a=0.037037; break;
				case 78: a=0.045455; break;
				case 84: a=0.043478; break;
				case 85: a=0.043478; break;
				case 86: a=0.043478; break;
				case 87: a=0.045455; break;
				case 88: a=0.055556; break;
				case 93: a=0.055556; break;
				case 94: a=0.055556; break;
				case 95: a=0.055556; break;
				case 96: a=0.211105; break;
				case 97: a=0.055556; break;
				case 98: a=0.055556; break;
				case 99: a=0.055556; break;
				default: break;
			}
			break;
		}
		case 97: {
			switch (n1) {
				case 67: a=0.035714; break;
				case 75: a=0.035714; break;
				case 76: a=0.035714; break;
				case 77: a=0.037037; break;
				case 78: a=0.045455; break;
				case 79: a=0.058824; break;
				case 85: a=0.043478; break;
				case 86: a=0.043478; break;
				case 87: a=0.045455; break;
				case 88: a=0.055556; break;
				case 89: a=0.058824; break;
				case 94: a=0.055556; break;
				case 95: a=0.055556; break;
				case 96: a=0.055556; break;
				case 97: a=0.220438; break;
				case 98: a=0.058824; break;
				case 99: a=0.058824; break;
				default: break;
			}
			break;
		}
		case 98: {
			switch (n1) {
				case 68: a=0.043478; break;
				case 76: a=0.035714; break;
				case 77: a=0.037037; break;
				case 78: a=0.045455; break;
				case 79: a=0.058824; break;
				case 86: a=0.043478; break;
				case 87: a=0.045455; break;
				case 88: a=0.055556; break;
				case 89: a=0.071429; break;
				case 95: a=0.055556; break;
				case 96: a=0.055556; break;
				case 97: a=0.058824; break;
				case 98: a=0.322212; break;
				case 99: a=0.071429; break;
				default: break;
			}
			break;
		}
		case 99: {
			switch (n1) {
				case 69: a=0.055556; break;
				case 77: a=0.037037; break;
				case 78: a=0.045455; break;
				case 79: a=0.058824; break;
				case 87: a=0.045455; break;
				case 88: a=0.055556; break;
				case 89: a=0.071429; break;
				case 96: a=0.055556; break;
				case 97: a=0.058824; break;
				case 98: a=0.071429; break;
				case 99: a=0.444883; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

#endif
