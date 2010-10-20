#include <stdio.h>

/**
 * Print '1' for each input character != EOF
 */
int main(int argc, char const* argv[])
{
  int c;

  while (c = getchar() != EOF)
    printf("%d\n", c);
  printf("EOF %d\n", c);

  return 0;
}
