//Atividades 1-10 de matriz

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

float** aloca_mat_float(int lin, int col){
	int i;
	float** mat;
	mat = malloc(sizeof(float*)*lin);
	for(i=0; i<lin; i++){
		mat[i]=malloc(sizeof(float)*col);
	}
	return mat;
}

void ler_matriz(float** mat, int lin, int col){
	srand(time(NULL));
	int i, j;
	for(i = 0; i < lin; i++){
		for (j = 0; j < col; j++){
			mat[i][j] = ((float)(rand()%10));
		}
	}
}

void imprime_matriz(float** mat, int lin, int col){
	int i, j;
	for(i = 0; i < lin; i++){
		printf("\t");
		for (j = 0; j < col; j++){
			printf("%.0f ", mat[i][j]);
		}
	printf("\n");
	}
}

float somadpq(float** mat, int ind){
	float soma = 0;
	int i;
		for(i=0; i<ind; i++){
			soma = soma + mat[i][i];
		}
	return soma;
}

float somadsq(float** mat, int ind){
	float soma = 0;
	int i, j=ind-1;
		for(i=0; i<ind; i++, j--){
			soma = soma + mat[i][j];
		}
	return soma;
}

void media_linha(float** mat, float* vet, int lin, int col){
	int i, j;
	float soma, media;
	for(i=0; i<lin; i++){
		soma=0;
		media=0;
		for(j=0; j<col; j++){
			soma = soma+mat[i][j];
		}
		media = (float)(soma/col);
		vet[i] = media;
	}
}

void media_coluna(float** mat, float* vet, int lin, int col){
	int i, j;
	float soma, media;
	for(i=0; i<col; i++){
		soma=0;
		media=0;
		for(j=0; j<lin; j++){
			soma = soma+mat[i][j];
		}
		media = (float)(soma/lin);
		vet[i] = media;
	}
}

void imprime_vetor(float* vet, int tam){
	int i;
	for(i=0; i<tam; i++){
		printf("%.2f ", vet[i]);
	}
	printf("\n");
}

void soma_linhas(float** mat, int col, int indA, int indB){
	int j;
	for(j=0; j<col; j++){
		mat[indA-1][j]=mat[indA-1][j]+mat[indB-1][j];
	}
}

void soma_colunas(float** mat, int lin, int indA, int indB){
	int i;
	for(i=0; i<lin; i++){
		mat[i][indA-1]=mat[i][indA-1]+mat[i][indB-1];
	}
}

float** soma_matrizes(float** matA, float** matB, int lin, int col){
	float** soma;
	soma = aloca_mat_float(lin, col);
	int i, j;
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			soma[i][j]=matA[i][j]+matB[i][j];
		}
	}
	return soma;
}

void multiplica_matriz_escalar(float** mat, int lin, int col, float escalar){
	int i, j;
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			mat[i][j]=mat[i][j]*escalar;
		}
	}
}

float** multiplica_matrizes(float** matA, int linA, int colA, float** matB, int linB, int colB){
	int i, j, k;
	float somap;
	float** produto;
	produto = aloca_mat_float(linA, colB);
	for(i=0; i<linA; i++){
		for(j=0; j<colB; j++){
			somap=0;
			for(k=0; k<colA; k++){
				somap=somap+matA[i][k]*matB[k][j];
			}
			produto[i][j]=somap;
		}
	}
	return produto;
}

float** transposta(float** mat, int lin, int col){
	float** transp;
	transp = aloca_mat_float(col, lin);
	int i, j;
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			transp[j][i]=mat[i][j];
		}
	}

	return transp;
}

void libera_matriz(float** mat, int lin){
	int i;
	for(i=0; i<lin; i++){
		free(mat[i]);
	}
	free(mat);
}

