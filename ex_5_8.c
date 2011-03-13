#include <stdio.h>

#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"
#define WHITE  "\x1B[37m"


static char
month_names[][13] = {
  "Unknown", "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

static char
daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} /* Leap year. */
};

/**
 * Return day of year.
 */
int
day_of_year(int year, int month, int day)
{
  int i, leap;

  leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

  if (month < 1 || month > 12 || day < 1 || day > daytab[leap][month])
    return -1;

  for (i = 1; i < month; i++)
    day +=daytab[leap][i];

  return day;
}

/**
 * Set PMONTH to the month number and PDAY to the day number.
 */
void
month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];

  *pmonth = i;
  *pday = yearday;
}

void
test(int year, int month, int day)
{
  int yearday, rmonth, rday;
  char date_str[20];
  char res_date_str[20];
  
  yearday = day_of_year(year, month, day);
  month_day(year, yearday, &rmonth, &rday);
  sprintf(date_str, "%04d-%02d-%02d", year, month, day);

  if (rday == day && rmonth == month)
    sprintf(res_date_str, "%s%2d %s%s", GREEN, rday, month_names[rmonth], WHITE);
  else
    sprintf(res_date_str, "%s%2d %s%s", RED, rday, month_names[rmonth], WHITE);

  printf("%-15s %-15s %2d'th day of the year\n", date_str,
         res_date_str, yearday);
}

int 
main(int argc, char const* argv[])
{
  test(2010, 1, 1);
  test(2010, 2, 28);
  test(2010, 0, 1);
  test(2010, 1, 0);
  test(2010, -1, 0);
  test(2010, -1, -1);
  test(-1, 1, 1);
  return 0;
}
