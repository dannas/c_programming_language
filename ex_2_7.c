#include <stdio.h>

/**
 * Invert bits in c starting at position p to p + n.
 */
unsigned int
invert(unsigned int x, int p, int n)
{
  unsigned int bitmask;
  unsigned int wanted_bits;
  unsigned int r_wanted_bits;
  unsigned int inverted_bits;

  /* Mask out our wanted bits. */
  bitmask =  ~(~0 << n) << (p + 1 -n);
  wanted_bits = x & bitmask;

  /* Align to the right. */
  r_wanted_bits = wanted_bits >> (p + 1 -n);

  /* Invert the right aligned bits. */
  inverted_bits = ~r_wanted_bits & (~(~0 << n));

  /* Clear the bits we have inverted in x and put the inverted ones there. */
  return (x & ~bitmask) | (inverted_bits << (p + 1 - n));
}

int 
main(int argc, char const* argv[])
{
  printf("0xFF (0, 1) = %X\n", invert(0xFF, 0, 1));
  printf("0xFF (1, 1) = %X\n", invert(0xFF, 1, 1));
  printf("0xFF (2, 1) = %X\n", invert(0xFF, 2, 1));
  printf("0xFF (3, 1) = %X\n", invert(0xFF, 3, 1));

  printf("0xFF (4, 1) = %X\n", invert(0xFF, 4, 1));
  printf("0xFF (4, 2) = %X\n", invert(0xFF, 4, 2));
  printf("0xFF (4, 3) = %X\n", invert(0xFF, 4, 3));
  printf("0xFF (4, 4) = %X\n", invert(0xFF, 4, 4));
  return 0;
}
