/*Andreas Landgrebe
Part 5 of Laboratory Assignment # 6
October 28, 2013
Part 2 of Laws of Arithmetic
This C program is showing that the floating point is not able to hold the distributive law. The distributive law that I am showing does not hold in floating point goes as this a(b+c) = ab + ac */

#include <stdio.h>

main() {
	//this method will figure out the facotorial numbers using a float
	float factorialFloat(float x){
		if(x<=1.0)
			return(1.0);
		else
			x = x * factorialFloat(x - 1.0);
		return x;
	}

		float a;
		a = factorialFloat(30.0); // I have stored the factorial of 30 in a
		float b;
		b = factorialFloat(30.0); // I have stored the factorial of 30 in b
		float c;
		c = -factorialFloat(30.0); // I have stored the facotorial of -30 in c. Making the C to be the the negative factorial will show the distributive law does not hold in floating numbers.
		if(a*(b + c) == a*b + a*c){ //if the distrituive if true, print out the distrituive law holds, if not true, print out that the distribuvie does not hold
			printf("%e\n",a*(b+c));
			printf("The distributibe law holds \n");
		}else{
			printf("The distributive law does not hold \n");
	}

}
