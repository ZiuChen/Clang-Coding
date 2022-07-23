#include <stdio.h>
int main() {
  int i;
  printf("0x%x\n", &i); // 0x61fe1c
  printf("%p\n", &i); // 0000 0000 0061 FE1C
  return 0;
}