#include <stdio.h>

int
bitcount(unsigned int x)
{
  int b;

  for (b = 0; x; x &= x - 1)
    b++;

  return b;
}

int
main(int argc, char const* argv[])
{
  printf("bitcount=%d\n", bitcount(0x0F));
  printf("bitcount=%d\n", bitcount(0x01));
  return 0;
}
