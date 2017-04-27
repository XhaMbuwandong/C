/*
Author: Ricardo Goncalves Dias
*/

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>

typedef int TIPOCHAVE;

typedef struct estrutura{
    TIPOCHAVE chave;
    estrutura *esq;
    estrutura *dir;
}NO;

typedef struct{
    NO *raiz;
}Arvore;

typedef struct estrf{
        NO* a;
        estrf *prox;
}NO_FILA;

typedef struct {
        NO_FILA* inicio;
        NO_FILA* fim;
}FILA;


	//Comecam metodos da FILA
	void inicializarFILA(FILA *h){
		h->inicio = NULL;
		h->fim = NULL;
	}
	
	void entrarFILA(FILA *fila, NO* p){
		NO_FILA* novo;
		novo = (NO_FILA*) malloc(sizeof(NO_FILA));
		novo-> a = p;
		novo->prox = NULL;
		if(fila->fim) fila->fim->prox = novo;
		else fila->inicio = novo;
		fila->fim = novo;
	}
	
	NO* sairFILA(FILA *f){
		NO_FILA* aux;
		NO* ch;
		if(!f->inicio) return(NULL);
		ch = f->inicio->a;
		aux = f->inicio;
		f->inicio = f->inicio->prox;
		free(aux);
		if(!f->inicio) f->fim = NULL;
		return(ch);
	}
	//Terminam metodos da FILA
	
	void inicializar(Arvore* arvore){
		arvore->raiz = NULL;
	}
	
	NO* busca(NO* raiz, TIPOCHAVE chave, NO** pai){
		*pai = NULL;
		if(!raiz) return NULL;
		NO* p = raiz;
		while(p && p->chave != chave){
			*pai = p;
			if(p->chave > chave) p = p->esq;
			else p = p->dir;	
		}
		if(p && p->chave == chave) return p;
		else return NULL;
	}
	
	bool inserir(NO** raiz, TIPOCHAVE chave){
		NO* pai;
		if(busca(*raiz, chave, &pai)) return false;
		NO* novo = (NO*)malloc(sizeof(NO));
		novo -> chave = chave;
		novo -> esq = NULL;
		novo -> dir = NULL;
		
		if(!pai) *raiz = novo;
		else{
			if(pai->chave > chave) pai -> esq = novo;
			else pai -> dir = novo;
		}
		return true;	
	}
	
	void exibir(NO* inicio){
		if(!inicio) printf("Arvore vazia");
		else{
			if(inicio){
				printf("%d ",inicio->chave);
				if(inicio->esq){
					printf("%de",inicio->chave);
					exibir(inicio->esq);
				}
				if(inicio->dir){
					printf("%dd",inicio->chave);
					exibir(inicio->dir);
				}
			}
		}
	}
	
	void exibirArvoreEmNivel(NO* raiz){
		FILA f;
		NO* p = raiz;
		inicializarFILA(&f);
		while( (p) || (f.inicio) ){
			if(p->esq) entrarFILA(&f, p->esq);
			if(p->dir) entrarFILA(&f, p->dir);
			printf("%d - ", p->chave);
			p = NULL;
			if(f.inicio) p = sairFILA(&f);
		}
		printf("\n");
	}
		
	void escreverEmArquivo(NO* raiz);
	
	int main(){
		Arvore arvore;
		inicializar(&arvore);
		
		inserir(&arvore.raiz, 20);
		inserir(&arvore.raiz, 04);
		inserir(&arvore.raiz, 05);
		inserir(&arvore.raiz, 15);
		inserir(&arvore.raiz, 23);
		inserir(&arvore.raiz, 16);
		inserir(&arvore.raiz, 64);
		inserir(&arvore.raiz, 10);
		inserir(&arvore.raiz, 19);
		inserir(&arvore.raiz, 14);
		inserir(&arvore.raiz, 30);
		inserir(&arvore.raiz, 03);
		inserir(&arvore.raiz, 13);
		inserir(&arvore.raiz, 9);
		inserir(&arvore.raiz, 8);
		inserir(&arvore.raiz, 22);
		inserir(&arvore.raiz, 21);
		inserir(&arvore.raiz, 90);
		inserir(&arvore.raiz, 4);
		inserir(&arvore.raiz, 15);
		inserir(&arvore.raiz, 23);
		inserir(&arvore.raiz, 64);
		inserir(&arvore.raiz, 19);
		inserir(&arvore.raiz, 14);
		
		printf("\nExibir Arvore em nivel\n");
		exibirArvoreEmNivel(arvore.raiz);
		
		/*
		Author: Ricardo Goncalves Dias
		*/		
		escreverEmArquivo(arvore.raiz);
		system("dot -Tpng /home/ricardo/Documentos/AED/desenho.dot > /home/ricardo/Documentos/AED/desenho.png");
		printf("\n\nby Ricardo Goncalves Dias\n");
	}
	
	/*
	Author: Ricardo Goncalves Dias
	*/
	void escreverEmArquivo(NO* raiz){
		FILE *file;		
		
		file = fopen("/home/ricardo/Documentos/AED/desenho.dot", "w+");
		
		fprintf(file, "digraph desenho{");//Write in new File
		
		FILA f;
		NO* p = raiz;
		NO* pai = NULL;
		inicializarFILA(&f);
		while( (p) || (f.inicio) ){
			if(p->esq){
				fprintf(file, "\n\t%d->%d;",p->chave,p->esq->chave);//Write in new File
				entrarFILA(&f, p->esq);
			}
			
			if(p->dir){
				fprintf(file, "\n\t%d->%d;",p->chave,p->dir->chave);//Write in new File
				entrarFILA(&f, p->dir);
			}
			
			p = NULL;
			if(f.inicio) p = sairFILA(&f);
		}
		fprintf(file, "\n}");//Write in new File
		fclose(file);
	}
