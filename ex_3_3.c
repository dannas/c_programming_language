#include <stdio.h>
#include <ctype.h>
#include <string.h>

int
is_same_sort(char c1, char c2)
{
    return ((islower(c1) && islower(c2))
            || (isupper(c1) && isupper(c2))
            || (isdigit(c1) && isdigit(c2)));
}

void expand(char *s, const char *t)
{
  int i, j;

  s[0] = t[0];

  for (i = 1, j = 1; i < strlen(t); i++)
    {
      char prev = t[i -1];
      char c = t[i];
      char next = t[i + 1];

      if (c == '-')
        {
          if (is_same_sort(prev, next))
            {
              int val;

              for (val = prev + 1; val < next; val++)
                s[j++] = val;
            }
          else
            s[j++] = c;
        }
      else
        s[j++] = c;
  }

  s[j] = '\0';
}

int 
main(int argc, char const* argv[])
{
  const char t[100] = "-a-c-1A-C-e-";
  char s[100];

  expand(s, t);

  puts(s);
  return 0;
}
