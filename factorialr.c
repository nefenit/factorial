/* factorialr.c - factorial calculated recursively
 * (c) Copyright 2019 Bartosz Mierzynski
 * Written in C11
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

void usage(int status) {
	fprintf(stderr, "usage: factorialr N\n");
	exit(status);
}

ull factorialr(ull n) {
	return n ? n * factorialr(n-1) : 1;
}

int main(int argc, char **argv) {
	if(argc != 2)
		usage(EXIT_FAILURE);
	printf("%llu\n", factorialr(strtoull(argv[1], NULL, 10)));
	return EXIT_SUCCESS;
}
