CC=gcc
FIND=find
CFLAGS= -Wall -g

PROGRAMS= $(patsubst %.c, %, $(wildcard *.c))

# $(PROGRAMS) uses the implicit rule %: %.c
all: $(PROGRAMS)

clean:
	$(RM) $(PROGRAMS)

.PHONY: all clean
