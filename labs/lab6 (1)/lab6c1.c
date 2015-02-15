#include<stdio.h>


void printbinary(int i){
        while (i > 0){
    if (i % 2 != 0) 
        printf("1");
        else
            printf("0");
            i = i / 2;
        }
}

void printhexadecimal(float x) {

printf("0x%08X, %f\n", *(int *)&x, x);

}
            main(){
float x;
float y;

printf("Enter a float value: ");
scanf("%f", &x);

printbinary(5);


printhexadecimal(5);

}
