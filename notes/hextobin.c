/**
 * A different way to convert hexadecimal to binary: use an array of
 * 4-character strings, one per hexadecimal digit.
 *
 * Extract each 4-bit hex digit and "look up" its binary representation 
 * in the array.
 */

#include <stdio.h>

main()
{
    /* Here's the translation table from hex to binary; note the "5" to allow
       room for a null character at the end of each string: */

    char bin[16][5] = {"0000","0001","0010","0011","0100","0101","0110","0111",
                       "1000","1001","1010","1011","1100","1101","1110","1111"};

    float x;                        /* value entered by user */
    unsigned *j = (unsigned *) &x;  /* *j is an int sharing same memory as x */

    char b; /* contains a 4-bit chunk of a word; really, all we need is a "nybble" ! */
    unsigned bytemask = 0xf0000000; /* 1111 0000 0000 ... 0000 */

    int i; /* loop index */

    printf("Enter a float: ");
    scanf("%f",&x);
    printf("In hex, %f = %08x\n",x,*j);

    /* Convert to binary one hex digit at a time, starting at the left end: */
    for (i = 7; i >= 0; i--)
    {
        b = (*j & bytemask) >> 4*i; /* pick out bits, then shift to right end */
        printf("%s ",bin[b]);
        bytemask >>= 4;             /* shift the mask 4 places to the right */
    }
    printf("\n");
}


