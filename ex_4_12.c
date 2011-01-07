#include <stdio.h>
#include <limits.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))

void
itoa(int n, char s[])
{
  static int i;

  if (n / 10)
    itoa(n / 10, s);
  else
    {
      i = 0;
      if (n < 0)
        s[i++] = '-';
      s[i] = '\0';
    }

  s[i++] = ABS(n % 10) + '0';
  s[i] = '\0';
}

int 
main(int argc, char const* argv[])
{
  char s[100];
  itoa(101, s);
  printf("%s\n", s);
  itoa(INT_MAX, s);
  printf("%s\n", s);
  itoa(INT_MIN, s);
  printf("%s\n", s);
  return 0;
}
