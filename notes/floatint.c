/* Bob Roos
 * 24 October 2013
 *
 * C program demonstrating:
 *     use of macro function-like definition ("max" and "min" macros)
 *     use of pointer variables to access bit patterns of float data
 *     use of mask variables to extract selected bits from a word
 *     use of unsigned variables to avoid "sign extension" issues when shifting
 *     use of << and >> shift operators
 *     use of various print formats (e.g., %u, %x, etc.)
 */
#include <stdio.h>
#define max(x1,x2) x2>x1?x2:x1
#define min(x1,x2) x2<x1?x2:x1

/**
 * Swap two integers:
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

main()
{
    float x;                       /* value entered by user */
    unsigned *i = (unsigned *) &x; /* x's bit pattern interpreted as an unsigned int */
    int left, right;               /* bit range to be read */
    unsigned bitmask;              /* pick out the selected bits */

    printf("Enter a float: ");
    scanf("%f",&x);
    printf("The integer with same bit pattern as %f is %u\n",x,*i);
    printf("The hexadecimal representation is %08x\n",*i);

    printf("\nEnter left and right bit positions (leftmost: 31, rightmost: 0): ");
    scanf("%d",&left);
    scanf("%d",&right);

    left = min(31,max(0,left));    /* force value to be in the legal range */
    right = min(31,max(0,right));  /* force value to be in the legal range */
    if (left < right)              /* if user used wrong ordering, fix it  */
        swap(&left, &right);

    /* Compute a bit mask consisting of 1s in positions left, ..., right. (In the
       following comments, assume number of bits in range is "#bits"): */

    bitmask = (1 << (left-right+1)); /* First, put a "1" followed by #bits "0"s */
    bitmask = bitmask - 1;  /* change those #bits "0"s to "1"s by subtracting 1 */
    bitmask <<= right;      /* shift the mask bits over to the correct position */
    printf("Bitmask: %08x\n",bitmask);

    /* Now print out the int value of the bits in the selected range.
       First, apply the bit mask to select the desired bits; then shift
       right to get the int value of just those bits: */

    printf("The integer between bits %d and %d, inclusive, is %u\n",
        left, right, (*i & bitmask)>>(right));
}
