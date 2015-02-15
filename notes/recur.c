/* Demonstration of recursion in C */

#include <stdio.h>

/* Function prototype (see definition below) */
int f(int i, int j);

main()
{
    int i,j; /* arguments for f */

    /* loop through a number of different i,j values */
    for (i = 1; i < 20; i++)
        for (j = 1; j < 20; j++)
            printf("f(%d,%d) = %d\n",i,j,f(i,j));
}

/* Recursive function f (doesn't do anything useful as far as I can tell) */
int f(int i, int j)
{
    if (j <= 0)     /* base case */
        return 1;
    else if (i <= 0)/* base case */
        return 0;
    else            /* recursive case */
        return i + j + f(i-1,j/2);
}
