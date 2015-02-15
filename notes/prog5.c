// prog5.c -- that extra set of parentheses in the "while" condition
// was necessary: assignment has lower precedence than "!-".
// This look executes as long as the condition "getchar() != 'n'"
// is true ... but why doesn't it print anything?
// 
// Compile using:
//       gcc prog5.c -o prog5
//
// Execute using:
//       ./prog5
//
// (Any name may be used as the executable; by default it is a.out)

#include <stdio.h>

main() {
    char c;
    while (c = getchar() != '\n') {
        putchar(c+1);
    }
    putchar('\n');
}
