#include <stdio.h>
#include <string.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))

void reverse(char s[])
{
  int i, j, c;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
      c = s[i];
      s[i] = s[j];
      s[j] = c;
    }
}

void itob(char s[], int n, int b)
{
  int sign, i;

  i = 0;
  sign = n;

  do {
    s[i++] = ABS(n % b) + '0';
  } while((n /= b) != 0);

  if (sign < 0)
    s[i++] = '-';

  s[i] = '\0';

  reverse(s);
}

int 
main(int argc, char const* argv[])
{
  char s[100];

  itob(s, 0x16, 16);
  puts(s);
  itob(s, 055, 8);
  puts(s);
  itob(s, 0x44, 2);
  puts(s);
  return 0;
}
