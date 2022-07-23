#include <stdio.h>
int main()
{
  int n;
  int result = 1;
  scanf("%d", &n);
  int i;
  for (i = 1; i <= n; i++)
  {
    result *= i;
  }
  printf("result: %d", result);
  return 0;
}