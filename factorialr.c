/* factorialr.c - factorial calculated recursively
 * (c) Copyright 2019 Bartosz Mierzynski
 * Written in C11
 */

#include <stdio.h>
#include <stdlib.h>

void usage(int status) {
	fprintf(stderr, "usage: factorialr N\n");
	exit(status);
}

unsigned long long factorial_recursive(unsigned long long n) {
	return n ? n * factorial_recursive(n-1) : 1;
}

int main(int argc, char **argv) {
	if(argc != 2)
		usage(EXIT_FAILURE);
	printf("%llu\n", factorial_recursive(strtoull(argv[1], NULL, 10)));
	return EXIT_SUCCESS;
}
