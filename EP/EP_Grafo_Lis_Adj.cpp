//--------------------------------------------------------------
// NOMES DOS RESPONSÁVEIS: blablabla E blablabla
//--------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <malloc.h>

// ######### ESCREVA O NROUSP DO PRIMEIRO INTEGRANTE AQUI
char* nroUSP1() {
    //return("0000000");
}

// ######### ESCREVA O NROUSP DO SEGUNDO INTEGRANTE AQUI (OU DEIXE COM ZERO)
char* nroUSP2() {
    //return("0000000");
}


// elemento das listas de adjacência e de resposta
typedef struct estr {
    int v; // elemento
	int peso; // custo (não precisa ser usado na resposta)
    struct estr *prox;
} NO;

// vertices do grafo (salas) - use este tipo ao criar o grafo
typedef struct {
    int flag; // para uso na busca em largura e profundidade, se necessario
    bool aberto; // vale true se a sala em questao esta aberta
    NO* inicio;
} VERTICE;


// funcao principal
NO *caminho(int N, int A, int *ijpeso, int *aberto, int inicio, int fim, int chave);


//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
NO *caminho(int N, int A, int *ijpeso, int *aberto, int inicio, int fim, int chave)
{
	NO* resp;
	resp = NULL;

	// seu codigo AQUI

	//...

	return resp;
}



VERTICE * criarGrafo (int N) {
	VERTICE * grafo; 
	grafo = (VERTICE *) malloc (sizeof (VERTICE) * N);

	int i;
	for (i = 0; i < N; i++) {
		grafo[i].inicio = NULL;
		printf("Vertice %d e ponteiro %p\n", i, grafo[i].inicio);
	}

	printf("Endereço de grafo na função criarGrafo: %p\n", grafo);
	return grafo;
}


NO * criarNO (int v) {
	NO * p = (NO *) malloc (sizeof (NO));
	p->v = v;
	p->prox = NULL;

	printf("Ponteiro em criarNO %p\n", p);
	return p;
}



//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------
int main() {


	// aqui vc pode incluir codigo de teste
	VERTICE * grafo;
	int N = 4;

	grafo = criarGrafo (N);

	printf("Endereço de grafo: %p\n", grafo);

	NO * p = criarNO (3);
	printf("Ponteiro do criarNO em main: %p\n", p);

	// exemplo de teste trivial
	//int N=3; // grafo de 3 vértices 1..3
	//int aberto[] = {1,1,1}; // todos abertos
	//int inicio=1;
	//int fim=3;
	//int chave=2;
	//int ijpeso[]={1,2,10, 2,3,20, 3,1,10};
	
	// o EP sera testado com uma serie de chamadas como esta
	//NO* teste = NULL;
	//teste = caminho(N, ijpeso, aberto, inicio, fim, chave);
	
	return 0;
}

// por favor nao inclua nenhum código abaixo da função main()

