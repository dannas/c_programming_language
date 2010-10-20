#include <stdio.h>

/** 
 * Print table of Fahrenheit and Celsius values in descending order.
 */
int main(int argc, char const* argv[])
{
  int fahr;

  for (fahr = 300; fahr >= 0; fahr -= 20) 
    printf("%3.0d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  return 0;
}
