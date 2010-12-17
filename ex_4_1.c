#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

static int
readline(char s[], int lim)
{
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;

  if (c == '\n')
    s[i++] = c;

  s[i] = '\0';

  return i;
}

static void
reverse(char s[])
{
  int i, j, c;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
      c = s[i];
      s[i] = s[j];
      s[j] = c;
    }
}

/**
 * Make a reversed copy of the pattern T and read the string S backwards
 * trying to find a match.
 */
static int
strrindex1(char s[], char t[])
{
  int i, j, k;

  char tc[100];
  strcpy(tc, t);
  reverse(tc);

  for (i = strlen(s) - 1; i > 0; i--)
    {
      for (j = i, k = 0; j > 0 && tc[k] != '\0' && s[j] == tc[k]; j--, k++)
        ;
      if (k > 0 && tc[k] == '\0')
        return j + 1;
    }

   return -1;
}

/**
 * Scan S from the end, trying to match against the pattern. Both S and T
 * are read in reverse through the iteration.
 */
static int
strrindex2(char s[], char t[])
{
  int i, j, k;

  for (i = strlen(s) - 1; i > 0; i--)
    {
      for (j = i, k = strlen(t) - 1; j > 0 && k > 0 && s[j] == t[k]; j--, k--)
        ;
      if (k == 0)
        return j + 1;
    }

   return -1;
}

/**
 * Search the string from the end starting at an offset strlen(pattern). For
 * each position in S, we scan forward trying to match against the pattern
 * T.
 */
static int
strrindex3(char s[], char t[])
{
  int i, j, k;

  for (i = strlen(s) - strlen(t); i >= 0; i--)
    {
      for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
        ;

      if (k > 0 && t[k] == '\0')
        return i;
    }

  return -1;
}

/**
 * Scan the string S for the pattern T and remember each hit. Return the
 * last one.
 */
static int
strrindex4(char s[], char t[])
{
  int i, j, k, pos;

  pos = -1;

  for (i = 0; s[i] != '\0'; i++)
    {
      for (j = i, k = 0; t[k] != '\0' && t[k] == s[j]; j++, k++)
        ;
      if (k > 0 && t[k] == '\0')
        pos = i;
    }

  return pos;
}

int 
main(int argc, char const* argv[])
{
  int found = 0;
  char pattern[] = "ould";
  char line[MAXLINE];

  while (readline(line, MAXLINE)) {
    if (strrindex4(line, pattern) >= 0) {
      printf("%s", line);
      ++found;
    }
  }

  return 0;
}
