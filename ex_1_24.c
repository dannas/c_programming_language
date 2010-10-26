#include <stdio.h>

#define NORMAL 0
#define START_SLASH_SEEN 1
#define START_STAR_SEEN 2
#define END_STAR_SEEN 3
#define START_STRING_SEEN 4
#define START_ACCENT_SEEN 5

/**
 * Check for unbalanced brackets, braces and parenthesis.
 */
int main(int argc, char const* argv[])
{
  int c;
  int last_ch;
  int state = NORMAL;
  int braces = 0;
  int brackets = 0;
  int parenthesis = 0;

  while ((c = getchar()) != EOF) {
    switch (state) {
      case NORMAL:
        if (c == '/') {
          last_ch = c;
          state = START_SLASH_SEEN;
        }
        else if (c == '"')
          state = START_STRING_SEEN;
        else if (c == '\'')
          state = START_ACCENT_SEEN;
        else if (c == '{')
          ++braces;
        else if (c == '[')
          ++brackets;
        else if (c == '(')
          ++parenthesis;
        else if (c == '}')
          --braces;
        else if (c == ']')
          --brackets;
        else if (c == ')')
          --parenthesis;

        if (braces < 0) {
          printf("Unbalanced braces\n");
          braces = 0;
         }
        if (brackets < 0) {
          printf("Unbalanced brackets\n");
          brackets = 0;
        }
        if (parenthesis < 0) {
          printf("Unbalanced parenthesis\n");
          parenthesis = 0;
        }
        break;

      case START_SLASH_SEEN:
        if (c == '*')
          state = START_STAR_SEEN;
        else if (c == '"')
          state = START_STRING_SEEN;
        else
          state = NORMAL;
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
        if (c == '\\')
          last_ch = c;
        else if (c == '"' && last_ch != '\\')
          state = NORMAL;
        break;

      case START_ACCENT_SEEN:
        if (c == '\\')
          last_ch = c;
        else if (c == '\'' && last_ch != '\\')
          state = NORMAL;
        break;

      default:
        break;
    }
  }

  if (braces)
    printf("Unbalanced braces\n");
  if (brackets)
    printf("Unbalanced brackets\n");
  if (parenthesis)
    printf("Unbalanced parenthesis\n");
  
  return 0;
}
