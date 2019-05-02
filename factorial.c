/* factorial.c - calculates nth factorial or double factorial
 * (c) Copyright 2019 Bartosz Mierzynski
 * Written in C11
 */

#define PROGRAM_NAME         "factorial"
#define PROGRAM_VERSION      "1.0"
#define COPYRIGHT_YEAR       "2019"
#define COPYRIGHT_HOLDER     "Bartosz Mierzynski"
#define LICENSE_ABBREVIATION ""
#define LICENSE_LINE         ""

#include <getopt.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
	FORMAT_DECIMAL,
	FORMAT_OCTAL,
	FORMAT_HEXADECIMAL,
	FORMAT_UPPER_HEXADECIMAL,
} format_t;

void usage(int status) {
	printf(
	"usage: %s [OPTION]... [NUMBER]...\n"
	"Calculates nth factorial or double factorial\n"
	"Factorial iteratively decimaly by default\n"
	"  -i NUMBER, --iterative=NUMBER\n"
	"  -r NUMBER, --recursive=NUMBER\n"
	"  -I NUMBER, --double-iterative=NUMBER\n"
	"  -R NUMBER, --double-recursive=NUMBER\n"
	"  -d, --decimal\n"	
	"  -o, --octal\n"	
	"  -x, --hexadecimal\n"
	"  -X, --upper-hexadecimal\n"
	"  -h, --help\n"
	"  -v, --version\n",
	PROGRAM_NAME);
	exit(status);
}

void version(void) {
	printf("%s %s\n"
	"Copyright (C) %s %s\n"
	"License %s: %s\n"
	"This is free software: you are free to change and redistribute it.\n"
	"There is NO WARRANTY, to the extent permitted by law.\n",
	PROGRAM_NAME, PROGRAM_VERSION,
	COPYRIGHT_YEAR, COPYRIGHT_HOLDER,
	LICENSE_ABBREVIATION, LICENSE_LINE);
	exit(EXIT_SUCCESS);
}

uintmax_t doublefactorialr(uintmax_t n) {
	return n > 1 ? n * doublefactorialr(n-2) : 1ULL;
}

uintmax_t factorialr(uintmax_t n) {
	return n ? n * factorialr(n-1) : 1ULL;
}

uintmax_t doublefactoriali(uintmax_t n) {
	uintmax_t i = 1ULL;
	
	if(n < 2)
		return i;
	
	do {
		i *= n;
		n -= 2;
	} while(n > 1);
	
	return i;
}

uintmax_t factoriali(uintmax_t n) {
	uintmax_t i = 1ULL;
	
	if(!n)
		return i;
	
	do
		i *= n;
	while(--n);
	
	return i;
}

int main(int argc, char **argv) {
	int c;
	format_t format = FORMAT_DECIMAL;
	const char* formats[] = {
		"%" PRIuMAX "\n",
		"%" PRIoMAX "\n",
		"%" PRIxMAX "\n",
		"%" PRIXMAX "\n",
	};
	const struct option longopts[] = {
	{"iterative",         required_argument, NULL, 'i'},
	{"recursive",         required_argument, NULL, 'r'},
	{"double-iterative",  required_argument, NULL, 'I'},
	{"double-recursive",  required_argument, NULL, 'R'},
	{"decimal",           no_argument,       NULL, 'd'},
	{"octal",             no_argument,       NULL, 'o'},
	{"hexadecimal",       no_argument,       NULL, 'x'},
	{"upper-hexadecimal", no_argument,       NULL, 'X'},
	{"help",              no_argument,       NULL, 'h'},
	{"version",           no_argument,       NULL, 'v'},
	{NULL,                0,                 NULL, 0}
	};

	while ((c = getopt_long(argc, argv, "i:r:I:R:doxXhv", longopts, NULL)) != -1) {
		switch (c) {
		case 'i':
			printf(formats[format], factoriali(strtoull(optarg, NULL, 0)));
			break;
		case 'r':
			printf(formats[format], factorialr(strtoull(optarg, NULL, 0)));
			break;
		case 'I':
			printf(formats[format], doublefactoriali(strtoull(optarg, NULL, 0)));
			break;
		case 'R':
			printf(formats[format], doublefactorialr(strtoull(optarg, NULL, 0)));
			break;
		case 'd':
			format = FORMAT_DECIMAL;
			break;
		case 'o':
			format = FORMAT_OCTAL;
			break;
		case 'x':
			format = FORMAT_HEXADECIMAL;
			break;
		case 'X':
			format = FORMAT_UPPER_HEXADECIMAL;
			break;
		case 'h':
			usage(EXIT_SUCCESS);
			break;
		case 'v':	
			version();
			break;
		case '?':
		default:
			usage(EXIT_FAILURE);
		}
	}
	
	argc -= optind;
	argv += optind;

	for(; argc; --argc, ++argv)
		printf(formats[format], factoriali(strtoull(*argv, NULL, 0)));

	return EXIT_SUCCESS;
}
