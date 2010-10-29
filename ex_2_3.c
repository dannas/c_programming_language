#include <stdio.h>

#define MAXLINE 80

int pow16(int exp)
{
  int base = 16;
  int i;

  if (exp == 0)
    return 1;

  if (exp == 1)
    return base;

  for (i = 1; i < exp; i++)
    base *= base;

  return base;
}

int htoi(const int s[], int lim)
{
  int d = 0, i, start;

  /* Check if we have a leading '0x' */
  if (lim > 2 
      && s[0] == '0' 
      && (s[1] == 'x' || s[1] == 'X'))
    start = 2;
  else
    start = 0;

  for (i = start; i < lim; i++) {
    if (s[i] >= '0' && s[i] <= '9')
      d += (s[i] - '0') * pow16(lim - i -1);
    else if (s[i] >= 'a' && s[i] <= 'f')
      d += (s[i] + 10 - 'a') * pow16(lim - i -1);
    else if (s[i] >= 'A' && s[i] <= 'F')
      d += (s[i] + 10 - 'A') * pow16(lim - i -1);
  }

  return d; 
}

int main(int argc, char const* argv[])
{
  int c;
  int n = 0;
  int line[MAXLINE];

  while ((c = getchar()) != EOF) {
    line[n++] = c;

    if (n == MAXLINE || c == '\n') {
      printf("%d, %X\n", htoi(line, n - 1), htoi(line, n - 1));
      n = 0;
    }
  }
  return 0;
}
