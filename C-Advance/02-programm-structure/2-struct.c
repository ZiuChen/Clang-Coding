#include <stdio.h>
int main() {
  struct date {
    int month;
    int day;
    int year;
  };

  struct date today;
  // struct date today = {8, 25, 2022}; // ���԰��ն���˳��Ϊÿ����Ա��ֵ
  // struct date today = {.month = 8, .year = 2022}; // ����δ����ʼ����ֵ ����Ĭ�ϴ�0��ʼΪ��Ա���ֵ

  today.month = 8;
  today.day = 25;
  today.year = 2022;

  printf("Today's date is: %i-%i-%i.\n", today.year, today.month, today.day);

  struct date* pDate = &today;
  printf("The address of today is: %p\n", pDate); // 000000000061FE0C


  return 0;
}