#ifndef _FAST_WEIGHTS_H_
#define _FAST_WEIGHTS_H_

float w0(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 0: {
			switch (n1) {
				case 0: a=0.333333; break;
				case 1: a=0.333333; break;
				case 7: a=0.333333; break;
				default: break;
			}
			break;
		}
		case 1: {
			switch (n1) {
				case 0: a=0.333333; break;
				case 1: a=0.333333; break;
				case 7: a=0.333333; break;
				default: break;
			}
			break;
		}
		case 7: {
			switch (n1) {
				case 0: a=0.333333; break;
				case 1: a=0.333333; break;
				case 7: a=0.333333; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w1(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 0: {
			switch (n1) {
				case 0: a=0.250000; break;
				case 1: a=0.250000; break;
				case 2: a=0.250000; break;
				case 8: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 1: {
			switch (n1) {
				case 0: a=0.250000; break;
				case 1: a=0.250000; break;
				case 2: a=0.250000; break;
				case 8: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 2: {
			switch (n1) {
				case 0: a=0.250000; break;
				case 1: a=0.250000; break;
				case 2: a=0.250000; break;
				case 8: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 8: {
			switch (n1) {
				case 0: a=0.250000; break;
				case 1: a=0.250000; break;
				case 2: a=0.250000; break;
				case 8: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w2(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 1: {
			switch (n1) {
				case 1: a=0.250000; break;
				case 2: a=0.250000; break;
				case 3: a=0.250000; break;
				case 9: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 2: {
			switch (n1) {
				case 1: a=0.250000; break;
				case 2: a=0.250000; break;
				case 3: a=0.250000; break;
				case 9: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 3: {
			switch (n1) {
				case 1: a=0.250000; break;
				case 2: a=0.250000; break;
				case 3: a=0.250000; break;
				case 9: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 9: {
			switch (n1) {
				case 1: a=0.250000; break;
				case 2: a=0.250000; break;
				case 3: a=0.250000; break;
				case 9: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w3(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 2: {
			switch (n1) {
				case 2: a=0.250000; break;
				case 3: a=0.250000; break;
				case 4: a=0.250000; break;
				case 10: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 3: {
			switch (n1) {
				case 2: a=0.250000; break;
				case 3: a=0.250000; break;
				case 4: a=0.250000; break;
				case 10: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 4: {
			switch (n1) {
				case 2: a=0.250000; break;
				case 3: a=0.250000; break;
				case 4: a=0.250000; break;
				case 10: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 10: {
			switch (n1) {
				case 2: a=0.250000; break;
				case 3: a=0.250000; break;
				case 4: a=0.250000; break;
				case 10: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w4(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 3: {
			switch (n1) {
				case 3: a=0.250000; break;
				case 4: a=0.250000; break;
				case 5: a=0.250000; break;
				case 11: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 4: {
			switch (n1) {
				case 3: a=0.250000; break;
				case 4: a=0.250000; break;
				case 5: a=0.250000; break;
				case 11: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 5: {
			switch (n1) {
				case 3: a=0.250000; break;
				case 4: a=0.250000; break;
				case 5: a=0.250000; break;
				case 11: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 11: {
			switch (n1) {
				case 3: a=0.250000; break;
				case 4: a=0.250000; break;
				case 5: a=0.250000; break;
				case 11: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w5(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 4: {
			switch (n1) {
				case 4: a=0.250000; break;
				case 5: a=0.250000; break;
				case 6: a=0.250000; break;
				case 12: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 5: {
			switch (n1) {
				case 4: a=0.250000; break;
				case 5: a=0.250000; break;
				case 6: a=0.250000; break;
				case 12: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 6: {
			switch (n1) {
				case 4: a=0.250000; break;
				case 5: a=0.250000; break;
				case 6: a=0.250000; break;
				case 12: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 12: {
			switch (n1) {
				case 4: a=0.250000; break;
				case 5: a=0.250000; break;
				case 6: a=0.250000; break;
				case 12: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w6(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 5: {
			switch (n1) {
				case 5: a=0.333333; break;
				case 6: a=0.333333; break;
				case 13: a=0.333333; break;
				default: break;
			}
			break;
		}
		case 6: {
			switch (n1) {
				case 5: a=0.333333; break;
				case 6: a=0.333333; break;
				case 13: a=0.333333; break;
				default: break;
			}
			break;
		}
		case 13: {
			switch (n1) {
				case 5: a=0.333333; break;
				case 6: a=0.333333; break;
				case 13: a=0.333333; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w7(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 0: {
			switch (n1) {
				case 0: a=0.250000; break;
				case 7: a=0.250000; break;
				case 8: a=0.250000; break;
				case 14: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 7: {
			switch (n1) {
				case 0: a=0.250000; break;
				case 7: a=0.250000; break;
				case 8: a=0.250000; break;
				case 14: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 8: {
			switch (n1) {
				case 0: a=0.250000; break;
				case 7: a=0.250000; break;
				case 8: a=0.250000; break;
				case 14: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 14: {
			switch (n1) {
				case 0: a=0.250000; break;
				case 7: a=0.250000; break;
				case 8: a=0.250000; break;
				case 14: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w8(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 1: {
			switch (n1) {
				case 1: a=0.200000; break;
				case 7: a=0.200000; break;
				case 8: a=0.200000; break;
				case 9: a=0.200000; break;
				case 15: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 7: {
			switch (n1) {
				case 1: a=0.200000; break;
				case 7: a=0.200000; break;
				case 8: a=0.200000; break;
				case 9: a=0.200000; break;
				case 15: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 8: {
			switch (n1) {
				case 1: a=0.200000; break;
				case 7: a=0.200000; break;
				case 8: a=0.200000; break;
				case 9: a=0.200000; break;
				case 15: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 9: {
			switch (n1) {
				case 1: a=0.200000; break;
				case 7: a=0.200000; break;
				case 8: a=0.200000; break;
				case 9: a=0.200000; break;
				case 15: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 15: {
			switch (n1) {
				case 1: a=0.200000; break;
				case 7: a=0.200000; break;
				case 8: a=0.200000; break;
				case 9: a=0.200000; break;
				case 15: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w9(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 2: {
			switch (n1) {
				case 2: a=0.200000; break;
				case 8: a=0.200000; break;
				case 9: a=0.200000; break;
				case 10: a=0.200000; break;
				case 16: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 8: {
			switch (n1) {
				case 2: a=0.200000; break;
				case 8: a=0.200000; break;
				case 9: a=0.200000; break;
				case 10: a=0.200000; break;
				case 16: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 9: {
			switch (n1) {
				case 2: a=0.200000; break;
				case 8: a=0.200000; break;
				case 9: a=0.200000; break;
				case 10: a=0.200000; break;
				case 16: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 10: {
			switch (n1) {
				case 2: a=0.200000; break;
				case 8: a=0.200000; break;
				case 9: a=0.200000; break;
				case 10: a=0.200000; break;
				case 16: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 16: {
			switch (n1) {
				case 2: a=0.200000; break;
				case 8: a=0.200000; break;
				case 9: a=0.200000; break;
				case 10: a=0.200000; break;
				case 16: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w10(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 3: {
			switch (n1) {
				case 3: a=0.200000; break;
				case 9: a=0.200000; break;
				case 10: a=0.200000; break;
				case 11: a=0.200000; break;
				case 17: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 9: {
			switch (n1) {
				case 3: a=0.200000; break;
				case 9: a=0.200000; break;
				case 10: a=0.200000; break;
				case 11: a=0.200000; break;
				case 17: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 10: {
			switch (n1) {
				case 3: a=0.200000; break;
				case 9: a=0.200000; break;
				case 10: a=0.200000; break;
				case 11: a=0.200000; break;
				case 17: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 11: {
			switch (n1) {
				case 3: a=0.200000; break;
				case 9: a=0.200000; break;
				case 10: a=0.200000; break;
				case 11: a=0.200000; break;
				case 17: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 17: {
			switch (n1) {
				case 3: a=0.200000; break;
				case 9: a=0.200000; break;
				case 10: a=0.200000; break;
				case 11: a=0.200000; break;
				case 17: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w11(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 4: {
			switch (n1) {
				case 4: a=0.200000; break;
				case 10: a=0.200000; break;
				case 11: a=0.200000; break;
				case 12: a=0.200000; break;
				case 18: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 10: {
			switch (n1) {
				case 4: a=0.200000; break;
				case 10: a=0.200000; break;
				case 11: a=0.200000; break;
				case 12: a=0.200000; break;
				case 18: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 11: {
			switch (n1) {
				case 4: a=0.200000; break;
				case 10: a=0.200000; break;
				case 11: a=0.200000; break;
				case 12: a=0.200000; break;
				case 18: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 12: {
			switch (n1) {
				case 4: a=0.200000; break;
				case 10: a=0.200000; break;
				case 11: a=0.200000; break;
				case 12: a=0.200000; break;
				case 18: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 18: {
			switch (n1) {
				case 4: a=0.200000; break;
				case 10: a=0.200000; break;
				case 11: a=0.200000; break;
				case 12: a=0.200000; break;
				case 18: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w12(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 5: {
			switch (n1) {
				case 5: a=0.200000; break;
				case 11: a=0.200000; break;
				case 12: a=0.200000; break;
				case 13: a=0.200000; break;
				case 19: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 11: {
			switch (n1) {
				case 5: a=0.200000; break;
				case 11: a=0.200000; break;
				case 12: a=0.200000; break;
				case 13: a=0.200000; break;
				case 19: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 12: {
			switch (n1) {
				case 5: a=0.200000; break;
				case 11: a=0.200000; break;
				case 12: a=0.200000; break;
				case 13: a=0.200000; break;
				case 19: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 13: {
			switch (n1) {
				case 5: a=0.200000; break;
				case 11: a=0.200000; break;
				case 12: a=0.200000; break;
				case 13: a=0.200000; break;
				case 19: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 19: {
			switch (n1) {
				case 5: a=0.200000; break;
				case 11: a=0.200000; break;
				case 12: a=0.200000; break;
				case 13: a=0.200000; break;
				case 19: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w13(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 6: {
			switch (n1) {
				case 6: a=0.250000; break;
				case 12: a=0.250000; break;
				case 13: a=0.250000; break;
				case 20: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 12: {
			switch (n1) {
				case 6: a=0.250000; break;
				case 12: a=0.250000; break;
				case 13: a=0.250000; break;
				case 20: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 13: {
			switch (n1) {
				case 6: a=0.250000; break;
				case 12: a=0.250000; break;
				case 13: a=0.250000; break;
				case 20: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 20: {
			switch (n1) {
				case 6: a=0.250000; break;
				case 12: a=0.250000; break;
				case 13: a=0.250000; break;
				case 20: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w14(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 7: {
			switch (n1) {
				case 7: a=0.250000; break;
				case 14: a=0.250000; break;
				case 15: a=0.250000; break;
				case 21: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 14: {
			switch (n1) {
				case 7: a=0.250000; break;
				case 14: a=0.250000; break;
				case 15: a=0.250000; break;
				case 21: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 15: {
			switch (n1) {
				case 7: a=0.250000; break;
				case 14: a=0.250000; break;
				case 15: a=0.250000; break;
				case 21: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 21: {
			switch (n1) {
				case 7: a=0.250000; break;
				case 14: a=0.250000; break;
				case 15: a=0.250000; break;
				case 21: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w15(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 8: {
			switch (n1) {
				case 8: a=0.200000; break;
				case 14: a=0.200000; break;
				case 15: a=0.200000; break;
				case 16: a=0.200000; break;
				case 22: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 14: {
			switch (n1) {
				case 8: a=0.200000; break;
				case 14: a=0.200000; break;
				case 15: a=0.200000; break;
				case 16: a=0.200000; break;
				case 22: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 15: {
			switch (n1) {
				case 8: a=0.200000; break;
				case 14: a=0.200000; break;
				case 15: a=0.200000; break;
				case 16: a=0.200000; break;
				case 22: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 16: {
			switch (n1) {
				case 8: a=0.200000; break;
				case 14: a=0.200000; break;
				case 15: a=0.200000; break;
				case 16: a=0.200000; break;
				case 22: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 22: {
			switch (n1) {
				case 8: a=0.200000; break;
				case 14: a=0.200000; break;
				case 15: a=0.200000; break;
				case 16: a=0.200000; break;
				case 22: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w16(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 9: {
			switch (n1) {
				case 9: a=0.200000; break;
				case 15: a=0.200000; break;
				case 16: a=0.200000; break;
				case 17: a=0.200000; break;
				case 23: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 15: {
			switch (n1) {
				case 9: a=0.200000; break;
				case 15: a=0.200000; break;
				case 16: a=0.200000; break;
				case 17: a=0.200000; break;
				case 23: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 16: {
			switch (n1) {
				case 9: a=0.200000; break;
				case 15: a=0.200000; break;
				case 16: a=0.200000; break;
				case 17: a=0.200000; break;
				case 23: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 17: {
			switch (n1) {
				case 9: a=0.200000; break;
				case 15: a=0.200000; break;
				case 16: a=0.200000; break;
				case 17: a=0.200000; break;
				case 23: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 23: {
			switch (n1) {
				case 9: a=0.200000; break;
				case 15: a=0.200000; break;
				case 16: a=0.200000; break;
				case 17: a=0.200000; break;
				case 23: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w17(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 10: {
			switch (n1) {
				case 10: a=0.200000; break;
				case 16: a=0.200000; break;
				case 17: a=0.200000; break;
				case 18: a=0.200000; break;
				case 24: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 16: {
			switch (n1) {
				case 10: a=0.200000; break;
				case 16: a=0.200000; break;
				case 17: a=0.200000; break;
				case 18: a=0.200000; break;
				case 24: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 17: {
			switch (n1) {
				case 10: a=0.200000; break;
				case 16: a=0.200000; break;
				case 17: a=0.200000; break;
				case 18: a=0.200000; break;
				case 24: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 18: {
			switch (n1) {
				case 10: a=0.200000; break;
				case 16: a=0.200000; break;
				case 17: a=0.200000; break;
				case 18: a=0.200000; break;
				case 24: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 24: {
			switch (n1) {
				case 10: a=0.200000; break;
				case 16: a=0.200000; break;
				case 17: a=0.200000; break;
				case 18: a=0.200000; break;
				case 24: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w18(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 11: {
			switch (n1) {
				case 11: a=0.200000; break;
				case 17: a=0.200000; break;
				case 18: a=0.200000; break;
				case 19: a=0.200000; break;
				case 25: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 17: {
			switch (n1) {
				case 11: a=0.200000; break;
				case 17: a=0.200000; break;
				case 18: a=0.200000; break;
				case 19: a=0.200000; break;
				case 25: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 18: {
			switch (n1) {
				case 11: a=0.200000; break;
				case 17: a=0.200000; break;
				case 18: a=0.200000; break;
				case 19: a=0.200000; break;
				case 25: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 19: {
			switch (n1) {
				case 11: a=0.200000; break;
				case 17: a=0.200000; break;
				case 18: a=0.200000; break;
				case 19: a=0.200000; break;
				case 25: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 25: {
			switch (n1) {
				case 11: a=0.200000; break;
				case 17: a=0.200000; break;
				case 18: a=0.200000; break;
				case 19: a=0.200000; break;
				case 25: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w19(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 12: {
			switch (n1) {
				case 12: a=0.200000; break;
				case 18: a=0.200000; break;
				case 19: a=0.200000; break;
				case 20: a=0.200000; break;
				case 26: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 18: {
			switch (n1) {
				case 12: a=0.200000; break;
				case 18: a=0.200000; break;
				case 19: a=0.200000; break;
				case 20: a=0.200000; break;
				case 26: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 19: {
			switch (n1) {
				case 12: a=0.200000; break;
				case 18: a=0.200000; break;
				case 19: a=0.200000; break;
				case 20: a=0.200000; break;
				case 26: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 20: {
			switch (n1) {
				case 12: a=0.200000; break;
				case 18: a=0.200000; break;
				case 19: a=0.200000; break;
				case 20: a=0.200000; break;
				case 26: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 26: {
			switch (n1) {
				case 12: a=0.200000; break;
				case 18: a=0.200000; break;
				case 19: a=0.200000; break;
				case 20: a=0.200000; break;
				case 26: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w20(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 13: {
			switch (n1) {
				case 13: a=0.250000; break;
				case 19: a=0.250000; break;
				case 20: a=0.250000; break;
				case 27: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 19: {
			switch (n1) {
				case 13: a=0.250000; break;
				case 19: a=0.250000; break;
				case 20: a=0.250000; break;
				case 27: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 20: {
			switch (n1) {
				case 13: a=0.250000; break;
				case 19: a=0.250000; break;
				case 20: a=0.250000; break;
				case 27: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 27: {
			switch (n1) {
				case 13: a=0.250000; break;
				case 19: a=0.250000; break;
				case 20: a=0.250000; break;
				case 27: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w21(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 14: {
			switch (n1) {
				case 14: a=0.250000; break;
				case 21: a=0.250000; break;
				case 22: a=0.250000; break;
				case 28: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 21: {
			switch (n1) {
				case 14: a=0.250000; break;
				case 21: a=0.250000; break;
				case 22: a=0.250000; break;
				case 28: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 22: {
			switch (n1) {
				case 14: a=0.250000; break;
				case 21: a=0.250000; break;
				case 22: a=0.250000; break;
				case 28: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 28: {
			switch (n1) {
				case 14: a=0.250000; break;
				case 21: a=0.250000; break;
				case 22: a=0.250000; break;
				case 28: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w22(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 15: {
			switch (n1) {
				case 15: a=0.200000; break;
				case 21: a=0.200000; break;
				case 22: a=0.200000; break;
				case 23: a=0.200000; break;
				case 29: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 21: {
			switch (n1) {
				case 15: a=0.200000; break;
				case 21: a=0.200000; break;
				case 22: a=0.200000; break;
				case 23: a=0.200000; break;
				case 29: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 22: {
			switch (n1) {
				case 15: a=0.200000; break;
				case 21: a=0.200000; break;
				case 22: a=0.200000; break;
				case 23: a=0.200000; break;
				case 29: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 23: {
			switch (n1) {
				case 15: a=0.200000; break;
				case 21: a=0.200000; break;
				case 22: a=0.200000; break;
				case 23: a=0.200000; break;
				case 29: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 29: {
			switch (n1) {
				case 15: a=0.200000; break;
				case 21: a=0.200000; break;
				case 22: a=0.200000; break;
				case 23: a=0.200000; break;
				case 29: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w23(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 16: {
			switch (n1) {
				case 16: a=0.200000; break;
				case 22: a=0.200000; break;
				case 23: a=0.200000; break;
				case 24: a=0.200000; break;
				case 30: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 22: {
			switch (n1) {
				case 16: a=0.200000; break;
				case 22: a=0.200000; break;
				case 23: a=0.200000; break;
				case 24: a=0.200000; break;
				case 30: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 23: {
			switch (n1) {
				case 16: a=0.200000; break;
				case 22: a=0.200000; break;
				case 23: a=0.200000; break;
				case 24: a=0.200000; break;
				case 30: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 24: {
			switch (n1) {
				case 16: a=0.200000; break;
				case 22: a=0.200000; break;
				case 23: a=0.200000; break;
				case 24: a=0.200000; break;
				case 30: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 30: {
			switch (n1) {
				case 16: a=0.200000; break;
				case 22: a=0.200000; break;
				case 23: a=0.200000; break;
				case 24: a=0.200000; break;
				case 30: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w24(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 17: {
			switch (n1) {
				case 17: a=0.200000; break;
				case 23: a=0.200000; break;
				case 24: a=0.200000; break;
				case 25: a=0.200000; break;
				case 31: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 23: {
			switch (n1) {
				case 17: a=0.200000; break;
				case 23: a=0.200000; break;
				case 24: a=0.200000; break;
				case 25: a=0.200000; break;
				case 31: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 24: {
			switch (n1) {
				case 17: a=0.200000; break;
				case 23: a=0.200000; break;
				case 24: a=0.200000; break;
				case 25: a=0.200000; break;
				case 31: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 25: {
			switch (n1) {
				case 17: a=0.200000; break;
				case 23: a=0.200000; break;
				case 24: a=0.200000; break;
				case 25: a=0.200000; break;
				case 31: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 31: {
			switch (n1) {
				case 17: a=0.200000; break;
				case 23: a=0.200000; break;
				case 24: a=0.200000; break;
				case 25: a=0.200000; break;
				case 31: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w25(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 18: {
			switch (n1) {
				case 18: a=0.200000; break;
				case 24: a=0.200000; break;
				case 25: a=0.200000; break;
				case 26: a=0.200000; break;
				case 32: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 24: {
			switch (n1) {
				case 18: a=0.200000; break;
				case 24: a=0.200000; break;
				case 25: a=0.200000; break;
				case 26: a=0.200000; break;
				case 32: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 25: {
			switch (n1) {
				case 18: a=0.200000; break;
				case 24: a=0.200000; break;
				case 25: a=0.200000; break;
				case 26: a=0.200000; break;
				case 32: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 26: {
			switch (n1) {
				case 18: a=0.200000; break;
				case 24: a=0.200000; break;
				case 25: a=0.200000; break;
				case 26: a=0.200000; break;
				case 32: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 32: {
			switch (n1) {
				case 18: a=0.200000; break;
				case 24: a=0.200000; break;
				case 25: a=0.200000; break;
				case 26: a=0.200000; break;
				case 32: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w26(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 19: {
			switch (n1) {
				case 19: a=0.200000; break;
				case 25: a=0.200000; break;
				case 26: a=0.200000; break;
				case 27: a=0.200000; break;
				case 33: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 25: {
			switch (n1) {
				case 19: a=0.200000; break;
				case 25: a=0.200000; break;
				case 26: a=0.200000; break;
				case 27: a=0.200000; break;
				case 33: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 26: {
			switch (n1) {
				case 19: a=0.200000; break;
				case 25: a=0.200000; break;
				case 26: a=0.200000; break;
				case 27: a=0.200000; break;
				case 33: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 27: {
			switch (n1) {
				case 19: a=0.200000; break;
				case 25: a=0.200000; break;
				case 26: a=0.200000; break;
				case 27: a=0.200000; break;
				case 33: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 33: {
			switch (n1) {
				case 19: a=0.200000; break;
				case 25: a=0.200000; break;
				case 26: a=0.200000; break;
				case 27: a=0.200000; break;
				case 33: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w27(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 20: {
			switch (n1) {
				case 20: a=0.250000; break;
				case 26: a=0.250000; break;
				case 27: a=0.250000; break;
				case 34: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 26: {
			switch (n1) {
				case 20: a=0.250000; break;
				case 26: a=0.250000; break;
				case 27: a=0.250000; break;
				case 34: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 27: {
			switch (n1) {
				case 20: a=0.250000; break;
				case 26: a=0.250000; break;
				case 27: a=0.250000; break;
				case 34: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 34: {
			switch (n1) {
				case 20: a=0.250000; break;
				case 26: a=0.250000; break;
				case 27: a=0.250000; break;
				case 34: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w28(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 21: {
			switch (n1) {
				case 21: a=0.250000; break;
				case 28: a=0.250000; break;
				case 29: a=0.250000; break;
				case 35: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 28: {
			switch (n1) {
				case 21: a=0.250000; break;
				case 28: a=0.250000; break;
				case 29: a=0.250000; break;
				case 35: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 29: {
			switch (n1) {
				case 21: a=0.250000; break;
				case 28: a=0.250000; break;
				case 29: a=0.250000; break;
				case 35: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 35: {
			switch (n1) {
				case 21: a=0.250000; break;
				case 28: a=0.250000; break;
				case 29: a=0.250000; break;
				case 35: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w29(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 22: {
			switch (n1) {
				case 22: a=0.200000; break;
				case 28: a=0.200000; break;
				case 29: a=0.200000; break;
				case 30: a=0.200000; break;
				case 36: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 28: {
			switch (n1) {
				case 22: a=0.200000; break;
				case 28: a=0.200000; break;
				case 29: a=0.200000; break;
				case 30: a=0.200000; break;
				case 36: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 29: {
			switch (n1) {
				case 22: a=0.200000; break;
				case 28: a=0.200000; break;
				case 29: a=0.200000; break;
				case 30: a=0.200000; break;
				case 36: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 30: {
			switch (n1) {
				case 22: a=0.200000; break;
				case 28: a=0.200000; break;
				case 29: a=0.200000; break;
				case 30: a=0.200000; break;
				case 36: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 36: {
			switch (n1) {
				case 22: a=0.200000; break;
				case 28: a=0.200000; break;
				case 29: a=0.200000; break;
				case 30: a=0.200000; break;
				case 36: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w30(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 23: {
			switch (n1) {
				case 23: a=0.200000; break;
				case 29: a=0.200000; break;
				case 30: a=0.200000; break;
				case 31: a=0.200000; break;
				case 37: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 29: {
			switch (n1) {
				case 23: a=0.200000; break;
				case 29: a=0.200000; break;
				case 30: a=0.200000; break;
				case 31: a=0.200000; break;
				case 37: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 30: {
			switch (n1) {
				case 23: a=0.200000; break;
				case 29: a=0.200000; break;
				case 30: a=0.200000; break;
				case 31: a=0.200000; break;
				case 37: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 31: {
			switch (n1) {
				case 23: a=0.200000; break;
				case 29: a=0.200000; break;
				case 30: a=0.200000; break;
				case 31: a=0.200000; break;
				case 37: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 37: {
			switch (n1) {
				case 23: a=0.200000; break;
				case 29: a=0.200000; break;
				case 30: a=0.200000; break;
				case 31: a=0.200000; break;
				case 37: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w31(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 24: {
			switch (n1) {
				case 24: a=0.200000; break;
				case 30: a=0.200000; break;
				case 31: a=0.200000; break;
				case 32: a=0.200000; break;
				case 38: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 30: {
			switch (n1) {
				case 24: a=0.200000; break;
				case 30: a=0.200000; break;
				case 31: a=0.200000; break;
				case 32: a=0.200000; break;
				case 38: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 31: {
			switch (n1) {
				case 24: a=0.200000; break;
				case 30: a=0.200000; break;
				case 31: a=0.200000; break;
				case 32: a=0.200000; break;
				case 38: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 32: {
			switch (n1) {
				case 24: a=0.200000; break;
				case 30: a=0.200000; break;
				case 31: a=0.200000; break;
				case 32: a=0.200000; break;
				case 38: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 38: {
			switch (n1) {
				case 24: a=0.200000; break;
				case 30: a=0.200000; break;
				case 31: a=0.200000; break;
				case 32: a=0.200000; break;
				case 38: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w32(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 25: {
			switch (n1) {
				case 25: a=0.200000; break;
				case 31: a=0.200000; break;
				case 32: a=0.200000; break;
				case 33: a=0.200000; break;
				case 39: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 31: {
			switch (n1) {
				case 25: a=0.200000; break;
				case 31: a=0.200000; break;
				case 32: a=0.200000; break;
				case 33: a=0.200000; break;
				case 39: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 32: {
			switch (n1) {
				case 25: a=0.200000; break;
				case 31: a=0.200000; break;
				case 32: a=0.200000; break;
				case 33: a=0.200000; break;
				case 39: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 33: {
			switch (n1) {
				case 25: a=0.200000; break;
				case 31: a=0.200000; break;
				case 32: a=0.200000; break;
				case 33: a=0.200000; break;
				case 39: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 39: {
			switch (n1) {
				case 25: a=0.200000; break;
				case 31: a=0.200000; break;
				case 32: a=0.200000; break;
				case 33: a=0.200000; break;
				case 39: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w33(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 26: {
			switch (n1) {
				case 26: a=0.200000; break;
				case 32: a=0.200000; break;
				case 33: a=0.200000; break;
				case 34: a=0.200000; break;
				case 40: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 32: {
			switch (n1) {
				case 26: a=0.200000; break;
				case 32: a=0.200000; break;
				case 33: a=0.200000; break;
				case 34: a=0.200000; break;
				case 40: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 33: {
			switch (n1) {
				case 26: a=0.200000; break;
				case 32: a=0.200000; break;
				case 33: a=0.200000; break;
				case 34: a=0.200000; break;
				case 40: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 34: {
			switch (n1) {
				case 26: a=0.200000; break;
				case 32: a=0.200000; break;
				case 33: a=0.200000; break;
				case 34: a=0.200000; break;
				case 40: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 40: {
			switch (n1) {
				case 26: a=0.200000; break;
				case 32: a=0.200000; break;
				case 33: a=0.200000; break;
				case 34: a=0.200000; break;
				case 40: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w34(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 27: {
			switch (n1) {
				case 27: a=0.250000; break;
				case 33: a=0.250000; break;
				case 34: a=0.250000; break;
				case 41: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 33: {
			switch (n1) {
				case 27: a=0.250000; break;
				case 33: a=0.250000; break;
				case 34: a=0.250000; break;
				case 41: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 34: {
			switch (n1) {
				case 27: a=0.250000; break;
				case 33: a=0.250000; break;
				case 34: a=0.250000; break;
				case 41: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 41: {
			switch (n1) {
				case 27: a=0.250000; break;
				case 33: a=0.250000; break;
				case 34: a=0.250000; break;
				case 41: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w35(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 28: {
			switch (n1) {
				case 28: a=0.250000; break;
				case 35: a=0.250000; break;
				case 36: a=0.250000; break;
				case 42: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 35: {
			switch (n1) {
				case 28: a=0.250000; break;
				case 35: a=0.250000; break;
				case 36: a=0.250000; break;
				case 42: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 36: {
			switch (n1) {
				case 28: a=0.250000; break;
				case 35: a=0.250000; break;
				case 36: a=0.250000; break;
				case 42: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 42: {
			switch (n1) {
				case 28: a=0.250000; break;
				case 35: a=0.250000; break;
				case 36: a=0.250000; break;
				case 42: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w36(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 29: {
			switch (n1) {
				case 29: a=0.200000; break;
				case 35: a=0.200000; break;
				case 36: a=0.200000; break;
				case 37: a=0.200000; break;
				case 43: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 35: {
			switch (n1) {
				case 29: a=0.200000; break;
				case 35: a=0.200000; break;
				case 36: a=0.200000; break;
				case 37: a=0.200000; break;
				case 43: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 36: {
			switch (n1) {
				case 29: a=0.200000; break;
				case 35: a=0.200000; break;
				case 36: a=0.200000; break;
				case 37: a=0.200000; break;
				case 43: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 37: {
			switch (n1) {
				case 29: a=0.200000; break;
				case 35: a=0.200000; break;
				case 36: a=0.200000; break;
				case 37: a=0.200000; break;
				case 43: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 43: {
			switch (n1) {
				case 29: a=0.200000; break;
				case 35: a=0.200000; break;
				case 36: a=0.200000; break;
				case 37: a=0.200000; break;
				case 43: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w37(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 30: {
			switch (n1) {
				case 30: a=0.200000; break;
				case 36: a=0.200000; break;
				case 37: a=0.200000; break;
				case 38: a=0.200000; break;
				case 44: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 36: {
			switch (n1) {
				case 30: a=0.200000; break;
				case 36: a=0.200000; break;
				case 37: a=0.200000; break;
				case 38: a=0.200000; break;
				case 44: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 37: {
			switch (n1) {
				case 30: a=0.200000; break;
				case 36: a=0.200000; break;
				case 37: a=0.200000; break;
				case 38: a=0.200000; break;
				case 44: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 38: {
			switch (n1) {
				case 30: a=0.200000; break;
				case 36: a=0.200000; break;
				case 37: a=0.200000; break;
				case 38: a=0.200000; break;
				case 44: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 44: {
			switch (n1) {
				case 30: a=0.200000; break;
				case 36: a=0.200000; break;
				case 37: a=0.200000; break;
				case 38: a=0.200000; break;
				case 44: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w38(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 31: {
			switch (n1) {
				case 31: a=0.200000; break;
				case 37: a=0.200000; break;
				case 38: a=0.200000; break;
				case 39: a=0.200000; break;
				case 45: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 37: {
			switch (n1) {
				case 31: a=0.200000; break;
				case 37: a=0.200000; break;
				case 38: a=0.200000; break;
				case 39: a=0.200000; break;
				case 45: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 38: {
			switch (n1) {
				case 31: a=0.200000; break;
				case 37: a=0.200000; break;
				case 38: a=0.200000; break;
				case 39: a=0.200000; break;
				case 45: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 39: {
			switch (n1) {
				case 31: a=0.200000; break;
				case 37: a=0.200000; break;
				case 38: a=0.200000; break;
				case 39: a=0.200000; break;
				case 45: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 45: {
			switch (n1) {
				case 31: a=0.200000; break;
				case 37: a=0.200000; break;
				case 38: a=0.200000; break;
				case 39: a=0.200000; break;
				case 45: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w39(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 32: {
			switch (n1) {
				case 32: a=0.200000; break;
				case 38: a=0.200000; break;
				case 39: a=0.200000; break;
				case 40: a=0.200000; break;
				case 46: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 38: {
			switch (n1) {
				case 32: a=0.200000; break;
				case 38: a=0.200000; break;
				case 39: a=0.200000; break;
				case 40: a=0.200000; break;
				case 46: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 39: {
			switch (n1) {
				case 32: a=0.200000; break;
				case 38: a=0.200000; break;
				case 39: a=0.200000; break;
				case 40: a=0.200000; break;
				case 46: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 40: {
			switch (n1) {
				case 32: a=0.200000; break;
				case 38: a=0.200000; break;
				case 39: a=0.200000; break;
				case 40: a=0.200000; break;
				case 46: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 46: {
			switch (n1) {
				case 32: a=0.200000; break;
				case 38: a=0.200000; break;
				case 39: a=0.200000; break;
				case 40: a=0.200000; break;
				case 46: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w40(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 33: {
			switch (n1) {
				case 33: a=0.200000; break;
				case 39: a=0.200000; break;
				case 40: a=0.200000; break;
				case 41: a=0.200000; break;
				case 47: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 39: {
			switch (n1) {
				case 33: a=0.200000; break;
				case 39: a=0.200000; break;
				case 40: a=0.200000; break;
				case 41: a=0.200000; break;
				case 47: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 40: {
			switch (n1) {
				case 33: a=0.200000; break;
				case 39: a=0.200000; break;
				case 40: a=0.200000; break;
				case 41: a=0.200000; break;
				case 47: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 41: {
			switch (n1) {
				case 33: a=0.200000; break;
				case 39: a=0.200000; break;
				case 40: a=0.200000; break;
				case 41: a=0.200000; break;
				case 47: a=0.200000; break;
				default: break;
			}
			break;
		}
		case 47: {
			switch (n1) {
				case 33: a=0.200000; break;
				case 39: a=0.200000; break;
				case 40: a=0.200000; break;
				case 41: a=0.200000; break;
				case 47: a=0.200000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w41(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 34: {
			switch (n1) {
				case 34: a=0.250000; break;
				case 40: a=0.250000; break;
				case 41: a=0.250000; break;
				case 48: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 40: {
			switch (n1) {
				case 34: a=0.250000; break;
				case 40: a=0.250000; break;
				case 41: a=0.250000; break;
				case 48: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 41: {
			switch (n1) {
				case 34: a=0.250000; break;
				case 40: a=0.250000; break;
				case 41: a=0.250000; break;
				case 48: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 48: {
			switch (n1) {
				case 34: a=0.250000; break;
				case 40: a=0.250000; break;
				case 41: a=0.250000; break;
				case 48: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w42(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 35: {
			switch (n1) {
				case 35: a=0.333333; break;
				case 42: a=0.333333; break;
				case 43: a=0.333333; break;
				default: break;
			}
			break;
		}
		case 42: {
			switch (n1) {
				case 35: a=0.333333; break;
				case 42: a=0.333333; break;
				case 43: a=0.333333; break;
				default: break;
			}
			break;
		}
		case 43: {
			switch (n1) {
				case 35: a=0.333333; break;
				case 42: a=0.333333; break;
				case 43: a=0.333333; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w43(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 36: {
			switch (n1) {
				case 36: a=0.250000; break;
				case 42: a=0.250000; break;
				case 43: a=0.250000; break;
				case 44: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 42: {
			switch (n1) {
				case 36: a=0.250000; break;
				case 42: a=0.250000; break;
				case 43: a=0.250000; break;
				case 44: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 43: {
			switch (n1) {
				case 36: a=0.250000; break;
				case 42: a=0.250000; break;
				case 43: a=0.250000; break;
				case 44: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 44: {
			switch (n1) {
				case 36: a=0.250000; break;
				case 42: a=0.250000; break;
				case 43: a=0.250000; break;
				case 44: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w44(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 37: {
			switch (n1) {
				case 37: a=0.250000; break;
				case 43: a=0.250000; break;
				case 44: a=0.250000; break;
				case 45: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 43: {
			switch (n1) {
				case 37: a=0.250000; break;
				case 43: a=0.250000; break;
				case 44: a=0.250000; break;
				case 45: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 44: {
			switch (n1) {
				case 37: a=0.250000; break;
				case 43: a=0.250000; break;
				case 44: a=0.250000; break;
				case 45: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 45: {
			switch (n1) {
				case 37: a=0.250000; break;
				case 43: a=0.250000; break;
				case 44: a=0.250000; break;
				case 45: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w45(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 38: {
			switch (n1) {
				case 38: a=0.250000; break;
				case 44: a=0.250000; break;
				case 45: a=0.250000; break;
				case 46: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 44: {
			switch (n1) {
				case 38: a=0.250000; break;
				case 44: a=0.250000; break;
				case 45: a=0.250000; break;
				case 46: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 45: {
			switch (n1) {
				case 38: a=0.250000; break;
				case 44: a=0.250000; break;
				case 45: a=0.250000; break;
				case 46: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 46: {
			switch (n1) {
				case 38: a=0.250000; break;
				case 44: a=0.250000; break;
				case 45: a=0.250000; break;
				case 46: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w46(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 39: {
			switch (n1) {
				case 39: a=0.250000; break;
				case 45: a=0.250000; break;
				case 46: a=0.250000; break;
				case 47: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 45: {
			switch (n1) {
				case 39: a=0.250000; break;
				case 45: a=0.250000; break;
				case 46: a=0.250000; break;
				case 47: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 46: {
			switch (n1) {
				case 39: a=0.250000; break;
				case 45: a=0.250000; break;
				case 46: a=0.250000; break;
				case 47: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 47: {
			switch (n1) {
				case 39: a=0.250000; break;
				case 45: a=0.250000; break;
				case 46: a=0.250000; break;
				case 47: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w47(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 40: {
			switch (n1) {
				case 40: a=0.250000; break;
				case 46: a=0.250000; break;
				case 47: a=0.250000; break;
				case 48: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 46: {
			switch (n1) {
				case 40: a=0.250000; break;
				case 46: a=0.250000; break;
				case 47: a=0.250000; break;
				case 48: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 47: {
			switch (n1) {
				case 40: a=0.250000; break;
				case 46: a=0.250000; break;
				case 47: a=0.250000; break;
				case 48: a=0.250000; break;
				default: break;
			}
			break;
		}
		case 48: {
			switch (n1) {
				case 40: a=0.250000; break;
				case 46: a=0.250000; break;
				case 47: a=0.250000; break;
				case 48: a=0.250000; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float w48(uint16_t n1) {
	float a = 0;
	switch (TOS_NODE_ID) {
		case 41: {
			switch (n1) {
				case 41: a=0.333333; break;
				case 47: a=0.333333; break;
				case 48: a=0.333333; break;
				default: break;
			}
			break;
		}
		case 47: {
			switch (n1) {
				case 41: a=0.333333; break;
				case 47: a=0.333333; break;
				case 48: a=0.333333; break;
				default: break;
			}
			break;
		}
		case 48: {
			switch (n1) {
				case 41: a=0.333333; break;
				case 47: a=0.333333; break;
				case 48: a=0.333333; break;
				default: break;
			}
			break;
		}
		default: break;
	}
	return a;
}

float W(uint8_t m, uint16_t n1) {
	switch (m) {
		case 0: return w0(n1);
		case 1: return w1(n1);
		case 2: return w2(n1);
		case 3: return w3(n1);
		case 4: return w4(n1);
		case 5: return w5(n1);
		case 6: return w6(n1);
		case 7: return w7(n1);
		case 8: return w8(n1);
		case 9: return w9(n1);
		case 10: return w10(n1);
		case 11: return w11(n1);
		case 12: return w12(n1);
		case 13: return w13(n1);
		case 14: return w14(n1);
		case 15: return w15(n1);
		case 16: return w16(n1);
		case 17: return w17(n1);
		case 18: return w18(n1);
		case 19: return w19(n1);
		case 20: return w20(n1);
		case 21: return w21(n1);
		case 22: return w22(n1);
		case 23: return w23(n1);
		case 24: return w24(n1);
		case 25: return w25(n1);
		case 26: return w26(n1);
		case 27: return w27(n1);
		case 28: return w28(n1);
		case 29: return w29(n1);
		case 30: return w30(n1);
		case 31: return w31(n1);
		case 32: return w32(n1);
		case 33: return w33(n1);
		case 34: return w34(n1);
		case 35: return w35(n1);
		case 36: return w36(n1);
		case 37: return w37(n1);
		case 38: return w38(n1);
		case 39: return w39(n1);
		case 40: return w40(n1);
		case 41: return w41(n1);
		case 42: return w42(n1);
		case 43: return w43(n1);
		case 44: return w44(n1);
		case 45: return w45(n1);
		case 46: return w46(n1);
		case 47: return w47(n1);
		case 48: return w48(n1);
		default: return 0;
	}
}

#endif
