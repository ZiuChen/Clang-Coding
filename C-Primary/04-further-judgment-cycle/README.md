# 04-进一步的判断与循环

## 逻辑类型和运算

### 逻辑类型

引入了`stdbool.h`头文件后，可以使用`bool`定义一个布尔类型。

但实际上布尔类型的值仍然是一个数。

```c
#include <stdbool.h>
bool b = 6>5;
bool t = true;
t = 2; // 能够通过编译
printf("%d\n", b); // > 1
```

### 逻辑运算

与或非：对逻辑量进行的运算，结果只有`0`或`1`。

`&&` `||` `!`

`!a` `a||b` `a&&b`

可以用逻辑运算简化判断：

```c
int flag1 = age > 20 && age <=30;
int flag2 = index < 0 || index > 99;
int flag3 = !(age < 20);
```

可以利用`&&`的短路机制简化代码：

```c
int flag = a==6 && b==7;
a==6 && b+=1;
```

### 条件运算和逗号运算

三目运算符，可以简化判断。

```c
count = (count > 20) ? count - 10 : count + 10;
```

## 多路分支

`switch-case`

```c
int type = 0;
switch (type)
{
case 0:
  printf("Good Morning!");
  break;
case 1:
  printf("Good Afternoon!");
  break;
case 2:
  printf("Good Night!");
  break;
default:
  break;
}
```
