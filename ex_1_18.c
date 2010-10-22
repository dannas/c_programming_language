#include <stdio.h>

#define MAX_LENGTH 100

int read_line(char s[], int lim)
{
  int i, c;

  for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = '\n';
    ++i;
  }

  s[i] = '\0';

  return i;
}

int do_remove(char s[])
{
  int i = 0;

  while (s[i] != '\n')
    ++i;

  --i;

  while (i > 0 && (s[i] == ' ' || s[i] == '\t'))
    --i;

  if (i > 0) {
    ++i;
    s[i] = '\n';
    ++i;
    s[i] = '\0';
  }

  return i;
}

int main(int argc, char const* argv[])
{
  char line[MAX_LENGTH];
  int start, n;

  while (n = read_line(line, MAX_LENGTH)) {
      if (do_remove(line) > 0) {
         printf("%s", line);
        }
    }

  return 0;
}
