#include <stdio.h>
#include <stdlib.h>


//Aritmética de ponteiros.
main (void) {
	int * vet;
	int * ptr;

	vet = (int*) malloc (sizeof (int));
	vet[4] = 44; //vet funciona como um vetor depois de malloc.

	ptr = vet; //ptr aponta para o início da área apontada por vet.

	*ptr = 11; //vet[0] = 11. Coloca 11 na 1ª posição da área alocada.
	ptr++; //incrementa o ponteiro em um int, ou seja, 4 bytes.

	*ptr = 12; //vet[0] = 12.
	

	printf("%p\n", ptr);
	printf("%d\n", *ptr);

	//free(ptr); //liberar ptr direto causa NULL POINTER ASSIGNMENT.
	//A forma correta é:
	ptr--;
	free (ptr);

	return 0;
}