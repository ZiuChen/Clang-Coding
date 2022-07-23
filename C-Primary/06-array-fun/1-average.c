#include <stdio.h>
int main() {
  double sum = 0;
  int x = 0;
  int count = 0;
  int array[100];
  int i = 0;
  printf("请输入个数: ");
  scanf("%d", &x);
  count = x;
  for (i = 0; i < count; i++) {
    int tmp = 0;
    printf("请输入第%d个数: ", i + 1);
    scanf("%d", &tmp);
    array[i] = tmp;
  }
  for (i = 0; i < count; i++) {
    sum += array[i];
  }
  double average = sum / count;
  printf("平均数为: %lf", average);
  return 0;
}