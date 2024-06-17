#include "../Librerias/getnum.h"
#include "../Librerias/random/random.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#define X 4
#define MAXNIVEL 10

void 
generaAleatorio( int incognita[] )
{
	char arregloAux[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = 9, i, numAux;


	for (i=0; i < X; i++)
	{
		numAux = randInt(0,n-1);
		incognita[i] = arregloAux[numAux];
		arregloAux[numAux] = arregloAux[--n];
	}
	return;
}


int
elegirNivel(){
    int n;
    do
    {
        n=getint("Ingrese el nivel (la cantidad de intentos): ");
    } while (n<1||n>MAXNIVEL);
    return n;
}


void
leerNumero(int numero[]){
    int i,j,num,numOK;
    do
    {   
        num=getint("Ingrese un Numero de %d digitos, sin repetir: ", X);
        for (i=X-1, numOK = 1; i>=0 && numOK ; i--, num/=10)
        {
            numero[i] = num % 10;
            if (numero[i] == 0)
                numOK = 0;
            else
                for (j=X-1; j>i && numOK ; j--)
                    if (numero[i] == numero[j])
                        numOK = 0;
        }
    } while (!numOK || num!=0);
}

int
cantidadBien(int numeroAleatorio[X], int numeroIngresado[X]){
    int bien=0;
    for (int i = 0;i<X; i++)
        if(numeroIngresado[i]==numeroAleatorio[i])
            bien++;
    return bien;
}

int
cantidadRegular(int numeroAleatorio[X], int numeroIngresado[]){
    int regular=0;
    for (int i = 0; i < X; i++)
        for (int j = 0; j < X; j++)
            if (numeroIngresado[i]==numeroAleatorio[j]&& i!=j)
                regular++;
    return regular;
}

int 
coincideNumero(int numeroAleatorio[X], int numeroIngresado[X]){
    int bien = cantidadBien(numeroAleatorio, numeroIngresado);
    if (bien==X)
        return 1;
    int regular = cantidadRegular(numeroAleatorio, numeroIngresado);
    (bien) ? (printf("Bien: %d\n",bien)) : (printf("Ninguno Bien\n"));
    (regular) ? (printf("Regulares: %d\n",regular)):(printf("Ninguno Regular\n"));
    return 0;
}

int
main (void)
{
	int incognita[X], numero[X];
	int acierto = 0;		/* Flag para indicar que el jugador adivinó */
	int paso, i, nivel;


	randomize();


	nivel = elegirNivel();


	generaAleatorio(incognita);


	for (paso=0; paso < nivel && !acierto; paso++)
	{
		printf("Queda%s %d oportunidad%s\n", (nivel-paso>1)?"n":"",
 				nivel-paso, (nivel-paso>1)?"es":"");
		leerNumero(numero);
		acierto = coincideNumero(incognita, numero);
	}
	if ( acierto )
		printf ("\nAdivinaste el numero en %d pasos\n",paso);
	else
	{
		printf ("\nLo siento, el numero es ");
		for (i=0; i < X; i++)
			printf ("%d",incognita[i]);
		printf("\n");
	}


	return 0;
}