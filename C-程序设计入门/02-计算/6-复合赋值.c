#include <stdio.h>
int main()
{
  int a = 0;
  int i = 5;
  // a = i++; // > 5
  a = ++i; // > 6
  printf("%d", a);
  return 0;
}