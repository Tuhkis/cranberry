#ifndef CASM_H
#define CASM_H

#include "cranberry.h"
#include "string.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <io.h>
#define F_OK 0
#define CASM_ACCESS _access
#else
#include "unistd.h"
#define CASM_ACCESS access
#endif

#define CASM_ARG(arg, indx) (strcmp(arg, argv[indx]) == 0)

#define CASM_FLAG_INPUT "-i"
#define CASM_FLAG_OUTPUT "-o"
#define CASM_FLAG_HELP "-h"

cr_Byte casm_asm2byte(char* text);
void casm_compileString(char* text, cr_Byte progData[CR_PROG_LEN]);
void casm_compileFile(char* inputPath, char* outputPath);

#endif /* CASM_H */
