#include "cranberry.h"

#ifndef CR_INTERP
#define CR_INTERP(b)
#endif /* CR_INTERP */

void cr_continue(cr_VM *vm) {
  cr_Byte b = vm->prog[vm->ptr0];
  switch (b) {
  case CR_PUT_CHAR:
    putchar((char)vm->prog[vm->ptr1]);
    break;
  case CR_MOV0:
    vm->ptr0 = vm->ptr1;
    break;
  case CR_MOV1:
    vm->ptr1 = vm->ptr2;
    break;
  case CR_MOV2:
    vm->ptr2 = vm->ptr1;
    break;
  case CR_MOV3:
    vm->ptr3 = vm->ptr1;
    break;
  case CR_EXIT:
    exit((int)vm->prog[vm->ptr1]);
    break;
  case CR_SET0:
    vm->ptr0 = vm->prog[vm->ptr0 + 1];
    ++vm->ptr0;
    break;
  case CR_SET1:
    vm->ptr1 = vm->prog[vm->ptr0 + 1];
    ++vm->ptr0;
    break;
  case CR_SET2:
    vm->ptr2 = vm->prog[vm->ptr0 + 1];
    ++vm->ptr0;
    break;
  case CR_SET3:
    vm->ptr3 = vm->prog[vm->ptr0 + 1];
    ++vm->ptr0;
    break;
  default:
    CR_INTERP(b);
    break;
  }
  ++vm->ptr0;
}

void cr_run(cr_VM *vm) {
  for (unsigned int i = 0; i < CR_PROG_LEN; ++i) {
    cr_continue(vm);
  }
  return;
}
