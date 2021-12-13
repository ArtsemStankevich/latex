#include <stdio.h>
#include <math.h>

struct result find_roots(double a, double b, double c);
void print_roots(struct result results);
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
	double a=4.584, b=4.4, c=1, from=1.12, to=6, k=0.5;
	struct result res = find_roots(a, b, c);
	calculate(&res, -5, 5, 2.5);
print_roots(res);
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
    for(int i=0;i<=to;i++){
        results->table[i][0]= x;
        results->table[i][1]= x*x*results->a+x*results->b+results->c;
        x+=k;
    }
}


void print_latex(struct result results){

    //use structure definition write function for print result in latex markup;
    //THERE

   printf("a=%lfb=%lf, root1=%lf", results.a, results.b, results.table[0][0]); //example


   //example for print table
   for(int i=0;i<=to;i++){
    printf("%lf %lf\n", results->table[i][0],  results->table[i][1]);
    }
}
