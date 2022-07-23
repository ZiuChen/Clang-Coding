#include <stdio.h>

void sum(int begin, int end);

int main() {
  sum(1, 10);
  sum(2, 5);
  sum(20, 30);
  return 0;
}

void sum(int begin, int end) {
  int i;
  int sum = 0;
  for (i = begin;i <= end;i++) {
    sum += i;
  }
  printf("sum: %d\n", sum);
}