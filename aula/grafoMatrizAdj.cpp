/*Operações sobre Grafo direcionado.*/

#include <stdio.h>
#include <stdlib.h>

#define DIM 4

void inicializarMatriz (int matriz[DIM][DIM]) {
	int i, j;
	for (i = 0; i < DIM; i++) 
		for (j = 0; j < DIM; j++) {
			matriz[i][j] = 0;
		}

}


void inserir (int matriz[DIM][DIM], int orig, int dest) {
	matriz[orig][dest] = 1;
}


bool temAresta (int matriz[DIM][DIM], int orig, int dest) {
	if (matriz[orig][dest] == 1) return true;
	else return false;
}

void imprimir (int matriz[DIM][DIM]) {
	
	int i, j;
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf ("\n");
	}
}


int Gsaida (int m[DIM][DIM], int i) {
	int j, resp = 0;
	for (j = 0; j < DIM; j++)
		if (m[i][j] == 1) resp++;

	return resp;
}


int Gentrada (int matriz[DIM][DIM], int j) {
	int i, resp = 0;
	for (i = 0; i < DIM; i++) 
		if (matriz[i][j] == 1) resp++;

	return resp;
}

void excluiArestas (int matriz[DIM][DIM], int i, int j) {
	matriz[i][j] = 0;
}



int main () {

	int matriz[DIM][DIM];
	
	//Inicializando a matriz com zeros.	
	inicializarMatriz (matriz);

	/*Inserindo arestas no grafo. Cada posição na matriz 
	representa uma aresta.*/
	inserir (matriz, 0, 1);
	inserir (matriz, 0, 2);
	inserir (matriz, 1, 2);
	inserir (matriz, 1, 3);
	inserir (matriz, 2, 3);
	inserir (matriz, 3, 0);
		
	
	//Verifica se existe aresta enter os vértices 1 e 3.
	bool result = temAresta (matriz, 1, 3);
	printf("Tem aresta?\n");
	if (result != 0) {
		printf("Sim, tem aresta\n");
	}
	
	/*Imprimindo graus de saída e entrada dos vértices 
	passados como parâmetro.*/
	printf("%d\n", Gsaida (matriz, 2));
	printf("%d\n", Gentrada (matriz, 4));

	//Imprime a matriz.
	imprimir (matriz);
	printf("\n");

	//Excluir aresta entre os vértices 2 e 4.
	excluiArestas (matriz, 2, 4);


	//Verifica a existência de aresta, novamente.
	result = temAresta (matriz, 4, 2);
	printf("Tem aresta?\n");
	if (result != 0) 
		printf("Sim, tem aresta\n");
	else printf("Não, não possui aresta\n");
	

	//Imprima a matriz.
	imprimir (matriz);
	

	return 0;
}