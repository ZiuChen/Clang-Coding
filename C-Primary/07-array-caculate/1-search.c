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