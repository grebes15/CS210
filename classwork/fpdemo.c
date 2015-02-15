/**
 * Various floating point operations resulting in special values;
 * hexadecimal representations of various special values.
 */

#include <stdio.h>
#include <math.h>

main() {
   /* Dividing a non-zero value by zero: */
    float x = 1.0, y = 0.0;
    float z1 = x/y;
    printf("%f / %f = %f\n",x,y,z1);
    printf("In hex, %f = %08x\n",y,*(int *)(&y));
    printf("In hex, %f = %08x\n",z1,*(int *)(&z1));

    x = -1.0;
    float z2 = x/y;
    printf("%f / %f = %f\n",x,y,z2);
    printf("In hex, %f = %08x\n",z2,*(int *)(&z2));

    x = 1.0;
    y = -0.0;
    printf("In hex, %f = %08x\n",y,*(int *)(&y));
    float z3 = x/y;
    printf("%f / %f = %f\n",x,y,z3);

    x = -1.0;
    float z4 = x/y;
    printf("%f / %f = %f\n",x,y,z4);

   /* Comparing -0 and +0: */
    if (-0.0 == 0.0)
        printf("%f and %f are equal\n",-0.0,0.0);
    else if (-0.0 < 0.0)
        printf("%f is less than %f\n",-0.0,0.0);
    else if (-0.0 > 0.0)
        printf("%f is greater than %f\n",-0.0,0.0);
    else
        printf("%f and %f are not comparable\n",-0.0,0.0);


   /* Comparing -inf and +inf: */
    if (z3 == z4)
        printf("%f and %f are equal\n",z3,z4);
    else if (z3 < z4)
        printf("%f is less than %f\n",z3,z4);
    else if (z3 > z4)
        printf("%f is greater than %f\n",z3,z4);
    else
        printf("%f and %f are not comparable\n",z3,z4);

   /* Various divisions involving zero and inf: */
    printf("%f / %f = %f\n",z1,z1,z1/z1);
    printf("%f / %f = %f\n",z1,z2,z1/z2);
    printf("%f / %f = %f\n",z1,0.0,z1/0.0);
    printf("%f / %f = %f\n",z2,0.0,z2/0.0);

   /* Various divisions of signed zero by signed zero: */
    x = 0.0;
    y = 0.0;
    float z5 = x/y;
    printf("%f / %f = %f\n",x,y,z5);

    x = -0.0;
    y = 0.0;
    float z6 = x/y;
    printf("%f / %f = %f\n",x,y,z6);

    x = -0.0;,
    y = -0.0;
    float z7 = x/y;
    printf("%f / %f = %f\n",x,y,z7);

    x = -0.0;
    y = 0.0;
    float z8 = x/y;
    printf("%f / %f = %f\n",x,y,z8);

   /* Various arguments, illegal and otherise, to math functions: */
    printf("sqrt(%f) = %lf\n",-1.0,sqrt(-1.0));
    printf("sqrt(%f) = %lf\n",z1,sqrt(z1));
    printf("sqrt(%f) = %lf\n",z2,sqrt(z2));
    printf("sqrt(%f) = %lf\n",z5,sqrt(z5));
    printf("log(%f) = %lf\n",0.0,log(0.0));
    printf("log(%f) = %lf\n",-1.0,log(-1.0));
    printf("log(%f) = %lf\n",z3,log(z3));
    printf("log(%f) = %lf\n",z4,log(z4));
    printf("exp(%f) = %lf\n",z3,exp(z3));
    printf("exp(%f) = %lf\n",z4,exp(z4));

   /* Comparing NaN values: */
    float z9 = sqrt(-1.0);
    float z10 = log(-1.0);
    if (z9 == z10)
        printf("%f and %f are equal\n",z9,z10);
    else if (z9 < z10)
        printf("%f is less than %f\n",z9,z10);
    else if (z9 > z10)
        printf("%f is greater than %f\n",z9,z10);
    else
        printf("%f and %f are not comparable\n",z9,z10);
    printf("In hex, %f = %08x\n",z9,*(int *)(&z9));
    printf("In hex, %f = %08x\n",z10,*(int *)(&z10));
}
