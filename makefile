CFLAGS= -g -Wall -std=c99

np: notacaoPolonesa.c
	gcc notacaoPolonesa.c -o np $(CFLAGS)

run: np
	./np
