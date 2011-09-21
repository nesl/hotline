#ifndef _DEPLOYMENT_H_
#define _DEPLOYMENT_H_

// Model coefficients
float A_i(uint8_t m) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 0: {
			switch (m) {
				case 0: a=0.108108; break;
				case 2: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 1: {
			switch (m) {
				case 0: a=0.108108; break;
				case 1: a=0.108108; break;
				case 3: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 2: {
			switch (m) {
				case 1: a=0.108108; break;
				case 4: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 3: {
			switch (m) {
				case 2: a=0.108108; break;
				case 5: a=0.108108; break;
				case 7: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 4: {
			switch (m) {
				case 3: a=0.108108; break;
				case 5: a=0.108108; break;
				case 6: a=0.108108; break;
				case 8: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 5: {
			switch (m) {
				case 4: a=0.108108; break;
				case 6: a=0.108108; break;
				case 9: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 6: {
			switch (m) {
				case 7: a=0.108108; break;
				case 10: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 7: {
			switch (m) {
				case 8: a=0.108108; break;
				case 10: a=0.108108; break;
				case 11: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 8: {
			switch (m) {
				case 9: a=0.108108; break;
				case 11: a=0.108108; break;
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
		case 0: res = 181; break;
		case 1: res = 124; break;
		case 2: res = 184; break;
		case 3: res = 105; break;
		case 4: res = 178; break;
		case 5: res = 126; break;
		case 6: res = 107; break;
		case 7: res = 121; break;
		case 8: res = 108; break;
		default: break;
	}
	return res;
}

#endif
