#include <stdio.h>
int main()
{
  int h1, m1;
  int h2, m2;

  printf("请输入时间差:\n");
  scanf("%d %d", &h1, &m1);
  scanf("%d %d", &h2, &m2);

  int ih = h1 - h2;
  int im = m1 - m2;

  if (im < 0)
  {
    // 出现了借位
    ih--;
    im += 60;
  }

  printf("%dh %dmin", ih, im);

  return 0;
}