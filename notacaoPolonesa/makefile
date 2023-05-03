CFLAGS= -g -Wall -std=c99

PROGS= arvoresNarias

all: $(PROGS)

%.c: %.c
	gcc $@.c -o $@ $(CFLAGS)

clean:
	rm -f $(PROGS)
