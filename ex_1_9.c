#include <stdio.h>

#define SPACE 0
#define NO_SPACE 1

/**
 * Substitue multi-spaces into single ones.
 */
int main(int argc, char const* argv[])
{
  int c;
  int last_written = NO_SPACE;

  while ((c = getchar()) != EOF)
    {
      if (last_written == SPACE)
        {
          if (c == ' ')
            ;
          else
            {
              putchar(c);
              last_written = NO_SPACE;
            }
        }
      else
        {
          if (c == ' ')
            {
              putchar(c);
              last_written = SPACE;
            }
          else
            putchar(c);
        }
    }
  return 0;
}
