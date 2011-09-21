#ifndef _DEPLOYMENT_H_
#define _DEPLOYMENT_H_

// Model coefficients
float A_i(uint8_t m) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 0: {
			switch (m) {
				case 0: a=0.160000; break;
				case 1: a=0.137931; break;
				case 5: a=0.137931; break;
				case 6: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 1: {
			switch (m) {
				case 0: a=0.137931; break;
				case 1: a=0.160000; break;
				case 2: a=0.137931; break;
				case 5: a=0.121212; break;
				case 6: a=0.137931; break;
				case 7: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 2: {
			switch (m) {
				case 1: a=0.137931; break;
				case 2: a=0.160000; break;
				case 3: a=0.137931; break;
				case 6: a=0.121212; break;
				case 7: a=0.137931; break;
				case 8: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 3: {
			switch (m) {
				case 2: a=0.137931; break;
				case 3: a=0.160000; break;
				case 4: a=0.137931; break;
				case 7: a=0.121212; break;
				case 8: a=0.137931; break;
				case 9: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 4: {
			switch (m) {
				case 3: a=0.137931; break;
				case 4: a=0.160000; break;
				case 8: a=0.121212; break;
				case 9: a=0.137931; break;
				default: break;
			}
			break;
		}
		case 5: {
			switch (m) {
				case 0: a=0.137931; break;
				case 1: a=0.121212; break;
				case 5: a=0.160000; break;
				case 6: a=0.137931; break;
				case 10: a=0.137931; break;
				case 11: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 6: {
			switch (m) {
				case 0: a=0.121212; break;
				case 1: a=0.137931; break;
				case 2: a=0.121212; break;
				case 5: a=0.137931; break;
				case 6: a=0.160000; break;
				case 7: a=0.137931; break;
				case 10: a=0.121212; break;
				case 11: a=0.137931; break;
				case 12: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 7: {
			switch (m) {
				case 1: a=0.121212; break;
				case 2: a=0.137931; break;
				case 3: a=0.121212; break;
				case 6: a=0.137931; break;
				case 7: a=0.160000; break;
				case 8: a=0.137931; break;
				case 11: a=0.121212; break;
				case 12: a=0.137931; break;
				case 13: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 8: {
			switch (m) {
				case 2: a=0.121212; break;
				case 3: a=0.137931; break;
				case 4: a=0.121212; break;
				case 7: a=0.137931; break;
				case 8: a=0.160000; break;
				case 9: a=0.137931; break;
				case 12: a=0.121212; break;
				case 13: a=0.137931; break;
				case 14: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 9: {
			switch (m) {
				case 3: a=0.121212; break;
				case 4: a=0.137931; break;
				case 8: a=0.137931; break;
				case 9: a=0.160000; break;
				case 13: a=0.121212; break;
				case 14: a=0.137931; break;
				default: break;
			}
			break;
		}
		case 10: {
			switch (m) {
				case 5: a=0.137931; break;
				case 6: a=0.121212; break;
				case 10: a=0.160000; break;
				case 11: a=0.137931; break;
				case 15: a=0.137931; break;
				case 16: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 11: {
			switch (m) {
				case 5: a=0.121212; break;
				case 6: a=0.137931; break;
				case 7: a=0.121212; break;
				case 10: a=0.137931; break;
				case 11: a=0.160000; break;
				case 12: a=0.137931; break;
				case 15: a=0.121212; break;
				case 16: a=0.137931; break;
				case 17: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 12: {
			switch (m) {
				case 6: a=0.121212; break;
				case 7: a=0.137931; break;
				case 8: a=0.121212; break;
				case 11: a=0.137931; break;
				case 12: a=0.160000; break;
				case 13: a=0.137931; break;
				case 16: a=0.121212; break;
				case 17: a=0.137931; break;
				case 18: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 13: {
			switch (m) {
				case 7: a=0.121212; break;
				case 8: a=0.137931; break;
				case 9: a=0.121212; break;
				case 12: a=0.137931; break;
				case 13: a=0.160000; break;
				case 14: a=0.137931; break;
				case 17: a=0.121212; break;
				case 18: a=0.137931; break;
				case 19: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 14: {
			switch (m) {
				case 8: a=0.121212; break;
				case 9: a=0.137931; break;
				case 13: a=0.137931; break;
				case 14: a=0.160000; break;
				case 18: a=0.121212; break;
				case 19: a=0.137931; break;
				default: break;
			}
			break;
		}
		case 15: {
			switch (m) {
				case 10: a=0.137931; break;
				case 11: a=0.121212; break;
				case 15: a=0.160000; break;
				case 16: a=0.137931; break;
				case 20: a=0.137931; break;
				case 21: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 16: {
			switch (m) {
				case 10: a=0.121212; break;
				case 11: a=0.137931; break;
				case 12: a=0.121212; break;
				case 15: a=0.137931; break;
				case 16: a=0.160000; break;
				case 17: a=0.137931; break;
				case 20: a=0.121212; break;
				case 21: a=0.137931; break;
				case 22: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 17: {
			switch (m) {
				case 11: a=0.121212; break;
				case 12: a=0.137931; break;
				case 13: a=0.121212; break;
				case 16: a=0.137931; break;
				case 17: a=0.160000; break;
				case 18: a=0.137931; break;
				case 21: a=0.121212; break;
				case 22: a=0.137931; break;
				case 23: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 18: {
			switch (m) {
				case 12: a=0.121212; break;
				case 13: a=0.137931; break;
				case 14: a=0.121212; break;
				case 17: a=0.137931; break;
				case 18: a=0.160000; break;
				case 19: a=0.137931; break;
				case 22: a=0.121212; break;
				case 23: a=0.137931; break;
				case 24: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 19: {
			switch (m) {
				case 13: a=0.121212; break;
				case 14: a=0.137931; break;
				case 18: a=0.137931; break;
				case 19: a=0.160000; break;
				case 23: a=0.121212; break;
				case 24: a=0.137931; break;
				default: break;
			}
			break;
		}
		case 20: {
			switch (m) {
				case 15: a=0.137931; break;
				case 16: a=0.121212; break;
				case 20: a=0.160000; break;
				case 21: a=0.137931; break;
				default: break;
			}
			break;
		}
		case 21: {
			switch (m) {
				case 15: a=0.121212; break;
				case 16: a=0.137931; break;
				case 17: a=0.121212; break;
				case 20: a=0.137931; break;
				case 21: a=0.160000; break;
				case 22: a=0.137931; break;
				default: break;
			}
			break;
		}
		case 22: {
			switch (m) {
				case 16: a=0.121212; break;
				case 17: a=0.137931; break;
				case 18: a=0.121212; break;
				case 21: a=0.137931; break;
				case 22: a=0.160000; break;
				case 23: a=0.137931; break;
				default: break;
			}
			break;
		}
		case 23: {
			switch (m) {
				case 17: a=0.121212; break;
				case 18: a=0.137931; break;
				case 19: a=0.121212; break;
				case 22: a=0.137931; break;
				case 23: a=0.160000; break;
				case 24: a=0.137931; break;
				default: break;
			}
			break;
		}
		case 24: {
			switch (m) {
				case 18: a=0.121212; break;
				case 19: a=0.137931; break;
				case 23: a=0.137931; break;
				case 24: a=0.160000; break;
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
		case 1: res = 189; break;
		case 2: res = 191; break;
		case 3: res = 190; break;
		case 4: res = 108; break;
		case 5: res = 194; break;
		case 6: res = 140; break;
		case 7: res = 121; break;
		case 8: res = 123; break;
		case 9: res = 185; break;
		case 10: res = 136; break;
		case 11: res = 135; break;
		case 12: res = 131; break;
		case 13: res = 138; break;
		case 14: res = 114; break;
		case 15: res = 193; break;
		case 16: res = 176; break;
		case 17: res = 169; break;
		case 18: res = 176; break;
		case 19: res = 181; break;
		case 20: res = 121; break;
		case 21: res = 106; break;
		case 22: res = 124; break;
		case 23: res = 169; break;
		case 24: res = 100; break;
		default: break;
	}
	return res;
}

#endif
