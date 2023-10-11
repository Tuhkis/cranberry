#ifndef CRANBERRY_H
#define CRANBERRY_H

#include "stdio.h"
#include "stdlib.h"

#define CR_PROG_LEN (1024 * 4)

#ifndef CR_INSTRUCTIONS
#define CR_INSTRUCTIONS
#endif /* CR_INSTRUCTIONS */

typedef unsigned char cr_Byte;

typedef enum cr_instruction {
  CR_EMPTY = 0,
  CR_MOV0,
  CR_MOV1,
  CR_MOV2,
  CR_MOV3,

  CR_PUT_CHAR,
  CR_EXIT,

  CR_SET0,
  CR_SET1,
  CR_SET2,
  CR_SET3,

  CR_ADD,
  CR_SUB,
  CR_MUL,
  CR_DIV,
  CR_INSTRUCTIONS
} cr_Instruction;

typedef struct {
  cr_Byte prog[CR_PROG_LEN];
  unsigned int ptr0;
  unsigned int ptr1;
  unsigned int ptr2;
  unsigned int ptr3;
} cr_VM;

void cr_continue(cr_VM *vm);
void cr_run(cr_VM *vm);

#endif /* CRANBERRY_H */
