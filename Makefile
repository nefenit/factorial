# (c) Copyright 2019 Bartosz Mierzynski

CC=cc
CFLAGS=-Wall -pedantic -std=c11 -O2

all: factoriali factorialr

factoriali:
	@$(CC) $(CFLAGS) factoriali.c -o factoriali

factorialr:
	@$(CC) $(CFLAGS) factorialr.c -o factorialr

.PHONY: clean

clean:
	@rm factoriali factorialr
