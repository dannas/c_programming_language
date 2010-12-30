#include <stdio.h>
#include <stdlib.h> /* For atof. */
#include <ctype.h>

#define MAXOP 100     /* Max size of operator/operand. */
#define MAXVAL 100
#define NUMBER '0'    /* Signal that a number has been found. */
#define BUFSIZE 100

double stack[MAXVAL];
char buf[BUFSIZE];
int sp = 0;
int bufp = 0;

void
push(double val)
{
  if (sp < MAXVAL)
    stack[sp++] = val;
  else
    printf("Error: full Stack\n");
}

double
pop()
{
  double val = 0.0;

  if (sp > 0)
    val = stack[--sp];
  else
    printf("Error: Stack is empty\n");

  return val;
}

int 
getch()
{
  return bufp > 0 ? buf[--bufp] : getchar();
}

void
ungetch(int c)
{
  if (bufp < BUFSIZE)
    buf[bufp++] = c;
  else
    printf("Error: Buffer is full\n");
}

int
getop(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';

  i = 0;

  if (! isdigit(c) && c != '.' && c != '-')
    return c;   /* Not a number. */

  if (c == '-')
    {
      c = getch();
      if ((isdigit(c)) || c == '.')
        s[++i] = c; /* Negative number. */
      else
        {
          if (c != EOF)
            ungetch(c);

          return '-'; /* Minus sign. */
        }
    }

  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;

  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;

  s[i] = '\0';

  if (c != EOF)
    ungetch(c);

  return NUMBER;
}

int 
main(int argc, char const* argv[])
{
  int type;
  double op1, op2;
  char s[MAXOP];

  /* TODO: Why don't character literals work for case statements? */
  while ((type = getop(s)) != EOF) {
    switch(type)
      {
        case NUMBER:
          push(atof(s));
          break;
        case '+':
          push(pop() + pop());
          break;
        case '-':
          op2 = pop();
          push(pop() - op2);
          break;
        case '/':
          op2 = pop();
          if (op2 != 0.0)
            push(pop() / op2);
          else
            printf("Error: division with zero\n");
          break;
        case '%':
          op2 = pop();
          push((int) pop() % (int) op2); /* modulo operates on int. */
          break;
        case '?':
          op2 = pop();
          printf("\t%.8g\n", op2);
          push(op2);
          break;
        case 'd':
          op2 = pop();
          push(op2);
          push(op2);
          break;
        case 's':
          op1 = pop();
          op2 = pop();
          push(op2);
          push(op1);
          break;
        case '\n':
          printf("\t%.8g\n", pop());
          break;
        default:
          printf("Error: Unknown command %s\n", s);
          break;
      }
  }
  return 0;
}
