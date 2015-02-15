/*Andreas Landgrebe
Part 4 of Laboratory Assignment # 6
October 28, 2013
Part 1 of the Law of Arithmetic
In this C program, it is shown that "order matters" when adding numbers. If a particular has so many so digits in a number when the number will not be added which causes the order of the addition to matter.
*/
#include <stdio.h>

main(){
	float eps;
	eps = 1.0;
	while (eps + 1.0 != 1.0) { //while loop which checks if eps + 1 does not equal 1. If so, then eps will be equal top eps divided by 2.

		eps = eps / 2.0;
	}
	printf("The Smallest Positive Integer that can added to 1 without changing its value is %e\n", eps); //displays the small positive interger can add to 1 without changing its value

	if((1.0 + eps) + eps == 1.0 + (eps + eps)){ //if statemnet to see if order matters when adding these particular orders. If all goes well, the output should show that the expression is not equal to eachother
		printf("The two expressions are equal \n");
	}else{
		printf("The two expressions are not equal \n");
	}



}
