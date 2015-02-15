// Use with the "time" command to see the change in user time
// as the input argument.
//
// Usage:
//           gcc timing.c -o timing
//           time ./timing 1000
// where the "1000" can be replaced with any number (try increasing
// powers of 10, e.g., 1000, 10000, 100000, ...)

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
  int i, j, k, max;

  if (argc < 2)
      printf("Please provide an int argument\n"),exit(1);

  max = atoi(argv[1]);

  // Execute loop max times, where user provides value of max:
  for (k = 1; k <= max; k++) {
    i = 10; j = 20;
    i = i*j; // just to do something!
  }
}
