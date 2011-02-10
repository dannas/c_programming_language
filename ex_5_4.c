#include <stdio.h>
#include <string.h>

/**
 * Return 1 if string T forms the end of string S.
 */
int
strend(char *s, char *t)
{
  char *bt = t;
  char *bs = s;

  while (*s)
    s++;

  while (*t)
    t++;

  for (; *s == *t; s--, t--)
    {
      if (t == bt) 
        return 1;
      else if (s == bs) 
        return 0;
    }

  return 0;
}

void
test(char *s, char *t)
{
  printf("'%s', '%s', %d\n", s, t, strend(s, t));
}

int 
main(int argc, char const* argv[])
{
  test("a", "a");
  test("ab", "b");
  test("a", "b");
  test("a", "");
  test("", "a");
  test("a", "aaaaaaaaaaa");

  return 0;
}
