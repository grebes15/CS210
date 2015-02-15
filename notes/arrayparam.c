/**
 * Arrays as parameters to functions. Given an integer array, find the
 * length of the longest subarray consisting of consecutive integer
 * values. For instance, the array "3,4,5,7,6,4,5,6,7,9,0" contains
 * a subarray of length 4 consisting of consecutive values: 4,5,6,7.
 *
 * Usage:
 *        gcc arrayparam.c -o arrayparam
 *        ./arrayparam
 */


#include <stdio.h>

/* Function prototypes */
int consec(int *a, int size);


main()
{
    /* The array to be examined: */
    int x[] = {3,4,   6,7,8,  2,  1,  3,4,  6,  9,10,11,12,13,  
                12,  11,  10,  12,  14,  3,  2,3,4,5};
    int i; /* loop index */

    printf("Array x: ");      /* display the original array */
    for (i = 0; i < 25; i++)
    {
        printf("%d ",x[i]);
    }
    printf("\n");

    /* Call the consec function to solve the problem: */
    printf("The longest sequence of consecutive integers in x has length %d\n",
            consec(x,25));
}

/**********************************************************************/

/**
 * Given an array "a" of size "size", find the length of the longest
 * subsequence consisting of consecutive values.
 */

int consec(int *a, int size)
{
    int max = 1;    /* length of longest sequence seen so far */
    int count = 1;  /* length of current consecutive sequence */
    int i;          /* loop counter */

    for (i = 1; i < size; i++) {
        if (a[i] == a[i-1]+1) {  /* Does this extend a consecutive seq.? */
            count++;
            if (count > max)     /* Is this bigger than previous max? */
                max = count;
        }
        else           /* Not consecutive, so reset length to 1 */
            count = 1;
    }

    return max;
}

