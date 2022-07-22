#include <stdio.h>
int main()
{
  printf("请分别输入身高的英尺和英寸");

  double foot;
  double inch;

  scanf("%lf %lf", &foot, &inch);

  printf("身高是:%f米", ((foot + inch/12) * 0.3048)); // > 身高是:1.701800米
  return 0;
}