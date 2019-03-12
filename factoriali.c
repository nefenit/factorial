/* factoriali.c - factorial calculated iteratively
 * (c) Copyright 2019 Bartosz Mierzynski
 * Written in C11
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

void usage(int status) {
	fprintf(stderr, "usage: factoriali N\n");
	exit(status);
}

ull factoriali(ull n) {
	ull i = 1ULL;
	if(!n)
		return 1ULL;
	do
		i *= n;
	while(--n);
	return i;
}

int main(int argc, char **argv) {
	if(argc != 2)
		usage(EXIT_FAILURE);
	printf("%llu\n", factoriali(strtoull(argv[1], NULL, 10)));
	return EXIT_SUCCESS;
}
