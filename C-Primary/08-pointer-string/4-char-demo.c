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