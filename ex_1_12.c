#include <stdio.h>

#define OUT 0
#define IN 1

/**
 * Print each word from stdin on its own line.
 */
int main(int argc, char const* argv[])
{
  int c;
  int state = OUT;

  while ((c = getchar()) != EOF) {
    if (state == OUT)
      {
        if (c == ' ' | c == '\t' || c == '\n')
          ;
        else
          {
            putchar(c);
            state = IN;
          }
      }
    else if (state == IN)
      {
        if (c == ' ' | c == '\t' || c == '\n')
          {
            putchar('\n');
            state = OUT;
          }
        else
          putchar(c);
      }
  }
  return 0;
}
