#include <stdio.h>
#include <string.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))

void
reverse(char s[])
{
  int i, j, c;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
      c = s[i];
      s[i] = s[j];
      s[j] = c;
    }
}

void
itoa(char s[], int n, int w)
{
  int sign, i;

  i = 0;
  sign = n;

  do {
    s[i++] = ABS(n % 10) + '0';
  } while ((n /= 10) != 0);

  if (sign < 0)
    --w;

  while (i < w)
    s[i++] = '0';

  if (sign < 0)
    s[i++] = '-';

  s[i] = '\0';

  reverse(s);
}

int 
main(int argc, char const* argv[])
{
  char s[100];

  itoa(s, 1, 5);
  puts(s);
  
  itoa(s, -1, 5);
  puts(s);

  itoa(s, -86400, 2);
  puts(s);
  return 0;
}
