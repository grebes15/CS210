/*Andreas Landgrebe
Computer Science 210 Fall 2013
Lab 2
printing out values from 0 to 50 in reverse binary*/
#include <stdio.h>

void printbinary(int i){
        while (i > 0){
    if (i % 2 != 0) 
        printf("1");
        else
            printf("0");
            i = i / 2;
        }
}
            main(){
                int j;
                for(j = 0; j <= 50; j++){
            printf("\n" "The value of %d in reverse binary is ",j);
            printbinary(j);
}
            }

