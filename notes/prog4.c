/* prog4.c -- read characters until newline, for each one
 * print the following character.
 *
 * Why isn't output interleaved with input?
 * 
 * Compile using:
 *       gcc prog4.c -o prog4
 *
 * Execute using:
 *       ./prog4
 *
 * (Any name may be used as the executable; by default it is a.out)
 */

#include <stdio.h>

main() {
    char c;
    while ((c = getchar()) != '\n') {
        putchar(c+1);
    }
    putchar('\n');
}
