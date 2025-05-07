#include <stdio.h>
#include <stdlib.h>     

int main(void)
{
    int *x = malloc(3 * sizeof(int)); //Guarda na memoria 3 inteiros
    x[0] = 72;
    x[1] = 73;      
    x[2] = 74;
    free(x); // Libera a memoria alocada para o vetor x
}