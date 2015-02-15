/*demo program 1: table of values of square root
*/
#include <stdio.h>
#include <math.h>
main(){
    int i; /* loop index; value to be enumerated */
    int j;
    for( i = 1; i<=10; i++) {
        printf("%4d %10.3lf\n", i, sqrt(i));
    }

    printf("i = %d\n",i);
    printf("j = %d\n",j);
    
    
    //double x[25];
    //int l;
    
    //for (l=0; l<25; l++){
       // x[l] = l*10+34;
    //}

    /*char c;
    while((c = getchar()) != EOF){
        printf("c = %c\n",c);
}
*/

}

