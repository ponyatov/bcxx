/// @file
/// @brief embedded runtime (portable core) headers

/// @defgroup bcx embedded runtime (portable part)
/// @{

#ifndef _H_BCX
#define _H_BCX

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/// @defgroup vm Virtual Machine
/// @{
						/// @brief bytecode interpreter
extern void VM(void);
						/// @brief current command opcode
extern uint8_t op;

/// @defgroup config Configuration
/// @{

#define BYTE uint8_t
#define WORD uint16_t
#define CELL uint32_t

#define Msz	0x1000
#define Rsz 0x100
#define Dsz 0x10

/// @}

						/// @brief main memory
extern BYTE M[Msz];
						/// @brief instruction pointer
extern CELL Ip;
						/// @brief compiler pointer
extern CELL Cp;

/// @defgroup op Command opcodes
/// @{

						/// @ref NOP
#define op_NOP	0x00
						/// @ref BYE
#define op_BYE	0xFF

						/// @ref JMP
#define op_JMP	0x01
						/// @ref qJMP
#define op_qJMP	0x02
						/// @ref CALL
#define op_CALL	0x03
						/// @ref RET
#define op_RET	0x04
						/// @ref LIT
#define op_LIT	0x05

/// @}

/// @defgroup code Core commands
/// @{

/// `NOP ( -- )` do nothing
extern void NOP(void);

/// `BYE ( -- )` stop user session
extern void BYE(void);

/// `JMP ( -- )` unconditional jump
extern void JMP(void);

/// @}

/// @defgroup mem Memory access
/// @{

/// @brief `B! ( addr byte -- )` store byte to memory
extern void Bstore(WORD addr, BYTE byte);
/// @brief `W! ( addr word -- )` store 16-bit word to memory
extern void Wstore(WORD addr, WORD word);
/// @brief `! ( addr cell -- )` store 32-bit cell to memory
extern void  store(WORD addr, CELL cell);

/// @brief `B@ ( addr -- byte )` fetch byte
extern BYTE Bfetch(WORD addr);
/// @brief `W@ ( addr -- word )` fetch 16-bit word
extern WORD Wfetch(WORD addr);

/// @}

/// @defgroup compiler Compiler
/// @{

extern void Bcompile(BYTE byte);
extern void Wcompile(WORD word);
extern void  compile(CELL cell);

/// @}

/// @defgroup debug Debug interface
/// @{

/// `DUMP ( -- )` dump main memory
extern void DUMP(void);

/// trace flag: print execution log
extern bool trace;

/// @}

/// @}

/// @}

#endif // _H_BCX