int main(){
	//1 e 2
	printf("Números 1 e 2: Soma das diagonais:\n");
	float** matriz1;
	int indice = 5;
	matriz1 = aloca_mat_float(indice, indice);
	ler_matriz(matriz1, indice, indice);
	imprime_matriz(matriz1, indice, indice);
	printf("A soma da diagonal principal é: %.0f\n", somadpq(matriz1, indice));
	printf("A soma da diagonal secundária é: %.0f\n\n", somadsq(matriz1, indice));
	libera_matriz(matriz1, indice);


	//3 e 4
	printf("Número 3 e 4: Médias:\n");
	float** matriz3;
	float* vet3;
	float* vet4;
	int lin3=5, col3=3;
	vet3 = malloc(sizeof(float)*lin3);
	vet4 = malloc(sizeof(float)*col3);
	matriz3 = aloca_mat_float(lin3, col3);
	ler_matriz(matriz3, lin3, col3);
	imprime_matriz(matriz3, lin3, col3);
	media_linha(matriz3, vet3, lin3, col3);
	media_coluna(matriz3, vet4, lin3, col3);
	printf("Médias das linhas: ");
	imprime_vetor(vet3, lin3);
	printf("Médias das colunas: ");
	imprime_vetor(vet4, col3);
	libera_matriz(matriz3, lin3);
	free(vet3);
	free(vet4);
	printf("\n");


	//5 e 6
	printf("Número 5 e 6: Somas:\n");
	float** matriz5;
	int lin5=5, col5=5, indlA=1, indlB=5, indcA=1, indcB=2;
	matriz5 = aloca_mat_float(lin5, col5);
	ler_matriz(matriz5, lin5, col5);
	imprime_matriz(matriz5, lin5, col5);
	soma_linhas(matriz5, col5, indlA, indlB);
	printf("Soma linhas %d e %d:\n", indlA, indlB);
	imprime_matriz(matriz5, lin5, col5);
	soma_colunas(matriz5, lin5, indcA, indcB);
	printf("Soma colunas %d e %d:\n", indcA, indcB);
	imprime_matriz(matriz5, lin5, col5);
	libera_matriz(matriz5, lin5);
	printf("\n");

	//7
	printf("Número 7: Soma matrizes:\n");
	float** matriz7A;
	float** matriz7B;
	int lin7=5, col7=5;
	matriz7A = aloca_mat_float(lin7, col7);
	matriz7B = aloca_mat_float(lin7, col7);
	ler_matriz(matriz7A, lin7, col7);
	printf("\tMatriz A:\n");
	imprime_matriz(matriz7A, lin7, col7);
	system("sleep 01");
	ler_matriz(matriz7B, lin7, col7);
	printf("\tMatriz B:\n");
	imprime_matriz(matriz7B, lin7, col7);
	printf("\tSoma:\n");
	imprime_matriz(soma_matrizes(matriz7A, matriz7B, lin7, col7), lin7, col7);
	libera_matriz(matriz7A, lin7);
	libera_matriz(matriz7B, lin7);
	printf("\n");

	//8
	printf("Número 8: Multiplica por escalar:\n");
	float** matriz8;
	float escalar = 2;
	int lin8=5, col8=5;
	matriz8 = aloca_mat_float(lin8, col8);
	ler_matriz(matriz8, lin8, col8);
	imprime_matriz(matriz8, lin8, col8);
	printf("Multiplicada por %.2f: \n", escalar);
	multiplica_matriz_escalar(matriz8, lin8, col8, escalar);
	imprime_matriz(matriz8, lin8, col8);
	libera_matriz(matriz8, lin8);
	printf("\n");

	//9
	printf("Número 9: Multiplica matrizes:\n");
	float** matriz9A;
	float** matriz9B;
	int lin9A=5, col9A=5, lin9B=col9A, col9B=5;
	matriz9A = aloca_mat_float(lin9A, col9A);
	matriz9B = aloca_mat_float(lin9B, col9B);
	ler_matriz(matriz9A, lin9A, col9A);
	printf("\tMatriz A:\n");
	imprime_matriz(matriz9A, lin9A, col9A);
	system("sleep 01");
	ler_matriz(matriz9B, lin9B, col9B);
	printf("\tMatriz B:\n");
	imprime_matriz(matriz9B, lin9B, col9B);
	printf("Resultado: \n");
	imprime_matriz(multiplica_matrizes(matriz9A, lin9A, col9A, matriz9B, lin9B, col9B), lin9A, col9B);
	libera_matriz(matriz9A, lin9A);
	libera_matriz(matriz9B, lin9B);
	printf("\n");	

	//10
	printf("Número 10: Transposta:\n");
	float** matriz10;
	int lin10=2, col10=5;
	matriz10 = aloca_mat_float(lin10, col10);
	ler_matriz(matriz10, lin10, col10);
	imprime_matriz(matriz10, lin10, col10);
	printf("\n\tT:\n");
	imprime_matriz(transposta(matriz10, lin10, col10), col10, lin10);
	libera_matriz(matriz10, lin10);
	printf("\n");
	return 0;
}