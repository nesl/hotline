#ifndef _DEPLOYMENT_H_
#define _DEPLOYMENT_H_

// Model coefficients
float A_i(uint8_t m) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 0: {
			switch (m) {
				case 0: a=0.118906; break;
				case 1: a=0.106270; break;
				case 3: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 1: {
			switch (m) {
				case 0: a=0.106270; break;
				case 1: a=0.118906; break;
				case 2: a=0.106270; break;
				case 4: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 2: {
			switch (m) {
				case 1: a=0.106270; break;
				case 2: a=0.118906; break;
				case 5: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 3: {
			switch (m) {
				case 0: a=0.106270; break;
				case 3: a=0.118906; break;
				case 4: a=0.106270; break;
				case 6: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 4: {
			switch (m) {
				case 1: a=0.106270; break;
				case 3: a=0.106270; break;
				case 4: a=0.118906; break;
				case 5: a=0.106270; break;
				case 7: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 5: {
			switch (m) {
				case 2: a=0.106270; break;
				case 4: a=0.106270; break;
				case 5: a=0.118906; break;
				case 8: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 6: {
			switch (m) {
				case 3: a=0.106270; break;
				case 6: a=0.118906; break;
				case 7: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 7: {
			switch (m) {
				case 4: a=0.106270; break;
				case 6: a=0.106270; break;
				case 7: a=0.118906; break;
				case 8: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 8: {
			switch (m) {
				case 5: a=0.106270; break;
				case 7: a=0.106270; break;
				case 8: a=0.118906; break;
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
		case 0: res = 176; break;
		case 1: res = 148; break;
		case 2: res = 135; break;
		case 3: res = 139; break;
		case 4: res = 129; break;
		case 5: res = 150; break;
		case 6: res = 167; break;
		case 7: res = 141; break;
		case 8: res = 118; break;
		default: break;
	}
	return res;
}

#endif
