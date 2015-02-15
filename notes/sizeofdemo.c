/* Demonstration of the "sizeof" operator.
 *
 * We can find the size of defined types (like int or double)
 * or of arrays or strings (but only if they are defined AS
 * ARRAYS and not as pointers). The size of a pointer is 
 * 8 bytes, regardless of how much memory it is "pointing to"
 * or the type of data pointed to.
 */

#include <stdio.h>
#include <stdlib.h>

main()
{
    int a[] = {10,5,2,1,3,6,12};  /* 28 bytes: 4*7 */
    double b[] = {3.14, 42.42, 2.718}; /* 24 bytes: 8*3 */
    char c[] = "abcdefghijklmnop"; /* 17 bytes (including \0) */

    int *x = (int *) malloc(100 * sizeof (int));  /* 400 ??? */
    double *y = (double *) malloc(1000 * sizeof (double)); /* 8000 ??? */
    char *z = "12345678901234567890";  /* 21 ??? */

    printf("Size of an int: %ld\n", sizeof (int));
    printf("Size of a double: %ld\n", sizeof (double));
    printf("Size of a char: %ld\n", sizeof (char));

    printf("Size of array a: %ld\n", sizeof a);
    printf("Size of array b: %ld\n", sizeof b);
    printf("Size of array c: %ld\n", sizeof c);
    printf("Size of array x: %ld\n", sizeof x);
    printf("Size of array y: %ld\n", sizeof y);
    printf("Size of array z: %ld\n", sizeof z);
}
