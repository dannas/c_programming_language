#include <stdio.h>
#include <ctype.h>

int
getch()
{
  return getc(stdin);
}

int
ungetch(int c)
{
  return ungetc(c, stdin);
}

/**
 * Get the next float from stdin and store it in NP. Return a positive
 * number if the operation was succesful, 0 for an invalid number and -1 for
 * EOF.
 */
int
getfloat(double *np)
{
  int c, sign;

  while (isspace(c = getch())) /* Skip blanks. */
    ; 

  if (! isdigit(c) && c != EOF && c != '+' && c != '-')
    {
      ungetch(c); /* Not a number. */
      return 0;
    }

  sign = (c == '-') ? -1 : 1;

  if (c == '-' || c == '+')
    c = getch();

  /* The integer part. */
  for (*np = 0; isdigit(c); c = getch())
    *np = 10 * *np + (c - '0');

  if (c == '.') /* We have decimal values. */
    {
      double power;

      c = getch();

      for (power = 1.0; isdigit(c); c = getch())
        {
          *np = 10 * *np + (c - '0');
          power *= 10;
        }

      *np = *np / power;
    }
  else
    {
      if (c != EOF)
        ungetch(c);
    }

  *np *= sign;

  return c;
}

int 
main(int argc, char const* argv[])
{
  double d;
  int ret;

  ret = getfloat(&d);
  
  if (ret > 0)
    printf("%lf\n", d);
  else if (ret == 0)
    printf("Invalid number\n");
  else
    printf("EOF\n");
  return 0;
}
