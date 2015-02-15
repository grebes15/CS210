/* Demonstration of malloc.
 *
 * Ask user for an array size, then create an array of that size.
 * Do this for both an int array and a double array.
 *
 * Don't forget to include <stdlib.h>
 */

#include <stdio.h>
#include <stdlib.h>

main()
{
    int *a;     /* Will eventually point to an array of integers */
    int n;      /* Size of the int array (input) */

    double *b;  /* Will eventually point to an array of doubles */
    int m;      /* Size of the double array (input) */

    printf("Enter the int array size: ");
    scanf("%d", &n);

    /* "malloc" returns the desired number of bytes from the
     * heap. We must cast this to the correct data type (so,
     * an array of integers is cast to "int *")
     */
    a = (int *) malloc(4 * n); /* 4 bytes per int times n ints */
    a[n-1] = -42;
    printf("It worked: a[%d] = %d\n", n-1, a[n-1]);

    printf("Enter the double array size: ");
    scanf("%d", &m);

    b = (double *) malloc(8 * m); /* 8 bytes per double times m ints */
    b[m-1] = -42;
    printf("It worked: b[%d] = %f\n", m-1, b[m-1]);
}
