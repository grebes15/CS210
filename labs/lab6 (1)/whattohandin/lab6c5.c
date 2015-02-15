#include <stdio.h>

main() {

	float factorialFloat(float x){
		if(x<=1.0)
			return(1.0);
		else
			x = x * factorialFloat(x - 1.0);
		return x;
	}

		float a;
		a = factorialFloat(30.0);
		float b;
		b = factorialFloat(30.0);
		float c;
		c = -factorialFloat(30.0);
		if(a*(b + c) == a*b + a*c){
			printf("%e\n",a*(b+c));
			printf("The distributibe law holds \n");
		}else{
			printf("The distributive law does not hold \n");
	}

}