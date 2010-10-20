CC=gcc
FIND=find

PROGRAMS= $(patsubst %.c, %, $(wildcard *.c))

# $(PROGRAMS) uses the implicit rule %: %.c
all: $(PROGRAMS)

clean:
	$(RM) $(PROGRAMS)

.PHONY: all clean
