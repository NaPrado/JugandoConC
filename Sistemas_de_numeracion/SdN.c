#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BLOCK 5
typedef struct vec
{
    int * array;
    int dim;
}vecT;


vecT getNumArray(int num,int dim){
    if(dim<=0){
        perror("Invalid Dim");
        exit(EXIT_FAILURE);
    }
    vecT ret;
    ret.array=malloc(sizeof(int)*BLOCK);
    ret.dim=0;
    int actualSize=BLOCK;
    int numCopy=num;
    if ( num == 0 ){
        ret.array=realloc(ret.array,sizeof(int)*1);
        *ret.array=0;
        ret.dim=1;
        return ret; 
    }
    while (dim--){
        int digit=numCopy%10;
        numCopy/=10;
        if (ret.dim==actualSize){
            ret.array=realloc(ret.array,sizeof(int)*(actualSize+BLOCK));
            actualSize+=BLOCK;
        }
        ret.array[ret.dim++]=digit;
    }
    ret.array=realloc(ret.array,sizeof(int)*(ret.dim));
    return ret;
}

int SS(int num,int p, int k){
    vecT numero = getNumArray(num,k);
    int resp=0;
    for ( int i = numero.dim-1; i >= 0; i-- ){
        resp+=numero.array[i]*pow(p,i);
    }
    free(numero.array);
    return resp;
}

int main(int argc, char const *argv[])
{
    printf("%d",SS(103,4,4));
    return 0;
}
