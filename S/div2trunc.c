/* 
[C] IF X≠0 GOTO A
    Z₂  ← Z₂+1
    IF Z₂≠0 GOTO E
[A] X   ← X-1
    IF X≠0 GOTO B
    Z₃  ← Z₃+1
    IF Z₃≠0 GOTO E
[B] X   ← X-1
    Y   ← Y+1
    Z₁  ← Z₁+1
    IF Z₁≠0 GOTO C
*/
#include "../Librerias/getnum.h"
#include <stdio.h>
#include <stdlib.h>
#define IFNOTJP(var,rot) if(var!=0) goto rot;

int div2trunc(__u_int x){
    unsigned int y,z1,z2,z3;
    z1=z2=z3=y=0;
    C:  IFNOTJP(x,A)
        z2++;
        IFNOTJP(z2,E)
    A:  x--;
        IFNOTJP(x,B)
        z3++;
        IFNOTJP(z3,E)
    B:  x--;
        y++;
        z1++;
        IFNOTJP(z1,C)
    E:return y;
}
int main(int argc, char const *argv[])
{
    int x =getint("ingrese x: ");
    printf("Y=%d\n",div2trunc(x));
    return 0;
}
