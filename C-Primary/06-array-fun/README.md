# 06-数组与函数

## 数组

定义一个数组：

```c
int array[100];
double array[100];
```

此处的`int`与`double`指的是每个数组元素的类型。

计算平均数：

```c
#include <stdio.h>
int isPrime(int i) {
  int rtn = 1;
  int k;
  for (k = 2; k < i - 1;k++) {
    if (i % k == 0) {
      rtn = 0;
      break;
    }
  }
  return rtn;
}

int main() {
  int number = 0;
  printf("请输入值: ");
  scanf("%d", &number);
  int flag = isPrime(number);
  printf("%d是素数吗? %d", number, flag);
  return 0;
}
```

## 函数的定义与使用

### 函数的定义

定义函数时，函数名之前的int表示该函数返回的是int类型的值，如果一个函数不返回任何值，可以以`void`开头。

同样的，函数的入参也需要指定他们的类型。

### 函数的使用

#### 函数声明

编译器自顶向下解析你的代码，也就是原则上，**函数的定义要放到函数的调用之前**。但是一进入源文件，第一眼看到的应该是你的主函数，这样我们可以在顶部进行函数原型的声明。

```c
void sum(int a, int b);
```

在定义函数原型的声明时，我们不必定义与函数定义时相同名称的入参，因为编译器只会检查参数的类型，而不会检查参数的名称。

```c
#include <stdio.h>

void sum(int a, int b);

int main() {
  sum(1, 10);
  sum(2, 5);
  sum(20, 30);
  return 0;
}

void sum(int begin, int end) {
  int i;
  int sum = 0;
  for (i = begin;i <= end;i++) {
    sum += i;
  }
  printf("sum: %d\n", sum);
}
```

#### 函数本地变量

假设我们编写一个`swap`函数，此函数能实现两值交换：

```c
#include <stdio.h>

void swap(int a, int b);

int main() {
  int a = 0;
  int b = 1;
  printf("a: %d b: %d\n", a, b);
  swap(a, b);
  printf("a: %d b: %d\n", a, b);
  return 0;
}

void swap(int a, int b) {
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
}
```

根据输出我们可以看到，a与b的值并未实现交换，这是因为函数传递参数时，仅仅是把值传递了过去。

在swap函数内部也有自己维护的一个变量空间，这个变量空间与main函数中的变量空间是相互独立的，故在swap函数中对值的变换并不会影响main函数中值的变换。
