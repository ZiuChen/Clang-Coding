#include <stdio.h>
int main() {
  // char
  char ac[] = { 0,1,2,3,4,5,6,7,8,9 };
  char* p = ac;
  printf("%p\n", p); // 000000000061FE06
  printf("%p\n", p + 1); // 000000000061FE07
  printf("%d\n", *(p + 1)); // 1

  // int
  char ai[] = { 0,1,2,3,4,5,6,7,8,9 };
  char* q = ai;
  printf("%p\n", q); // 000000000061FDFC
  printf("%p\n", q + 1); // 000000000061FDFD
  printf("%d\n", *(q + 1)); // 1
  return 0;
}