#include <stdio.h>

/**
 * Set bits from position P to P-N of X to be the same as the bits N to 0 of
 * Y.
 *
 * Note that offsets are from right, e.g. p=2 means (1 << 2 + 1).
 */
unsigned int
setbits (unsigned int x, int p, int n, int y)
{
    int y_bits;
    int x_bit_mask;
    
    y_bits = y & ~(~0 << n);

    x_bit_mask = ~(~(~0 << n)) << (p + 1 -n);

    printf("%x\n", x_bit_mask);

    return (x & x_bit_mask) | y_bits;
}

int main(int argc, char const* argv[])
{
  setbits(1, 0, 1, 1); 
  setbits(1, 1, 2, 1); 
  setbits(1, 2, 3, 1); 
  setbits(1, 3, 4, 1); 
  setbits(1, 4, 5, 1); 
  return 0;
}
