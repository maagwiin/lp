#include <stdio.h>
#include <stdlib.h>

void preenche_vetor(int tam, float *vet){
	int i;
	for(i=0; i<tam; i++){
		printf("Digite o %dº valor:", i+1);
		scanf("%f", &vet[i]);
	}
}

void imprime_vetor (int tam, float *vet){
	int i;
	for(i=0; i<tam; i++){
		printf(" %.0f  ", vet[i]);
	}
	printf("\n");
}

float soma_vetor (int tam, float *vet){
	float soma=0;
	int i;
	for(i=0; i<tam; i++){
		soma=soma + vet[i];
	}
	return soma;
}

float media_vetor (int tam, float *vet){
	float media=0;
	media = soma_vetor(tam, vet)/tam;
	return media;
}

void ordena_vetor(int tam, float *vet){
	int i, j, menor, troca;
  for (i=0; i<tam; i++){
    menor = i;
    for (j = (i+1); j<=tam; j++) {
      if(vet[j] > vet[menor]) {
        menor = j;
      }
    }
    if (i != menor) {
      troca = vet[i];
      vet[i] = vet[menor];
      vet[menor] = troca;
    }
  }
}

void mescla_vetor(int tam, float *vet, int tamA, float *vetA, int tamB, float *vetB){
	int i=0, j, k;
	while(i<=tam){
		for(j=0; j<tamA; j++, ++i){
			vet[i]=vetA[j];
		}
		for(k=0; k<tamB; k++, ++i){
			vet[i]=vetB[k];
		}
	}
}




int main(void) {
 /*
  int tam;
	float *vet;
	printf("Digite o tamanho do vetor:");
	scanf ("%d",&tam);
	vet= malloc (sizeof(float) *tam);
	preenche_vetor(tam, vet);
	imprime_vetor(tam, vet);
	printf("soma: %.2f \n",soma_vetor(tam,vet));
	printf("media: %.2f \n", media_vetor(tam,vet));
*/

	int tamA, tamB, tamC;
	float *vetA, *vetB, *vetC;
	printf("\n\nDigite o tamanho do 1º vetor: ");
	scanf("%d", &tamA);
	vetA = malloc(sizeof(float)*tamA);
	preenche_vetor(tamA,vetA);
	imprime_vetor(tamA,vetA);
	printf("\nDigite o tamanho do 2º vetor: ");
	scanf("%d", &tamB);
	vetB = malloc(sizeof(float)*tamB);
	preenche_vetor(tamB,vetB);
	imprime_vetor(tamB,vetB);
	ordena_vetor(tamA,vetA);
	ordena_vetor(tamB,vetB);
	tamC=tamA+tamB;
	printf("%d\n", tamC);
	vetC = (float *)malloc(sizeof(float)*tamC);
	mescla_vetor (tamC,vetC,tamA,vetA,tamB,vetB);
	//ordena_vetor(tamC,vetC);
	imprime_vetor (tamC,vetC);
	return 0;
}