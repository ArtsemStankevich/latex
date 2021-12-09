#include <stdio.h>
#include <math.h>

void calculate(int results[], dounle from, double to, int k){
	int array[][];
	int 1el = 0;
	printf("[");
	for(int i=from; i<=to; i+k){
		int x=i;
		int y=result[0]*i*i + result[1]*i + result[2];
		int 2el = 0;
		array[1el][2el] = x;
		array[1el][2el+1] = y;
		1el++;
		printf("[%d,%d]  ", x, y);
		
		
		
		
		
	
	}
	printf("]"); 
	
	
	
	
}

void generate_table_result_for_latex(array[][]){
	printf("\begin{tabular}{|c|c|} \hline \n");
	for (int i=from; i<=to; i+k){
		printf("%d & %d \ \hline", array[1el][2el], array[1el][2el+1]);
	}
	printf("end{tabular}");
	
}
