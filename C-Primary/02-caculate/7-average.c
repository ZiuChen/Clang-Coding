#include <stdio.h>
int main()
{
  printf("��ֱ�������ߵ�Ӣ�ߺ�Ӣ��");

  double foot;
  double inch;

  scanf("%lf %lf", &foot, &inch);

  printf("�����:%f��", ((foot + inch/12) * 0.3048)); // > �����:1.701800��
  return 0;
}