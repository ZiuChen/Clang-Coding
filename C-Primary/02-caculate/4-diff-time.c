#include <stdio.h>
int main()
{
  int h1, m1;
  int h2, m2;

  printf("«Î ‰»Î ±º‰≤Ó:\n");
  scanf("%d %d", &h1, &m1);
  scanf("%d %d", &h2, &m2);

  int t1 = h1*60 + m1;
  int t2 = h2*60 + m2;
  int t = t1 - t2;

  printf("%dh %dmin", t/60, t%60);

  return 0;
}