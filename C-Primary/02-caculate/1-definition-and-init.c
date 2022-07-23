#include <stdio.h>
int main()
{
  int a;
  int b = 0;
  printf("%d %d", a, b); // > unknown 0

  // 变量名区分大小写
  int asd = 0;
  int aSd = 6;
  printf("%d %d", asd, aSd);

  // 连续定义变量 仍然需要初始化
  int a, b = 100, c = 99;
  printf("%d %d %d", a, b, c); // > 1016 100 99
  return 0;
}