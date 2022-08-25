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
  printf("%d", sizeof(a));
  int i;
  *result = a[0];
  for (i = 1; i < length; i++) {
    if (a[i] > *result) {
      *result = a[i];
    }
  }
}