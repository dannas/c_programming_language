#include <stdio.h>

/**
 * Append the T string to S. Return a pointer to the resulting string.
 */
char *
strcat(char *s, char *t)
{
  char *ret = s;

  while (*s)
    s++;

  while((*s++ = *t++) != '\0')
    ;

  return ret;
}

int 
main(int argc, char const* argv[])
{
  char s[20] = "Hello ";
  char t[20] = "world!";
  printf("'%s'\n", strcat(s, t));
  return 0;
}
