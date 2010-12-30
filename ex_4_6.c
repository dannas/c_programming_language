#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> /* For atof. */
#include <string.h>

#define BUFSIZE 100
#define MAXOP 100     /* Max size of operator/operand. */
#define MAXVAL 100
#define NAME 'n'
#define NUMBER '0'    /* Signal that a number has been found. */

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

  if (sp >= 0)
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

  /* Do we have a math function? */
  if (islower(c))
    { 
      while (islower(s[++i] = c = getch()))
             ;

      s[i] = '\0';

      if (c != EOF)
        ungetch(c); /* Read one char too much. */

      if (strlen(s) > 1)
        return NAME;
      else
        return c;
    }

  /* .. Is it a number? */
  if (! isdigit(c) && c != '.' && c != '-')
    return c;   /* Not a number. */


  /* Is it a negative number? */
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

void mathfnc(const char* s)
{
  if (! strcmp(s, "sin"))
    push(sin(pop()));
  else if (! strcmp(s, "cos"))
    push(sin(pop()));
  else if (! strcmp(s, "pow"))
    push(pow(pop(), pop()));
  else
    printf("Error: Non implemented math function\n");
}

int 
main(int argc, char const* argv[])
{
  int type;
  int var = 0.0;
  int i;
  double op1, op2;
  char s[MAXOP];
  double variable[26];

  for (i = 0; i < 26; i++)
    variable[i] = 0.0;

  while ((type = getop(s)) != EOF) {
    switch(type)
      {
        case NUMBER:
          push(atof(s));
          break;
        case NAME:
          mathfnc(s);
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
        case '=':
          pop();
          if (var >= 'A' && var <= 'Z')
            variable[var - 'A'] = pop();
          else
            printf("Error: No variable name\n");
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
          if (type >= 'A' && type <= 'Z')
            push(variable[type - 'A']);
          else
            printf("Error: Unknown command %s\n", s);
          break;
      }
    var = type;
  }
  return 0;
}
