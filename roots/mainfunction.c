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

    double roots[1];
    int roots_num;

    double from;
    double to;

    double table[50][2];
};

int main(){
	double a, b, c, from, to, k;
	scanf("%lf", &a);
	scanf("%lf", &b);
	scanf("%lf", &c);
	scanf("%lf", &from);
	scanf("%lf", &to);
	scanf("%lf", &k);
	struct result res = find_roots(a, b, c);
	calculate(&res, from, to, k);
print_latex(res);
}

struct result find_roots(double a, double b, double c)
{
    double roots[2];
    int roots_num=0;
	double d = b*b - 4*a*c;
	if (d > 0){
        roots[0] = (-b + sqrt(d))/(2 * a);
        roots[1] = (-b - sqrt(d))/(2 * a);
        roots_num=2;
    }else if(d == 0 ){
        roots_num=1;
        roots[0] =  -b/2*a;
    }else{
        roots_num=0;
    }
    struct result results = {a,b,c,d};
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

    //use structure definition write function for print result in latex markup;
    //THERE

    // printf("a=%lfb=%lf, root1=%lf", results.a, results.b, results.table[0][0]); //example


	printf("Mamy funkcje %.1fx^2 + %.1fx + %.1f\n", results.a, results.b, results.c);
	printf("\\Delta = %.1f^2 - 4\\times%.1f\\times%.1f\n", results.b, results.a, results.c);
	if(results.roots_num==2){
		printf("x_1 = \frac{-%.1f + \\sqrt{%.1f}}{2\\times%.1f} \n", results.b, results.d, results.a);
		printf("x_2 = \frac{-%.1f - \\sqrt{%.1f}}{2\\times%.1f} \n", results.b, results.d, results.a);
		printf("x_1 = %.1f\n", results.roots[0]);
		printf("x_2 = %.1f\n", results.roots[1]);
	}
	if(results.roots_num==1){
		printf("x = \\frac{-%.1f}{2\\times%.1f} \n", results.b, results.a);
		printf("x = %.1f\n", results.roots[0]);	
	}
	if(results.roots_num==0){
		printf("Niema pierwiastkow\n");	
	}




  //example for print table
  // for(int i=0;i<=to;i++){
  // printf("%lf %lf\n", results->table[i][0],  results->table[i][1]);
  //  }
    
    
    printf("\\begin{tabular}{|c|c|} \\hline \n");
	
	
	for(int i=0;i<=results.to;i++){
    printf("%.1f %.1f \\ \\hline\n", results.table[i][0], results.table[i][1]);

	}

	printf("\\end{tabular}\n");
	
	
	
	
}

    
   
