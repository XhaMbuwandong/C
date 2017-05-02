#include <stdio.h>
#include <stdlib.h>


int main () {
	
	int **matriz;
	int N = 5, i, j;

	matriz = (int **) malloc (sizeof (int *) * N);

	for (i = 0; i < N; i++) {
		matriz[i] = (int *) malloc (sizeof (int) * N);
		for (j = 0; j < N; j++) 
			matriz[i][j] = 0;
	}

	matriz[3][4] = 5;

	int s, d;
	for (s = 0; s < N; s++) {
		for (d = 0; d < N; d++) 
			printf("%d ", matriz[s][d]);
		printf("\n");
	}



	return 0;
}