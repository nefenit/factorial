/* factorialr.c - factorial calculated recursively
 * (c) Copyright 2019 Bartosz Mierzynski
 * Written in C11
 */

#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial_recursive(unsigned long long n) {
	return n ? n * factorial_recursive(n-1) : 1;
}

int main(int argc, char **argv) {
	printf("%llu\n", factorial_recursive(strtoull(argv[1], NULL, 10)));
	return 0;
}
