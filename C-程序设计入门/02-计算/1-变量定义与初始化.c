#include <stdio.h>
int main()
{
  int a;
  int b = 0;
  printf("%d %d", a, b); // > unknown 0

  // ���������ִ�Сд
  int asd = 0;
  int aSd = 6;
  printf("%d %d", asd, aSd);

  // ����������� ��Ȼ��Ҫ��ʼ��
  int a, b = 100, c = 99;
  printf("%d %d %d", a, b, c); // > 1016 100 99
  return 0;
}