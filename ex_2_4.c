#include <stdio.h>

int exists(char c, char *s)
{
  int i = 0;

  while (s[i++] != '\0')
    if (s[i] == c)
      return 1;

  return 0;
}

void squeeze(char *s1, char *s2)
{
  int i, j;

  i = j = 0;

  while(s1[i++] != '\0')
    if (! exists(s1[i], s2))
      s1[j++] = s1[i];
  s1[j] = '\0';
}

int main(int argc, char const* argv[])
{
  char s1[] = "abcdefghijklmnop";
  char s2[] = "ap";
  squeeze(s1, s2);

  printf("%s\n", s1);
  printf("%s\n", s2);

  return 0;
}
