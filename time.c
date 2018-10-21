#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

void preenche_vetor(int tam, float *vet){
  for(int i=0; i<tam; i++){
    vet[i] = ((float)rand())/(INT_MAX);
  }
}

void imprime_vetor(int tam, float *vet){
  for(int i=0; i<tam; i++){
    printf("%.2f ", vet[i]);
  }
  printf("\n");
}

void copia_vetor(int tam, float *vetA, float *vetB){
	int i;
	for(i=0; i<tam; i++){
		vetB[i] = vetA[i];
	}
}

void bubble_sort(int tam, float *vet){
  float aux;
  for(int i=0; i<tam-1; i++){
    for(int j=0; j<tam-1; j++){
      if(vet[j]>vet[j+1]){
        aux = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = aux;
      }
    }
  }
}

void direct_sort(int tam, float *vet){
  float aux;
  int min;
  for(int i=0; i<tam-1; i++){
    min = i;
    for(int j=i+1; j<tam; j++){
      if(vet[min]>vet[j]){
        min = j;
      }
    }
    aux = vet[i];
    vet[i] = vet[min];
    vet[min] = aux;
  }
}

void merge(int tam, float *vet){
  int tamA, tamB, i=0, j=0;
  float *vetA, *vetB, aux;
  tamA = tam/2+tam%2;
  tamB = tam/2;
  vetA = vet;
  vetB = vet+tamA;
  while(i<tamA && j<tamB){
    if(vetA[i]>vetB[j]){
      aux = vetB[j];
      for(int k=tamA+j; k>i+j; k--){
        vet[k] = vet[k-1];
      }
      vet[i+j] = aux;
      j++;
      vetA++;
    } else i++;
  }
}

void merge_sort(int tam, float *vet){
  if(tam>1){ 
    int m = tam/2;
    merge_sort(m+tam%2, vet);
    merge_sort(m, vet+m+tam%2);
    merge(tam, vet); 
  }
} 

int main(void){
int tam;
float *vet, *vet2, *vet3;

printf("    ________________________________________________________\n");
printf("   |                                                        |\n");
printf("   |             *****Tempos de execução******              |\n");
printf("   |--------------------------------------------------------|\n");
printf("   |    Tam.    |    MERGE    |    DIRECT    |    BUBBLE    |\n");
printf("   |------------|-------------|--------------|--------------|\n");



tam = 1000;
vet = malloc(sizeof(float) *tam);
vet2 = malloc(sizeof(float) *tam);
vet3 = malloc(sizeof(float) *tam);
preenche_vetor(tam, vet);
copia_vetor(tam, vet, vet2);
copia_vetor(tam, vet, vet3);
printf("   |     %d   |    ", tam);

clock_t tempomm;
tempomm = clock();
merge_sort(tam, vet3);
printf("%f |    ", (clock() - tempomm) / (double)CLOCKS_PER_SEC);

clock_t tempomd;
tempomd = clock();
direct_sort(tam, vet2);
printf("%f  |     ", (clock() - tempomd) / (double)CLOCKS_PER_SEC);

clock_t tempomb;
tempomb = clock();
bubble_sort(tam, vet);
printf("%f |\n", (clock() - tempomb) / (double)CLOCKS_PER_SEC);


tam = 10000;
vet = malloc(sizeof(float) *tam);
vet2 = malloc(sizeof(float) *tam);
vet3 = malloc(sizeof(float) *tam);
preenche_vetor(tam, vet);
copia_vetor(tam, vet, vet2);
copia_vetor(tam, vet, vet3);
printf("   |    %d   |    ", tam);

clock_t tempodm;
tempodm = clock();
merge_sort(tam, vet3);
printf("%f |    ", (clock() - tempodm) / (double)CLOCKS_PER_SEC);

clock_t tempodd;
tempodd = clock();
direct_sort(tam, vet2);
printf("%f  |     ", (clock() - tempodd) / (double)CLOCKS_PER_SEC);

clock_t tempodb;
tempodb = clock();
bubble_sort(tam, vet);
printf("%f |\n", (clock() - tempodb) / (double)CLOCKS_PER_SEC);


tam = 100000;
vet = malloc(sizeof(float) *tam);
vet2 = malloc(sizeof(float) *tam);
vet3 = malloc(sizeof(float) *tam);
preenche_vetor(tam, vet);
copia_vetor(tam, vet, vet2);
copia_vetor(tam, vet, vet3);
printf("   |   %d   |    ", tam);

clock_t tempocm;
tempocm = clock();
merge_sort(tam, vet3);
printf("%f |   ", (clock() - tempocm) / (double)CLOCKS_PER_SEC);

clock_t tempocd;
tempocd = clock();
direct_sort(tam, vet2);
printf("%f  |    ", (clock() - tempocd) / (double)CLOCKS_PER_SEC);

clock_t tempocb;
tempocb = clock();
bubble_sort(tam, vet);
printf("%f |\n", (clock() - tempocb) / (double)CLOCKS_PER_SEC);


tam = 1000000;
vet = malloc(sizeof(float) *tam);
vet2 = malloc(sizeof(float) *tam);
vet3 = malloc(sizeof(float) *tam);
preenche_vetor(tam, vet);
copia_vetor(tam, vet, vet2);
copia_vetor(tam, vet, vet3);
printf("   |  %d   |  ", tam);

clock_t tempommm;
tempommm = clock();
merge_sort(tam, vet3);
printf("%f | ", (clock() - tempommm) / (double)CLOCKS_PER_SEC);

clock_t tempommd;
tempommd = clock();
direct_sort(tam, vet2);
printf("%f  | ", (clock() - tempommd) / (double)CLOCKS_PER_SEC);

clock_t tempommb;
tempommb = clock();
bubble_sort(tam, vet);
printf("%f |\n", (clock() - tempommb) / (double)CLOCKS_PER_SEC);


printf("\n   |____________|_____________|______________|______________|\n");
return 0;
}
