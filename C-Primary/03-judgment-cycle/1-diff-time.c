#include <stdio.h>
int main()
{
  int h1, m1;
  int h2, m2;

  printf("������ʱ���:\n");
  scanf("%d %d", &h1, &m1);
  scanf("%d %d", &h2, &m2);

  int ih = h1 - h2;
  int im = m1 - m2;

  if (im < 0)
  {
    // �����˽�λ
    ih--;
    im += 60;
  }

  printf("%dh %dmin", ih, im);

  return 0;
}