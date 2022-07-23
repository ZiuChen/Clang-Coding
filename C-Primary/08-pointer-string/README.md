# ָ�����ַ���

## ��scanf��ʶȡ��ַ����&

��֮ǰ��scanf�����У�����Ҫ�ñ��������û�����ֵʱ�������ڱ���ǰ��һ��`&`��

���`&`�����þ��ǣ�ȡ�������ĵ�ַ�����Ĳ�����������һ��������

```c
#include <stdio.h>
int main() {
  int i;
  printf("0x%x\n", &i); // 0x61fe1c
  printf("%p\n", &i); // 0000 0000 0061 FE1C
  return 0;
}
```

> printf�е�%pָ�������ʽΪ��ַ

�����`0x61fe1c`���Ǳ���`i`���ڴ��еĵ�ַ��

### ���ڱ����ĵ�ַ

���������������Կ�������������ڱ����������ڴ��еĵ�ַҲ���ڡ�

`FE1C - FE18 = 4`��ǡΪһ��int�Ĵ�С��

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

## ָ��

ָ����һ�����ڱ����ַ�ı�����

```c
int i; // common variable
int* p = &i; // p: pointer
int* p, q; // p, q: common variable
int *p, q; // same
```

### ��ָ���������

ָ����Ϊ��������ʱ������ζ�ź��������õ��ⲿ�����ĵ�ַ���Ӷ�ֱ�Ӳ������������ֵ��

��ָ����дswap������

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

���Դ����������a��b��ֵ�ܹ�����ȷ�����ˡ�

### ���뺯��������

��ǰ��������У����ǳ��Ը�search�����������飬����search�����м�������ĳ��ȡ�

Ȼ����search�����ж�����ʹ��sizeofʱȴ�����ˣ�������Ϊ���뺯�������鱻תΪ��ָ�룬
����ָ���ܹ��ò�������ķ�ʽ��������

```c
int sum(int *ar, int n);
int sum(int *, int);
int sum(int arr[], int n);
int sum(int [], int);
```

�����ֺ���ԭ���ǵȼ۵ġ�

* **��������������ָ��**������������������ַ������ `int a[10]; int *p=a;` ���е�p��������a�ĵ�ַ��
* �������е�Ԫ��ȡ��ַʱ��������`&`��
* ����a�ĵ�ַ���ǵ�һ��Ԫ�صĵ�ַ��`a == &a[0]`
* []����������Զ���������Ҳ���Զ�ָ����
  * `p[0] === a[0]`
* ���������һ��constָ�룬Ҳ���������޷�ͨ����ֵ��ʽ�ı������ֵ
  * `int b[]; === int * const b;`

## �ַ�����

�õ�����`'`��ʾ�ַ����������磺`'a'` `'1'`

* `''`Ҳ��һ���ַ�
* ��printf��scanf����`%c`���ַ����������


ÿ���ַ���C�ж���һ��ASCII���Ӧ������`'A'`��Ӧ��ASCII��Ϊ65��

```c
// char-demo.c
#include <stdio.h>
int main() {
  char a = '1';
  char b = 1;
  if (a == b) printf("���");

  char c = 'A'; // > 65
  printf("%c\n", c);
  printf("%d\n", c);

  int d;
  printf("������d: \n");
  scanf("%d", &d);
  printf("%c", d);
  return 0;
}
```

### �����ַ�

