/*
[C] IF X₂≠0 GOTO A
    IF X₁≠0 GOTO D
    Z₂  ← Z₂+1
    IF Z₂≠0 GOTO E
[D] Y   ← Y+1
    Z₃  ← Z₃+1
    IF Z₃≠0 GOTO E
[A] IF X₁≠0 GOTO B
    Z₄  ← Z₄+1
    IF Z₄≠0 GOTO E
[B] X₁  ← X₁-1
    X₂  ← X₂-1
    Z₁  ← Z₁+1
    IF Z₁≠0 GOTO [C]
*/
#include "../Librerias/getnum.h"
#include <stdio.h>
#include <stdlib.h>
#define IFNOTJP(var,rot) if(var!=0) goto rot;
int mayorQue(__u_int x1, __u_int x2){
    unsigned int y,z1,z2,z3,z4;
    z1=z2=z3=z4=y=0;
    C:  IFNOTJP(x2,A)
        IFNOTJP(x1,D)
        z2++;
        IFNOTJP(z2,E)
    D:  y++;
        z3++;
        IFNOTJP(z3,E)
    A:  IFNOTJP(x1,B)
        z4++;
        IFNOTJP(z4,E)
    B:  x1--;
        x2--;
        z1++;
        IFNOTJP(z1,C)
    E: return y;
}

int main(int argc, char const *argv[])
{
    int x1 =getint("ingrese x1: ");
    int x2 =getint("ingrese x2: ");
    printf("Y=%d\n",mayorQue(x1,x2));
    return 0;
}
