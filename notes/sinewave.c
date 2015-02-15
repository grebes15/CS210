/**
 * Plots a sine wave. Each column on the screen represents an
 * x-value, spaced at intervals of 0.1. Each row represents a y-value,
 * spaced at intervals of 0.2.
 *
 * Usage (note use of "-lm" to access math library):
 *        gcc sinewave.c -lm -o sinewave
 *        ./sinewave 
 */
 
#include <stdio.h>
#include <math.h>

main()
{
    int    x,     /* loop counter for x axis (multiply by .1)*/
           y;     /* loop counter for y axis (multiply by .2 and subtract 1) */
    double yval,  /* actual y value corresponding to y counter */
           xval,  /* actual x value corresponding to x counter */
           sine;  /* value of sin(x) */

    /* Loop over all y-values (counting down): */
    for (y = 10; y >= 0; y--)
    {
        yval = y * .2 - 1; /* convert loop index to y-value */
        for (x = 0; x < 80; x++)
        {
            xval = x * .1; /* convert loop index to x-value */
            sine = sin(xval); 
            if (sine <= yval && sine > yval - .2) /* graph point here? */
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
