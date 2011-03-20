CC=gcc
FIND=find
CFLAGS= -Wall -g
LDFLAGS=-lm

PROGRAMS= $(patsubst %.c, %, $(wildcard *.c))
TESTS= $(wildcard tests/*.t)


# $(PROGRAMS) uses the implicit rule %: %.c
all: $(PROGRAMS)

check: $(TESTS)
	@for i in $(TESTS); \
	do \
		./run_tests.py $$i; \
	done; 

clean:
	$(RM) $(PROGRAMS)


.PHONY: all clean check
