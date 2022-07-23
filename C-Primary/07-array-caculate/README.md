# 07-数组运算

## 数组运算

### 数组的集成初始化

C99定义数组方式：针对稀疏数组，可以简化你的代码。

```c
int a[] = {2,3,4,5,6,7,8,9}; // > 2 3 4 5 6 7 8 9
int b[10] = {2,3,4}; // > 2 3 4 0 0 0 0 0 0 0
int c[10] = {[1]=2, [5]=7}; // > 0 2 0 0 0 7 0 0 0 0
```

获取数组的长度：

```c
int length = sizeof(a) / sizeof(a[0]);
```

```c
// search.c
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
```