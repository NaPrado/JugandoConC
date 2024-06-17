/*
[C] IF X₁≠O GOTO A
    IF X₂≠0 GOTO D
    Z₂  ← Z₂+1
    IF Z₂≠0 GOTO E
[D] Z₃  ← Z₃+1
    IF Z₃≠0 GOTO D
[A] IF X₂≠0 GOTO B
    Y   ← Y+1
    X₁  ← X₁-1
    IF X₁≠0 GOTO A
    Z₄  ← Z₄+1
    IF Z₄≠0 GOTO E
[B] X₁  ← X₁-1
    X₂  ← X₂-1
    Z₁  ← Z₁+1
    IF Z₁≠0 GOTO C
*/
#include "../Librerias/getnum.h"
#include <stdio.h>
#include <stdlib.h>
#define IFNOTJP(var,rot) if(var!=0) goto rot;

int R(__u_int x1,__u_int x2){
    unsigned int y,z1,z2,z3,z4;
    z1=z2=z3=z4=y=0;
    C:  IFNOTJP(x1,A)
        IFNOTJP(x2,D)
        z2++;
        IFNOTJP(z2,E)
    D:  z3++;
        IFNOTJP(z3,D)
    A:  IFNOTJP(x2,B)
        y++;
        x1--;
        IFNOTJP(x1,A)
        z4++;
        IFNOTJP(z4,E)
    B:  x1--;
        x2--;
        z1++;
        IFNOTJP(z1,C)
    E:  return y;
}

int main(int argc, char const *argv[]){
    int x1 =getint("ingrese x1: ");
    int x2 =getint("ingrese x2: ");
    printf("Y=%d\n",R(x1,x2));
    return 0;
}
