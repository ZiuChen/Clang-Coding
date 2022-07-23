#include <stdio.h>
int search(int array[], int item, int length);
int main() {
  int array[10] = { 9,8,7,3,2,1,4,5,6,0 };
  int target = 8;
  // 不能将length放进search中计算 原因是将数组作为参数传递时 其会退化为指针
  // 要在main中计算好length再传递进去
  int length = sizeof(array) / sizeof(array[0]);
  int index = search(array, target, length);
  printf("元素%d在第%d个位置上", target, index);
  return 0;
}

int search(int array[], int item, int length) {
  int i;
  for (i = 0; i < length;i++) {
    if (array[i] == item) {
      return i + 1;
    } else {
      continue;
    }
  }
  return -1;
}