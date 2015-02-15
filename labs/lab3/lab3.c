#include <stdio.h>

main(){

int x;
int y;
int z;

printf("Enter the two values to be added: ");
scanf("%d %d", &x, &y); //scan in x and y as integer to be later on added
z = x + y;
printf("The sum of %d", x); //print out x 
printf(" and %d", y); //print out y
printf(" is %d\n", z); //print out the result when x is added to y
}
