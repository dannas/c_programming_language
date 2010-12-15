#include <stdio.h>
#include <stdlib.h>

#include <sys/time.h>

#define SIZE 5

void
usage_and_exit(const char *progname)
{
  printf("Usage: %s [OPTIONS] SIZE_OF_INPUT\n"
         "\n"
         "Options:\n"
         "  -n        : Set if you want to run normal binary search\n"
         "  -s        : Set if you want to run simplified binary search\n"
         "\n"
         "Tests binary search on a vector of ints of size SIZE_OF_INPUT.\n"
         "No special considerations are taken when it comes to factors such\n"
         "as pipelines and L1/L2 caches.\n",
         progname);
  exit(1);
}

void
die(const char *msg)
{
  perror(msg);
  exit(1);
}

/**
 * Binary search, find the position of X in V.
 */
int 
binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;

  while (low <= high)
    {
      mid = (low + high) / 2;
      if (x < v[mid])
        high = mid - 1;
      else if (x > v[mid])
        low = mid + 1;
      else
        return mid;
    }
  return -1;
}

/**
 * Binary search that tries to minimize the number of if statemnts inside
 * the while loop.
 */
int 
simplified_binsearch(int x, int v[], int n)
{

  int low, high, mid;

  low = 0;
  high = n - 1;

  mid = (low + high) / 2;
  while (low <= high && x != v[mid])
    {
      if (x < v[mid])
        high = mid - 1;
      else
        low = mid + 1;

      mid = (low + high) / 2;
    }

  if (x == v[mid])
    return mid;

  return -1;
}

/**
 * Returns usecs it took to execute SEARCH_FUNC for the indata V with size
 * LEN.
 */
long
measure(int (search_func)(int, int*, int),
        int v[], int len)
{
  struct timeval start, end;
  int i;

  if (gettimeofday(&start, NULL) == -1)
    die("gettimeofday");
  
  for (i = 0; i < len; i++)
    search_func(i, v, len);

  if (gettimeofday(&end, NULL) == -1)
    die("gettimeofday");

  return end.tv_usec - start.tv_usec;
}

void
do_search(int normal, int simplified, int len)
{
  int i;
  int *v = malloc(len * sizeof(*v));

  /* Initialize vector. */
  for (i = 0; i < len; i++)
    v[i] = i;

  if (normal)
    printf("regular=%ld\n", measure(binsearch, v, len));

  if (simplified)
    printf("simplified=%ld\n", measure(simplified_binsearch, v, len));

  free(v);
}

/**
 * Measure the time difference between using a binary search with one if
 * statement and one with the usual two.
 */
int 
main(int argc, char const* argv[])
{
  size_t len;
  int c, normal = 0, simple = 0;
  const char *progname = *argv;

  while (--argc > 0 && (*++argv)[0] == '-')
      while ((c = *++argv[0]))
        switch (c)
          {
            case 'n':
              normal = 1;
              break;
            case 's':
              simple = 1;
              break;
            default:
              usage_and_exit(progname);
              break;
          }

  if (argc != 1)
    usage_and_exit(progname);

  len = atoi(argv[0]);

  do_search(normal, simple, len);

  return 0;
}
