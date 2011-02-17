#include <stdio.h>
#include <ctype.h>

enum {SIZE = 100};

/**
 * Convert the string S to a integer.
 */
int
atoi(const char *s)
{
  int i, d = 0;
  int sign;

  while (isspace(*s))
    s++;

  if (! isdigit(*s) && *s != '-' && *s != '+')
    return 0; /* Not a number. */

  sign = (*s == '-') ? -1 : 1;

  if (*s == '-' || *s == '+')
    s++;

  for (i = 0; isdigit(*s); s++)
    {
      d = 10 * d + (*s - '0');
    }

  return d * sign;
}

/**
 * Convert the string S to a float number.
 */
double
atof(const char *s)
{
  int d = 0;
  int sign;

  while (isspace(*s))
    s++;

  if (! isdigit(*s) && *s != '-' && *s != '+')
    return 0; /* Not a number. */

  sign = (*s == '-') ? -1 : 1;

  if (*s == '-' || *s == '+')
    s++;

  for (; isdigit(*s); s++)
    {
      d = 10 * d + (*s - '0');
    }

  if (*s == '.')
    {
      int power;

      s++;

      for (power = 1.0; isdigit(*s); s++)
        {
          d = 10 * d + (*s - '0');
          power *= 10.0;
        }
      return (d * sign) / power;
    }
  else
    return d * sign;

}

/**
 * Reverse the string S.
 */
void
reverse(char *s)
{
  char *end = s;
  char *start = s;

  while (*end)
    end++;

  end--;

  for (; start <  end; start++, end--)
    {
      char temp;

      temp = *start;
      *start = *end;
      *end = temp;
    }
}

/**
 * Convert the number D to a string S.
 */
void
itoa(char *s, int d)
{
  char *p = s;

  do
    {
      *p = (d % 10) + '0';
      d /= 10;
      p++;
    } while (d);

  *p = '\0';

  reverse(s);
}

/**
 * Return index of first occurence of SEARCHFOR in S or -1 if no match was
 * found.
 */
int
strindex(char *s, char *searchfor)
{
  int i;

  for (i = 0; *s; s++, i++)
    {
      if (*s == *searchfor)
        {
          char *ps = s;
          char *psf = searchfor;

          for (; *psf && *ps == *psf; ps++, psf++)
            ;

          if (! *psf)
            return i;
        }
    }

  return -1;
}

void
test_atoi(char *s)
{
  printf("'%s' = %d\n", s, atoi(s));
}

void
test_atof(char *s)
{
  printf("'%s' = %3.6f\n", s, atof(s));
}

void
test_itoa(int d)
{
  char s[SIZE];

  itoa(s, d);
  printf("'%d' = %s\n", d, s);
}

void
test_reverse(char *s)
{
  char cs[SIZE];
  char *csp = cs;

  while ((*csp++ = *s++))
    ;

  printf("'%s' = ", cs);
  reverse(cs);
  printf("'%s'\n", cs);
}

void
test_strindex(char *s, char *t)
{
  printf("Match for '%s' found in '%s' on pos %d\n", t, s, strindex(s, t));
}

int 
main(int argc, char const* argv[])
{
  printf("[atoi]\n");
  test_atoi("1");
  test_atoi("-1");
  test_atoi("0");
  test_atoi("10");
  test_atoi("100");
  test_atoi("-10");

  printf("[atof]\n");
  test_atof("1");
  test_atof("-1.0");
  test_atof("0.0");
  test_atof("10.0");
  test_atof("-10.0");

  printf("[reverse]\n");
  test_reverse("hej");
  test_reverse("");

  printf("[itoa]\n");
  test_itoa(1);
  test_itoa(12);
  test_itoa(0);
  test_itoa(9);

  printf("[strindex]\n");
  test_strindex("ab", "a");
  test_strindex("ab", "b");
  test_strindex("ab", "c");
  test_strindex("", "a");
  test_strindex("", "");
  return 0;
}
