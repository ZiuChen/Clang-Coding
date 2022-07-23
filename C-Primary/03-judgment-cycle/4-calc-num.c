#include <stdio.h>
int main()
{
  int number = 0;
  int n = 0;
  scanf("%d", &number);
  n++;
  number /= 10;
  while (number > 0)
  {
    n++;
    number /= 10;
  }
  printf("%d", n);
  return 0;
}