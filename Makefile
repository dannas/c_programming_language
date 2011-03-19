CC=gcc
FIND=find
CFLAGS= -Wall -g
LDFLAGS=-lm

PROGRAMS= $(patsubst %.c, %, $(wildcard *.c))
TESTS= $(wildcard tests/*.t)

# $(PROGRAMS) uses the implicit rule %: %.c
all: $(PROGRAMS)

check: $(TESTS)
	@./run_tests.py $<

clean:
	$(RM) $(PROGRAMS)

.PHONY: all clean check
