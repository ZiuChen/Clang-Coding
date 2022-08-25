# ָ�����ַ���

## ָ���ʹ��

### ָ��Ӧ�ó���

#### ��������

����������ָ�봫�ݸ�`swap`��������`swap`������ͨ��ָ�����ʵ�ʵı������Ӷ��������ߵ�ֵ��

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

#### ȡ����������Сֵ

```c
// 2-pointer-usage.c
#include <stdio.h>

// a[] => *a Ҳ����
void minmax(int a[], int length, int* min, int* max);

int main() {
  int a[] = { 1,2,3,4,5,6,7,8,9,10 };
  int min, max;
  minmax(a, sizeof(a) / sizeof(a[0]), &min, &max);
  printf("%d %d\n", min, max);
  return 0;
}

// min��max��`minmax`�����м���, ��`main`�����н���
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

* �������������״̬�����ͨ��ָ�뷵��
* ����������ִ��ʱ����������1������״̬����0��-1

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

### ���뺯��������

������Ϊ����������һ�����飬�������ᱻת��Ϊָ��

�������º�����

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

�������ں������ڶ�����ʹ��`sizeof`���������ᱨ��

> warning: 'sizeof' on array function parameter 'a' will return size of 'int *'

�˱���˵����`sizeof(a) == size(int *)`�õ��Ĳ���������ռ�õĴ�С


�ں������ڣ����ǿ���ͨ����������ķ�ʽ�������ָ��


## ָ�������

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

�ڴ˳����У����Ƕ�ָ�������ָ�����+1������

- ָ��`char[]`��ָ��+1ʱ����ַ�ı���`1`
- ָ��`int[]`��ָ��+1ʱ����ַ�ı���`4`

������Ϊsizeof(char) = 1����sizeof(int) = 4

**Ϊָ��+1ʱ��ָ�뽫ֱ��ָ����һ����Ԫ�ĵ�ַ�����������+1**

ͬʱ�����ǿ��Կ�����ȡ`*(p+1)`��ֵʱ��ʵ����ȡ���ľ�������������ڵ�һ��Ԫ��ƫ��1����Ԫ��Ԫ�أ�Ҳ����`ac[1]`

**������鲻��ָ��һƬ��������Ŀռ䣬�����飬����������û������**

## �ַ�������

- int putchar(int c)
- ���׼���дһ���ַ�
- ���أ�д�˼����ַ���EOF(-1) ��ʾдʧ��

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

���򽫲��϶�ȡ������벢�������������̨��ʲôʱ��õ���`EOF`��ʲôʱ�������

- ��win��`EOF`����`Ctrl+C`
- ��Linux�ϴ���`Ctrl+D`


