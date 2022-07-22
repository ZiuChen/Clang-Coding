#include <stdio.h>
int main()
{
  int x, tmp;
  int result = 0;
  printf("input:");
  scanf("%d", &x);
  tmp = x;
  while (x > 1)
  {
    x /= 2;
    result++;
  }
  printf("log2 of %d is %d", tmp, result);
  return 0;
}