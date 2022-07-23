# 06-�����뺯��

## ����

����һ�����飺

```c
int array[100];
double array[100];
```

�˴���`int`��`double`ָ����ÿ������Ԫ�ص����͡�

����ƽ������

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
  printf("������ֵ: ");
  scanf("%d", &number);
  int flag = isPrime(number);
  printf("%d��������? %d", number, flag);
  return 0;
}
```

## �����Ķ�����ʹ��

### �����Ķ���

���庯��ʱ��������֮ǰ��int��ʾ�ú������ص���int���͵�ֵ�����һ�������������κ�ֵ��������`void`��ͷ��

ͬ���ģ����������Ҳ��Ҫָ�����ǵ����͡�

### ������ʹ��

#### ��������

�������Զ����½�����Ĵ��룬Ҳ����ԭ���ϣ�**�����Ķ���Ҫ�ŵ������ĵ���֮ǰ**������һ����Դ�ļ�����һ�ۿ�����Ӧ����������������������ǿ����ڶ������к���ԭ�͵�������

```c
void sum(int a, int b);
```

�ڶ��庯��ԭ�͵�����ʱ�����ǲ��ض����뺯������ʱ��ͬ���Ƶ���Σ���Ϊ������ֻ������������ͣ�����������������ơ�

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

#### �������ر���

�������Ǳ�дһ��`swap`�������˺�����ʵ����ֵ������

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

����������ǿ��Կ�����a��b��ֵ��δʵ�ֽ�����������Ϊ�������ݲ���ʱ�������ǰ�ֵ�����˹�ȥ��

��swap�����ڲ�Ҳ���Լ�ά����һ�������ռ䣬��������ռ���main�����еı����ռ����໥�����ģ�����swap�����ж�ֵ�ı任������Ӱ��main������ֵ�ı任��
