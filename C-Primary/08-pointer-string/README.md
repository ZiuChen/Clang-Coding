# 指针与字符串

## 从scanf认识取地址运算&

在之前的scanf函数中，我们要用变量接收用户输入值时，必须在变量前加一个`&`。

这个`&`的作用就是，取到变量的地址，它的操作数必须是一个变量。

```c
#include <stdio.h>
int main() {
  int i;
  printf("0x%x\n", &i); // 0x61fe1c
  printf("%p\n", &i); // 0000 0000 0061 FE1C
  return 0;
}
```

> printf中的%p指定输出格式为地址

这里的`0x61fe1c`就是变量`i`在内存中的地址。

### 相邻变量的地址

下述代码的输出可以看出：定义的相邻变量，其在内存中的地址也相邻。

`FE1C - FE18 = 4`，恰为一个int的大小。

```c
#include <stdio.h>
int main() {
  int i;
  int j;
  printf("%p\n", &i); // 0000 0000 0061 FE1C
  printf("%p\n", &j); // 0000 0000 0061 FE18
  return 0;
}
```

## 指针

指针是一个用于保存地址的变量。

```c
int i; // common variable
int* p = &i; // p: pointer
int* p, q; // p, q: common variable
int *p, q; // same
```

### 用指针操作变量

指针作为函数参数时，这意味着函数可以拿到外部变量的地址，从而直接操作这个变量的值。

用指针重写swap函数：

```c
// new-swap.c
#include <stdio.h>

void swap(int* a, int* b);

int main() {
  int a = 0;
  int b = 1;
  printf("a: %d b: %d\n", a, b);
  swap(&a, &b);
  printf("a: %d b: %d\n", a, b);
  return 0;
}

void swap(int* a, int* b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
```

可以从输出看到，a和b的值能够被正确交换了。

### 传入函数的数组

在前面的例子中，我们尝试给search函数传入数组，并在search函数中计算数组的长度。

然而在search函数中对数组使用sizeof时却报错了，这是因为传入函数的数组被转为了指针，
这种指针能够用操作数组的方式来操作。

```c
int sum(int *ar, int n);
int sum(int *, int);
int sum(int arr[], int n);
int sum(int [], int);
```

这四种函数原型是等价的。

* **数组变量是特殊的指针**，数组变量本身表达地址，所以 `int a[10]; int *p=a;` 其中的p就是数组a的地址。
* 对数组中的元素取地址时，必须用`&`。
* 数组a的地址就是第一个元素的地址：`a == &a[0]`
* []运算符，可以对数组做，也可以对指针做
  * `p[0] === a[0]`
* 数组变量是一个const指针，也就是我们无法通过赋值方式改变数组的值
  * `int b[]; === int * const b;`

## 字符类型

用单引号`'`表示字符字面量，如：`'a'` `'1'`

* `''`也是一个字符
* 在printf和scanf中用`%c`做字符的输入输出


每个字符在C中都有一个ASCII码对应，例如`'A'`对应的ASCII码为65。

```c
// char-demo.c
#include <stdio.h>
int main() {
  char a = '1';
  char b = 1;
  if (a == b) printf("相等");

  char c = 'A'; // > 65
  printf("%c\n", c);
  printf("%d\n", c);

  int d;
  printf("请输入d: \n");
  scanf("%d", &d);
  printf("%c", d);
  return 0;
}
```

### 逃逸字符

用反斜杠`\`实现字符的转义。

## 字符串

在C语言中，字符串指的是以0结尾的一串字符：

```c
char word[] = { 'H', 'e', 'l', 'l', 'o', '!' }; // 字符数组
char word[] = { 'H', 'e', 'l', 'l', 'o', '!', '\0' }; // 字符串
char word[] = { 'H', 'e', 'l', 'l', 'o', '!', 0 }; // 字符串
char word = "Hello!"; // 字符串
```

* 0与'\0'含义是相同的
* 0标志着字符串的结束，但不是字符串的一部分
  * 计算字符串长度时，不包含这个0
* 字符串以数组形式存在，以数组或指针形式访问
  * 大多数情况下，以数组或指针形式访问
* `string.h`中有很多处理字符串的函数

### 定义字符串变量

下述代码都可以定义一个字符串变量：

```c
char* str = "Hello!";
char word[] = "Hello!";
char line[10] = "Hello!";
```

注意，使用的是双引号`""`。

在C语言中，如果两个相邻字符串没有任何连接，它会帮你把它们连接起来。

```c
char str = "Hello" ", World!";
```

### 指针还是数组？

在定义字符串时，我们可以选择指针定义/数组定义。

* 用数组定义：这个字符串就在这里
  * 作为本地变量，它占用的空间会被自动回收
* 用指针定义：你不知道这个字符串存放在哪，“我”指向了字符串所在的地址
  * 只读字符串
  * 用指针表达函数参数
  * 动态分配空间

**如果要构造一个字符串：数组。 如果要处理一个字符串：指针**

> char*是字符串？

`char*`不一定是字符串：这里有一个指针，指针指向了字节类型的变量（一串连续的字节）
只有当`char*`所指的地方结尾有0，此时我们才能说此`char*`为字符串

## 字符串计算

C语言诞生时，计算机多用于进行数值计算，而现代计算机多处理字符，故而C语言针对字符串并没有那么“重视”。

### 字符串输入输出

当我们输入`Hello World`时，会发现`Hello`与`World`被分别分配到了string1与string2两个变量中。

```c
#include <stdio.h>
int main() {
  char string1[8];
  char string2[8];
  scanf("%s", &string1);
  scanf("%s", &string2);
  printf("%s --- %s", string1, string2);
  return 0;
}
```

这个scanf函数是不安全的，因为当我们输入超过8个字符时，前面的字符都将被舍弃，只保留第9个及以后的：

> `input: 1234657890` `output: 90`，这和变量在内存中存储的顺序有关。
> 
> scanf函数读到空格/Tab/回车为止。

这时我们可以用`%7s`来限制输入字符的个数，<=7个字符的值都能够被成功接收，超过7的部分直接舍弃。

#### 常见错误

* `char *string;`
* scanf("%s", &string); 没有对字符串输入做限制
* 以为char*是字符串类型，定义了一个字符串类型的变量string就可以直接使用了
  * 由于没有对string初始化为0，所以不一定每次运行都出错

#### 空字符串

```c
char buffer[100] = ""; // 这是一个空的字符串，buffer[0] === '\0'

char buffer[] = ""; // 这个数组的长度只有1
```

### 字符串函数

`strlen()` 返回s字符串的长度（不包括结尾的0）

```c
#include <stdio.h>
#include <string.h>
int main() {
  char line[] = "Hello";
  int length = strlen(line); // 返回s字符串的长度（不包括结尾的0）
  printf("%d", length); // > 5
  return 0;
}
```

`strcmp()` 比较两个字符串，函数返回值：

* `s1 === s2` => 0
* `s1 > s2` => 1
* `s1 < s2` => -1

注意，当我们用`s1 == s2`表达式比较字符串时，指的是两个字符串的地址是否相同，实际上这个值永远都是false。要比较字符串，则应当使用`strcmp()`函数

```c
#include <stdio.h>
#include <string.h>
int main() {
  char s1[] = "abc";
  char s2[] = "abc";
  printf("%d\n", s1 == s2); // > 0 false 不相同
  printf("%d\n", strcmp(s1, s2)); // > 0 相同
  return 0;
}
```