#include "casm.h"

typedef unsigned char U8;
typedef signed   char I8;

typedef unsigned short U16;
typedef signed   short I16;

typedef unsigned int U32;
typedef signed   int I32;

U16 countLines(char* str) {
	U16 c = 0;
	while (str != '\0') {
		if (str == '\n') ++c;
		++str;
	}
	return c;
}

#define SPACE (' ')
cr_Byte casm_asm2byte(char* text) {
	return CR_EXIT;
}

void casm_compileString(char* text, cr_Byte progData[CR_PROG_LEN]) {
	for (U16 l = 0; l  countLines(text); ++l
}

void casm_compileFile(char* inputPath, char* outputPath) {
  cr_Byte progData[CR_PROG_LEN];
  for (U32 i = 0; i < CR_PROG_LEN; ++i) progData[i] = CR_EXIT;

  /* Parse the assembly into the progData buffer. */
  {
    FILE* input = NULL;
    input = fopen(inputPath, "r");
    if (input == NULL) {
      printf("Can\'t open input file.\n");
      exit(1);
    }
	/* char* asmText = fread */
    fclose(input);
  }
  /* Write the progData to the output file. */
  {
    FILE* output = NULL;
    output = fopen(outputPath, "wb");
    if (output == NULL) {
      printf("Can\'t open output file for writing.\n");
      exit(1);
    }
    fwrite(progData, sizeof(progData), 1, output);
    fclose(output);
  }
}

#ifdef CASM_EXE
I32 main(I32 argc, char** argv) {
  char inputFile[128];
  char outputFile[128];
  inputFile[0] = 0;
  outputFile[0] = 0;
  for (U8 argI = 1; argI < argc; ++argI) {
    if (CASM_ARG(CASM_FLAG_INPUT, argI)) {
      ++argI;
      strcpy(inputFile, argv[argI]);
    } else if (CASM_ARG(CASM_FLAG_OUTPUT, argI)) {
      ++argI;
      strcpy(outputFile, argv[argI]);
    } else if (CASM_ARG(CASM_FLAG_HELP, argI)) {
      printf(
"Cranberry-assembler\n-------------------"
"\n -i: input file"
"\n -o: output file"
"\n -h: show this help text\n");
      exit(0);
	  return 0;
    } else {
      printf("Unknown flag \"%s\".\n", argv[argI]);
      exit(1);
	  return 1;
    }
  }
  if (inputFile[0] == 0) {
    printf("No input file provided.\n");
    exit(1);
	return 1;
  }
  if (outputFile[0] == 0) {
    char* defaultFilepath = "casm_output.bin";
    strcpy(outputFile, defaultFilepath);
  }
  if (access(inputFile, F_OK) != 0) {
    printf("File %s does not exist, please choose a file that exists.\n", inputFile);
	exit(1);
	return 1;
  }
  casm_compileFile(inputFile, outputFile);
  exit(0);
  return 0;
}
#endif /* CASM_EXE */
