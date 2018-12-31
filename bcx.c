/// @file
/// @brief embedded runtime (portable core) ANSI C'89 code

#include "bcx.h"

BYTE M[Msz];

CELL Ip =0;

CELL Cp	=0;

bool trace	=true;

void DUMP(void) {
	fprintf(stderr,"\n\n");
	for (CELL addr=0;addr<Cp;addr++) {
		if (addr % 0x10 == 0) printf("\n%.4X: ",addr);		// start addr: line
		fprintf(stderr,"%.2X ",M[addr]);					// every byte
	}
	fprintf(stderr,"\n");
}

void NOP(void)	{ if (trace) printf("nop"); }
void BYE(void)	{ if (trace) printf("bye"); exit(0); }

void JMP(void)	{ Ip = Wfetch(Ip); if (trace) printf("jmp %.4X",Ip); }

void Bstore(WORD addr, BYTE byte) { *(BYTE*)&M[addr] = byte; }
void Wstore(WORD addr, WORD word) { *(WORD*)&M[addr] = word; }
void  store(WORD addr, CELL cell) { *(CELL*)&M[addr] = cell; }

BYTE Bfetch(WORD addr) { return *(BYTE*)&M[addr]; }
WORD Wfetch(WORD addr) { return *(WORD*)&M[addr]; }


void Bcompile(BYTE byte) { Bstore(Cp,byte); Cp += sizeof(BYTE); }
void Wcompile(WORD word) { Wstore(Cp,word); Cp += sizeof(WORD); }
void  compile(CELL cell) {  store(Cp,cell); Cp += sizeof(CELL); }

uint8_t op;

void VM(void) {
	for (;;) {
		op = M[Ip++];
		if (trace) printf("\n%.4X: %.2X ",Ip-1,op);
		switch (op) {
			case op_NOP: NOP(); break;
			case op_BYE: BYE(); break;
			case op_JMP: JMP(); break;
			default:
				fprintf(stderr,"\n\n%.4X: %.2X\n\n",Ip-1,op); exit(-1);
		}
	}
}
