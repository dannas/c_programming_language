#include <stdio.h>

char get_char(int i)
{
  return i > 0 ? ' ' : '|';
}

void print_histogram(int nresult[12], int max)
{
  int i, j;

  for (i = 0; i < max; i++)
    {
      for (j = 0; j < 12; j++)
        printf("%c ", get_char(nresult[j]--));
      putchar('\n');
    }
}

/**
 * Count the number of digits, white spaces and other characters. Display
 * the result using a vertical histogram.
 */
int main(int argc, char const* argv[])
{
  int c, i , nwhite, nother, max;
  int ndigit[10];
  int result[12];

  nwhite = nother = max = 0;

  for (i = 0; i < 10; i++)
    ndigit[i] = 0;
  
  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9')
      ++ndigit[c - '0'];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;
  }

  for (i = 0; i < 10; i++)
      if (ndigit[i] > max)
        max = ndigit[i];

  max = nwhite > max ? nwhite : max;
  max = nother > max ? nother : max;

  for (i = 0; i < 10; i++) {
    result[i] = max - ndigit[i];
  }

  result[10] = max - nwhite;
  result[11] = max - nother;

  print_histogram(result, max);

  return 0;
}
