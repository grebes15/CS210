/*
Andreas Landgrebe
November 18, 2013
Part 5 of the Take Home Exam
This program will write a C program that creates a double array called f which has the size of 21. The array represents the tabulated values of the function f(x) at 21 consecutive integer values.
This program will also hold a function called fill that will take a double f and two int parameters called low and high. The low and high values represent the range of integers being listed. Then create double pointer varible called f2 and set it equal to an address obtained by adding to f's address.
*/



#include <stdio.h>
#include <math.h>

main(){

  void fill(double f[], int low, int high){

    double * f2; //declaring the f2 pointer
    f2 = &f[-low]; //assigned f2 to the address of the array f[-low]
    int x; //declaring an integer
    for(x = low; x <=high; x++){ // x will go through the low to the value of high 
      f2[x] =(double)x * sin(x) + x * cos(x); //f2[x] is equal to the double of x*sin(x) + x*cos(x) which changes the orignal f since f2 is assigned to the address of f[-low]

    } 
  }

  double f [21]; //declaring the size of the array f.
  int low = -5; //declaring the size of low.
  int high = 15; //declaring the size of high.
  int x;
  fill(f, low, high); //calling the fill function with the assigned values listed before.
	
  printf("  x     f(x)\n"); //prints the format for the output
  printf("----- ----------\n"); //prits the format for the output
  for(x = low; x <= high; x++){ //x goes through the values of low to the values of high
    printf("%d      %f\n",x,f[x-low]); //prints the format of the integers of x and doubles of f[x-low] 
  } 

}
