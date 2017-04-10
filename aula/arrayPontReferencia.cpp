#include <stdio.h>
#include <stdlib.h>



void inicializarArrayReferencia (int * v) {
	int i;
	for (i = 0; i < 10; i++)
		v[i] = (i + 1) * 4;	
}


main (void) {
	int i;
	int * v;

	v = (int*) malloc (sizeof (int) * 10);

	inicializarArrayReferencia (v);

	for (i = 0; i < 10; i++)
		printf ("%d ", v[i]);

	printf("\n");

	

}