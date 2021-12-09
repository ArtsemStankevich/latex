#include <stdio.h>
#include <math.h>

double find_roots(double a, double b, double c)
{
	double d, b1, x1, x2, x;
	b1 = b*b ;
	double d = b1 - 4*a*c;
	if (d > 0){
	x1 = (-b + sqrt(d))/(2 * a);
	x2 = (-b - sqrt(d))/(2 * a);
	int results[]=[a, b, c, d, b1, x1, x2];
}
    if (d == 0 ){
	x =  -b/2*a;
	int reults[]=[a, b, c, d, b1, x];
	
}
	if ( d < 0){
	printf("%d %d",x1,x2);
	int results[]=[a, b, c, d, b1, NULL];
}
}
}

void generate_roots_result_for_latex(int results[]){
	printf("Mamy funkcje %dx^2 + %dx +%d\n", results[0], results[1], results[2]);
	printf("\Delta = %d^2 - 4\times%d\times%d\n", results[1], results[0], results[2]);
	if(results[3]>0){
		printf("x_1 = \frac{-%d + \sqrt{%d}}{2\times%d} \n", result[1], result[3], result[0]);
		printf("x_2 = \frac{-%d - \sqrt{%d}}{2\times%d} \n", result[1], result[3], result[0]);
		printf("x_1 = %d\n", result[5]);
		printf("x_2 = %d\n", result[6]);
	}
	if(results[3]==0){
		printf("x = \frac{-%d}{2\times%d} \n", result[1], result[0]);
		printf("x = %d\n", result[5]);	
	}
	if(results[3]<0){
		printf("Niema pierwiasykow");	
	}
	
}
	
	
	
	
	
	
	
	

