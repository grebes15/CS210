/**
 * Functions and pass-by-reference.
 * How to swap; how not to swap.
 *
 * Usage:
 *        gcc swap.c -o swap
 *        ./swap
 */


#include <stdio.h>

/* Function prototypes--see below for actual function definition. */
void badswap(int a, int b);
void goodswap(int *a, int *b);


main()
{
    int x = 10, y = 20; /* valued to be swapped */

    printf("Values to be swapped: x = %d, y = %d\n",x,y);
    badswap(x, y);
    printf("After calling badswap: x = %d, y = %d\n",x,y);

    goodswap(&x, &y);
    printf("After calling goodswap: x = %d, y = %d\n",x,y);
}


/**********************************************************************/

/**
 * Can't swap values using pass-by-value
 */

void badswap(int a, int b)
{
    int hold;         /* temp value for the swap */

    hold = a;
    a = b;
    b = hold;
    printf("Inside badswap, a = %d, b = %d\n",a,b);
}

/**
 * To swap values, use pass-by-reference
 */

void goodswap(int *a, int *b)
{
    int hold;         /* temp value for the swap */

    hold = *a;
    *a = *b;
    *b = hold;
    printf("Inside goodswap, *a = %d, *b = %d\n", *a, *b);
}