�÷�б��`\`ʵ���ַ���ת�塣

## �ַ���

��C�����У��ַ���ָ������0��β��һ���ַ���

```c
char word[] = { 'H', 'e', 'l', 'l', 'o', '!' }; // �ַ�����
char word[] = { 'H', 'e', 'l', 'l', 'o', '!', '\0' }; // �ַ���
char word[] = { 'H', 'e', 'l', 'l', 'o', '!', 0 }; // �ַ���
char word = "Hello!"; // �ַ���
```

* 0��'\0'��������ͬ��
* 0��־���ַ����Ľ������������ַ�����һ����
  * �����ַ�������ʱ�����������0
* �ַ�����������ʽ���ڣ��������ָ����ʽ����
  * ���������£��������ָ����ʽ����
* `string.h`���кܶദ���ַ����ĺ���

### �����ַ�������

�������붼���Զ���һ���ַ���������

```c
char* str = "Hello!";
char word[] = "Hello!";
char line[10] = "Hello!";
```

ע�⣬ʹ�õ���˫����`""`��

��C�����У�������������ַ���û���κ����ӣ�����������������������

```c
char str = "Hello" ", World!";
```

### ָ�뻹�����飿

�ڶ����ַ���ʱ�����ǿ���ѡ��ָ�붨��/���鶨�塣

* �����鶨�壺����ַ�����������
  * ��Ϊ���ر�������ռ�õĿռ�ᱻ�Զ�����
* ��ָ�붨�壺�㲻֪������ַ���������ģ����ҡ�ָ�����ַ������ڵĵ�ַ
  * ֻ���ַ���
  * ��ָ����ﺯ������
  * ��̬����ռ�

**���Ҫ����һ���ַ��������顣 ���Ҫ����һ���ַ�����ָ��**

> char*���ַ�����

`char*`��һ�����ַ�����������һ��ָ�룬ָ��ָ�����ֽ����͵ı�����һ���������ֽڣ�
ֻ�е�`char*`��ָ�ĵط���β��0����ʱ���ǲ���˵��`char*`Ϊ�ַ���

## �ַ�������

C���Ե���ʱ������������ڽ�����ֵ���㣬���ִ�������ദ���ַ����ʶ�C��������ַ�����û����ô�����ӡ���

### �ַ����������

����������`Hello World`ʱ���ᷢ��`Hello`��`World`���ֱ���䵽��string1��string2���������С�

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

���scanf�����ǲ���ȫ�ģ���Ϊ���������볬��8���ַ�ʱ��ǰ����ַ�������������ֻ������9�����Ժ�ģ�

> `input: 1234657890` `output: 90`����ͱ������ڴ��д洢��˳���йء�
> 
> scanf���������ո�/Tab/�س�Ϊֹ��

��ʱ���ǿ�����`%7s`�����������ַ��ĸ�����<=7���ַ���ֵ���ܹ����ɹ����գ�����7�Ĳ���ֱ��������

#### ��������

* `char *string;`
* scanf("%s", &string); û�ж��ַ�������������
* ��Ϊchar*���ַ������ͣ�������һ���ַ������͵ı���string�Ϳ���ֱ��ʹ����
  * ����û�ж�string��ʼ��Ϊ0�����Բ�һ��ÿ�����ж�����

#### ���ַ���

```c
char buffer[100] = ""; // ����һ���յ��ַ�����buffer[0] === '\0'

char buffer[] = ""; // �������ĳ���ֻ��1
```

### �ַ�������

`strlen()` ����s�ַ����ĳ��ȣ���������β��0��

```c
#include <stdio.h>
#include <string.h>
int main() {
  char line[] = "Hello";
  int length = strlen(line); // ����s�ַ����ĳ��ȣ���������β��0��
  printf("%d", length); // > 5
  return 0;
}
```

`strcmp()` �Ƚ������ַ�������������ֵ��

* `s1 === s2` => 0
* `s1 > s2` => 1
* `s1 < s2` => -1

ע�⣬��������`s1 == s2`����ʽ�Ƚ��ַ���ʱ��ָ���������ַ����ĵ�ַ�Ƿ���ͬ��ʵ�������ֵ��Զ����false��Ҫ�Ƚ��ַ�������Ӧ��ʹ��`strcmp()`����

```c
#include <stdio.h>
#include <string.h>
int main() {
  char s1[] = "abc";
  char s2[] = "abc";
  printf("%d\n", s1 == s2); // > 0 false ����ͬ
  printf("%d\n", strcmp(s1, s2)); // > 0 ��ͬ
  return 0;
}
```