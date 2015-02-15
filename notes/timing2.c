// Use with the "time" command to see the change in kernel time
// as the input argument changes.
//
// Usage:
//           gcc timing2.c -o timing2
//           time ./timing2 1000
// where the "1000" can be replaced with any number (try increasing
// powers of 10, e.g., 1000, 10000, 100000, ...)

#include <stdio.h>
#include <stdlib.h>

main(int argc, char * argv[]) {
    int *i;
    int j;
    int n;

    if (argc < 2)
        printf("You must provide an integer\n"),exit(1);

    n = atoi(argv[1]);

    // Repeatedly allocate 1000 words to the pointer variable i.
    // NOTE: C will not do "garbage collection"!
    for (j = 1; j <= n; j++) {
      i = (int*) malloc(1000*sizeof(int));
    }
}
