# 指针与字符串

## 指针的使用

### 指针应用场景

#### 两数交换

将两个数的指针传递给`swap`函数，在`swap`函数中通过指针访问实际的变量，从而交换二者的值。

```c
// 1-pointer-usage.c
#include <stdio.h>

void swap(int* pa, int* pb);

int main() {
  int a = 0;
  int b = 1;
  printf("%d %d\n", a, b);
  swap(&a, &b);
  printf("%d %d\n", a, b);
  return 0;
}

void swap(int* pa, int* pb) {
  int tmp = *pa;
  *pa = *pb;
  *pb = tmp;
}
```

#### 取数组的最大最小值

```c
// 2-pointer-usage.c
#include <stdio.h>

// a[] => *a 也可以
void minmax(int a[], int length, int* min, int* max);

int main() {
  int a[] = { 1,2,3,4,5,6,7,8,9,10 };
  int min, max;
  minmax(a, sizeof(a) / sizeof(a[0]), &min, &max);
  printf("%d %d\n", min, max);
  return 0;
}

// min与max在`minmax`函数中计算, 在`main`函数中接收
void minmax(int a[], int length, int* min, int* max) {
  int i;
  *min = *max = a[0];
  for (i = 1; i < length; i++) {
    if (a[i] < *min) {
      *min = a[i];
    }
    if (a[i] > *max) {
      *max = a[i];
    }
  }
}
```

* 函数返回运算的状态，结果通过指针返回
* 当函数正常执行时，函数返回1，其余状态返回0或-1

```c
// 3-pointer-usage.c
#include <stdio.h>

int divide(int a, int b, int* result);

int main() {
  int a = 99;
  int b = 3;
  int result = 0;
  if (divide(a, b, &result)) {
    printf("%d", result);
  }
  return 0;
}

int divide(int a, int b, int* result) {
  int ret = 1;
  if (b == 0) ret = 0;
  else {
    *result = a / b;
  }
  return ret;
}
```

### 传入函数的数组

当我们为函数传入了一个数组，这个数组会被转化为指针

考虑以下函数：

```c
// 4-array-pass-in-func
#include <stdio.h>

void max(int a[], int length, int* result);

int main() {
  int a[] = { 1,2,3,4,5 };
  int length = sizeof(a) / sizeof(a[0]);
  int result;
  max(a, length, &result);
  printf("%d\n", result);
  return 0;
}

void max(int a[], int length, int* result) {
  int i;
  *result = a[0];
  for (i = 1; i < length; i++) {
    if (a[i] > *result) {
      *result = a[i];
    }
  }
}
```

当我们在函数体内对数组使用`sizeof`，编译器会报错：

> warning: 'sizeof' on array function parameter 'a' will return size of 'int *'

此报错说明：`sizeof(a) == size(int *)`得到的并不是数组占用的大小


在函数体内，我们可以通过操作数组的方式操作这个指针


## 指针的运算

```c
#include <stdio.h>
int main() {
  // char
  char ac[] = { 0,1,2,3,4,5,6,7,8,9 };
  char* p = ac;
  printf("%p\n", p); // 000000000061FE06
  printf("%p\n", p + 1); // 000000000061FE07
  printf("%d\n", *(p + 1)); // 1

  // int
  char ai[] = { 0,1,2,3,4,5,6,7,8,9 };
  char* q = ai;
  printf("%p\n", q); // 000000000061FDFC
  printf("%p\n", q + 1); // 000000000061FDFD
  printf("%d\n", *(q + 1)); // 1
  return 0;
}
```

在此程序中，我们对指向数组的指针进行+1操作：

- 指向`char[]`的指针+1时，地址改变了`1`
- 指向`int[]`的指针+1时，地址改变了`4`

这是因为sizeof(char) = 1，而sizeof(int) = 4

**为指针+1时，指针将直接指向下一个单元的地址，而不是真的+1**

同时，我们可以看到，取`*(p+1)`的值时，实际上取到的就是数组中相对于第一个元素偏移1个单元的元素，也就是`ac[1]`

**如果数组不是指向一片连续分配的空间，如数组，则这种运算没有意义**

## 字符串操作

- int putchar(int c)
- 向标准输出写一个字符
- 返回：写了几个字符，EOF(-1) 表示写失败

```c
// 6-string-operate.c
#include <stdio.h>
int main() {
  int ch;
  while ((ch = getchar()) != EOF) {
    putchar(ch);
  }
  printf("EOF\n");
  return 0;
}
```

程序将不断读取你的输入并将其输出到控制台，什么时候得到了`EOF`，什么时候结束。

- 在win上`EOF`代表`Ctrl+C`
- 在Linux上代表`Ctrl+D`


