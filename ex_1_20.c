#include <stdio.h>

#define TABINC 8

/**
 * Translate tabs to spaces, while preserving tabstops.
 */
int main(int argc, char const* argv[])
{
  int c, nb, pos = 1;

  while ((c = getchar()) != EOF) {

    if (c == '\t') {

      nb = TABINC - (pos -1) % TABINC;
      while (nb > 0) {
        putchar(' ');
        nb--;
        pos++;
      }
    }

    else if (c == '\n') {
      putchar(c);
      pos = 1;
    }
    else {
      putchar(c);
      ++pos;
    }
  }

  return 0;
}
