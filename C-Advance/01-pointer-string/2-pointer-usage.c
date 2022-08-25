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