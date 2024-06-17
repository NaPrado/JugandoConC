#include <stdio.h>
#include <stdlib.h>
#include "../Librerias/random.h"
#include <ctype.h>
#include "../Librerias/getnum.h"
#include <string.h>

#define MIN 0
#define MAX 9


char recibeLetra ( ) {
    printf("\nColoque una letra minuscula del alfabeto ingles: ");

    char letra;
    while ((letra = getchar()) != '\n' && letra != EOF);
    
    while ( letra < 'a' || letra > 'z' ) {
        printf("letra=%c",letra);
        printf("Mal, pone de nuevo: ");
        letra = getchar();
    }

    return letra;
}


char * chequeaLetra ( char *p, char *vecInvisible , char letra ) { // si 
    for ( int i = 0 ; p[i] != 0 && vecInvisible[i] != 0 ; i++ ) {
        
        if ( letra == p[i] ) 
            vecInvisible[i] = letra;

    }

    return vecInvisible;

}


void invisible ( char * p , int dim) {

    for ( int i = 0 ; i < dim ; i++ ) 
        p[i] = '-';

}


int nivel ( ) {  
    int level = getint("Coloque una cantidad de intentos del 1 al 25: "); 

    while ( level <= 0 || level >= 26 ) {
        level = getint("MAL, coloque otro: ");
    }

    return level;

}

int main () {
    randomize();
    char * palabra[] = {"rojo", "papas", "salto", "pelota", "auto", "materia", "ventana", "semaforo", "libro", "edificio"};
    char * letraPalabra = palabra[randInt(MIN,MAX)];
    int tamanio = strlen(letraPalabra);
    char * aux;
    aux = malloc(tamanio*sizeof(char));
    invisible(aux, tamanio);
    int intentos = nivel(), gano = 0;

    while( intentos > 0 && !gano) {
        int count = 0;
        char letra = recibeLetra();
        aux = chequeaLetra(letraPalabra, aux, letra);

        for ( int i = 0 ; i < tamanio ; i++ ) {
            printf("%c ", aux[i]);
            if ( aux[i] != '-' )
                count++;
        }

        if ( count == tamanio ) {
            printf("\nGanaste!! ");
            gano = 1;
        }
        
        intentos--;
    }

    if (intentos == 0) 
        printf("\nPerdiste la palabra era: %s\n", letraPalabra);

    free(aux);
    return 0;

}