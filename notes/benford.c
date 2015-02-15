/**
 * "Benford's Law" states that in many real-life tables of numerical data,
 * the leading digit is far more likely to be a "1" than any other digit.
 * Moreover, the likelihood that the first digit is a given value d > 1
 * decreases logarithmically as d increases. For instance, in a list of
 * the populations of 1015 towns in Pennsylvania, 269 of them begin with
 * a '1', 183 of them begin with a '2', 111 of them begin with a '3',
 * 90 begin with a '4', etc. Only 45 of the populations begin with a '9'.
 *
 * This program reads in a column of numbers, one per line, and tabulates
 * the number of times the numbers begin with '1', '2', ..., '9'.
 *
 * Three data files were tested: pa.dat, ny.dat, ohio.dat. All three are 
 * taken from the United States Census Bureau and may be found at:
 *
 *     https://www.census.gov/popest/data/cities/totals/2011/SUB-EST2011-3.html
 *
 * Usage:
 *        ./benford < pa.dat
 *        ./benford < ny.dat
 *        ./benford < ohio.dat
 */

 
#include <stdio.h>
#include <ctype.h>

main()
{
    int digit[9]; /* digit[i-1] = how often digit i begins a value */
    char c;       /* one input character */
    int i,        /* loop counter */
        dig,      /* actual digit corresponding to ASCII code for a digit */
        flag;     /* boolean flag to let us know we are seeking first digit */

    /* set all digit counts to 0: */
    for (i = 1; i < 10; i++)
        digit[i] = 0;

    flag = 1; /* initially we assume we are at beginning of a line */

    /* Loop over all input characters: */
    while ((c = getchar()) != EOF)
    {
        if (isdigit(c) && flag) /* is this the first digit on the line? */
        {
            dig = c - '0';   /* convert char code to digit */
            digit[dig-1]++;  /* increment appropriate counter */
            flag = 0;        /* ignore remaining digits on this line */
        }
        if (c == '\n')       /* at end of line, reset flag */
        {
            flag = 1;
        }
    }

    /* Print out the frequencies: */
    printf("Digit   First-Digit Frequency\n");
    printf("-----   ---------------------\n");
    for (i = 1; i < 10; i++)
    {
        printf("%4d          %4d\n",i,digit[i-1]); 
    }
}
