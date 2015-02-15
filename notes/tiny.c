/* Tiny C program to illustrate general approach to functions.
 * Functions may be completely defined prior to their use, or
 * they may be defined "in prototype form" (just parameters and
 * return type, no body) and fully defined at the end of the file.
 * Here, "main" calls both "max" and "min". We fully define "min"
 * prior to main, but we define "max" AFTER main, so we must
 * provide a prototype for max. Either way is correct (but it
 * is weird to mix the two styles as in this program!).
 *
 * Some of this is style choices (some programmers like to put
 * "main" at the top, others like to put it at the bottom), but 
 * some of it is necessary because there may be circular references 
 * in functions.
 */

#include <stdio.h>

/* Function min returns the smaller of its two arguments. */
double min(double x, double y)
{
    return x <=y ? x : y; /* the "?:" operator is like a mini-"if" */
}

/* Function max returns the larger of its two arguments; however,
 * it is defined down below and only a prototype is shown here.
 * It is not necessary to provide parameter names in a prototype
 * (but it is allowed).
 */
double max(double, double); /* note semicolon at the end of the prototype*/


int main()
{
    double x = 3.14, y = 2.718;

    printf("x = %f, y = %f, min = %f, max = %f\n",x,y,min(x,y),max(x,y));
}



/*********************************************************************/

/**
 * Even though max is defined down here, we had to provide its
 * prototype up above since it is called from main and main is defined
 * up above. (C doesn't allow "forward references" -- everything must
 * be declared BEFORE its first use.)
 */
double max(double x, double y)
{
    return x >= y ? x : y;
}
