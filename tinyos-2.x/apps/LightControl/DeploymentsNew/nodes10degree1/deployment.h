#ifndef _DEPLOYMENT_H_
#define _DEPLOYMENT_H_

// Model coefficients
float A_i(uint8_t m) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 0: {
			switch (m) {
				case 0: a=0.108108; break;
				case 9: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 1: {
			switch (m) {
				case 0: a=0.108108; break;
				case 1: a=0.108108; break;
				case 10: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 2: {
			switch (m) {
				case 1: a=0.108108; break;
				case 2: a=0.108108; break;
				case 11: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 3: {
			switch (m) {
				case 2: a=0.108108; break;
				case 3: a=0.108108; break;
				case 12: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 4: {
			switch (m) {
				case 3: a=0.108108; break;
				case 4: a=0.108108; break;
				case 13: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 5: {
			switch (m) {
				case 4: a=0.108108; break;
				case 5: a=0.108108; break;
				case 14: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 6: {
			switch (m) {
				case 5: a=0.108108; break;
				case 6: a=0.108108; break;
				case 15: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 7: {
			switch (m) {
				case 6: a=0.108108; break;
				case 7: a=0.108108; break;
				case 16: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 8: {
			switch (m) {
				case 7: a=0.108108; break;
				case 8: a=0.108108; break;
				case 17: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 9: {
			switch (m) {
				case 8: a=0.108108; break;
				case 18: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 10: {
			switch (m) {
				case 9: a=0.108108; break;
				case 19: a=0.108108; break;
				case 28: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 11: {
			switch (m) {
				case 10: a=0.108108; break;
				case 19: a=0.108108; break;
				case 20: a=0.108108; break;
				case 29: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 12: {
			switch (m) {
				case 11: a=0.108108; break;
				case 20: a=0.108108; break;
				case 21: a=0.108108; break;
				case 30: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 13: {
			switch (m) {
				case 12: a=0.108108; break;
				case 21: a=0.108108; break;
				case 22: a=0.108108; break;
				case 31: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 14: {
			switch (m) {
				case 13: a=0.108108; break;
				case 22: a=0.108108; break;
				case 23: a=0.108108; break;
				case 32: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 15: {
			switch (m) {
				case 14: a=0.108108; break;
				case 23: a=0.108108; break;
				case 24: a=0.108108; break;
				case 33: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 16: {
			switch (m) {
				case 15: a=0.108108; break;
				case 24: a=0.108108; break;
				case 25: a=0.108108; break;
				case 34: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 17: {
			switch (m) {
				case 16: a=0.108108; break;
				case 25: a=0.108108; break;
				case 26: a=0.108108; break;
				case 35: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 18: {
			switch (m) {
				case 17: a=0.108108; break;
				case 26: a=0.108108; break;
				case 27: a=0.108108; break;
				case 36: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 19: {
			switch (m) {
				case 18: a=0.108108; break;
				case 27: a=0.108108; break;
				case 37: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 20: {
			switch (m) {
				case 28: a=0.108108; break;
				case 38: a=0.108108; break;
				case 47: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 21: {
			switch (m) {
				case 29: a=0.108108; break;
				case 38: a=0.108108; break;
				case 39: a=0.108108; break;
				case 48: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 22: {
			switch (m) {
				case 30: a=0.108108; break;
				case 39: a=0.108108; break;
				case 40: a=0.108108; break;
				case 49: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 23: {
			switch (m) {
				case 31: a=0.108108; break;
				case 40: a=0.108108; break;
				case 41: a=0.108108; break;
				case 50: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 24: {
			switch (m) {
				case 32: a=0.108108; break;
				case 41: a=0.108108; break;
				case 42: a=0.108108; break;
				case 51: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 25: {
			switch (m) {
				case 33: a=0.108108; break;
				case 42: a=0.108108; break;
				case 43: a=0.108108; break;
				case 52: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 26: {
			switch (m) {
				case 34: a=0.108108; break;
				case 43: a=0.108108; break;
				case 44: a=0.108108; break;
				case 53: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 27: {
			switch (m) {
				case 35: a=0.108108; break;
				case 44: a=0.108108; break;
				case 45: a=0.108108; break;
				case 54: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 28: {
			switch (m) {
				case 36: a=0.108108; break;
				case 45: a=0.108108; break;
				case 46: a=0.108108; break;
				case 55: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 29: {
			switch (m) {
				case 37: a=0.108108; break;
				case 46: a=0.108108; break;
				case 56: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 30: {
			switch (m) {
				case 47: a=0.108108; break;
				case 57: a=0.108108; break;
				case 66: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 31: {
			switch (m) {
				case 48: a=0.108108; break;
				case 57: a=0.108108; break;
				case 58: a=0.108108; break;
				case 67: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 32: {
			switch (m) {
				case 49: a=0.108108; break;
				case 58: a=0.108108; break;
				case 59: a=0.108108; break;
				case 68: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 33: {
			switch (m) {
				case 50: a=0.108108; break;
				case 59: a=0.108108; break;
				case 60: a=0.108108; break;
				case 69: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 34: {
			switch (m) {
				case 51: a=0.108108; break;
				case 60: a=0.108108; break;
				case 61: a=0.108108; break;
				case 70: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 35: {
			switch (m) {
				case 52: a=0.108108; break;
				case 61: a=0.108108; break;
				case 62: a=0.108108; break;
				case 71: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 36: {
			switch (m) {
				case 53: a=0.108108; break;
				case 62: a=0.108108; break;
				case 63: a=0.108108; break;
				case 72: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 37: {
			switch (m) {
				case 54: a=0.108108; break;
				case 63: a=0.108108; break;
				case 64: a=0.108108; break;
				case 73: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 38: {
			switch (m) {
				case 55: a=0.108108; break;
				case 64: a=0.108108; break;
				case 65: a=0.108108; break;
				case 74: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 39: {
			switch (m) {
				case 56: a=0.108108; break;
				case 65: a=0.108108; break;
				case 75: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 40: {
			switch (m) {
				case 66: a=0.108108; break;
				case 76: a=0.108108; break;
				case 85: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 41: {
			switch (m) {
				case 67: a=0.108108; break;
				case 76: a=0.108108; break;
				case 77: a=0.108108; break;
				case 86: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 42: {
			switch (m) {
				case 68: a=0.108108; break;
				case 77: a=0.108108; break;
				case 78: a=0.108108; break;
				case 87: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 43: {
			switch (m) {
				case 69: a=0.108108; break;
				case 78: a=0.108108; break;
				case 79: a=0.108108; break;
				case 88: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 44: {
			switch (m) {
				case 70: a=0.108108; break;
				case 79: a=0.108108; break;
				case 80: a=0.108108; break;
				case 89: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 45: {
			switch (m) {
				case 71: a=0.108108; break;
				case 80: a=0.108108; break;
				case 81: a=0.108108; break;
				case 90: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 46: {
			switch (m) {
				case 72: a=0.108108; break;
				case 81: a=0.108108; break;
				case 82: a=0.108108; break;
				case 91: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 47: {
			switch (m) {
				case 73: a=0.108108; break;
				case 82: a=0.108108; break;
				case 83: a=0.108108; break;
				case 92: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 48: {
			switch (m) {
				case 74: a=0.108108; break;
				case 83: a=0.108108; break;
				case 84: a=0.108108; break;
				case 93: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 49: {
			switch (m) {
				case 75: a=0.108108; break;
				case 84: a=0.108108; break;
				case 94: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 50: {
			switch (m) {
				case 85: a=0.108108; break;
				case 95: a=0.108108; break;
				case 104: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 51: {
			switch (m) {
				case 86: a=0.108108; break;
				case 95: a=0.108108; break;
				case 96: a=0.108108; break;
				case 105: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 52: {
			switch (m) {
				case 87: a=0.108108; break;
				case 96: a=0.108108; break;
				case 97: a=0.108108; break;
				case 106: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 53: {
			switch (m) {
				case 88: a=0.108108; break;
				case 97: a=0.108108; break;
				case 98: a=0.108108; break;
				case 107: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 54: {
			switch (m) {
				case 89: a=0.108108; break;
				case 98: a=0.108108; break;
				case 99: a=0.108108; break;
				case 108: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 55: {
			switch (m) {
				case 90: a=0.108108; break;
				case 99: a=0.108108; break;
				case 100: a=0.108108; break;
				case 109: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 56: {
			switch (m) {
				case 91: a=0.108108; break;
				case 100: a=0.108108; break;
				case 101: a=0.108108; break;
				case 110: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 57: {
			switch (m) {
				case 92: a=0.108108; break;
				case 101: a=0.108108; break;
				case 102: a=0.108108; break;
				case 111: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 58: {
			switch (m) {
				case 93: a=0.108108; break;
				case 102: a=0.108108; break;
				case 103: a=0.108108; break;
				case 112: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 59: {
			switch (m) {
				case 94: a=0.108108; break;
				case 103: a=0.108108; break;
				case 113: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 60: {
			switch (m) {
				case 104: a=0.108108; break;
				case 114: a=0.108108; break;
				case 123: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 61: {
			switch (m) {
				case 105: a=0.108108; break;
				case 114: a=0.108108; break;
				case 115: a=0.108108; break;
				case 124: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 62: {
			switch (m) {
				case 106: a=0.108108; break;
				case 115: a=0.108108; break;
				case 116: a=0.108108; break;
				case 125: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 63: {
			switch (m) {
				case 107: a=0.108108; break;
				case 116: a=0.108108; break;
				case 117: a=0.108108; break;
				case 126: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 64: {
			switch (m) {
				case 108: a=0.108108; break;
				case 117: a=0.108108; break;
				case 118: a=0.108108; break;
				case 127: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 65: {
			switch (m) {
				case 109: a=0.108108; break;
				case 118: a=0.108108; break;
				case 119: a=0.108108; break;
				case 128: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 66: {
			switch (m) {
				case 110: a=0.108108; break;
				case 119: a=0.108108; break;
				case 120: a=0.108108; break;
				case 129: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 67: {
			switch (m) {
				case 111: a=0.108108; break;
				case 120: a=0.108108; break;
				case 121: a=0.108108; break;
				case 130: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 68: {
			switch (m) {
				case 112: a=0.108108; break;
				case 121: a=0.108108; break;
				case 122: a=0.108108; break;
				case 131: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 69: {
			switch (m) {
				case 113: a=0.108108; break;
				case 122: a=0.108108; break;
				case 132: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 70: {
			switch (m) {
				case 123: a=0.108108; break;
				case 133: a=0.108108; break;
				case 142: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 71: {
			switch (m) {
				case 124: a=0.108108; break;
				case 133: a=0.108108; break;
				case 134: a=0.108108; break;
				case 143: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 72: {
			switch (m) {
				case 125: a=0.108108; break;
				case 134: a=0.108108; break;
				case 135: a=0.108108; break;
				case 144: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 73: {
			switch (m) {
				case 126: a=0.108108; break;
				case 135: a=0.108108; break;
				case 136: a=0.108108; break;
				case 145: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 74: {
			switch (m) {
				case 127: a=0.108108; break;
				case 136: a=0.108108; break;
				case 137: a=0.108108; break;
				case 146: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 75: {
			switch (m) {
				case 128: a=0.108108; break;
				case 137: a=0.108108; break;
				case 138: a=0.108108; break;
				case 147: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 76: {
			switch (m) {
				case 129: a=0.108108; break;
				case 138: a=0.108108; break;
				case 139: a=0.108108; break;
				case 148: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 77: {
			switch (m) {
				case 130: a=0.108108; break;
				case 139: a=0.108108; break;
				case 140: a=0.108108; break;
				case 149: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 78: {
			switch (m) {
				case 131: a=0.108108; break;
				case 140: a=0.108108; break;
				case 141: a=0.108108; break;
				case 150: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 79: {
			switch (m) {
				case 132: a=0.108108; break;
				case 141: a=0.108108; break;
				case 151: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 80: {
			switch (m) {
				case 142: a=0.108108; break;
				case 152: a=0.108108; break;
				case 161: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 81: {
			switch (m) {
				case 143: a=0.108108; break;
				case 152: a=0.108108; break;
				case 153: a=0.108108; break;
				case 162: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 82: {
			switch (m) {
				case 144: a=0.108108; break;
				case 153: a=0.108108; break;
				case 154: a=0.108108; break;
				case 163: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 83: {
			switch (m) {
				case 145: a=0.108108; break;
				case 154: a=0.108108; break;
				case 155: a=0.108108; break;
				case 164: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 84: {
			switch (m) {
				case 146: a=0.108108; break;
				case 155: a=0.108108; break;
				case 156: a=0.108108; break;
				case 165: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 85: {
			switch (m) {
				case 147: a=0.108108; break;
				case 156: a=0.108108; break;
				case 157: a=0.108108; break;
				case 166: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 86: {
			switch (m) {
				case 148: a=0.108108; break;
				case 157: a=0.108108; break;
				case 158: a=0.108108; break;
				case 167: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 87: {
			switch (m) {
				case 149: a=0.108108; break;
				case 158: a=0.108108; break;
				case 159: a=0.108108; break;
				case 168: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 88: {
			switch (m) {
				case 150: a=0.108108; break;
				case 159: a=0.108108; break;
				case 160: a=0.108108; break;
				case 169: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 89: {
			switch (m) {
				case 151: a=0.108108; break;
				case 160: a=0.108108; break;
				case 170: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 90: {
			switch (m) {
				case 161: a=0.108108; break;
				case 171: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 91: {
			switch (m) {
				case 162: a=0.108108; break;
				case 171: a=0.108108; break;
				case 172: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 92: {
			switch (m) {
				case 163: a=0.108108; break;
				case 172: a=0.108108; break;
				case 173: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 93: {
			switch (m) {
				case 164: a=0.108108; break;
				case 173: a=0.108108; break;
				case 174: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 94: {
			switch (m) {
				case 165: a=0.108108; break;
				case 174: a=0.108108; break;
				case 175: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 95: {
			switch (m) {
				case 166: a=0.108108; break;
				case 175: a=0.108108; break;
				case 176: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 96: {
			switch (m) {
				case 167: a=0.108108; break;
				case 176: a=0.108108; break;
				case 177: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 97: {
			switch (m) {
				case 168: a=0.108108; break;
				case 177: a=0.108108; break;
				case 178: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 98: {
			switch (m) {
				case 169: a=0.108108; break;
				case 178: a=0.108108; break;
				case 179: a=0.108108; break;
				default: break;
			}
			break;
		}
		case 99: {
			switch (m) {
				case 170: a=0.108108; break;
				case 179: a=0.108108; break;
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
		case 0: res = 138; break;
		case 1: res = 155; break;
		case 2: res = 124; break;
		case 3: res = 151; break;
		case 4: res = 142; break;
		case 5: res = 156; break;
		case 6: res = 138; break;
		case 7: res = 170; break;
		case 8: res = 192; break;
		case 9: res = 113; break;
		case 10: res = 139; break;
		case 11: res = 170; break;
		case 12: res = 144; break;
		case 13: res = 125; break;
		case 14: res = 190; break;
		case 15: res = 141; break;
		case 16: res = 167; break;
		case 17: res = 127; break;
		case 18: res = 127; break;
		case 19: res = 141; break;
		case 20: res = 183; break;
		case 21: res = 179; break;
		case 22: res = 181; break;
		case 23: res = 164; break;
		case 24: res = 199; break;
		case 25: res = 133; break;
		case 26: res = 176; break;
		case 27: res = 168; break;
		case 28: res = 158; break;
		case 29: res = 164; break;
		case 30: res = 193; break;
		case 31: res = 193; break;
		case 32: res = 111; break;
		case 33: res = 138; break;
		case 34: res = 106; break;
		case 35: res = 159; break;
		case 36: res = 183; break;
		case 37: res = 187; break;
		case 38: res = 161; break;
		case 39: res = 198; break;
		case 40: res = 133; break;
		case 41: res = 160; break;
		case 42: res = 169; break;
		case 43: res = 139; break;
		case 44: res = 138; break;
		case 45: res = 102; break;
		case 46: res = 124; break;
		case 47: res = 139; break;
		case 48: res = 150; break;
		case 49: res = 182; break;
		case 50: res = 100; break;
		case 51: res = 124; break;
		case 52: res = 172; break;
		case 53: res = 122; break;
		case 54: res = 179; break;
		case 55: res = 133; break;
		case 56: res = 130; break;
		case 57: res = 166; break;
		case 58: res = 116; break;
		case 59: res = 145; break;
		case 60: res = 173; break;
		case 61: res = 154; break;
		case 62: res = 145; break;
		case 63: res = 184; break;
		case 64: res = 167; break;
		case 65: res = 190; break;
		case 66: res = 109; break;
		case 67: res = 170; break;
		case 68: res = 151; break;
		case 69: res = 102; break;
		case 70: res = 182; break;
		case 71: res = 113; break;
		case 72: res = 112; break;
		case 73: res = 162; break;
		case 74: res = 131; break;
		case 75: res = 143; break;
		case 76: res = 144; break;
		case 77: res = 114; break;
		case 78: res = 141; break;
		case 79: res = 117; break;
		case 80: res = 174; break;
		case 81: res = 153; break;
		case 82: res = 198; break;
		case 83: res = 103; break;
		case 84: res = 197; break;
		case 85: res = 159; break;
		case 86: res = 103; break;
		case 87: res = 143; break;
		case 88: res = 138; break;
		case 89: res = 139; break;
		case 90: res = 172; break;
		case 91: res = 166; break;
		case 92: res = 176; break;
		case 93: res = 136; break;
		case 94: res = 196; break;
		case 95: res = 180; break;
		case 96: res = 154; break;
		case 97: res = 159; break;
		case 98: res = 142; break;
		case 99: res = 111; break;
		default: break;
	}
	return res;
}

#endif
