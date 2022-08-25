#include <stdio.h>

int divide(int a, int b, int* result);

int main() {
  int a = 99;
  int b = 3;
  int result = 0;
  if (divide(a, b, &result)) {
    printf("%d", result);
  }
  return 0;
}

int divide(int a, int b, int* result) {
  int ret = 1;
  if (b == 0) ret = 0;
  else {
    *result = a / b;
  }
  return ret;
}