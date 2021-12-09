#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *v1, int *v2) {
  int temp = *v1;
  *v1 = *v2;
  *v2 = temp;
}

int particao(int vetor[], int esq, int dir) {

	int pivo = vetor[dir];

	int i = (esq - 1);
	int j;

	for (j = esq; j < dir; j++) {
    	if (vetor[j] <= pivo) {
			i++;
      		trocar(&vetor[i], &vetor[j]);
    	}
  	}

	trocar(&vetor[i + 1], &vetor[dir]);

	return (i + 1);
}

void quickSort(int vetor[], int esq, int dir) {
	if (esq < dir) {

    int pivo = particao(vetor, esq, dir);
    
    quickSort(vetor, esq, pivo - 1);

    quickSort(vetor, pivo + 1, dir);
  }
}

int main(int argc, char *argv[]) {
	
	int vetor[1000];
	int c;
	
	int tam = sizeof(vetor) / sizeof(int);
	
	FILE *arq = fopen("Quick Sort.txt", "w");
	
	srand(time(NULL));
	
	fprintf(arq, "Desordenado:\n");
	printf("Desordenado:\n");
	for(c = 0; c < tam; c++) {
		vetor[c] = rand() % 2000;
		printf("%d ", vetor[c]);
		fprintf(arq, "%d ", vetor[c]);
	}

	printf("\n\n");
  	
	quickSort(vetor, 0, tam - 1);
	
	fprintf(arq, "\n\nOrdenado:\n");
	printf("Ordenado:\n");
	for(c = 0; c < tam; c++) {
		printf("%d ", vetor[c]);
		fprintf(arq, "%d ", vetor[c]);
	}
	
	fclose(arq);
	
	return 0;
}
