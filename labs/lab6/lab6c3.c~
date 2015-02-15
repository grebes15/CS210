#include <stdio.h>

main() {

 	unsigned long factorial (unsigned long x) {

		if (x<=1)
			return(1);
		else
			x=x*factorial(x-1);
		return(x);
	}

	float factorialFloat(float x){
		if(x<=1.0)
			return(1.0);
		else
			x = x * factorialFloat(x - 1.0);
		return x;
	}
	unsigned long x;
	x = 1;
	while(factorial(x) / x == factorial(x-1)){
		x++;
	}
	x--;
		printf("Here is the factorial numbers before it breaks %d is %u\n", x, factorial(x));
		int i;
		for(i = 1; i <= 36; i++){
			printf("%d: %f\n", i, factorialFloat(i));
		}

		float r;
		r = 1.0;
		while(factorialFloat(r) / r == factorialFloat(r -1.0)) {

			r++;
		}
		r--;
		printf("Here is the float factorial number before the precision breaks %f is %e\n", r, factorialFloat(r));
}
