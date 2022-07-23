#include <stdio.h>
int main() {
  int i;
  int j;
  printf("%p\n", &i); // 0000 0000 0061 FE1C
  printf("%p\n", &j); // 0000 0000 0061 FE18
  return 0;
}