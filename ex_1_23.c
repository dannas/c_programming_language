#include <stdio.h>

#define NORMAL 0
#define START_SLASH_SEEN 1
#define START_STAR_SEEN 2
#define END_STAR_SEEN 3
#define START_STRING_SEEN 4

/**
 * Remove all comments from a C program.
 */
int main(int argc, char const* argv[])
{
  int c;
  int last_ch;
  int state = NORMAL;

  while ((c = getchar()) != EOF) {
    switch (state) {
      case NORMAL:
        if (c == '/') {
          last_ch = c;
          state = START_SLASH_SEEN;
        }
        else if (c == '"') {
          putchar(c);
          state = START_STRING_SEEN;
        }
        else
          putchar(c);
        break;

      case START_SLASH_SEEN:
        if (c == '*')
          state = START_STAR_SEEN;
        else {
          putchar(last_ch);
          putchar(c);
        }

        if (c == '"')
          state = START_STRING_SEEN;
        break;

      case START_STAR_SEEN:
        if (c == '*')
          state = END_STAR_SEEN;
        break;

      case END_STAR_SEEN:
        if (c == '/')
          state = NORMAL;
        break;

      case START_STRING_SEEN:
        putchar(c);
        if (c == '\\')
          last_ch = c;
        if (c == '"' && last_ch != '\\')
          state = NORMAL;
        break;
      default:
        break;
    }
  }

  return 0;
}
