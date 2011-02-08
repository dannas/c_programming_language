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
 * Fetch next number from stdin and save it to PN. Return last valid number
 * read or 0 for an invalid number and -1 for EOF.
 */
int
getint(int *pn)
{
  int c, d, sign;

  while (isspace(c = getch())) /* Skip blanks. */
    ;

  if (! isdigit(c) && c != EOF && c != '+' && c != '-')
    {
      ungetch(c); /* Not a number. */
      return 0;
    }

  sign = (c == '-') ? -1 : 1;

  if (c == '+' || c == '-')
    {
      d = c; /* Remember the sign character. */
      c = getch();

      if (! isdigit(c))
        {
          if (c != EOF)
            ungetch(c);
          ungetch(d);
          return 0;
        }
    }

  for (*pn = 0; isdigit(c); c = getch())
    {
      *pn = 10 * *pn + (c - '0');
    }

  *pn *= sign;
  if (c != EOF)
    ungetch(c);

  return c;
}

int 
main(int argc, char const* argv[])
{
  
  int n, ret;

  ret = getint(&n);
  if (ret > 0)
    printf("%d\n", n);
  else if (ret == 0)
    printf("Input is not a valid number\n");
  else
    printf("Got EOF\n");

  return 0;
}
