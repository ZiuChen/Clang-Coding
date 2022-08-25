#include <stdio.h>

void swap(int* pa, int* pb);

int main() {
  int a = 0;
  int b = 1;
  printf("%d %d\n", a, b);
  swap(&a, &b);
  printf("%d %d\n", a, b);
  return 0;
}

void swap(int* pa, int* pb) {
  int tmp = *pa;
  *pa = *pb;
  *pb = tmp;
}