#ifndef _DEPLOYMENT_H_
#define _DEPLOYMENT_H_

// Model coefficients
float A_i(uint8_t m) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 0: {
			switch (m) {
				case 0: a=0.189036; break;
				case 1: a=0.158983; break;
				case 2: a=0.107643; break;
				case 5: a=0.158983; break;
				case 6: a=0.137174; break;
				case 10: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 1: {
			switch (m) {
				case 0: a=0.158983; break;
				case 1: a=0.189036; break;
				case 2: a=0.158983; break;
				case 3: a=0.107643; break;
				case 5: a=0.137174; break;
				case 6: a=0.158983; break;
				case 7: a=0.137174; break;
				case 11: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 2: {
			switch (m) {
				case 0: a=0.107643; break;
				case 1: a=0.158983; break;
				case 2: a=0.189036; break;
				case 3: a=0.158983; break;
				case 4: a=0.107643; break;
				case 6: a=0.137174; break;
				case 7: a=0.158983; break;
				case 8: a=0.137174; break;
				case 12: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 3: {
			switch (m) {
				case 1: a=0.107643; break;
				case 2: a=0.158983; break;
				case 3: a=0.189036; break;
				case 4: a=0.158983; break;
				case 7: a=0.137174; break;
				case 8: a=0.158983; break;
				case 9: a=0.137174; break;
				case 13: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 4: {
			switch (m) {
				case 2: a=0.107643; break;
				case 3: a=0.158983; break;
				case 4: a=0.189036; break;
				case 8: a=0.137174; break;
				case 9: a=0.158983; break;
				case 14: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 5: {
			switch (m) {
				case 0: a=0.158983; break;
				case 1: a=0.137174; break;
				case 5: a=0.189036; break;
				case 6: a=0.158983; break;
				case 7: a=0.107643; break;
				case 10: a=0.158983; break;
				case 11: a=0.137174; break;
				case 15: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 6: {
			switch (m) {
				case 0: a=0.137174; break;
				case 1: a=0.158983; break;
				case 2: a=0.137174; break;
				case 5: a=0.158983; break;
				case 6: a=0.189036; break;
				case 7: a=0.158983; break;
				case 8: a=0.107643; break;
				case 10: a=0.137174; break;
				case 11: a=0.158983; break;
				case 12: a=0.137174; break;
				case 16: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 7: {
			switch (m) {
				case 1: a=0.137174; break;
				case 2: a=0.158983; break;
				case 3: a=0.137174; break;
				case 5: a=0.107643; break;
				case 6: a=0.158983; break;
				case 7: a=0.189036; break;
				case 8: a=0.158983; break;
				case 9: a=0.107643; break;
				case 11: a=0.137174; break;
				case 12: a=0.158983; break;
				case 13: a=0.137174; break;
				case 17: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 8: {
			switch (m) {
				case 2: a=0.137174; break;
				case 3: a=0.158983; break;
				case 4: a=0.137174; break;
				case 6: a=0.107643; break;
				case 7: a=0.158983; break;
				case 8: a=0.189036; break;
				case 9: a=0.158983; break;
				case 12: a=0.137174; break;
				case 13: a=0.158983; break;
				case 14: a=0.137174; break;
				case 18: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 9: {
			switch (m) {
				case 3: a=0.137174; break;
				case 4: a=0.158983; break;
				case 7: a=0.107643; break;
				case 8: a=0.158983; break;
				case 9: a=0.189036; break;
				case 13: a=0.137174; break;
				case 14: a=0.158983; break;
				case 19: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 10: {
			switch (m) {
				case 0: a=0.107643; break;
				case 5: a=0.158983; break;
				case 6: a=0.137174; break;
				case 10: a=0.189036; break;
				case 11: a=0.158983; break;
				case 12: a=0.107643; break;
				case 15: a=0.158983; break;
				case 16: a=0.137174; break;
				case 20: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 11: {
			switch (m) {
				case 1: a=0.107643; break;
				case 5: a=0.137174; break;
				case 6: a=0.158983; break;
				case 7: a=0.137174; break;
				case 10: a=0.158983; break;
				case 11: a=0.189036; break;
				case 12: a=0.158983; break;
				case 13: a=0.107643; break;
				case 15: a=0.137174; break;
				case 16: a=0.158983; break;
				case 17: a=0.137174; break;
				case 21: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 12: {
			switch (m) {
				case 2: a=0.107643; break;
				case 6: a=0.137174; break;
				case 7: a=0.158983; break;
				case 8: a=0.137174; break;
				case 10: a=0.107643; break;
				case 11: a=0.158983; break;
				case 12: a=0.189036; break;
				case 13: a=0.158983; break;
				case 14: a=0.107643; break;
				case 16: a=0.137174; break;
				case 17: a=0.158983; break;
				case 18: a=0.137174; break;
				case 22: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 13: {
			switch (m) {
				case 3: a=0.107643; break;
				case 7: a=0.137174; break;
				case 8: a=0.158983; break;
				case 9: a=0.137174; break;
				case 11: a=0.107643; break;
				case 12: a=0.158983; break;
				case 13: a=0.189036; break;
				case 14: a=0.158983; break;
				case 17: a=0.137174; break;
				case 18: a=0.158983; break;
				case 19: a=0.137174; break;
				case 23: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 14: {
			switch (m) {
				case 4: a=0.107643; break;
				case 8: a=0.137174; break;
				case 9: a=0.158983; break;
				case 12: a=0.107643; break;
				case 13: a=0.158983; break;
				case 14: a=0.189036; break;
				case 18: a=0.137174; break;
				case 19: a=0.158983; break;
				case 24: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 15: {
			switch (m) {
				case 5: a=0.107643; break;
				case 10: a=0.158983; break;
				case 11: a=0.137174; break;
				case 15: a=0.189036; break;
				case 16: a=0.158983; break;
				case 17: a=0.107643; break;
				case 20: a=0.158983; break;
				case 21: a=0.137174; break;
				default: break;
			}
			break;
		}
		case 16: {
			switch (m) {
				case 6: a=0.107643; break;
				case 10: a=0.137174; break;
				case 11: a=0.158983; break;
				case 12: a=0.137174; break;
				case 15: a=0.158983; break;
				case 16: a=0.189036; break;
				case 17: a=0.158983; break;
				case 18: a=0.107643; break;
				case 20: a=0.137174; break;
				case 21: a=0.158983; break;
				case 22: a=0.137174; break;
				default: break;
			}
			break;
		}
		case 17: {
			switch (m) {
				case 7: a=0.107643; break;
				case 11: a=0.137174; break;
				case 12: a=0.158983; break;
				case 13: a=0.137174; break;
				case 15: a=0.107643; break;
				case 16: a=0.158983; break;
				case 17: a=0.189036; break;
				case 18: a=0.158983; break;
				case 19: a=0.107643; break;
				case 21: a=0.137174; break;
				case 22: a=0.158983; break;
				case 23: a=0.137174; break;
				default: break;
			}
			break;
		}
		case 18: {
			switch (m) {
				case 8: a=0.107643; break;
				case 12: a=0.137174; break;
				case 13: a=0.158983; break;
				case 14: a=0.137174; break;
				case 16: a=0.107643; break;
				case 17: a=0.158983; break;
				case 18: a=0.189036; break;
				case 19: a=0.158983; break;
				case 22: a=0.137174; break;
				case 23: a=0.158983; break;
				case 24: a=0.137174; break;
				default: break;
			}
			break;
		}
		case 19: {
			switch (m) {
				case 9: a=0.107643; break;
				case 13: a=0.137174; break;
				case 14: a=0.158983; break;
				case 17: a=0.107643; break;
				case 18: a=0.158983; break;
				case 19: a=0.189036; break;
				case 23: a=0.137174; break;
				case 24: a=0.158983; break;
				default: break;
			}
			break;
		}
		case 20: {
			switch (m) {
				case 10: a=0.107643; break;
				case 15: a=0.158983; break;
				case 16: a=0.137174; break;
				case 20: a=0.189036; break;
				case 21: a=0.158983; break;
				case 22: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 21: {
			switch (m) {
				case 11: a=0.107643; break;
				case 15: a=0.137174; break;
				case 16: a=0.158983; break;
				case 17: a=0.137174; break;
				case 20: a=0.158983; break;
				case 21: a=0.189036; break;
				case 22: a=0.158983; break;
				case 23: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 22: {
			switch (m) {
				case 12: a=0.107643; break;
				case 16: a=0.137174; break;
				case 17: a=0.158983; break;
				case 18: a=0.137174; break;
				case 20: a=0.107643; break;
				case 21: a=0.158983; break;
				case 22: a=0.189036; break;
				case 23: a=0.158983; break;
				case 24: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 23: {
			switch (m) {
				case 13: a=0.107643; break;
				case 17: a=0.137174; break;
				case 18: a=0.158983; break;
				case 19: a=0.137174; break;
				case 21: a=0.107643; break;
				case 22: a=0.158983; break;
				case 23: a=0.189036; break;
				case 24: a=0.158983; break;
				default: break;
			}
			break;
		}
		case 24: {
			switch (m) {
				case 14: a=0.107643; break;
				case 18: a=0.137174; break;
				case 19: a=0.158983; break;
				case 22: a=0.107643; break;
				case 23: a=0.158983; break;
				case 24: a=0.189036; break;
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
		case 0: res = 122; break;
		case 1: res = 139; break;
		case 2: res = 139; break;
		case 3: res = 126; break;
		case 4: res = 198; break;
		case 5: res = 159; break;
		case 6: res = 140; break;
		case 7: res = 163; break;
		case 8: res = 171; break;
		case 9: res = 159; break;
		case 10: res = 162; break;
		case 11: res = 127; break;
		case 12: res = 171; break;
		case 13: res = 165; break;
		case 14: res = 161; break;
		case 15: res = 118; break;
		case 16: res = 102; break;
		case 17: res = 101; break;
		case 18: res = 119; break;
		case 19: res = 118; break;
		case 20: res = 159; break;
		case 21: res = 192; break;
		case 22: res = 152; break;
		case 23: res = 184; break;
		case 24: res = 170; break;
		default: break;
	}
	return res;
}

#endif
