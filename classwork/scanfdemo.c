/* Demonstration of scanf function. Input an int, a double, and a string,
 * then print them back out.
 *
 * Things to watch for:
 *   -- note use of the "&" operator for input of int and double
 *   -- be sure to use the "%lf" format when inputting a double; "%f" won't work
 *   -- string input is terminated by any whitespace character (space, tab, \n)
 *   -- unpredictable results can occur if input string exceeds length of char array
 *
 * Usage:
 *        gcc scanfdemo.c -o scanfdemo
 *        ./scanfdemo
 */

#include <stdio.h>
#define MAXSTRING 20

int main()
{
    int x;              /* an input integer */
    char z[MAXSTRING];  /* string (max length, not including \0, is MAXSTRING-1 */
    double y;           /* an input double */

    printf("Enter an integer: ");
    scanf("%d", &x);

    printf("Enter a double: ");
    scanf("%lf", &y);

    printf("Enter a string: ");
    scanf("%s",z);

    printf("integer: %d\n",x);
    printf("double: %f\n",y);
    printf("string: %s\n",z);
}
