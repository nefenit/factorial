/* factorial.c - calculates nth factorial
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

void usage(int status) {
	printf(
	"usage: %s [OPTION]... [NUMBER]...\n"
	"Calculates nth factorial\n"
	"  -i NUMBER, --iterative=NUMBER\n"
	"  -r NUMBER, --recursive=NUMBER\n"
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
	LICENSE_ABBREVIATION, LICENSE_LINE
	);
	exit(EXIT_SUCCESS);
}

uintmax_t factorialr(uintmax_t n) {
	return n ? n * factorialr(n-1) : 1ULL;
}

uintmax_t factoriali(uintmax_t n) {
	uintmax_t i = 1ULL;
	if(!n)
		return 1ULL;
	do
		i *= n;
	while(--n);
	return i;
}

int main(int argc, char **argv) {
	int c;
	const struct option longopts[] = {
	{"iterative", required_argument, NULL, 'i'},
	{"recursive", required_argument, NULL, 'r'},
	{"help",      no_argument,       NULL, 'h'},
	{"version",   no_argument,       NULL, 'v'},
	{NULL,        0,                 NULL, 0}
	};

	while ((c = getopt_long(argc, argv, "i:r:hv", longopts, NULL)) != -1) {
		switch (c) {
		case 'i':
			printf("%" PRIdMAX "\n", factoriali(strtoull(optarg, NULL, 0)));
			break;
		case 'r':
			printf("%" PRIdMAX "\n", factorialr(strtoull(optarg, NULL, 0)));
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

	if(argc) {
		while(argc) {	
			printf("%" PRIdMAX "\n", factoriali(strtoull(*argv, NULL, 0)));
			--argc;
			++argv;
		}
	} else {
		usage(EXIT_FAILURE);
	}


	return EXIT_SUCCESS;
}
