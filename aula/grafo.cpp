#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct no {
	int v;
	struct no * prox;
} NO;


typedef struct vertice {
	NO * inicio;
	int chave;
	//int flag;
} VERTICE;


VERTICE * criarGrafo (int v) {
	VERTICE * grafo;
	grafo = (VERTICE *) malloc (sizeof (VERTICE) * v);

	int i;
	for (i = 0; i < v; i++) {
		grafo[i].inicio = NULL;
		grafo[i].chave = i;
	}
	return grafo;
}


int GrauSaida (VERTICE * grafo, int i) {
	int resp = 0;
	NO * p = grafo[i].inicio;
	while (p) {
		resp++;
		p = p->prox;
	}
	return resp;
}


int GrauEntrada (VERTICE * grafo, int vertice, int n) {
	int i, resp = 0;
	for (i = 0; i < n; i++) {
		NO * p = grafo[i].inicio;
		while (p) {
			if (p->v == vertice) resp++;
			p = p->prox;
		}
	}
	return resp;
}


bool existeAresta (VERTICE * grafo, int i, int vert) {
	NO * lista = grafo[i].inicio;
	if (!lista) return false;
	while (lista) {
		if (lista->v == vert) return true;
		lista = lista->prox;
	}
}


NO * criarNO (int vertice) {
	NO * p = (NO *) malloc (sizeof (NO));
	p->v = vertice;
	p->prox = NULL;

	return p;
}


void inserirAresta (VERTICE * grafo, int vertice_orig, int vertice_dest) {
	bool existe = existeAresta (grafo, vertice_orig, vertice_dest);
	NO * novo = criarNO (vertice_dest);
	if (existe == 0) grafo[vertice_orig].inicio = novo;
	
	NO * p = grafo[vertice_orig].inicio;
	printf("Imprimindo p: %p\n", p);
	printf("Chave de p->v: %d\n", p->v);
	printf("Imprimindo p->prox: %p\n", p->prox);
	printf("Imprimindo grafo[vertice_orig].inicio: %p\n", grafo[vertice_orig].inicio);
	printf("Imprimindo grafo[vertice_orig].inicio->v: %d\n", grafo[vertice_orig].inicio->v);
	printf("Imprimindo grafo[vertice_orig].inicio->prox: %p\n", grafo[vertice_orig].inicio->prox);
}



void imprimirListaAdj (VERTICE * grafo, int v) {
	int i;
	NO * p = grafo[0].inicio;
	for (i = 0; i < v; i++) {
		printf("%d ", grafo[i].chave);
		printf("Ponteiro: %p\n", grafo[i].inicio);
	}
	
}


int main () {

	int n = 4, i, j;
	VERTICE * grafo;
	grafo = criarGrafo (n);

	inserirAresta (grafo, 0, 1);
	//inserirAresta (grafo, 0, 2);

	//inserirAresta (grafo, 1, 2);
	
		
	imprimirListaAdj (grafo, n);		


	return 0;
}
