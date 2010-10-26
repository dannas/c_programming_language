#include <stdio.h>

#define MAX_WIDTH 20

/*
 * Break long lines into one or more lines of MAX_WIDTH. Set the line breaks
 * after the last non-white character before the MAX_WIDTH column.
 */
int main(int argc, char const* argv[])
{
  int c;
  int pos = 0;
  char line[MAX_WIDTH];

  /* while we have input */
  while ((c = getchar()) != EOF)
    {
      /* store the char in an array */
      line[pos] = c;
      ++pos;

      if (c == '\n')
        {
          int i;

          for (i = 0; i < pos; i++)
            putchar(line[i]);
          pos = 0;
        }

      if (pos == MAX_WIDTH)
        {
          int lastpos = pos;
          int i, j;

          /* search backwards for first white space */
          while (lastpos > 0 
                 && line[lastpos] != ' ' 
                 && line[lastpos] != '\t')
            --lastpos;

          /* Write the line. */
          for (i = 0; i < lastpos; i++)
            putchar(line[i]);

          putchar('\n');

          /* Rearrange the rest of the line to start at pos = 0. */
          for (i = 0, j = lastpos; i < lastpos && j < MAX_WIDTH; i++, j++)
            line[i] = line[j];

          pos = i;

        }
    }
  return 0;
}
