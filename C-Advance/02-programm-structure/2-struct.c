#include <stdio.h>
int main() {
  struct date {
    int month;
    int day;
    int year;
  };

  struct date today;
  // struct date today = {8, 25, 2022}; // 可以按照定义顺序为每个成员赋值
  // struct date today = {.month = 8, .year = 2022}; // 其他未被初始化的值 程序默认从0开始为成员填充值

  today.month = 8;
  today.day = 25;
  today.year = 2022;

  printf("Today's date is: %i-%i-%i.\n", today.year, today.month, today.day);

  struct date* pDate = &today;
  printf("The address of today is: %p\n", pDate); // 000000000061FE0C


  return 0;
}