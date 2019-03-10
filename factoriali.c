/* factoriali.c - factorial calculated iteratively
 * (c) Copyright 2019 Bartosz Mierzynski
 * Written in C11
 */

#include <stdio.h>
#include <stdlib.h>

void usage(int status) {
	fprintf(stderr, "usage: factoriali N\n");
	exit(status);
}

unsigned long long factorial_iterative(unsigned long long n) {
	unsigned long long a = 1;
	do
		a *= n;
	while(--n);
	return a;
}

int main(int argc, char **argv) {
	if(argc != 2)
		usage(EXIT_FAILURE);
	printf("%llu\n", factorial_iterative(strtoull(argv[1], NULL, 10)));
	return EXIT_SUCCESS;
}
