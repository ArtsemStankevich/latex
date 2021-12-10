#include <stdio.h>
#include <math.h>

double find_roots(double a, double b, double c, double from, double to, int k);


int main(){
	double a=4, b=4, c=1, from=1, to=6, k=1;
	find_roots(a, b, c, from, to, k);
	
	
	
	
	
	
}

double find_roots(double a, double b, double c, double from, double to, int k)
{
	double b1, x1, x2, x;
	int results[6];
	b1 = b*b ;
	double d = b1 - 4*a*c;
	if (d > 0){
	x1 = (-b + sqrt(d))/(2 * a);
	x2 = (-b - sqrt(d))/(2 * a);
    int results[]={a, b, c, d, b1, x1, x2};
}
    if (d == 0 ){
	x =  -b/2*a;
    int results[]={a, b, c, d, b1, x};
	
}
	if ( d < 0){
    int results[]={a, b, c, d, b1};
}

	printf("Mamy funkcje %dx^2 + %dx +%d\n", results[0], results[1], results[2]);
	printf("\\Delta = %d^2 - 4\\times%d\\times%d\n", results[1], results[0], results[2]);
	if(results[3]>0){
		printf("x_1 = \frac{-%d + \\sqrt{%d}}{2\\times%d} \n", results[1], results[3], results[0]);
		printf("x_2 = \frac{-%d - \\sqrt{%d}}{2\\times%d} \n", results[1], results[3], results[0]);
		printf("x_1 = %d\n", results[5]);
		printf("x_2 = %d\n", results[6]);
	}
	if(results[3]==0){
		printf("x = \\frac{-%d}{2\\times%d} \n", results[1], results[0]);
		printf("x = %d\n", results[5]);	
	}
	if(results[3]<0){
		printf("Niema pierwiastkow\n");	
	}
	
	
		printf("\\begin{tabular}{|c|c|} \\hline \n");
	int el1 = 0;
	int el2 = 0;
    int tab[el1][el2];
	
	for(int i=1; i<=6; i++){
		int x=i;
		int y=4*i*i + 4*i + 1;
		tab[el1][el2] = x;
		tab[el1][el2+1] = y;
		el1++;
		printf("%d & %d \\ \\hline\n", tab[el1][el2], tab[el1][el2+1]);

	}

	printf("\\end{tabular}\n");
	
	
	
	
}
