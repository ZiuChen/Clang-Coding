#include <stdio.h>
int main()
{
  int price = 0;
  printf("��������:");
  scanf("%d", &price);
  int change = 100 - price;
  printf("����%dԪ", change);
  return 0;
}