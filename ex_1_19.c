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

void reverse(char s[])
{
  int i = 0, j = 0;
  char temp;

  /* Go to the end of the string. */
  while (s[i] != '\0')
    ++i;

  --i;

  /* Ignore the line ending. */
  if (s[i] == '\n')
    --i;

  while (j < i) {
    temp = s[j];
    s[j] = s[i];
    s[i] = temp;
    ++j;
    --i;
  }
}

int main(int argc, char const* argv[])
{
  char line[MAX_LENGTH];
  int start, n;

  while (n = read_line(line, MAX_LENGTH)) {
    reverse(line);
    printf("%s", line);
  }

  return 0;
}
