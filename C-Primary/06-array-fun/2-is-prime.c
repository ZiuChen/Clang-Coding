#include <stdio.h>
int isPrime(int i) {
  int rtn = 1;
  int k;
  for (k = 2; k < i - 1;k++) {
    if (i % k == 0) {
      rtn = 0;
      break;
    }
  }
  return rtn;
}

int main() {
  int number = 0;
  printf("请输入值: ");
  scanf("%d", &number);
  int flag = isPrime(number);
  printf("%d是素数吗? %d", number, flag);
  return 0;
}