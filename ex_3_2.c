#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
usage_and_exit(const char *progname)
{
  printf("Usage: %s [OPTIONS] STRING\n"
         "\n"
         "Options:\n"
         "  -u        : Set if you want unescape the string\n"
         "\n"
         "Escapes or unescapes the STRING and sends the result to stdout.\n"
         "Note that it only handles \\t and \\n though\n",
         progname);
  exit(1);
}

/**
 * S is an escaped version of T.
 */
void
escape(char *s, const char *t)
{
  while (*t)
    {
      if (*t == '\t')
        {
          *s++ = '\\';
          *s++ = 't';
        }
      else if (*t == '\n')
        {
          *s++ = '\\';
          *s++ = 'n';
        }
      else
        {
          *s++ = *t;
        }
      t++;
    }
  *s = '\0';
}

/** 
 * S is an unescaped version of T.
 */
void
unescape(char *s, const char *t)
{
  while (*t)
    {
      if (*t == '\\' && *(t + 1) == 't')
        {
          *s++ = '\t';
          t++;
        }
      else if (*t == '\\' && *(t +1) == 'n')
        {
          *s++ = '\n';
          t++;
        }
      else
        *s++ = *t;

      t++;
    }

  *s = '\0';
}

int 
main(int argc, char const* argv[])
{
  const char *progname = argv[0];
  int do_escape = 1, c;
  const char *t;
  char *s;

  while (--argc && (*++argv)[0] == '-')
    while ((c = *++argv[0]))
      switch (c)
        {
          case 'u':
            do_escape = 0;
            break;
          default:
            usage_and_exit(progname);
        }

  if (argc != 1)
    usage_and_exit(progname);

  t = *argv;
  s = malloc(strlen(t) * (*t) + 1);

  if (do_escape)
    escape(s, t);
  else
    unescape(s, t);

  puts(s);

  free(s);
  
  return 0;
}
