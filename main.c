#include "cranberry.c"

int main(int argc, char** argv) {
  cr_VM vm = {0};
  FILE* file = NULL;
  file = fopen(argv[1], "rb");
  fread(vm.prog, sizeof(vm.prog), 1, file);
  if (file == NULL) {
    printf("Could not read %s.\n", argv[1]);
	exit(1);
	return 1;
  }
  fclose(file);
  cr_run(&vm);
  exit(0);
  return 0;
}
