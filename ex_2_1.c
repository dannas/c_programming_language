#include <stdio.h>

/**
 * Determine the limits for the integer types.
 */
int main(int argc, char const* argv[])
{
  /* ~0 converts the number to all one's.
   * (unsigned <type>) ~0 >> 1 guarentes that we shift in zeroes.
   * '-' for min values is just pure magic to me.  */

  printf("Max short: %16d\n",
         (short)((unsigned short) ~0 >> 1));
  printf("Min short: %16d\n",
         -(short)((unsigned short) ~0 >> 1));
  printf("Max int: %16d\n",
         (int)((unsigned int) ~0 >> 1));
  printf("Min int: %16d\n",
         -(int)((unsigned int) ~0 >> 1));
  printf("Max long: %16ld\n",
         (long)((unsigned long) ~0 >> 1));
  printf("Min int: %16ld\n",
         -(long)((unsigned long) ~0 >> 1));

  return 0;
}
