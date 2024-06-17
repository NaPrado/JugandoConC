/* 
[C] IF X₁≠0 GOTO A
    IF X₂≠0 GOTO E
    Y   ← Y+1
[D] Z₂  ← Z₂+1
    IF Z₂≠0 GOTO E
[A] IF X₂≠0 GOTO B
    Z₃  ← Z₃+1
    IF Z₃≠0 GOTO D
[B] X₁  ← X₁-1
    X₂  ← X₂-1
    Z₁  ← Z₁+1
    IF Z₁≠0 GOTO C
*/
#include "../Librerias/getnum.h"
#include <stdio.h>
#include <stdlib.h>

int eq(__u_int x1,__u_int x2){
    unsigned int y,z1,z2,z3;
    z1=z2=z3=y=0;
    C:  if(x1!=0) goto A;
        if(x2!=0) goto E;
        y++;
    D:  z2++;
        if(z2!=0) goto E;
    A:  if(x2!=0) goto B;
        z3++;
        if(z3!=0) goto D;
    B:  x1--;
        x2--;
        z1++;
        if (z1!=0) goto C;
    E: return y;
}

int main(int argc, char const *argv[]){
    printf("Y=%d\n",eq(5,5));
}
