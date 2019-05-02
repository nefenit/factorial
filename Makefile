# (c) Copyright 2019 Bartosz Mierzynski

CC=cc
CFLAGS=-Wall -pedantic -std=c99 -O2 -g

.PHONY: all
all: 
	@$(CC) factorial.c -o factorial $(CFLAGS) 

.PHONY: clean
clean:
	@rm factorial
