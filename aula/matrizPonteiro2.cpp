#include <stdio.h>
#include <stdlib.h>



void inicializarMatriz (int *matriz[], int N) {

	int i, j;

	for (i = 0; i < N; i++) {
		matriz[i] = (int *) malloc (sizeof (int) * N);
		for (j = 0; j < N; j++) 
			matriz[i][j] = 0;
	}
}



void imprimirMatriz (int *matriz[], int N) {

	int s, d;
	for (s = 0; s < N; s++) {
		for (d = 0; d < N; d++) 
			printf("%d ", matriz[s][d]);
		printf("\n");
	}
}

int main () {
	
	int **matriz;
	int N = 5;

	matriz = (int **) malloc (sizeof (int *) * N);

	inicializarMatriz (matriz, N);
	
	matriz[1][3] = 7;

	imprimirMatriz (matriz, N);

	/*
	int s, d;
	for (s = 0; s < N; s++) {
		for (d = 0; d < N; d++) 
			printf("%d ", matriz[s][d]);
		printf("\n");
	}
	*/


	return 0;
}