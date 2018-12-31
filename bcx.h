/// @file
/// @brief embedded runtime (portable part)

/// @defgroup bcx embedded runtime (portable part)

#ifndef _H_BCX
#define _H_BCX

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/// @defgroup vm Virtual Machine
/// @{

/// @defgroup config Configuration
/// @{

#define CELL uint16_t

#define Msz	0x1000
#define Rsz 0x100
#define Dsz 0x10

/// @}

extern CELL M[Msz];		/// main memory
extern CELL Ip;			/// instruction pointer
extern CELL Cp;			/// compiler pointer

/// @}

/// @defgroup op Opcodes
/// @{

#define op_NOP	0x00
#define op_BYE	0xFF

/// @}

extern void BYE(void);		/// `BYE ( -- )` stop system

/// @defgroup debug Debug
/// @{

extern void DUMP(void);		/// dump main memory

/// @}

#endif // _H_BCX
