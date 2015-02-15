/*Andreas Landgrebe
November 19, 2013
Part 3 of the Take Home Exam
This C program will input 2 intger values and determine how many bits these two values have in common.
*/

#include <stdio.h>
#include <math.h>

main(){
	int i1; //read in the first integer
	int i2; //read in the second integer
	printf("Please enter the first interger: ");
	scanf("%d", &i1); //scans the first integer by looking at the address of the i1 interger value being scanned in.
	printf("Please enter the second integer: ");
	scanf("%d", &i2); //scans the second integer by lookingat the address of the i2 integer value being scanned in 

	
	printf("%x %x \n", i1, i2); //prints the hexadecimal of i1 and i2
	int countcommon = 0; //
	int mask = 1; //
	int position; //counter to change the position
	for(position = 0; position <= 31; position++){ //counter to be able to chagne the bit postion of the integers being read in.
		if(((i1 ^ i2) & mask) == 0){ //if i1 xor i2 and mask is equal to zero, then the bits are equal to each other.
			countcommon++; 
		}
		mask = mask << 1; //change the bit position
	}
	printf("%d and %d have %d bits in common", i1, i2, countcommon);
	//prints out the 2 intergers being read in and how many bits they are in common. 
	printf("\n"); //create a new line
}


