#include <stdio.h>

#define MAX_LENGTH 15
#define IN 0
#define OUT 1

char get_char(int i)
{
  return i > 0 ? ' ' : '|';
}

void print_histogram(int nresult[MAX_LENGTH], int max)
{
  int i, j;

  for (i = 0; i < max; i++)
    {
      for (j = 0; j < MAX_LENGTH; j++)
        printf("%c ", get_char(nresult[j]--));
      putchar('\n');
    }
}

/**
 * Count the number of digits, white spaces and other characters. Display
 * the result using a vertical histogram.
 */
int main(int argc, char const* argv[])
{
  int c, i , max, count;
  int state;
  int words[MAX_LENGTH];
  int result[MAX_LENGTH];

  max = count = 0;
  state = OUT;

  for (i = 0; i < MAX_LENGTH; i++)
    words[i] = 0;

  while ((c = getchar()) != EOF) {
    if (state == IN)
      {
        if (c == ' ' || c == '\t' || c == '\n')
          {
            ++count;
            words[count]++;
            count = 0;
            state = OUT;
          }
        else
            ++count;
      }
    else if (state == OUT)
      {
        if (c == ' ' || c == '\t' || c == '\n')
          ;
        else
            state = IN;
      }
  }

  for (i = 0; i < MAX_LENGTH; i++)
      if (words[i] > max)
        max = words[i];

  for (i = 0; i < MAX_LENGTH; i++) {
    result[i] = max - words[i];
  }

  print_histogram(result, max);

  return 0;
}
