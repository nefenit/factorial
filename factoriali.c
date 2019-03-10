/* factoriali.c - factorial calculated iteratively
 * (c) Copyright 2019 Bartosz Mierzynski
 * Written in C11
 */

#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial_iterative(unsigned long long n) {
	unsigned long long a = 1;
	do
		a *= n;
	while(--n);
	return a;
}

int main(int argc, char **argv) {
	printf("%llu\n", factorial_iterative(strtoull(argv[1], NULL, 10)));
	return 0;
}
