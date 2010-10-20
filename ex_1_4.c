#include <stdio.h>

/**
 * Convert Celsius to Fahrenheit and display the result in a table.
 */
int main(int argc, char const* argv[])
{
  float fahr, celsius;
  int upper, lower, step;

  lower = -40;
  upper = 100;
  step = 20;

  celsius = lower;

  while (celsius <= upper) {
    fahr = (9.0 / 5.0) * celsius - 32;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius += step;
  }
  return 0;
}
