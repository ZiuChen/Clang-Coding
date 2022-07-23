#include <stdio.h>
int main()
{
  int a = 5;
  int b = 6;
  int t = 0;
  t = a; // a=5 b=6 t=5
  a = b; // a=6 b=6 t=5
  b = t; // a=6 b=5 t=5
  return 0;
}