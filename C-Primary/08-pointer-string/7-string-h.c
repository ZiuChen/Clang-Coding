#include <stdio.h>
#include <string.h>
int main() {
  char line[] = "Hello";
  int length = strlen(line); // ����s�ַ����ĳ��ȣ���������β��0��
  printf("%d\n", length); // > 5

  char s1[] = "abc";
  char s2[] = "abc";
  printf("%d\n", s1 == s2); // > 0
  printf("%d\n", strcmp(s1, s2)); // > 0
  return 0;
}