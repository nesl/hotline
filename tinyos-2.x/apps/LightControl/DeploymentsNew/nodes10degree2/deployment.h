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
				case 10: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 1: {
			switch (m) {
				case 0: a=0.106270; break;
				case 1: a=0.118906; break;
				case 2: a=0.106270; break;
				case 11: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 2: {
			switch (m) {
				case 1: a=0.106270; break;
				case 2: a=0.118906; break;
				case 3: a=0.106270; break;
				case 12: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 3: {
			switch (m) {
				case 2: a=0.106270; break;
				case 3: a=0.118906; break;
				case 4: a=0.106270; break;
				case 13: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 4: {
			switch (m) {
				case 3: a=0.106270; break;
				case 4: a=0.118906; break;
				case 5: a=0.106270; break;
				case 14: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 5: {
			switch (m) {
				case 4: a=0.106270; break;
				case 5: a=0.118906; break;
				case 6: a=0.106270; break;
				case 15: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 6: {
			switch (m) {
				case 5: a=0.106270; break;
				case 6: a=0.118906; break;
				case 7: a=0.106270; break;
				case 16: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 7: {
			switch (m) {
				case 6: a=0.106270; break;
				case 7: a=0.118906; break;
				case 8: a=0.106270; break;
				case 17: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 8: {
			switch (m) {
				case 7: a=0.106270; break;
				case 8: a=0.118906; break;
				case 9: a=0.106270; break;
				case 18: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 9: {
			switch (m) {
				case 8: a=0.106270; break;
				case 9: a=0.118906; break;
				case 19: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 10: {
			switch (m) {
				case 0: a=0.106270; break;
				case 10: a=0.118906; break;
				case 11: a=0.106270; break;
				case 20: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 11: {
			switch (m) {
				case 1: a=0.106270; break;
				case 10: a=0.106270; break;
				case 11: a=0.118906; break;
				case 12: a=0.106270; break;
				case 21: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 12: {
			switch (m) {
				case 2: a=0.106270; break;
				case 11: a=0.106270; break;
				case 12: a=0.118906; break;
				case 13: a=0.106270; break;
				case 22: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 13: {
			switch (m) {
				case 3: a=0.106270; break;
				case 12: a=0.106270; break;
				case 13: a=0.118906; break;
				case 14: a=0.106270; break;
				case 23: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 14: {
			switch (m) {
				case 4: a=0.106270; break;
				case 13: a=0.106270; break;
				case 14: a=0.118906; break;
				case 15: a=0.106270; break;
				case 24: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 15: {
			switch (m) {
				case 5: a=0.106270; break;
				case 14: a=0.106270; break;
				case 15: a=0.118906; break;
				case 16: a=0.106270; break;
				case 25: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 16: {
			switch (m) {
				case 6: a=0.106270; break;
				case 15: a=0.106270; break;
				case 16: a=0.118906; break;
				case 17: a=0.106270; break;
				case 26: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 17: {
			switch (m) {
				case 7: a=0.106270; break;
				case 16: a=0.106270; break;
				case 17: a=0.118906; break;
				case 18: a=0.106270; break;
				case 27: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 18: {
			switch (m) {
				case 8: a=0.106270; break;
				case 17: a=0.106270; break;
				case 18: a=0.118906; break;
				case 19: a=0.106270; break;
				case 28: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 19: {
			switch (m) {
				case 9: a=0.106270; break;
				case 18: a=0.106270; break;
				case 19: a=0.118906; break;
				case 29: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 20: {
			switch (m) {
				case 10: a=0.106270; break;
				case 20: a=0.118906; break;
				case 21: a=0.106270; break;
				case 30: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 21: {
			switch (m) {
				case 11: a=0.106270; break;
				case 20: a=0.106270; break;
				case 21: a=0.118906; break;
				case 22: a=0.106270; break;
				case 31: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 22: {
			switch (m) {
				case 12: a=0.106270; break;
				case 21: a=0.106270; break;
				case 22: a=0.118906; break;
				case 23: a=0.106270; break;
				case 32: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 23: {
			switch (m) {
				case 13: a=0.106270; break;
				case 22: a=0.106270; break;
				case 23: a=0.118906; break;
				case 24: a=0.106270; break;
				case 33: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 24: {
			switch (m) {
				case 14: a=0.106270; break;
				case 23: a=0.106270; break;
				case 24: a=0.118906; break;
				case 25: a=0.106270; break;
				case 34: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 25: {
			switch (m) {
				case 15: a=0.106270; break;
				case 24: a=0.106270; break;
				case 25: a=0.118906; break;
				case 26: a=0.106270; break;
				case 35: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 26: {
			switch (m) {
				case 16: a=0.106270; break;
				case 25: a=0.106270; break;
				case 26: a=0.118906; break;
				case 27: a=0.106270; break;
				case 36: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 27: {
			switch (m) {
				case 17: a=0.106270; break;
				case 26: a=0.106270; break;
				case 27: a=0.118906; break;
				case 28: a=0.106270; break;
				case 37: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 28: {
			switch (m) {
				case 18: a=0.106270; break;
				case 27: a=0.106270; break;
				case 28: a=0.118906; break;
				case 29: a=0.106270; break;
				case 38: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 29: {
			switch (m) {
				case 19: a=0.106270; break;
				case 28: a=0.106270; break;
				case 29: a=0.118906; break;
				case 39: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 30: {
			switch (m) {
				case 20: a=0.106270; break;
				case 30: a=0.118906; break;
				case 31: a=0.106270; break;
				case 40: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 31: {
			switch (m) {
				case 21: a=0.106270; break;
				case 30: a=0.106270; break;
				case 31: a=0.118906; break;
				case 32: a=0.106270; break;
				case 41: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 32: {
			switch (m) {
				case 22: a=0.106270; break;
				case 31: a=0.106270; break;
				case 32: a=0.118906; break;
				case 33: a=0.106270; break;
				case 42: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 33: {
			switch (m) {
				case 23: a=0.106270; break;
				case 32: a=0.106270; break;
				case 33: a=0.118906; break;
				case 34: a=0.106270; break;
				case 43: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 34: {
			switch (m) {
				case 24: a=0.106270; break;
				case 33: a=0.106270; break;
				case 34: a=0.118906; break;
				case 35: a=0.106270; break;
				case 44: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 35: {
			switch (m) {
				case 25: a=0.106270; break;
				case 34: a=0.106270; break;
				case 35: a=0.118906; break;
				case 36: a=0.106270; break;
				case 45: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 36: {
			switch (m) {
				case 26: a=0.106270; break;
				case 35: a=0.106270; break;
				case 36: a=0.118906; break;
				case 37: a=0.106270; break;
				case 46: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 37: {
			switch (m) {
				case 27: a=0.106270; break;
				case 36: a=0.106270; break;
				case 37: a=0.118906; break;
				case 38: a=0.106270; break;
				case 47: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 38: {
			switch (m) {
				case 28: a=0.106270; break;
				case 37: a=0.106270; break;
				case 38: a=0.118906; break;
				case 39: a=0.106270; break;
				case 48: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 39: {
			switch (m) {
				case 29: a=0.106270; break;
				case 38: a=0.106270; break;
				case 39: a=0.118906; break;
				case 49: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 40: {
			switch (m) {
				case 30: a=0.106270; break;
				case 40: a=0.118906; break;
				case 41: a=0.106270; break;
				case 50: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 41: {
			switch (m) {
				case 31: a=0.106270; break;
				case 40: a=0.106270; break;
				case 41: a=0.118906; break;
				case 42: a=0.106270; break;
				case 51: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 42: {
			switch (m) {
				case 32: a=0.106270; break;
				case 41: a=0.106270; break;
				case 42: a=0.118906; break;
				case 43: a=0.106270; break;
				case 52: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 43: {
			switch (m) {
				case 33: a=0.106270; break;
				case 42: a=0.106270; break;
				case 43: a=0.118906; break;
				case 44: a=0.106270; break;
				case 53: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 44: {
			switch (m) {
				case 34: a=0.106270; break;
				case 43: a=0.106270; break;
				case 44: a=0.118906; break;
				case 45: a=0.106270; break;
				case 54: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 45: {
			switch (m) {
				case 35: a=0.106270; break;
				case 44: a=0.106270; break;
				case 45: a=0.118906; break;
				case 46: a=0.106270; break;
				case 55: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 46: {
			switch (m) {
				case 36: a=0.106270; break;
				case 45: a=0.106270; break;
				case 46: a=0.118906; break;
				case 47: a=0.106270; break;
				case 56: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 47: {
			switch (m) {
				case 37: a=0.106270; break;
				case 46: a=0.106270; break;
				case 47: a=0.118906; break;
				case 48: a=0.106270; break;
				case 57: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 48: {
			switch (m) {
				case 38: a=0.106270; break;
				case 47: a=0.106270; break;
				case 48: a=0.118906; break;
				case 49: a=0.106270; break;
				case 58: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 49: {
			switch (m) {
				case 39: a=0.106270; break;
				case 48: a=0.106270; break;
				case 49: a=0.118906; break;
				case 59: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 50: {
			switch (m) {
				case 40: a=0.106270; break;
				case 50: a=0.118906; break;
				case 51: a=0.106270; break;
				case 60: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 51: {
			switch (m) {
				case 41: a=0.106270; break;
				case 50: a=0.106270; break;
				case 51: a=0.118906; break;
				case 52: a=0.106270; break;
				case 61: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 52: {
			switch (m) {
				case 42: a=0.106270; break;
				case 51: a=0.106270; break;
				case 52: a=0.118906; break;
				case 53: a=0.106270; break;
				case 62: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 53: {
			switch (m) {
				case 43: a=0.106270; break;
				case 52: a=0.106270; break;
				case 53: a=0.118906; break;
				case 54: a=0.106270; break;
				case 63: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 54: {
			switch (m) {
				case 44: a=0.106270; break;
				case 53: a=0.106270; break;
				case 54: a=0.118906; break;
				case 55: a=0.106270; break;
				case 64: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 55: {
			switch (m) {
				case 45: a=0.106270; break;
				case 54: a=0.106270; break;
				case 55: a=0.118906; break;
				case 56: a=0.106270; break;
				case 65: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 56: {
			switch (m) {
				case 46: a=0.106270; break;
				case 55: a=0.106270; break;
				case 56: a=0.118906; break;
				case 57: a=0.106270; break;
				case 66: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 57: {
			switch (m) {
				case 47: a=0.106270; break;
				case 56: a=0.106270; break;
				case 57: a=0.118906; break;
				case 58: a=0.106270; break;
				case 67: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 58: {
			switch (m) {
				case 48: a=0.106270; break;
				case 57: a=0.106270; break;
				case 58: a=0.118906; break;
				case 59: a=0.106270; break;
				case 68: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 59: {
			switch (m) {
				case 49: a=0.106270; break;
				case 58: a=0.106270; break;
				case 59: a=0.118906; break;
				case 69: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 60: {
			switch (m) {
				case 50: a=0.106270; break;
				case 60: a=0.118906; break;
				case 61: a=0.106270; break;
				case 70: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 61: {
			switch (m) {
				case 51: a=0.106270; break;
				case 60: a=0.106270; break;
				case 61: a=0.118906; break;
				case 62: a=0.106270; break;
				case 71: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 62: {
			switch (m) {
				case 52: a=0.106270; break;
				case 61: a=0.106270; break;
				case 62: a=0.118906; break;
				case 63: a=0.106270; break;
				case 72: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 63: {
			switch (m) {
				case 53: a=0.106270; break;
				case 62: a=0.106270; break;
				case 63: a=0.118906; break;
				case 64: a=0.106270; break;
				case 73: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 64: {
			switch (m) {
				case 54: a=0.106270; break;
				case 63: a=0.106270; break;
				case 64: a=0.118906; break;
				case 65: a=0.106270; break;
				case 74: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 65: {
			switch (m) {
				case 55: a=0.106270; break;
				case 64: a=0.106270; break;
				case 65: a=0.118906; break;
				case 66: a=0.106270; break;
				case 75: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 66: {
			switch (m) {
				case 56: a=0.106270; break;
				case 65: a=0.106270; break;
				case 66: a=0.118906; break;
				case 67: a=0.106270; break;
				case 76: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 67: {
			switch (m) {
				case 57: a=0.106270; break;
				case 66: a=0.106270; break;
				case 67: a=0.118906; break;
				case 68: a=0.106270; break;
				case 77: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 68: {
			switch (m) {
				case 58: a=0.106270; break;
				case 67: a=0.106270; break;
				case 68: a=0.118906; break;
				case 69: a=0.106270; break;
				case 78: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 69: {
			switch (m) {
				case 59: a=0.106270; break;
				case 68: a=0.106270; break;
				case 69: a=0.118906; break;
				case 79: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 70: {
			switch (m) {
				case 60: a=0.106270; break;
				case 70: a=0.118906; break;
				case 71: a=0.106270; break;
				case 80: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 71: {
			switch (m) {
				case 61: a=0.106270; break;
				case 70: a=0.106270; break;
				case 71: a=0.118906; break;
				case 72: a=0.106270; break;
				case 81: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 72: {
			switch (m) {
				case 62: a=0.106270; break;
				case 71: a=0.106270; break;
				case 72: a=0.118906; break;
				case 73: a=0.106270; break;
				case 82: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 73: {
			switch (m) {
				case 63: a=0.106270; break;
				case 72: a=0.106270; break;
				case 73: a=0.118906; break;
				case 74: a=0.106270; break;
				case 83: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 74: {
			switch (m) {
				case 64: a=0.106270; break;
				case 73: a=0.106270; break;
				case 74: a=0.118906; break;
				case 75: a=0.106270; break;
				case 84: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 75: {
			switch (m) {
				case 65: a=0.106270; break;
				case 74: a=0.106270; break;
				case 75: a=0.118906; break;
				case 76: a=0.106270; break;
				case 85: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 76: {
			switch (m) {
				case 66: a=0.106270; break;
				case 75: a=0.106270; break;
				case 76: a=0.118906; break;
				case 77: a=0.106270; break;
				case 86: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 77: {
			switch (m) {
				case 67: a=0.106270; break;
				case 76: a=0.106270; break;
				case 77: a=0.118906; break;
				case 78: a=0.106270; break;
				case 87: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 78: {
			switch (m) {
				case 68: a=0.106270; break;
				case 77: a=0.106270; break;
				case 78: a=0.118906; break;
				case 79: a=0.106270; break;
				case 88: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 79: {
			switch (m) {
				case 69: a=0.106270; break;
				case 78: a=0.106270; break;
				case 79: a=0.118906; break;
				case 89: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 80: {
			switch (m) {
				case 70: a=0.106270; break;
				case 80: a=0.118906; break;
				case 81: a=0.106270; break;
				case 90: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 81: {
			switch (m) {
				case 71: a=0.106270; break;
				case 80: a=0.106270; break;
				case 81: a=0.118906; break;
				case 82: a=0.106270; break;
				case 91: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 82: {
			switch (m) {
				case 72: a=0.106270; break;
				case 81: a=0.106270; break;
				case 82: a=0.118906; break;
				case 83: a=0.106270; break;
				case 92: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 83: {
			switch (m) {
				case 73: a=0.106270; break;
				case 82: a=0.106270; break;
				case 83: a=0.118906; break;
				case 84: a=0.106270; break;
				case 93: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 84: {
			switch (m) {
				case 74: a=0.106270; break;
				case 83: a=0.106270; break;
				case 84: a=0.118906; break;
				case 85: a=0.106270; break;
				case 94: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 85: {
			switch (m) {
				case 75: a=0.106270; break;
				case 84: a=0.106270; break;
				case 85: a=0.118906; break;
				case 86: a=0.106270; break;
				case 95: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 86: {
			switch (m) {
				case 76: a=0.106270; break;
				case 85: a=0.106270; break;
				case 86: a=0.118906; break;
				case 87: a=0.106270; break;
				case 96: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 87: {
			switch (m) {
				case 77: a=0.106270; break;
				case 86: a=0.106270; break;
				case 87: a=0.118906; break;
				case 88: a=0.106270; break;
				case 97: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 88: {
			switch (m) {
				case 78: a=0.106270; break;
				case 87: a=0.106270; break;
				case 88: a=0.118906; break;
				case 89: a=0.106270; break;
				case 98: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 89: {
			switch (m) {
				case 79: a=0.106270; break;
				case 88: a=0.106270; break;
				case 89: a=0.118906; break;
				case 99: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 90: {
			switch (m) {
				case 80: a=0.106270; break;
				case 90: a=0.118906; break;
				case 91: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 91: {
			switch (m) {
				case 81: a=0.106270; break;
				case 90: a=0.106270; break;
				case 91: a=0.118906; break;
				case 92: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 92: {
			switch (m) {
				case 82: a=0.106270; break;
				case 91: a=0.106270; break;
				case 92: a=0.118906; break;
				case 93: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 93: {
			switch (m) {
				case 83: a=0.106270; break;
				case 92: a=0.106270; break;
				case 93: a=0.118906; break;
				case 94: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 94: {
			switch (m) {
				case 84: a=0.106270; break;
				case 93: a=0.106270; break;
				case 94: a=0.118906; break;
				case 95: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 95: {
			switch (m) {
				case 85: a=0.106270; break;
				case 94: a=0.106270; break;
				case 95: a=0.118906; break;
				case 96: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 96: {
			switch (m) {
				case 86: a=0.106270; break;
				case 95: a=0.106270; break;
				case 96: a=0.118906; break;
				case 97: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 97: {
			switch (m) {
				case 87: a=0.106270; break;
				case 96: a=0.106270; break;
				case 97: a=0.118906; break;
				case 98: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 98: {
			switch (m) {
				case 88: a=0.106270; break;
				case 97: a=0.106270; break;
				case 98: a=0.118906; break;
				case 99: a=0.106270; break;
				default: break;
			}
			break;
		}
		case 99: {
			switch (m) {
				case 89: a=0.106270; break;
				case 98: a=0.106270; break;
				case 99: a=0.118906; break;
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
		case 0: res = 147; break;
		case 1: res = 130; break;
		case 2: res = 188; break;
		case 3: res = 176; break;
		case 4: res = 196; break;
		case 5: res = 149; break;
		case 6: res = 190; break;
		case 7: res = 190; break;
		case 8: res = 106; break;
		case 9: res = 181; break;
		case 10: res = 196; break;
		case 11: res = 102; break;
		case 12: res = 159; break;
		case 13: res = 133; break;
		case 14: res = 175; break;
		case 15: res = 103; break;
		case 16: res = 175; break;
		case 17: res = 160; break;
		case 18: res = 187; break;
		case 19: res = 150; break;
		case 20: res = 193; break;
		case 21: res = 177; break;
		case 22: res = 180; break;
		case 23: res = 168; break;
		case 24: res = 120; break;
		case 25: res = 127; break;
		case 26: res = 180; break;
		case 27: res = 103; break;
		case 28: res = 120; break;
		case 29: res = 130; break;
		case 30: res = 125; break;
		case 31: res = 125; break;
		case 32: res = 130; break;
		case 33: res = 137; break;
		case 34: res = 192; break;
		case 35: res = 193; break;
		case 36: res = 172; break;
		case 37: res = 114; break;
		case 38: res = 149; break;
		case 39: res = 139; break;
		case 40: res = 171; break;
		case 41: res = 164; break;
		case 42: res = 106; break;
		case 43: res = 131; break;
		case 44: res = 127; break;
		case 45: res = 135; break;
		case 46: res = 191; break;
		case 47: res = 166; break;
		case 48: res = 109; break;
		case 49: res = 153; break;
		case 50: res = 196; break;
		case 51: res = 105; break;
		case 52: res = 187; break;
		case 53: res = 169; break;
		case 54: res = 197; break;
		case 55: res = 190; break;
		case 56: res = 148; break;
		case 57: res = 121; break;
		case 58: res = 146; break;
		case 59: res = 140; break;
		case 60: res = 199; break;
		case 61: res = 161; break;
		case 62: res = 136; break;
		case 63: res = 108; break;
		case 64: res = 115; break;
		case 65: res = 172; break;
		case 66: res = 187; break;
		case 67: res = 173; break;
		case 68: res = 190; break;
		case 69: res = 175; break;
		case 70: res = 155; break;
		case 71: res = 148; break;
		case 72: res = 168; break;
		case 73: res = 150; break;
		case 74: res = 149; break;
		case 75: res = 187; break;
		case 76: res = 175; break;
		case 77: res = 147; break;
		case 78: res = 159; break;
		case 79: res = 190; break;
		case 80: res = 110; break;
		case 81: res = 129; break;
		case 82: res = 183; break;
		case 83: res = 103; break;
		case 84: res = 144; break;
		case 85: res = 156; break;
		case 86: res = 116; break;
		case 87: res = 184; break;
		case 88: res = 149; break;
		case 89: res = 180; break;
		case 90: res = 180; break;
		case 91: res = 128; break;
		case 92: res = 140; break;
		case 93: res = 172; break;
		case 94: res = 183; break;
		case 95: res = 150; break;
		case 96: res = 142; break;
		case 97: res = 198; break;
		case 98: res = 108; break;
		case 99: res = 176; break;
		default: break;
	}
	return res;
}

#endif
