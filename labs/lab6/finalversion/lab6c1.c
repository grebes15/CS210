/*Andreas Landgrebe
Part 1 of Laboratory Assignment # 6
October 28, 2013
Decode a FLoatuing-Point Value Using Masks
This C program will read in a float number and display the hexidecimal, 32 bit float numnber, sign, fraction and significand of a particular number*/
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
        bitmask = (1 << (left - right + 1)); //put a 1 to the selected bits
        bitmask = bitmask - 1; //decrease the bitmask by 1 
        bitmask <<= right; 
        return bitmask; //return the bitmask value to print out the correct float value
    }

    unsigned extract(unsigned value, unsigned left, unsigned right) {
	//method to extract the position to read in
        return (value & bitmap(left, right)) >> right; 
    }


    float x;                       // value entered by user
    unsigned *i = (unsigned *) &x; // x's bit pattern interpreted as an unsigned int
    int left, right;               // bit range to be read 
    unsigned bitmask;              // pick out the selected bits
    int position; // value to print out a particular position.
    float fraction; //value to print out the fraction
    float significand; //value to print out the significand
    unsigned exponent; //value to print out the exponet
    printf("Enter a float value: "); //print and scan in a float value
    scanf("%f",&x);

    printf("In hex: %08x\n",*i);

    for (position=31; position>=0; position--) {
        printf("%u",extract(*i,position,position)); //prints out the bits from positions 31 - 0 
        if ((position==31)||(position==23)) printf(" "); // when at bit position 31, print a space and when at bit position 23, print a space. 
    }
    printf("\n");

    if (extract(*i,31,31)==0) { //at bit 31, this if statement checks if the sign is positive or negative.
        printf("Sign: +\n");
    }
    else
    {
        printf("Sign: -\n");
    }

    exponent = extract(*i, 30, 23)-127;
    printf("Exponent: 2^%u\n", exponent); //prints the exponenet of a particular number

    fraction = extract(*i,22,0)/8388608.0;
    printf("Fraction: %f\n", fraction); //prints out the fraction of a particular number

    significand = fraction  + 1.0;
    printf("Significand: %f\n", significand); //prints out the significand of a particular number




}
