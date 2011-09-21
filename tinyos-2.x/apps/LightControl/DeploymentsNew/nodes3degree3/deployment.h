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
				case 3: a=0.137931; break;
				case 4: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 1: {
			switch (m) {
				case 0: a=0.137931; break;
				case 1: a=0.160000; break;
				case 2: a=0.137931; break;
				case 3: a=0.121212; break;
				case 4: a=0.137931; break;
				case 5: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 2: {
			switch (m) {
				case 1: a=0.137931; break;
				case 2: a=0.160000; break;
				case 4: a=0.121212; break;
				case 5: a=0.137931; break;
				default: break;
			}
			break;
		}
		case 3: {
			switch (m) {
				case 0: a=0.137931; break;
				case 1: a=0.121212; break;
				case 3: a=0.160000; break;
				case 4: a=0.137931; break;
				case 6: a=0.137931; break;
				case 7: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 4: {
			switch (m) {
				case 0: a=0.121212; break;
				case 1: a=0.137931; break;
				case 2: a=0.121212; break;
				case 3: a=0.137931; break;
				case 4: a=0.160000; break;
				case 5: a=0.137931; break;
				case 6: a=0.121212; break;
				case 7: a=0.137931; break;
				case 8: a=0.121212; break;
				default: break;
			}
			break;
		}
		case 5: {
			switch (m) {
				case 1: a=0.121212; break;
				case 2: a=0.137931; break;
				case 4: a=0.137931; break;
				case 5: a=0.160000; break;
				case 7: a=0.121212; break;
				case 8: a=0.137931; break;
				default: break;
			}
			break;
		}
		case 6: {
			switch (m) {
				case 3: a=0.137931; break;
				case 4: a=0.121212; break;
				case 6: a=0.160000; break;
				case 7: a=0.137931; break;
				default: break;
			}
			break;
		}
		case 7: {
			switch (m) {
				case 3: a=0.121212; break;
				case 4: a=0.137931; break;
				case 5: a=0.121212; break;
				case 6: a=0.137931; break;
				case 7: a=0.160000; break;
				case 8: a=0.137931; break;
				default: break;
			}
			break;
		}
		case 8: {
			switch (m) {
				case 4: a=0.121212; break;
				case 5: a=0.137931; break;
				case 7: a=0.137931; break;
				case 8: a=0.160000; break;
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
		case 1: res = 178; break;
		case 2: res = 122; break;
		case 3: res = 117; break;
		case 4: res = 164; break;
		case 5: res = 164; break;
		case 6: res = 149; break;
		case 7: res = 106; break;
		case 8: res = 131; break;
		default: break;
	}
	return res;
}

#endif
