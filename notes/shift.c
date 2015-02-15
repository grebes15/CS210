/**
 * Demonstration program--printf using three different formats for both
 * a signed int and an unsigned int. Note that the "%d" format treats
 * unsigned values as if they were signed and the "%u" format treats
 * signed values as if they were unsigned.
 * The %x format is probably the easiest way to see the difference.
 */

#include <stdio.h>
main()
{
    unsigned x = -21; /* Yes, this is legal! */
    int y = -21;

    printf("Comparison of %%d, %%x, and %%u output formats on int and unsigned:\n\n");

    printf("%%d format: \"unsigned x = -21;\", is %d; shifted right: %d\n",x,x>>1);
    printf("%%0x8 format: \"unsigned x = -21;\", is %0x8; shifted right: %08x\n",x,x>>1);
    printf("%%u format: \"unsigned x = -21;\", is %u; shifted right: %u\n",x,x>>1);

    printf("\n%%d format: \"int y = -21;\", is %d; shifted right: %d\n",y,y>>1);
    printf("%%0x8 format: \"int y = -21;\", is %0x8; shifted right: %08x\n",y,y>>1);
    printf("%%u format: \"int y = -21;\", is %u; shifted right: %u\n",y,y>>1);

}
