#include <stdio.h>

/**
 * Returns first position in S1 that matches any of the characters in S2.
 */
int any(char* s1, char* s2)
{
  int i, j;

    for (i = 0; s1[i] != '\0'; ++i)
      {
        for (j = 0; s2[j] != '\0'; ++j)
          if (s1[i] == s2[j])
            return i;
      }
    return -1;

}

int main(int argc, char const* argv[])
{
  char s1[] = "abcd";
  char s2[] = "b";

  printf("%d\n", any(s1, s2));

  return 0;
}
