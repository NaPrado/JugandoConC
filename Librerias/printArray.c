#include "./printArray.h"
#include <stdio.h>
//RECIBE (ARRAY , DIM)
void printArray(int arreglo[], int dim){
    printf("\nEl arreglo es: \n");
    for( int i = 0; i < dim; i++){
        printf("%d ",arreglo[i]); 
    }
    printf("\n");
}


    