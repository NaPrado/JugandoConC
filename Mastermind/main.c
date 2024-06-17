#include "master.h"
#include <stdlib.h>

int main(int argc, char const *argv[]){

    int     dim         =   chooseLegth()   ;
    int*    vecRand     =   randomVec(dim)  ;
    int     intentos    =   nivel()         ;
    int     cond        =   1               ;

    for (int i = 0; i < intentos && cond; i++){
        int*                vec     =   leerNumero(dim)                 ;
        struct cantCond     bnReg   =   cantCond(vec,vecRand,dim)       ;
                            cond    =   coincideNumero(bnReg,dim)       ;
    }
    free(vecRand);
    return 0;
}
