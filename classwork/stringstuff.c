/* Demonstration of strings.
 *
 * Usage:
 *       gcc stringstuff.c -o stringstuff
 *       ./stringstuff
 */
#include <stdio.h>

main()
{
    /* Declare a few strings; memory is allocated as indicated in comments */
    char *firstname = "Bob",                /* allocates 4 bytes */
         *lastname = "Cowznofski",          /* allocates 11 bytes */
         *address1 = "520 North Main St.",  /* allocates 19 bytes */
         *address2 = "Box Q",               /* allocates 6 bytes */
         *city = "Meadville",               /* allocates 10 bytes */
         *state = "PA";                     /* allocates 3 bytes */
    char *i;            /* loops through memory addresses of the strings */

    printf("%s %s\n%s\n%s\n%s, %s\n",firstname,lastname,address1,address2,city,state);

    printf("Char  ASCII Value\n");
    for (i = firstname; i < firstname+53; i++) { /* 53 = sum of memory allocations */
        printf("  %c\t(%d)\n",*i,*i);
    }
}
