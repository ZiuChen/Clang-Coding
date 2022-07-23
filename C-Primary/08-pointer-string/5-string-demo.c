#include <stdio.h>
int main() {
  // char word[] = { 'H', 'e', 'l', 'l', 'o', '!' }; // ×Ö·ûÊý×é
  // char word[] = { 'H', 'e', 'l', 'l', 'o', '!', '\0' }; // ×Ö·û´®
  // char word[] = { 'H', 'e', 'l', 'l', 'o', '!', 0 }; // ×Ö·û´®
  // char word = "Hello!"; // ×Ö·û´®

  char* str = "Hello!";
  char word[] = "Hello!";
  char line[10] = "Hello!";

  return 0;
}