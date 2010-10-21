#include <stdio.h>

#define MAX_SIZE 100

int read_line(char s[], int lim)
{
  int c, i = 0;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

int main(int argc, char const* argv[])
{
  char line[MAX_SIZE];
  int n = 0;

  while (n = read_line(line, MAX_SIZE))
    if (n >= 80)
      printf("%s", line);
  return 0;
}
