#ifndef _DEPLOYMENT_H_
#define _DEPLOYMENT_H_

// Model coefficients
float A_i(uint8_t m) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 0: {
			switch (m) {
				case 0: a=0.108108; break;
				case 6: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 1: {
			switch (m) {
				case 0: a=0.108108; break;
				case 1: a=0.108108; break;
				case 7: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 2: {
			switch (m) {
				case 1: a=0.108108; break;
				case 2: a=0.108108; break;
				case 8: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 3: {
			switch (m) {
				case 2: a=0.108108; break;
				case 3: a=0.108108; break;
				case 9: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 4: {
			switch (m) {
				case 3: a=0.108108; break;
				case 4: a=0.108108; break;
				case 10: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 5: {
			switch (m) {
				case 4: a=0.108108; break;
				case 5: a=0.108108; break;
				case 11: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 6: {
			switch (m) {
				case 5: a=0.108108; break;
				case 12: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 7: {
			switch (m) {
				case 6: a=0.108108; break;
				case 13: a=0.108108; break;
				case 19: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 8: {
			switch (m) {
				case 7: a=0.108108; break;
				case 13: a=0.108108; break;
				case 14: a=0.108108; break;
				case 20: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 9: {
			switch (m) {
				case 8: a=0.108108; break;
				case 14: a=0.108108; break;
				case 15: a=0.108108; break;
				case 21: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 10: {
			switch (m) {
				case 9: a=0.108108; break;
				case 15: a=0.108108; break;
				case 16: a=0.108108; break;
				case 22: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 11: {
			switch (m) {
				case 10: a=0.108108; break;
				case 16: a=0.108108; break;
				case 17: a=0.108108; break;
				case 23: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 12: {
			switch (m) {
				case 11: a=0.108108; break;
				case 17: a=0.108108; break;
				case 18: a=0.108108; break;
				case 24: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 13: {
			switch (m) {
				case 12: a=0.108108; break;
				case 18: a=0.108108; break;
				case 25: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 14: {
			switch (m) {
				case 19: a=0.108108; break;
				case 26: a=0.108108; break;
				case 32: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 15: {
			switch (m) {
				case 20: a=0.108108; break;
				case 26: a=0.108108; break;
				case 27: a=0.108108; break;
				case 33: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 16: {
			switch (m) {
				case 21: a=0.108108; break;
				case 27: a=0.108108; break;
				case 28: a=0.108108; break;
				case 34: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 17: {
			switch (m) {
				case 22: a=0.108108; break;
				case 28: a=0.108108; break;
				case 29: a=0.108108; break;
				case 35: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 18: {
			switch (m) {
				case 23: a=0.108108; break;
				case 29: a=0.108108; break;
				case 30: a=0.108108; break;
				case 36: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 19: {
			switch (m) {
				case 24: a=0.108108; break;
				case 30: a=0.108108; break;
				case 31: a=0.108108; break;
				case 37: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 20: {
			switch (m) {
				case 25: a=0.108108; break;
				case 31: a=0.108108; break;
				case 38: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 21: {
			switch (m) {
				case 32: a=0.108108; break;
				case 39: a=0.108108; break;
				case 45: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 22: {
			switch (m) {
				case 33: a=0.108108; break;
				case 39: a=0.108108; break;
				case 40: a=0.108108; break;
				case 46: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 23: {
			switch (m) {
				case 34: a=0.108108; break;
				case 40: a=0.108108; break;
				case 41: a=0.108108; break;
				case 47: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 24: {
			switch (m) {
				case 35: a=0.108108; break;
				case 41: a=0.108108; break;
				case 42: a=0.108108; break;
				case 48: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 25: {
			switch (m) {
				case 36: a=0.108108; break;
				case 42: a=0.108108; break;
				case 43: a=0.108108; break;
				case 49: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 26: {
			switch (m) {
				case 37: a=0.108108; break;
				case 43: a=0.108108; break;
				case 44: a=0.108108; break;
				case 50: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 27: {
			switch (m) {
				case 38: a=0.108108; break;
				case 44: a=0.108108; break;
				case 51: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 28: {
			switch (m) {
				case 45: a=0.108108; break;
				case 52: a=0.108108; break;
				case 58: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 29: {
			switch (m) {
				case 46: a=0.108108; break;
				case 52: a=0.108108; break;
				case 53: a=0.108108; break;
				case 59: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 30: {
			switch (m) {
				case 47: a=0.108108; break;
				case 53: a=0.108108; break;
				case 54: a=0.108108; break;
				case 60: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 31: {
			switch (m) {
				case 48: a=0.108108; break;
				case 54: a=0.108108; break;
				case 55: a=0.108108; break;
				case 61: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 32: {
			switch (m) {
				case 49: a=0.108108; break;
				case 55: a=0.108108; break;
				case 56: a=0.108108; break;
				case 62: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 33: {
			switch (m) {
				case 50: a=0.108108; break;
				case 56: a=0.108108; break;
				case 57: a=0.108108; break;
				case 63: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 34: {
			switch (m) {
				case 51: a=0.108108; break;
				case 57: a=0.108108; break;
				case 64: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 35: {
			switch (m) {
				case 58: a=0.108108; break;
				case 65: a=0.108108; break;
				case 71: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 36: {
			switch (m) {
				case 59: a=0.108108; break;
				case 65: a=0.108108; break;
				case 66: a=0.108108; break;
				case 72: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 37: {
			switch (m) {
				case 60: a=0.108108; break;
				case 66: a=0.108108; break;
				case 67: a=0.108108; break;
				case 73: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 38: {
			switch (m) {
				case 61: a=0.108108; break;
				case 67: a=0.108108; break;
				case 68: a=0.108108; break;
				case 74: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 39: {
			switch (m) {
				case 62: a=0.108108; break;
				case 68: a=0.108108; break;
				case 69: a=0.108108; break;
				case 75: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 40: {
			switch (m) {
				case 63: a=0.108108; break;
				case 69: a=0.108108; break;
				case 70: a=0.108108; break;
				case 76: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 41: {
			switch (m) {
				case 64: a=0.108108; break;
				case 70: a=0.108108; break;
				case 77: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 42: {
			switch (m) {
				case 71: a=0.108108; break;
				case 78: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 43: {
			switch (m) {
				case 72: a=0.108108; break;
				case 78: a=0.108108; break;
				case 79: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 44: {
			switch (m) {
				case 73: a=0.108108; break;
				case 79: a=0.108108; break;
				case 80: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 45: {
			switch (m) {
				case 74: a=0.108108; break;
				case 80: a=0.108108; break;
				case 81: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 46: {
			switch (m) {
				case 75: a=0.108108; break;
				case 81: a=0.108108; break;
				case 82: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 47: {
			switch (m) {
				case 76: a=0.108108; break;
				case 82: a=0.108108; break;
				case 83: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 48: {
			switch (m) {
				case 77: a=0.108108; break;
				case 83: a=0.108108; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

// Ambient light
uint16_t ambient() {
	uint16_t res = 0;
	switch (TOS_NODE_ID) {
		case 0: res = 135; break;
		case 1: res = 122; break;
		case 2: res = 142; break;
		case 3: res = 179; break;
		case 4: res = 199; break;
		case 5: res = 198; break;
		case 6: res = 106; break;
		case 7: res = 180; break;
		case 8: res = 131; break;
		case 9: res = 138; break;
		case 10: res = 140; break;
		case 11: res = 172; break;
		case 12: res = 172; break;
		case 13: res = 120; break;
		case 14: res = 101; break;
		case 15: res = 137; break;
		case 16: res = 175; break;
		case 17: res = 139; break;
		case 18: res = 175; break;
		case 19: res = 112; break;
		case 20: res = 103; break;
		case 21: res = 163; break;
		case 22: res = 116; break;
		case 23: res = 144; break;
		case 24: res = 159; break;
		case 25: res = 143; break;
		case 26: res = 100; break;
		case 27: res = 181; break;
		case 28: res = 158; break;
		case 29: res = 187; break;
		case 30: res = 133; break;
		case 31: res = 138; break;
		case 32: res = 173; break;
		case 33: res = 139; break;
		case 34: res = 125; break;
		case 35: res = 175; break;
		case 36: res = 134; break;
		case 37: res = 154; break;
		case 38: res = 145; break;
		case 39: res = 185; break;
		case 40: res = 108; break;
		case 41: res = 163; break;
		case 42: res = 146; break;
		case 43: res = 155; break;
		case 44: res = 142; break;
		case 45: res = 134; break;
		case 46: res = 187; break;
		case 47: res = 142; break;
		case 48: res = 170; break;
		default: break;
	}
	return res;
}

#endif
