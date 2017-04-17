#include <stdio.h>

int main (void) {
   typedef struct {
      int dia, mes, ano; 
   } data;
   printf ("sizeof (data) = %ld\n", 
            sizeof (data));        
}
