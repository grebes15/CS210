/*Andreas Landgrebe
Part 2 of Laboratory Assignment # 6
October 28, 2013
Roundoff Error
This C program will show what the smallest positive integer that can added to 1 without changing its value */
#include <stdio.h>

main(){
	float eps;
	eps = 1.0;
	while (eps + 1.0 != 1.0) { //as long as eps + 1 is not equal to 1, then the eps will keep on getting smaller until when it is added, 1 will change its value

		eps = eps / 2.0;
	}
	printf("The Smallest Positive Integer that can added to 1 without changing its value is %e\n", eps); //display the smallest positive interger that can be added to 1 without changing its value in an exponent form.

}
