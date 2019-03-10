# (c) Copyright 2019 Bartosz Mierzynski

CC=cc
CFLAGS=-Wall -pedantic -std=c11

all: factoriali factorialr

factoriali:
	@$(CC) $(CFLAGS) factoriali.c -o factoriali

factorialr:
	@$(CC) $(CFLAGS) factorailr.c -o factorialr

clean:
	@rm factoriali factorialr
