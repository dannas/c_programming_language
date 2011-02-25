#include <stdio.h>
#include <string.h>

enum {MAXLINES = 5000, MAXLEN = 1000};

/* Vector of pointers to the lines we've read and want to sort. */
char *lineptr[MAXLINES];

/* The lines we've read separated by '\0' characters. */
char storage[MAXLINES * MAXLEN];

/**
 * Read one line with max LIM characters from stdin and store it in S.
 */
int
readline(char *s, int lim)
{
  int i = 0;
  char c;

  while ((c = getchar()) != EOF && c != '\n' && lim > 0)
    {
      *s++ = c;
      i++;
    }
  return i;
}

/**
 * Read lines from stdin until EOF or MAXLINES is reached. Store lines in
 * STORAGEPTR and the addresses in LINEPTR. */
int
readlines(char *lineptr[], char *storageptr, int maxlines)
{
  int len, nlines;
  char line[MAXLEN];

  nlines = 0;
  while ((len = readline(line, MAXLEN)) > 0)
    if (nlines >= maxlines)
      return -1;
    else
      {
        line[len] = '\0';
        strcpy(storageptr, line);
        lineptr[nlines++] = storageptr;
        storageptr += (strlen(storageptr) + 1);
      }
  return nlines;
}

/**
 * Write NLINES from LINEPTR to stdout.
 */
void
writelines(char *lineptr[], int nlines)
{
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

/**
 * Swap the values in V with index I and J.
 */
void
swap(char *v[], int i, int j)
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

/**
 * Sort the values in V from LEFT to RIGHT using strcmp() as comparator.
 */
void qsort(char *v[], int left, int right)
{
  int last;
  int i;

  if (left >= right) /* We need atleast two values. */
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);

}

int 
main(int argc, char const* argv[])
{
  int nlines;
  char *storageptr = storage;

  if ((nlines = readlines(lineptr, storageptr, MAXLINES)) >= 0)
    {
      qsort(lineptr, 0, nlines - 1);
      writelines(lineptr, nlines);
      return 0;
    }
  else
    {
      printf("Error: Too many lines\n");
      return 1;
    }
}
