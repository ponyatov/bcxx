/// @file
/// @brief embedded runtime (portable core) ANSI C'89 code

#include "bcx.h"

BYTE M[Msz];

CELL Ip =0;

CELL Cp	=0;

bool trace	=true;

void DUMP(void) {
	for (CELL addr=0;addr<Cp;addr++) {
		if (addr % 0x10 == 0) printf("\n%.4X: ",addr);		// start addr: line
		fprintf(stderr,"%.2X ",M[addr]);					// every byte
	}
}

void NOP(void)	{ if (trace) printf("nop"); }
void BYE(void)	{ if (trace) printf("bye"); exit(0); }

void Bcompile(BYTE byte) { *(BYTE*)&M[Cp] = byte; Cp += sizeof(BYTE); }
void Wcompile(WORD word) { *(WORD*)&M[Cp] = word; Cp += sizeof(WORD); }
void  compile(CELL cell) { *(CELL*)&M[Cp] = cell; Cp += sizeof(CELL); }

uint8_t op;

void VM(void) {
	for (;;) {
		op = M[Ip++];
		if (trace) printf("\n%.4X: %.2X ",Ip-1,op);
		switch (op) {
			case op_NOP: NOP(); break;
			case op_BYE: BYE(); break;
			default:
				fprintf(stderr,"\n\n%.4X: %.2X\n\n",Ip-1,op); exit(-1);
		}
	}
}
