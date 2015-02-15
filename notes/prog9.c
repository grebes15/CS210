// prog9.c -- defining and calling functions. Recursion.
// 
// Compile using:
//       gcc prog9.c -o prog9
//
// Execute using:
//       ./prog9
//
// (Any name may be used as the executable; by default it is a.out)

#include <stdio.h>
f(int i) 
{
    if (i <= 0) return 1;
    return i * f(i-1);
}

main() {
   int i;
   for (i = 1; i <= 10; i++)
       printf("f(%d) = %d\n",i,f(i));
}
