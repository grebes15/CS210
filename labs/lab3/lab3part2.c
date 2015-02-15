#include <stdio.h>
#define MAXSTRING 20 //the maxstring will be 20 characters

main(){

char x[MAXSTRING];//call in the max string for x
char y[MAXSTRING];//call in the max string for y

printf("First name: ");
scanf("%s", x); //scan in the string of x to be the first name

printf("Last name: "); 
scanf("%s", y); //scan in the string of y to be the last name

printf("Hello, %s %s!\n", x, y); //print out the strings of x and y that I have scanned in

}
