# 07-��������

## ��������

### ����ļ��ɳ�ʼ��

C99�������鷽ʽ�����ϡ�����飬���Լ���Ĵ��롣

```c
int a[] = {2,3,4,5,6,7,8,9}; // > 2 3 4 5 6 7 8 9
int b[10] = {2,3,4}; // > 2 3 4 0 0 0 0 0 0 0
int c[10] = {[1]=2, [5]=7}; // > 0 2 0 0 0 7 0 0 0 0
```

��ȡ����ĳ��ȣ�

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
  // ���ܽ�length�Ž�search�м��� ԭ���ǽ�������Ϊ��������ʱ ����˻�Ϊָ��
  // Ҫ��main�м����length�ٴ��ݽ�ȥ
  int length = sizeof(array) / sizeof(array[0]);
  int index = search(array, target, length);
  printf("Ԫ��%d�ڵ�%d��λ����", target, index);
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