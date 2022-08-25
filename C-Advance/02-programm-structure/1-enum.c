#include <stdio.h>
enum color { red, yellow, green };
void f(enum color c);

int main() {
  enum color a = red;
  enum color b = yellow;
  enum color c = green;
  f(a); // 0
  f(b); // 1
  f(c); // 2
  return 0;
}

void f(enum color c) {
  printf("%d\n", c); // ½«color´òÓ¡Êä³ö
}