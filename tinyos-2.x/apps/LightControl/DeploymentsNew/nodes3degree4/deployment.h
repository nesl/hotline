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
				case 3: a=0.158983; break;
				case 4: a=0.137174; break;
				case 6: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 1: {
			switch (m) {
				case 0: a=0.158983; break;
				case 1: a=0.189036; break;
				case 2: a=0.158983; break;
				case 3: a=0.137174; break;
				case 4: a=0.158983; break;
				case 5: a=0.137174; break;
				case 7: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 2: {
			switch (m) {
				case 0: a=0.107643; break;
				case 1: a=0.158983; break;
				case 2: a=0.189036; break;
				case 4: a=0.137174; break;
				case 5: a=0.158983; break;
				case 8: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 3: {
			switch (m) {
				case 0: a=0.158983; break;
				case 1: a=0.137174; break;
				case 3: a=0.189036; break;
				case 4: a=0.158983; break;
				case 5: a=0.107643; break;
				case 6: a=0.158983; break;
				case 7: a=0.137174; break;
				default: break;
			}
			break;
		}
		case 4: {
			switch (m) {
				case 0: a=0.137174; break;
				case 1: a=0.158983; break;
				case 2: a=0.137174; break;
				case 3: a=0.158983; break;
				case 4: a=0.189036; break;
				case 5: a=0.158983; break;
				case 6: a=0.137174; break;
				case 7: a=0.158983; break;
				case 8: a=0.137174; break;
				default: break;
			}
			break;
		}
		case 5: {
			switch (m) {
				case 1: a=0.137174; break;
				case 2: a=0.158983; break;
				case 3: a=0.107643; break;
				case 4: a=0.158983; break;
				case 5: a=0.189036; break;
				case 7: a=0.137174; break;
				case 8: a=0.158983; break;
				default: break;
			}
			break;
		}
		case 6: {
			switch (m) {
				case 0: a=0.107643; break;
				case 3: a=0.158983; break;
				case 4: a=0.137174; break;
				case 6: a=0.189036; break;
				case 7: a=0.158983; break;
				case 8: a=0.107643; break;
				default: break;
			}
			break;
		}
		case 7: {
			switch (m) {
				case 1: a=0.107643; break;
				case 3: a=0.137174; break;
				case 4: a=0.158983; break;
				case 5: a=0.137174; break;
				case 6: a=0.158983; break;
				case 7: a=0.189036; break;
				case 8: a=0.158983; break;
				default: break;
			}
			break;
		}
		case 8: {
			switch (m) {
				case 2: a=0.107643; break;
				case 4: a=0.137174; break;
				case 5: a=0.158983; break;
				case 6: a=0.107643; break;
				case 7: a=0.158983; break;
				case 8: a=0.189036; break;
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
		case 0: res = 167; break;
		case 1: res = 119; break;
		case 2: res = 164; break;
		case 3: res = 114; break;
		case 4: res = 199; break;
		case 5: res = 180; break;
		case 6: res = 125; break;
		case 7: res = 104; break;
		case 8: res = 155; break;
		default: break;
	}
	return res;
}

#endif
