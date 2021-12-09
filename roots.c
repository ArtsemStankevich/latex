#include <stdio.h>
#include <math.h>

double roots(double, double, double);

int main(){
	int a =12;
	int b = 41;
	int c = 412;

	roots(a,b,c);


}
doble roots(double a, double b, double c)
{
	int a, b,c, b1, x1, x2, x;
	b1 = b*b ;
	double D = b1 - 4*a*c;
	if (D > 0){
	x1 = (-b + sqrt(D))/(2 * a);
	x2 = (-b - sqrt(D))/(2 * a);
	
}
    if (D == 0 ){
	x =  -b/2*a;
	
}
	if ( D < 0){
	printf("%d %d",x1,x2);
}
}
}
