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
    int flag; // para uso na busca em largura e profundidade, se necessario. 0=não-visitado 1=descoberto 2=concluído.
    bool aberto; // vale true se a sala em questao esta aberta
    NO* inicio;
} VERTICE;



// Protótipos das funções utilizadas no programa.
NO *caminho(int N, int A, int *ijpeso, int *aberto, int inicio, int fim, int chave);
VERTICE * criarGrafo (int N);
NO * criarNO (int vertice, int peso);
void inserirAresta (VERTICE * grafo, int A, int *ijpeso);
void imprimirListaAdjacentes (VERTICE * grafo, int N);
void iniciarVetoresAux (int * ant, int * peso, int * visitado, int N);


//Função que cria um grafo e devolve seu endereço.
VERTICE * criarGrafo (int * aberto, int N) {
	
	VERTICE * grafo; 
	grafo = (VERTICE *) malloc (sizeof (VERTICE) * (N + 1));
	int i;

	for (i = 1; i < N; i++) {
		grafo[i].inicio = NULL;
		grafo[i].aberto = aberto[i];

	} //fim do for.

	return grafo;

} //fim da função criarGrafo.


//Função que cria um novo NO e retorno seu endereço.
NO * criarNO (int vertice, int peso) {
	
	NO * novo_no = (NO *) malloc (sizeof (NO));
	novo_no->v = vertice;
	novo_no->peso = peso;
	novo_no->prox = NULL;

	return novo_no;

} //fim da função criarNO.


//Função que insere aresta no grafo não-direcionado ponderado.
void inserirAresta (VERTICE * grafo, int A, int *ijpeso) {
	
	int i, vert_in, vert_adj, peso;

	for (i = 0; i < (3 * A); i += 3) {
		vert_in = ijpeso[i];
		vert_adj = ijpeso[i+1];
		peso = ijpeso[i+2];

		NO * novo_adj = criarNO (vert_adj, peso);
		novo_adj->prox = grafo[vert_in].inicio;
		grafo[vert_in].inicio = novo_adj;


		NO * novo_adj_2 = criarNO (vert_in, peso);
		novo_adj_2->prox = grafo[vert_adj].inicio;
		grafo[vert_adj].inicio = novo_adj_2;

	} //fim do for.
	
} //fim da função inserirAresta.


//Função imprimirListaAdjacentes. Usada pra testar se estavam corretas as inserções.
void imprimirListaAdjacentes (VERTICE * grafo, int N) {
	
	int i;
	for (i = 1; i <= N; i++) {
		NO * p = grafo[i].inicio;
		
		printf ("Vertice: %d\n", i);
		while (p != NULL) {
			printf("Adjacentes: %d, peso %d ", p->v, p->peso);
			p = p->prox;

		} //fim do while.

		printf("\n");

	} //fim do for

} //fim da função imprimirListaAdjacentes.


//Função iniciarVetoresAux.
void iniciarVetoresAux (int * ant, int * peso, int * visitados, int N) {

	int i;
	for (i = 1; i <= N; i++) {
		ant[i] = - 1;
		peso[i] = -1;
		visitados[i] = 0;

	} //fim do for.

} //fim da função iniciarVetoresAux.


//Devolve o número de arestas que saem do vértice.
int grauSaida (VERTICE * grafo, int i) {
	
	int resp = 0;
	NO * p = grafo[i].inicio;
	while (p) {
		resp++;
		p = p->prox;
	}
	return resp;

} //fim da função grauSaida.


//Função buscarMenosAdjacente. Retorno a posição do menor caminho.
int buscarMenorAdjacente (int * peso, int * ant, int * visitados, int N) {

	int i, primeiro = 1, menor = -1;
	for (i = 1; i <= N; i++) {
		if (peso[i] >= 0 && visitados[i] == 0) {
			if (primeiro) {
				menor = i;
				primeiro = 0;

			} else {
				if (peso[menor] > peso[i]) menor = i;

			} //fim do if else.

		} //fim do if.

	} //fim do for.

	return menor;

} //fim da função buscarMenorAdjacente.


//Função que vai gerar o menor caminho.
void menorCaminho (VERTICE * grafo, int vert_in, int * ant, int * peso, int * visitados, int N) {

	int i, cont, vert_u, grau_saida, indice;
	cont = N;
	//Inicializando os vetores auxiliares ant, peso e visitados.
	iniciarVetoresAux (ant, peso, visitados, N);

	//Vértice inicial recebe peo 0;
	peso[vert_in] = 0;

	while (cont > 0) {
		vert_u = buscarMenorAdjacente (peso, ant, visitados, N);

		visitados[vert_u] = 1;
		cont--;

		grau_saida = grauSaida (grafo, vert_u);

		NO * p = grafo[vert_u].inicio;

		for (i = 0; i < grau_saida; i++) {
			
			indice = p->v;
			if (peso[indice] < 0) {
				peso[indice] = peso[vert_u] + p->peso;
				ant[indice] = vert_u;

			} else {
				if (peso[indice] > peso[vert_u]) {
					peso[indice] = peso[vert_u] + p->peso;
					ant[indice] = vert_u;

				} //fim do if.

			} //fim do if else.

			p = p->prox; //atualizando o prox.

		} //fim do for.

		//...

	} //fim do while.

} //fim da função menorCaminho.




//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
NO *caminho(int N, int A, int *ijpeso, int *aberto, int inicio, int fim, int chave) {
	
	NO* resp;
	resp = NULL;

	//seu codigo AQUI//

	//Instanciando e criando o grafo.
	VERTICE * grafo = criarGrafo (aberto, N); 
	int * ant = (int *) malloc (sizeof (int)); //vetor de anteriores.
	int * peso = (int *) malloc (sizeof (int)); //vetor de pesos.
	int * visitados = (int *) malloc (sizeof (int)); //vetor de vértices visitados.
	
	//Inserindo as arestas no grafo.
	inserirAresta (grafo, A, ijpeso);

	menorCaminho (grafo, inicio, ant, peso, visitados, N);


	//imprimirListaAdjacentes (grafo, N);

	int b;
	for (b = 0; b < N; b++) {
		printf("Vetor aberto: %d\n", aberto[b]);
	}

	

	int a;
	for (a = 1; a <= N; a++) {
		printf("Anteriores: %d - Pesos: %d - Visitados: %d - Vertice aberto: %d\n", 
			ant[a], peso[a], visitados[a], grafo[a].aberto);
	}

	//.................//



	return resp;

} //fim da função caminho.



//---------------------------------------------------------
// use main() para fazer chamadas de teste ao seu programa
//---------------------------------------------------------
int main() {


	// aqui vc pode incluir codigo de teste
	// exemplo de teste trivial
	int N=6; // grafo de 3 vértices 1..3
	int A=9; // número de arestas
	int aberto[] = {1,1,1,1,1,1}; // todos abertos
	int inicio=1; // vértice inicial
	int fim=3; // vértice final
	int chave=2; // chave para abrir as portas
	int ijpeso[]={1,2,4, 1,3,2, 2,3,1, 2,4,5, 3,4,8, 3,5,10, 4,5,2, 4,6,6, 5,6,2}; //
	
	// o EP sera testado com uma serie de chamadas como esta
	NO* teste = NULL;
	teste = caminho(N, A, ijpeso, aberto, inicio, fim, chave);
	



	/////////

	return 0;
}

// por favor nao inclua nenhum código abaixo da função main()

