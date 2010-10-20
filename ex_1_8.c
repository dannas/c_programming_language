#include <stdio.h>

/**
 * Print number of spaces, tabs and lines.
 */
int main(int argc, char const* argv[])
{
  int c, n_spaces = 0, n_tabs = 0, n_lines = 0;

  while ((c = getchar()) != EOF)
    {

      if (c == '\n')
        ++n_lines;

      if (c == '\t')
        ++n_tabs;

      if (c == ' ')
          ++n_spaces;
    }
  printf("%d %d %d\n", n_spaces, n_tabs, n_lines);
  return 0;
}
