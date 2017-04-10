#include <stdio.h>
#include <stdlib.h>


main (void) {
	int i;
	int * v;

	v = (int*) malloc (sizeof (int) * 10);

	for (i = 0; i < 10; i++)
		v[i] = i+1;

	for (i = 0; i < 10; i++)
		printf ("%d ", v[i]);
	printf("\n");

}