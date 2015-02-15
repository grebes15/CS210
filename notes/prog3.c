// input/output is done with library functions; a file named 
// stdio.h contains their declarations, a library named libc (glibc?)
// contains their definitions. Putchar prints a single character.
// 
// Compile using:
//       gcc prog3.c -o prog3
//
// Execute using:
//       ./prog3
//
// (Any name may be used as the executable; by default it is a.out)

#include <stdio.h>

main() {
    int i = 65, j = 97, k = 10;
    putchar(i);
    putchar(j);
    putchar(k);
}
