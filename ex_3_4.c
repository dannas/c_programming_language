#include <stdio.h>
#include <string.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))

void
reverse(char s[])
{
  int i, j;
  char temp;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
      temp = s[i];
      s[i] = s[j];
      s[j] = temp;
    }
}

void itoa(char s[], int n)
{
  int i, sign;

  /*
   * This snippet won't work if n = INT_MIN since abs(INT_MIN) > abs(INT_MAX)
   *
   *  if ((sign = n) < 0)
   *    n = -n;
  */

  sign = n;

  i = 0;

  do 
    {
      s[i++] = ABS(n % 10) + '0';
    } 
  while ((n /= 10) != 0);

  if (sign < 0)
    s[i++] = '-';

  s[i] = '\0';

  reverse(s);

}

int 
main(int argc, char const* argv[])
{
  char s[100];
  int z = ~0 << (sizeof(z) * 8 - 1); /* INT_MIN */

  itoa(s, z);
  printf("z=%d s=%s\n", z, s);

  return 0;
}
