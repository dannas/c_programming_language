#include <stdio.h>

int
wordlength()
{
  int i;
  unsigned int x = (unsigned) ~0;

  for (i = 0; x; x >>= 1)
    i++;

  return i;
}

unsigned int
rightrot(unsigned int x, int n)
{
  unsigned int outside = x & (~(~0 << n));
  unsigned int result = x >> n;

  result |= (outside << (wordlength() - 1));

  return result;
}

int
main(int argc, char const* argv[])
{

  printf("0x01 rr=%u\n", rightrot(0x01, 1));
  return 0;
}
