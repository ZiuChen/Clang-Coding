#include <stdio.h>
int main()
{
  const int AMOUNT = 100;
  int price = 0;
  printf("ÇëÊäÈë½ğ¶î:");
  scanf("%d", &price);
  int change = AMOUNT - price;
  printf("ÕÒÄú%dÔª", change);
  return 0;
}