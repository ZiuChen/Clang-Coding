#include <stdio.h>
int main()
{
  int type = 0;
  switch (type)
  {
  case 0:
    printf("Good Morning!");
    break;
  case 1:
    printf("Good Afternoon!");
    break;
  case 2:
    printf("Good Night!");
    break;
  default:
    break;
  }
  return 0;
}