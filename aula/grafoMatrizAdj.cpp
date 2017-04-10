/*Operações sobre Grafo direcionado.*/

#include <stdio.h>
#include <stdlib.h>


void inicializarMatriz (int matriz[5][5]) {
	int i, j;
	for (i = 0; i < 5; i++) 
		for (j = 0; j < 5; j++) {
			matriz[i][j] = 0;
		}

}


void inserir (int matriz[5][5], int orig, int dest) {
	matriz[orig][dest] = 1;
}


bool temAresta (int matriz[5][5], int orig, int dest) {
	if (matriz[orig][dest] == 1) return true;
	else return false;
}

void imprimir (int matriz[5][5]) {
	
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf ("\n");
	}
}


int Gsaida (int m[5][5], int i) {
	int j, resp = 0;
	for (j = 0; j < 5; j++)
		if (m[i][j] == 1) resp++;

	return resp;
}


int Gentrada (int matriz[5][5], int j) {
	int i, resp = 0;
	for (i = 0; i < 5; i++) 
		if (matriz[i][j] == 1) resp++;

	return resp;
}


int main () {

	int matriz[5][5];
	
	inicializarMatriz (matriz);

	inserir (matriz, 0, 1);
	inserir (matriz, 0, 4);
	inserir (matriz, 1, 2);
	inserir (matriz, 1, 3);
	inserir (matriz, 2, 0);
	inserir (matriz, 2, 4);
	inserir (matriz, 3, 2);
	inserir (matriz, 3, 4);
		
	bool result = temAresta (matriz, 1, 3);
	printf("Tem aresta? %d\n", result);
	printf("%d\n", Gsaida (matriz, 2));
	printf("%d\n", Gentrada (matriz, 4));

	imprimir (matriz);
	

	return 0;
}