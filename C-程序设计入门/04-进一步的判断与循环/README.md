# 04-��һ�����ж���ѭ��

## �߼����ͺ�����

### �߼�����

������`stdbool.h`ͷ�ļ��󣬿���ʹ��`bool`����һ���������͡�

��ʵ���ϲ������͵�ֵ��Ȼ��һ������

```c
#include <stdbool.h>
bool b = 6>5;
bool t = true;
t = 2; // �ܹ�ͨ������
printf("%d\n", b); // > 1
```

### �߼�����

���ǣ����߼������е����㣬���ֻ��`0`��`1`��

`&&` `||` `!`

`!a` `a||b` `a&&b`

�������߼�������жϣ�

```c
int flag1 = age > 20 && age <=30;
int flag2 = index < 0 || index > 99;
int flag3 = !(age < 20);
```

��������`&&`�Ķ�·���Ƽ򻯴��룺

```c
int flag = a==6 && b==7;
a==6 && b+=1;
```

### ��������Ͷ�������

��Ŀ����������Լ��жϡ�

```c
count = (count > 20) ? count - 10 : count + 10;
```

## ��·��֧

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
