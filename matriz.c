#include <stdio.h>

int main(){
	const int quant_alunos=4, quant_notas=3;
	int i, j;
	float notas[quant_alunos][quant_notas];
	printf("Preenchimento das notas:\n");
	for(i=0; i<quant_alunos; i++){
		printf("\tAluno %d: \n", i+1);
		for (j=0; j<quant_notas; j++){
			printf("Notas %d: ", j+1);
			scanf("%f", &notas[i][j]);
		}
	}
	printf("Impressão das Notas:\n");
	for(i=0; i<quant_alunos; i++){
		printf("\tAluno %d: \n", i+1);
		for (j=0; j<quant_notas; j++){
			printf("Notas %d: ", j+1);
			printf("%5.1f ", notas[i][j]);
		}
		printf("\n");
	}
	return 0;
}