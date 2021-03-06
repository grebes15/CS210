#include <stdio.h>
#include <time.h>
#include <math.h>

main(){
    time_t now; /* "time_t is a special type for holding time data */

    time(&now); /* "time" get the current time */
    printf("Bob Roos\nLab 1\n%s\n",ctime(&now)); /* "ctime" formats it */
    printf("%s%10s%10s%10s%10s\n", "x", "1/(x^2)", "sqrt(n)", "log_3(n)", "1.1^x");
    printf("%s%9s%10s%11s%10s\n", "-", "-----", "-------", "--------", "-----");
    int y;
    for( y = 1; y<=32; y++){
        printf("%d", y);
        float p = (float) 1/(y*y);
        printf("%10.5f", p);
        float n = (float) sqrt(y);
        printf("%10.5f", n);
        float a = (float) log10(y)/log10(3);
        printf("%10.5f", a);
        float b = (float) pow((1.1), y);
        printf("%10.5f", b);
        printf("\n");
    }
}
