#include <stdio.h>
#include <math.h>

struct result find_roots(double a, double b, double c);
void print_latex(struct result results);
void calculate(struct result *results, double from, double to, double k);

struct result{
    double a;
    double b;
    double c;
    double d;
    
    double x1;
    double x2;
   

    double roots[2];

    double from;
    double to;

    double table[50][2];
};

int main(){
	double a, b, c, from, to, k;

    int roots_num=0;
	

	scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &from, &to, &k);
	struct result res = find_roots(a, b, c);
	calculate(&res, from, to, k);
print_latex(res);
}

struct result find_roots(double a, double b, double c)
{
	double x1;
	double x2;
    double roots[1];
	double d = b*b - 4*a*c;
	if (d > 0){
        roots[0] = (-b + sqrt(d))/(2 * a);
        roots[1] = (-b - sqrt(d))/(2 * a);
        x1 = roots[0];
        x2 = roots[1];
     
    }else if(d == 0 ){
        roots[0] =  -b/(2*a);
        x1 = roots[0];
    }
    
    struct result results = {a,b,c,d,x1,x2};
    return results;
}

void calculate(struct result *results, double from, double to, double k){
    double x=from;
    results->to= to;
    for(int i=0;i<=to;i++){
        results->table[i][0]= x;
        results->table[i][1]= x*x*results->a+x*results->b+results->c;
        x+=k;
    }
}


void print_latex(struct result results){
    printf("\\section{%.1fx^2+%.1f*x+%.1f}\n", results.a, results.b, results.c);
	printf("Mamy funkcje %.1fx^2 + %.1fx + %.1f\n", results.a, results.b, results.c);
	printf("\\Delta = %.1f^2 - 4\\times%.1f\\times%.1f\n", results.b, results.a, results.c);
	if(results.d>0){
		
		printf("x_1 = \\frac{-%.1f + \\sqrt{%.1f}}{2\\times%.1f} \n", results.b, results.d, results.a);
		printf("x_2 = \\frac{-%.1f - \\sqrt{%.1f}}{2\\times%.1f} \n", results.b, results.d, results.a);
		printf("x_1 = %.1f\n", results.x1);
		printf("x_2 = %.1f\n", results.x2);
		printf("\\newline\n");
		printf("Robimy sprawdzanie:\n");
		printf("\\newline\n");
		printf("%.1f\\times%.1f^2 + %.1f\\times%.1f + %.1f = 0\n", results.a, results.x1, results.b, results.x1, results.c); 
		printf("\\newline\n");
		printf("%.1f\\times%.1f^2 + %.1f\\times%.1f + %.1f = 0\n", results.a, results.x2, results.b, results.x2, results.c); 
		
		if (results.a*results.x1*results.x1+results.b*results.x1+results.c<0.1 && results.a*results.x2*results.x2+results.b*results.x2+results.c<0.1){
			printf("Poprawne rozwiazanie");
		}
		else{
			printf("Nieprawidlowe rozwiazanie");
		}
		
	}
	if(results.d==0){
		printf("x = \\frac{-%.1f}{2\\times%.1f} \n", results.b, results.a);
		printf("x = %.1f\n", results.x1);	
		printf("\\newline\n");
		printf("Robimy sprawdzanie:\n");
		printf("\\newline\n");
		printf("%.1f\\times%.1f^2 + %.1f\\times%.1f + %.1f = 0\n", results.a, results.x1, results.b, results.x1, results.c); 
		if (results.a*results.x1*results.x1+results.b*results.x1+results.c<0.1){
			printf("Prawidlowe rozwiazanie");
		}
		else{
			printf("Nieprawidlowe rozwiazanie");
		}
		
		
	}
	if(results.d<0){
		printf("Niema pierwiastkow\n");	
	}



    printf("\\newline\n");
    printf("\\begin{tabular}{|c|c|} \\hline \n");
	
	
	for(int i=0;i<=results.to;i++){
    printf("%.1f & %.1f \\", results.table[i][0], results.table[i][1]);
    printf("\\ \n");
	}
    printf("\\hline\n");
	printf("\\end{tabular}\n");
	
	printf("\\end{%.1fx^2+%.1f*x+%.1f}\n", results.a, results.b, results.c);
	
	
}

    
   

