/// @file
/// @brief embedded runtime (portable part)

#include "bcx.h"

CELL M[Msz];

CELL Ip =0;

CELL Cp	=0;

void DUMP(void) {
	for (CELL addr=0;addr<Cp;addr++) {
		if (addr % 0x10 == 0) printf("\n%.4X: ",addr);		// start addr: line
		printf("%.2X ",M[addr]);							// every byte
	}
}

void BYE(void)	{ exit(0); }
