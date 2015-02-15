#include <stdio.h>
#define max(x1,x2) x2>x1?x2:x1
#define min(x1,x2) x2<x1?x2:x1

/**
 * Swap two integers:
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

main()

{



    unsigned bitmap(int left, int right){

        unsigned bitmask;   // pick out the selected bits
        bitmask = (1 << (left - right + 1));
        bitmask = bitmask - 1;
        bitmask <<= right;
        return bitmask;
    }

    unsigned extract(unsigned value, unsigned left, unsigned right) {

        return (value & bitmap(left, right)) >> right; 
    }


    float x;                       // value entered by user
    unsigned *i = (unsigned *) &x; // x's bit pattern interpreted as an unsigned int
    int left, right;               // bit range to be read 
    unsigned bitmask;              // pick out the selected bits
    int position;
    float fraction;
    float significand;
    unsigned exponent;
    printf("Enter a float value: ");
    scanf("%f",&x);

    printf("In hex: %08x\n",*i);

    for (position=31; position>=0; position--) {
        printf("%u",extract(*i,position,position));
        if ((position==31)||(position==23)) printf(" ");
    }
    printf("\n");

    if (extract(*i,31,31)==0) {
        printf("Sign: +\n");
    }
    else
    {
        printf("Sign: -\n");
    }

    exponent = extract(*i, 30, 23)-127;
    printf("Exponent: 2^%u\n", exponent);

    fraction = extract(*i,22,0)/8388608.0;
    printf("Fraction: %f\n", fraction);

    significand = fraction  + 1.0;
    printf("Significand: %f\n", significand);




}
