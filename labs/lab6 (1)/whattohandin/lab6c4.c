#include <stdio.h>

main(){
	float eps;
	eps = 1.0;
	while (eps + 1.0 != 1.0) {

		eps = eps / 2.0;
	}
	printf("The Smallest Positive Integer that can added to 1 without changing its value is %e\n", eps);

	if((1.0 + eps) + eps == 1.0 + (eps + eps)){
		printf("The two expressions are equal \n");
	}else{
		printf("The two expressions are not equal \n");
	}



}