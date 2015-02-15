//Andreas Landgrebe
//Part 5 of the Computer Science 210 Final Project
//This C program will be able to list mips assembly language as output from a list of coordinates given in a text file. In the terminal, I have written the command: ./Part5 <Part5Coordinates.txt so my code will print out mips instruction from the list of coordinates in the text file.



#include <stdio.h>

main(){


	int x; //x coordinate
	int y; //y coordinate
	int penUp = 0;
	while(scanf("%d %d ", &x, &y) == 2){ 
		    if (penUp == 0){ //If it the first list of coordinate being called, print out to go to the first vertex.
			printf("main: \n");
			printf("\t\t# Get to first vertex, (%d,%d)\n",x,y);//print out the first list of instructions
		}else{
			printf("\n");
			printf("\t\t# Now draw to (%d,%d) \n",x,y); //print out the rest of the list of instructions with Now draw to instead of writing Get to first vertex.	
		}

			printf("\tli \t $a0,%d \n", x);
			printf("\tli \t $a1,%d \t \n", penUp); //the penUp will write either a 0 or 1 depending on whether to draw a line or not.
			printf("\tjal \t horiz \n");
			printf("\n");
			printf("\tli \t $a0,%d \n", y);
			printf("\tli \t $a1,%d \t \n", penUp); //the penUp will write either a 0 or 1 depending on whether to draw a line or not.
			printf("\tjal \t vert \n");
			

			penUp = 1; //change the value of penUp to 1 instead of 0, so the value of a1 will be 1 to be able to draw a line in mips. 

	}

	printf("\tli \t $v0,10 \n");
	printf("\tsyscall \n");
}
