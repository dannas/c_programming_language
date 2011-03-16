#include <stdio.h>

#include <string.h>
#include <stdlib.h>

void
usage_and_exit(const char *progname)
{
  printf("USAGE: %s expression\n"
         "  Must be atleast two operands and one operator\n", progname);
  exit(1);
}

int
calculate(int op1, int op2, char operator)
{
  printf("[DEBUG] %d %c %d\n", op1, operator, op2);
  switch (operator)
    {
      case '*':
        return op1 * op2;
        break;
      case '/':
        return op1 / op2;
        break;
      case '+':
        return op1 + op2;
        break;
      case '-':
        return op1 - op2;
        break;
    }

  return -1;
}

int
is_operator(char op)
{
  return op == '*' || op == '/' || op == '+' || op == '-';
}

/**
 * A polish calculator.
 *
 * This could have been solved easier with a stack.
 */
int 
main(int argc, const char *argv[])
{
  const char **op = NULL;
  const char **p;
  const char *progname = argv[0];
  const char **end = argv + argc - 1;
  int operand;
  int res = 0;

  /* Find the first operator. */
  for (; argc > 0; argc--, argv++)
    {
      if (is_operator(**argv))
        {
          op = argv;
          break;
        }
    }

  if (! op)
    usage_and_exit(progname);

  res = atoi(*(op -1));
  p = op - 2;
  operand = atoi(*p);

  while (*p > progname && op <= end)
    {
      res = calculate(res, operand, **op);
      p--;
      operand = atoi(*p);
      op++;
    }

  printf("%d\n", res);

  return 0;
}
