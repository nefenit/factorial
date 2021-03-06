#!/usr/bin/python3
# -*- coding: utf-8 -*-
'''
factorial.c - calculates nth factorial or double factorial
 (c) Copyright 2019 Bartosz Mierzynski
'''

from sys    import argv, exit
from enum   import Enum
from getopt import gnu_getopt

program_name  = "factorial"
__author__    = "Bartosz Mierzynski"
__version__   = "1.0"
__copyright__ = "Copyright (C) 2019 Bartosz Mierzynski"
__license__   = ""
license_line  = ""

class Format(Enum):
    decimal           = 0
    octal             = 1
    hexadecimal       = 2
    upper_hexadecimal = 3
    binary            = 4

def usage(status):
    print(
    "usage: {:s} [OPTION]... [NUMBER]...\n"
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
    "  -v, --version".format(program_name))
    exit(status)

def version(status):
    print("{:s} {:s}\n"
    "{:s}\n"
    "License {:s}: {:s}\n"
    "This is free software: you are free to change and redistribute it.\n"
    "There is NO WARRANTY, to the extent permitted by law.".format(
    program_name, __version__,
    __copyright__,
    __license__, license_line))
    exit(status)

def doublefactorialr(n):
    return n * doublefactorialr(n-2) if n > 1 else 1

def factorialr(n):
    return n * factorialr(n-1) if n else 1

def doublefactoriali(n):
    i = 1
    if(n < 2):
        return i
    i *= n
    n -= 2
    while(n > 1):
        i *= n
        n -= 2
    return i

def factoriali(n):
    i = 1
    if(n == 0):
        return i
    i *= n
    n -= 1
    while(n):
        i *= n
        n -= 1
    return i

def main():
    fmt = Format.decimal
    formats = [
            "{:d}",        
            "{:o}",        
            "{:x}",        
            "{:X}",        
            "{:b}",        
    ]
    longopts = [
        "iterative=",
        "recursive=",
        "double-iterative=",
        "double-recursive=",
        "decimal",
        "octal",
        "hexadecimal",
        "upper-hexadecimal",
        "binary",
        "help",
        "version"
    ]
    try:
        opts, args = gnu_getopt(argv[1:], "i:r:I:R:doxXbhv", longopts)
    except GetoptError as err:
        print(err)
        usage(1)
    for o, a in opts:
        if o in ("-i", "--iterative"):
                print(formats[fmt.value].format(factoriali(int(a))))
        elif o in ("-r", "--recursive"):
                print(formats[fmt.value].format(factorialr(int(a))))
        elif o in ("-I", "--double-iterative"):
                print(formats[fmt.value].format(doublefactoriali(int(a))))
        elif o in ("-R", "--double-recursive"):
                print(formats[fmt.value].format(doublefactorialr(int(a))))
        elif o in ("-d", "--decimal"):
                fmt = Format.decimal
        elif o in ("-o", "--octal"):
                fmt = Format.octal
        elif o in ("-x", "--hexadecimal"):
                fmt = Format.hexadecimal
        elif o in ("-X", "--upper-hexadecimal"):
                fmt = Format.upper_hexadecimal
        elif o in ("-b", "--binary"):
                fmt = Format.binary
        elif o in ("-h", "--help"):
                usage(0)
        elif o in ("-v", "--version"):	
                version(0)
        else:
                usage(1)
    for a in args:
        print(formats[fmt.value].format(factoriali(int(a))))
    return 0

if __name__ == "__main__":
    exit(main())
