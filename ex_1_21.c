#include <stdio.h>

#define TABINC 8

/**
 * Translate tabs to spaces, while preserving tabstops.
 */
int main(int argc, char const* argv[])
{
  int c, nb = 0, nt = 0, pos = 0;

  for (; (c = getchar()) != EOF; ++pos) {
    if (c == ' ') {
      if (pos % TABINC != 0)
        ++nb;
      else {
        nb = 0;
        ++nt;
      }
    }
    else {
       if (c == '\t')
         nb = 0;
       else {
          while (nb > 0) {
            putchar(' ');
            --nb;
          }
       }

      while (nt > 0) {
        putchar('\t');
        --nt;;
      }

      if (c == '\n')
        pos = 0;
      else if (c == '\t')
        pos = pos + TABINC - ((pos - 1) % TABINC) - 1;

      putchar(c);
    }
  }
  
  return 0;
}
