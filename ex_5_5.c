#include <stdio.h>

char *
strcpy(char *s, const char *t)
{
  char *bs = s;

  while ((*s++ = *t++) != '\0')
    ;

  return bs;
}

int
strncmp(const char *s, const char *t, size_t n)
{
  int i = 0;

  while (*s == *t)
    {
      if (i >= n - 1)
        break;

      s++;
      t++;
      i++;
    }
  return *s - *t;
}

char *
strncpy(char *s, const char *t, size_t n)
{
  int i = 0;
  char *bs = s;

  while ((*s++ = *t++) != '\0' && i < n)
    i++;

  return bs;
}

char *
strncat(char *s, const char *t, size_t n)
{
  int i = 0;
  char *bs = s;

  while (*s)
    s++;

  while ((*s++ = *t++) != '\0' && i < n)
    i++;

  return bs;
}

void
test_cmp(char *s, char *t, size_t n)
{
  printf("'%.*s', '%.*s', %d\n", n, s, n, t, strncmp(s, t, n));
}

void
test_cpy(char *s, char *t, size_t n)
{
  char cs[20];
  strcpy(cs, s);

  printf("'%s', '%.*s', '%s'\n", s, n, t, strncpy(cs, t, n));
}

void
test_cat(char *s, char *t, size_t n)
{
  char cs[20];
  strcpy(cs, s);

  printf("'%s', '%.*s', '%s'\n", s, n, t, strncat(cs, t, n));
}


int 
main(int argc, char const* argv[])
{
  printf("[strncpy]\n"); 
  test_cmp("a", "a", 1);
  test_cmp("a", "b", 1);
  test_cmp("b", "a", 1);
  test_cmp("ab", "ac", 1);
  test_cmp("ab", "ac", 2);

  printf("[strncpy]\n");
  test_cpy("", "a", 1);
  test_cpy("ab", "", 1);

  printf("[strncat]\n");
  test_cat("", "a", 1);
  test_cat("a", "a", 1);
  return 0;
}
