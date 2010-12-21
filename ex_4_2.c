#include <stdio.h>
#include <ctype.h>

/**
 * Convert a character array to a double.
 *
 * Handles signs, and exponent notation.
 */
double
atof(char s[])
{
  double val, power;
  int i, sign, exp, exp_sign;

  for (i = 0; isspace(s[i]); i++)
    ;

  sign = s[i] == '-' ? -1 : 1;

  if (s[i] == '-' || s[i] == '+')
    ++i;

  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');

  if (s[i] == '.')
    ++i;

  for (power = 1.0; isdigit(s[i]); i++)
    {
      val = 10.0 * val + (s[i] - '0');
      power *= 10.0;
    }

  val = sign * (val / power);

  if (s[i] == 'e' || s[i] == 'E')
    {
      ++i;

      exp_sign = s[i] == '-' ? -1 : 1;

      if (s[i] == '+' || s[i] == '-')
        ++i;

      for (exp = 0; isdigit(s[i]); i++)
        exp = 10 * exp + (s[i] - '0');

      if (exp_sign > 0)
        while (exp--)
          val *= 10;
      else
        while (exp --)
          val /= 10;
    }

  return val;
}



int 
main(int argc, char const* argv[])
{
  char pi[] = "3.14";
  char x[] = "3.14e-3";
  char y[] = "3.10E4";
  char z[] = "300E5";

  printf("%f\n", atof(pi));
  printf("%f\n", atof(x));
  printf("%f\n", atof(y));
  printf("%f\n", atof(z));

  return 0;
}
