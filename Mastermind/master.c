#include <stdio.h>
#include <stdlib.h>
#include "../Librerias/random.h"
#include "../Librerias/getnum.h"
#include "master.h"

int chooseLegth(){
    int num=-1;
    while (VALID_COND){
        num=getint("Ingrese un numero del 1 al 10 inclusive para elegir la cantidad de digitos\n");
        if (!VALID_COND){
            printf("Ingreso un numero no valido\n");
        }
    }
    return num;
}

void shuffle(int v[]){
    srand(time(NULL));
    for (int i = 0; i  < MAX; i++){
        int aux= v[i];
        int ran= randInt(MIN,MAX);
        v[i]=v[ran];
        v[ran]=aux;
    }
}

int * randomVec(int dim){
    int * v=malloc(sizeof(int)*MAX);
    for (int i = 0; i < MAX; i++){
        *(v+i)=i+1;
    }
    shuffle(v);
    v=realloc(v,sizeof(int)*dim);
    return v;
}

int nivel(){
    int num=-1;
    while (VALID_COND){
        num=getint("Ingrese un numero del 1 al 10 inclusive para elegir la dificultad\n");
        if (!VALID_COND){
            printf("Ingreso un numero no valido\n");
        }
    }
    return num;
}

int isValidNum(int num,int dim){
    int count=0;
    while (num!=0){
        num/=10;
        count++;
    }
    return count==dim;
}

int * numToVec(int num,int dim){
    int numero[dim];
    int i,j,numOK;
    do
    {   
        for (i=dim-1, numOK = 1; i>=0 && numOK ; i--, num/=10)
        {
            numero[i] = num % 10;
            if (numero[i] == 0)
                numOK = 0;
            else
                for (j=dim-1; j>i && numOK ; j--)
                    if (numero[i] == numero[j])
                        numOK = 0;
        }
    } while (!numOK || num!=0);
    return numero;
}

int * leerNumero(int dim){
    int num=-1;
    int cond=0;
    while (XDIGIT)
    {
        num=getint("Numero Introducido por el jugador:\t");
        cond=isValidNum(num,dim);
        if (!XDIGIT){
            printf("Numero no valido");
        }
    }
    return numToVec(num,dim);
}

int coincideNumero(struct cantCond cond,int dim){
    return cond.bien==dim;
}

struct cantCond cantCond(int e [],int s [],int dim){
    struct cantCond ret;
    ret.bien=0;
    ret.regular=0;
    for (size_t i = 0; i < dim; i++)
        for (size_t j = 0; j < dim; j++)
            if (e[i]==s[j]){
                if (i==j)
                    ret.bien++;
                else
                    ret.regular++;
            }
    return ret;
}
